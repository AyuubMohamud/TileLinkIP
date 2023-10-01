`timescale 1ns / 1ps
module litesdcard_wrapper (
    input   wire logic                      host_clk_i,
    input   wire logic                      host_rst_i,
    input   wire logic                      lsioc_rx_vld_i,
    input   wire logic [12:0]               lsioc_rx_sbsp_i,
    input   wire logic [31:0]               lsioc_rx_data_i,
    input   wire logic [2:0]                lsioc_rx_opc_i,
    output       logic                      lsioc_rx_busy_o,

    output       logic [1:0]                lsioc_tx_err_code_o,
    output       logic [31:0]               lsioc_tx_data_o,
    output       logic                      lsioc_tx_vld_o,
    input   wire logic                      lsioc_tx_busy_i,

    // Cache request channel
    output   wire logic                     cache_req_vld_o,
    output   wire logic  [1:0]              cache_req_op_o, // 00 - Read , 01-RWM (upgrade to M), 10-invalidate (upgrade to M), 11-write out
    output   wire logic  [22:0]             cache_req_cl_o,
    output   wire logic  [63:0]             cache_req_data_o,

    input    wire logic                     emc_busy_i,

    // Cache response channel
    input    wire logic                     cache_resp_vld_i,
    input    wire logic [63:0]              cache_resp_data_i,
    input    wire logic                     cache_resp_exc_i,
    input    wire logic                     cache_resp_fwd_i,
    // Ordering point request channel
    input    wire logic  [22:0]             op_req_cl_i,
    input    wire logic  [1:0]              op_req_op_i,
    input    wire logic                     op_req_vld_i,
    // Ordering point response address channel
    output   wire logic                     op_resp_vld_o,
    output   wire logic                     op_resp_uniq_found_o, // Found cache line in M/O/E/F states
    output   wire logic  [63:0]             op_resp_data_o,

    output  wire logic                      irq_o,

    input  wire                             sdcard_cd,
    output reg                              sdcard_clk,
    inout  wire                             sdcard_cmd,
    inout  wire    [3:0]                    sdcard_data
);
    wire busy;
    wire [47:0] working_data;
    wire working_vld;
    skdbf #(.DW(48)) lsi_skidbuffer (host_clk_i, host_rst_i, busy, working_data, working_vld, lsioc_rx_busy_o, {
        lsioc_rx_sbsp_i, lsioc_rx_data_i, lsioc_rx_opc_i
    }, lsioc_rx_vld_i);

    wire [12:0] working_lsioc_sbsp = working_data[47:35];
    wire [31:0] working_lsioc_data = working_data[34:3];
    wire [2:0] working_lsioc_opc = working_data[2:0];
    wire         wb_ctrl_ack;
    reg [29:0]   wb_ctrl_adr;
    reg [1:0]    wb_ctrl_bte = 2'b00;
    reg [2:0]    wb_ctrl_cti = 3'b000; // LSI doesnt support DMA over slave interfaces like this
    reg          wb_ctrl_cyc;
    wire [31:0]  wb_ctrl_dat_r;
    reg  [31:0]  wb_ctrl_dat_w;
    wire         wb_ctrl_err;
    reg [3:0]    wb_ctrl_sel;
    wire         wb_ctrl_stb;
    reg          wb_ctrl_we;
    //! Looking at the source code for the DMA Readers and Writers it appears that the dma readers/writers also has cti = 3'b000 and bte = 2'b00
    reg          wb_dma_ack;
    wire [29:0]  wb_dma_adr;
    wire [1:0]   wb_dma_bte;
    wire [2:0]   wb_dma_cti;
    wire         wb_dma_cyc;
    reg [31:0]   wb_dma_dat_r;
    wire [31:0]  wb_dma_dat_w;
    wire         wb_dma_err = 1'b0;
    wire [3:0]   wb_dma_sel;
    wire         wb_dma_stb;
    wire         wb_dma_we;
    reg          in_progress;
    assign wb_ctrl_stb = in_progress&!(wb_ctrl_ack|wb_ctrl_err);
    litesdcard_core mmc0 (host_clk_i, irq_o, host_rst_i, sdcard_cd, sdcard_clk, sdcard_cmd, sdcard_data, 
    wb_ctrl_ack,
    wb_ctrl_adr,
    wb_ctrl_bte,
    wb_ctrl_cti,
    wb_ctrl_cyc,
    wb_ctrl_dat_r,
    wb_ctrl_dat_w,
    wb_ctrl_err,
    wb_ctrl_sel,
    wb_ctrl_stb,
    wb_ctrl_we,
    wb_dma_ack,
    wb_dma_adr,
    wb_dma_bte,
    wb_dma_cti,
    wb_dma_cyc,
    wb_dma_dat_r,
    wb_dma_dat_w,
    wb_dma_err,
    wb_dma_sel,
    wb_dma_stb,
    wb_dma_we);
    //! This module converts Wishbone B3 signals into HSI memory signals, and LSI signals into Wishbone B3 slave signals
    //! this module does NOT support the special LSI opcodes for the AMO* operations
    always_ff @(posedge host_clk_i) begin
        if ((wb_ctrl_ack|wb_ctrl_err)&in_progress) begin
            lsioc_tx_vld_o <= 1'b1;
            lsioc_tx_data_o <= wb_ctrl_dat_r;
            lsioc_tx_err_code_o <= wb_ctrl_err ? 2'b01 : 2'b00;
        end else begin
            lsioc_tx_vld_o <= 1'b0;
        end
    end
    always_ff @(posedge host_clk_i) begin
        if (working_vld&!busy) begin 
            in_progress <= 1'b1;
            wb_ctrl_adr <= {17'h0000, working_lsioc_sbsp};
            wb_ctrl_we <= working_lsioc_opc == 3'b001;
            wb_ctrl_cyc <= 1'b1;
            wb_ctrl_sel <= 4'b1111;
        end
        else if (in_progress&(wb_ctrl_ack|wb_ctrl_err)) begin
            in_progress <= 1'b0;
        end
    end
    reg [63:0] cache_line [0:15];
    reg [22:0] cache_line_stored;
    reg [3:0] cache_line_valid = 4'b0000; // this keeps the peripheral coherent with main memory without needing fancypants cache coherence instructions
    //! 0000 - Invalid, 0001 - Shared, 0010 - Exclusive, 0100 - Owned, 1000 - Modified
    reg wb_master_transaction_in_progress;
    reg cycle_type;
    reg [27:0] four_byte_aligned_addr;
    reg mcp_complete_transaction;

    wire match = cache_line_stored==four_byte_aligned_addr[27:5];

    always_ff @(posedge host_clk_i) begin
        if (wb_dma_stb&wb_dma_cyc&!wb_master_transaction_in_progress) begin
            wb_master_transaction_in_progress <= 1'b1;
            cycle_type <= wb_dma_we;
            four_byte_aligned_addr <= wb_dma_adr[27:0];
            wb_dma_ack <= 1'b0;
        end
        else if (mcp_complete_transaction) begin
            wb_dma_ack <= 1'b1;
        end
        else begin
            wb_dma_ack <= 1'b1;
        end
    end
    // Ordering point response machine
    reg [1:0] OP_STATE;
    reg [3:0] counter;
    localparam OP_IDLE = 2'b00;
    localparam OP_DATA = 2'b01;
    always_ff @(posedge host_clk_i) begin
        case (OP_STATE)
            OP_IDLE: begin
                if (op_req_vld_i&(op_req_cl_i==cache_line_stored)) begin
                    if (op_req_op_i==2'b00||op_req_op_i==2'b01) begin
                        OP_STATE <=  |cache_line_valid[3:1] ? OP_DATA : OP_IDLE;
                    end
                    op_resp_vld_o <= 1'b1;
                    op_resp_uniq_found_o <= |cache_line_valid[3:1];
                end else begin
                    op_resp_vld_o <= 1'b0;
                    op_resp_uniq_found_o <= 1'b0;
                end
            end
            OP_DATA: begin
                op_resp_vld_o <= 1'b1;
                op_resp_uniq_found_o <= 1'b1;
                op_resp_data_o <= cache_line[counter];
                if (counter == 4'b1111) begin
                    OP_STATE <= OP_IDLE;
                    counter <= 4'b0000;
                end else begin
                    counter <= counter + 1'b1;
                end
            end 
        endcase
    end

    always_ff @(posedge host_clk_i) begin
        if (cache_resp_vld_i&cycle_type) begin
            if (cycle_type) begin
                
            end
        end
        else if (op_req_vld_i&(op_req_cl_i==cache_line_stored)) begin
            if ((op_req_op_i==2'b01||op_req_op_i==2'b10||op_req_op_i==2'b11)) begin
                cache_line_valid <= 4'b0000;
            end
            else if (op_req_op_i==2'b00) begin
                cache_line_valid <= cache_line_valid[3] ? 4'b0100 : cache_line_valid[2] ? 4'b0100 : 4'b0001;
            end
        end
    end

endmodule

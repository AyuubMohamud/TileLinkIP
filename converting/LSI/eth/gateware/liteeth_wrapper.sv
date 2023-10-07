`timescale 1ns / 1ps
module liteeth_wrapper (
    input   wire logic                      host_clk_i,
    input   wire logic                      host_rst_i,
    input   wire logic                      lsioc_rx_vld_i,
    input   wire logic [13:0]               lsioc_rx_sbsp_i,
    input   wire logic [31:0]               lsioc_rx_data_i,
    input   wire logic [2:0]                lsioc_rx_opc_i,
    output       logic                      lsioc_rx_busy_o,

    output       logic [1:0]                lsioc_tx_err_code_o,
    output       logic [31:0]               lsioc_tx_data_o,
    output       logic                      lsioc_tx_vld_o,
    input   wire logic                      lsioc_tx_busy_i,

    output  wire logic                      irq_o,
    input  wire          mii_clocks_rx,
    input  wire          mii_clocks_tx,
    input  wire          mii_col,
    input  wire          mii_crs,
    output wire          mii_mdc,
    inout  wire          mii_mdio,
    output wire          mii_rst_n,
    input  wire    [3:0] mii_rx_data,
    input  wire          mii_rx_dv,
    input  wire          mii_rx_er,
    output reg     [3:0] mii_tx_data,
    output reg           mii_tx_en
);
    wire busy;
    wire [48:0] working_data;
    wire working_vld;
    skdbf #(.DW(49)) lsi_skidbuffer (host_clk_i, host_rst_i, busy, working_data, working_vld, lsioc_rx_busy_o, {
        lsioc_rx_sbsp_i, lsioc_rx_data_i, lsioc_rx_opc_i
    }, lsioc_rx_vld_i);
    wire [13:0] working_lsioc_sbsp = working_data[48:35];
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
    reg          in_progress;
    assign wb_ctrl_stb = in_progress&!(wb_ctrl_ack|wb_ctrl_err);
    liteeth_core eth0 (irq_o,
    mii_clocks_rx,
    mii_clocks_tx,
    mii_col,
    mii_crs,
    mii_mdc,
    mii_mdio,
    mii_rst_n,
    mii_rx_data,
    mii_rx_dv,
    mii_rx_er,
    mii_tx_data,
    mii_tx_en,
    host_clk_i,
    host_rst_i,
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
    wb_ctrl_we);
    assign busy = in_progress|lsioc_tx_busy_i;
    //always_ff @(posedge host_clk_i) begin : check
    //    if ((wb_ctrl_ack|wb_ctrl_err)&in_progress) begin // if an actual transaction is present
    //        lsioc_tx_vld_o <= 1'b1;
    //        lsioc_tx_data_o <= wb_ctrl_dat_r;
    //        lsioc_tx_err_code_o <= wb_ctrl_err ? 2'b01 : 2'b00;
    //    end else begin
    //        lsioc_tx_vld_o <= 1'b0;
    //    end
    //end
    //always_ff @(posedge host_clk_i) begin
    //    if (working_vld&!busy) begin 
    //        in_progress <= 1'b1;
    //        wb_ctrl_adr <= {16'h0000, working_lsioc_sbsp};
    //        wb_ctrl_we <= working_lsioc_opc == 3'b001;
    //        wb_ctrl_cyc <= 1'b1;
    //        wb_ctrl_sel <= 4'b1111;
    //        wb_ctrl_dat_w <= working_lsioc_data;
    //    end
    //    else if (in_progress&(wb_ctrl_ack|wb_ctrl_err)) begin
    //        in_progress <= 1'b0;
    //    end
    //end
endmodule

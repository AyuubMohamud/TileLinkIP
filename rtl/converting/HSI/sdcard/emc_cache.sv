module emc_cache (
    input   wire logic                      host_clk_i,
    input   wire logic                      host_rst_i,

    output  wire logic                      wb_dma_ack,
    input   wire logic [29:0]               wb_dma_adr,
    input   wire logic  [1:0]               wb_dma_bte,
    input   wire logic  [2:0]               wb_dma_cti,
    input   wire logic                      wb_dma_cyc,
    output  wire logic [31:0]               wb_dma_dat_r,
    input   wire logic [31:0]               wb_dma_dat_w,
    output  wire logic                      wb_dma_err,
    input   wire logic  [3:0]               wb_dma_sel,
    input   wire logic                      wb_dma_stb,
    input   wire logic                      wb_dma_we,
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
    output   wire logic  [63:0]             op_resp_data_o
);
    reg [63:0] cache_line [0:15];
    reg [22:0] cache_line_stored;
    reg [4:0] cache_line_valid = 4'b0000; // this keeps the peripheral coherent with main memory without needing fancypants cache coherence instructions
    //! 00000 - Invalid, 00001 - Forward, 00010 - Shared, 00100 - Exculusive, 01000 - Owned, 10000 - Modified
    reg wb_master_transaction_in_progress;
    reg cycle_type;
    reg [27:0] four_byte_aligned_addr;
    reg mcp_complete_transaction;
    reg publish_request;

    always_ff @(posedge host_clk_i) begin
        if (wb_dma_stb&wb_dma_cyc&!wb_master_transaction_in_progress) begin
            wb_master_transaction_in_progress <= 1'b1;
            cycle_type <= wb_dma_we;
            four_byte_aligned_addr <= wb_dma_adr[27:0];
            wb_dma_ack <= 1'b0;
        end
        else if (mcp_complete_transaction) begin
            wb_dma_ack <= 1'b1;
            wb_master_transaction_in_progress <= 1'b0;
        end
        else begin
            wb_dma_ack <= 1'b0;
        end
    end
    reg [3:0] counter_2;
    wire cl_match = (cache_line_stored == four_byte_aligned_addr[27:5])&(|cache_line_valid);
    wire write_perms = cache_line_valid[4]|cache_line_valid[3];
    wire [31:0] data_wanted = four_byte_aligned_addr[4] ? cache_line[cache_line_stored[3:0]][63:32] : cache_line[cache_line_stored[3:0]][31:0];

    reg []

    always_ff @(posedge host_clk_i) begin
        if (!publish_request&wb_master_transaction_in_progress) begin
            if (cl_match&!cycle_type) begin
                
            end
        end
    end


    // Ordering point response machine
    reg OP_STATE;
    reg [3:0] counter;
    localparam OP_IDLE = 1'b0;
    localparam OP_DATA = 1'b1;
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
    
endmodule

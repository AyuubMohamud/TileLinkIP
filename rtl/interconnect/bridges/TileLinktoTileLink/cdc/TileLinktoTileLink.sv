module TileLinktoTileLink 
#(parameter AW = 32, parameter DW = 32, parameter RS = 4, parameter LGB2FW = 8)
(
    input   wire logic                          tilelink_clock_u,
    input   wire logic                          tilelink_reset_u,
    input   wire logic                          tilelink_clock_v,
    input   wire logic                          tilelink_reset_v,
    // Slave interface
    input   wire logic [2:0]                    u_a_opcode,
    input   wire logic [2:0]                    u_a_param,
    input   wire logic [3:0]                    u_a_size,
    input   wire logic [RS-1:0]                 u_a_source,
    input   wire logic [AW-1:0]                 u_a_address,
    input   wire logic [DW/8-1:0]               u_a_mask,
    input   wire logic [DW-1:0]                 u_a_data,
    input   wire logic                          u_a_corrupt,
    input   wire logic                          u_a_valid,
    output  wire logic                          u_a_ready,
    output  wire logic [2:0]                    u_d_opcode,
    output  wire logic [1:0]                    u_d_param,
    output  wire logic [3:0]                    u_d_size,
    output  wire logic [RS-1:0]                 u_d_source,
    output  wire logic                          u_d_denied,
    output  wire logic [DW-1:0]                 u_d_data,
    output  wire logic                          u_d_corrupt,
    output  wire logic                          u_d_valid,
    input   wire logic                          u_d_ready,
    output  wire logic [2:0]                    v_a_opcode,
    output  wire logic [2:0]                    v_a_param,
    output  wire logic [3:0]                    v_a_size,
    output  wire logic [RS-1:0]                 v_a_source,
    output  wire logic [AW-1:0]                 v_a_address,
    output  wire logic [DW/8-1:0]               v_a_mask,
    output  wire logic [DW-1:0]                 v_a_data,
    output  wire logic                          v_a_corrupt,
    output  wire logic                          v_a_valid,
    input   wire logic                          v_a_ready,
    input   wire logic [2:0]                    v_d_opcode,
    input   wire logic [1:0]                    v_d_param,
    input   wire logic [3:0]                    v_d_size,
    input   wire logic [RS-1:0]                 v_d_source,
    input   wire logic                          v_d_denied,
    input   wire logic [DW-1:0]                 v_d_data,
    input   wire logic                          v_d_corrupt,
    input   wire logic                          v_d_valid,
    output   wire logic                         v_d_ready
);
    // skidbuffer
    wire [RS-1:0] working_u_source;
    wire [3:0] working_u_size;
    wire [DW-1:0] working_u_data;
    wire [DW/8-1:0] working_u_mask;
    wire [2:0] working_u_opcode;
    wire [AW-1:0] working_u_address;
    wire [2:0] working_u_param;
    wire working_u_valid;
    wire working_u_corrupt;
    wire u_busy;
    wire bridge_busy;
    assign u_a_ready = ~bridge_busy;
    skdbf #(RS+4+7+DW+AW+DW/8) skidbuffer (tilelink_clock_u, tilelink_reset_u, u_busy, {
        working_u_source,
        working_u_size,
        working_u_data,
        working_u_mask,
        working_u_opcode,
        working_u_address,
        working_u_param,
        working_u_corrupt
    }, working_u_valid, bridge_busy, {
        u_a_source, u_a_size, u_a_data, u_a_mask, u_a_opcode, u_a_address, u_a_param, u_a_corrupt
    }, u_a_valid);
    wire cdc_wreset = !tilelink_reset_u;
    wire cdc_rreset = !tilelink_reset_v;
    wire cdc_wfull;
    assign u_busy = cdc_wfull;
    wire cdc_wwrite = !cdc_wfull&working_u_valid;
    wire cdc_rempty;
    wire cdc_rread = v_a_ready&!cdc_rempty;
    assign v_a_valid = !cdc_rempty;
    cdcfifo #(.ASIZE(LGB2FW), .DSIZE(11+RS+AW+DW+DW/8)) utov (tilelink_clock_u, cdc_wreset, cdc_wwrite, {
    working_u_opcode, working_u_param, working_u_size, working_u_source, working_u_address, working_u_mask, working_u_data, working_u_corrupt}, cdc_wfull,
    tilelink_clock_v, cdc_rreset, cdc_rread, {
    v_a_opcode, v_a_param, v_a_size, v_a_source, v_a_address, v_a_mask, v_a_data, v_a_corrupt}, cdc_rempty);

    // Another skidbuffer
    wire [RS-1:0] working_v_source;
    wire [3:0] working_v_size;
    wire [DW-1:0] working_v_data;
    wire [2:0] working_v_opcode;
    wire [1:0] working_v_param;
    wire working_v_valid;
    wire working_v_corrupt;
    wire working_v_denied;
    wire v_busy;
    wire v_bridge_busy;
    assign v_d_ready = ~v_bridge_busy;
    skdbf #(RS+4+7+DW) skidbuffer2 (tilelink_clock_v, tilelink_reset_v, v_busy, {
        working_v_source,
        working_v_size,
        working_v_data,
        working_v_opcode,
        working_v_param,
        working_v_corrupt,
        working_v_denied
    }, working_v_valid, v_bridge_busy, {
        v_d_source, v_d_size, v_d_data, v_d_opcode, v_d_param, v_d_corrupt, v_d_denied
    }, v_d_valid);
    // other cdc fifo
    wire ret_cdc_wreset = !tilelink_reset_v;
    wire ret_cdc_rreset = !tilelink_reset_u;
    wire ret_cdc_wfull;
    assign v_busy = ret_cdc_wfull;
    wire ret_cdc_wwrite = !ret_cdc_wfull&working_v_valid;
    wire ret_cdc_rempty;
    wire ret_cdc_rread = u_d_ready&!ret_cdc_rempty;
    assign u_d_valid = !ret_cdc_rempty;
    cdcfifo #(.ASIZE(LGB2FW), .DSIZE(RS+4+7+DW)) vtou (tilelink_clock_v, ret_cdc_wreset, ret_cdc_wwrite, {
    working_v_opcode, working_v_param, working_v_size, working_v_source, working_v_data, working_v_corrupt, working_v_denied}, ret_cdc_wfull,
    tilelink_clock_u, ret_cdc_rreset, ret_cdc_rread, {
    u_d_opcode, u_d_param, u_d_size, u_d_source, u_d_data, u_d_corrupt, u_d_denied}, ret_cdc_rempty);
endmodule

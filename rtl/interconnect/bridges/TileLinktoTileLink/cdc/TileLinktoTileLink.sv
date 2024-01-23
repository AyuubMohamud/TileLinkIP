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
    wire cdc_wreset = !tilelink_reset_u;
    wire cdc_rreset = !tilelink_reset_v;
    wire cdc_wfull;
    wire cdc_wwrite = !cdc_wfull&;
    wire cdc_rempty;
    wire cdc_rread;

    // Use SKIDBUFFER
    cdcfifo #(.ASIZE(LGB2FW), .DSIZE(11+RS+AW+DW+DW/8)) utov (tilelink_clock_u, cdc_wreset, cdc_wwrite, {
    u_a_opcode, u_a_param, u_a_size, u_a_source, u_a_address, u_a_mask, u_a_data, u_a_corrupt}, cdc_wfull,
    tilelink_clock_v, cdc_rreset, cdc_rread, {
    v_a_opcode, v_a_param, v_a_size, v_a_source, v_a_address, v_a_mask, v_a_data, v_a_corrupt}, cdc_rempty);

    // Another skidbuffer
    // other cdc fifo

endmodule

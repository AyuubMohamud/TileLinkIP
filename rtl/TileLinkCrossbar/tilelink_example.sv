`include "tilelink_defines.sv"
module tilelink_example (
    input   wire logic              tilelink_clk,
    input   wire logic              tilelink_reset,

    input   tlul_narrow::tlul_m2s     tl_i,
    output  tlul_narrow::tlul_s2m     tl_o
);
    wire [2:0] something;
    assign something = tl_i.a_opcode;
endmodule

module l2slave #(parameter TL_RS = 3) (
    input   wire logic                                         l2_clock_i,
    input   wire logic                                         l2_reset_i,

    input   wire logic [2:0]                                   l2_a_opcode,
    input   wire logic [2:0]                                   l2_a_param,
    input   wire logic [3:0]                                   l2_a_size,
    input   wire logic [TL_RS-1:0]                             l2_a_source,
    input   wire logic [3:0]                                   l2_a_address,
    input   wire logic [3:0]                                   l2_a_mask,
    input   wire logic [31:0]                                  l2_a_data,
    input   wire logic                                         l2_a_corrupt,
    input   wire logic                                         l2_a_valid,
    output  wire logic                                         l2_a_ready,
    output       logic [2:0]                                   l2_d_opcode,
    output       logic [1:0]                                   l2_d_param,
    output       logic [3:0]                                   l2_d_size,
    output       logic [TL_RS-1:0]                             l2_d_source,
    output       logic                                         l2_d_denied,
    output       logic [31:0]                                  l2_d_data,
    output       logic                                         l2_d_corrupt,
    output       logic                                         l2_d_valid,
    input   wire logic                                         l2_d_ready
);
    reg [31:0]  configurationRegister = 32'h07090401;
    reg [1:0]   wayEnable = 0;
    reg [31:0]  addressToFlush = 0;
endmodule

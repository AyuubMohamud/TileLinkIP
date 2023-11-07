module openPolarisSD #(parameter TL_RS = 4) (
    input   wire logic                          sd_clock_i,
    input   wire logic                          sd_reset_i,

    // Slave interface
    input   wire logic [2:0]                    sd_a_opcode,
    input   wire logic [2:0]                    sd_a_param,
    input   wire logic [3:0]                    sd_a_size,
    input   wire logic [TL_RS-1:0]              sd_a_source,
    input   wire logic [3:0]                    sd_a_address,
    input   wire logic [3:0]                    sd_a_mask,
    input   wire logic [31:0]                   sd_a_data,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic                          sd_a_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic                          sd_a_valid,
    output  wire logic                          sd_a_ready,

    output       logic [2:0]                    sd_d_opcode,
    output       logic [1:0]                    sd_d_param,
    output       logic [TL_SZ-1:0]              sd_d_size,
    output       logic [TL_RS-1:0]              sd_d_source,
    output       logic                          sd_d_denied,
    output       logic [31:0]                   sd_d_data,
    output       logic                          sd_d_corrupt,
    output       logic                          sd_d_valid,
    input   wire logic                          sd_d_ready
);
    
endmodule

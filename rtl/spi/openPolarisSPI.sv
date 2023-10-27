module openPolarisSPI #(
    parameter TL_RS = 4,
    parameter TL_SZ = 4,
    parameter CS = 2
    ) (
    input   wire logic                          spi_clock_i,
    input   wire logic                          spi_reset_i,

    // Slave interface
    input   wire logic [2:0]                    spi_a_opcode,
    input   wire logic [2:0]                    spi_a_param,
    input   wire logic [TL_SZ-1:0]              spi_a_size,
    input   wire logic [TL_RS-1:0]              spi_a_source,
    input   wire logic [3:0]                    spi_a_address,
    input   wire logic [3:0]                    spi_a_mask,
    input   wire logic [31:0]                   spi_a_data,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic                          spi_a_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic                          spi_a_valid,
    output  wire logic                          spi_a_ready,

    output       logic [2:0]                    spi_d_opcode,
    output       logic [1:0]                    spi_d_param,
    output       logic [TL_SZ-1:0]              spi_d_size,
    output       logic [TL_RS-1:0]              spi_d_source,
    output       logic                          spi_d_denied,
    output       logic [31:0]                   spi_d_data,
    output       logic                          spi_d_corrupt,
    output       logic                          spi_d_valid,
    input   wire logic                          spi_d_ready
);
    wire spi_busy;
    wire [TL_RS-1:0] working_source;
    wire [TL_SZ-1:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire [3:0] working_address;
    wire [2:0] working_param;
    wire working_valid;
    skdbf #(TL_RS+TL_SZ+42+4) skidbuffer (spi_clock_i, spi_reset_i, ~spi_d_ready, {
        working_source,
        working_size,
        working_data,
        working_mask,
        working_opcode,
        working_address,
        working_param
    }, working_valid, spi_busy, {
        spi_a_source, spi_a_size, spi_a_data, spi_a_mask, spi_a_opcode, spi_a_address, spi_a_param
    }, spi_a_valid);
    assign spi_a_ready = ~spi_busy;

    reg [3:0] clock_divider;
    reg [15:0] spi_config;
`ifdef FORMAL
    wire [TL_RS:0] outstanding;
    tlul_slave_formal #(.AW(4), .RS(TL_RS), .MAX(2)) formal (
        uart_clock_i,
        uart_reset_i,
        uart_a_opcode,
        uart_a_param,
        uart_a_size,
        uart_a_source,
        uart_a_address,
        uart_a_mask,
        uart_a_data,
        uart_a_corrupt,
        uart_a_valid,
        uart_a_ready,
        uart_d_opcode,
        uart_d_param,
        uart_d_size,
        uart_d_source,
        uart_d_denied,
        uart_d_data,
        uart_d_corrupt,
        uart_d_valid,
        uart_d_ready,
        outstanding
    );
`endif
endmodule

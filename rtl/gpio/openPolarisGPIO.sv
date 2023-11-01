module openPolarisGPIO #(parameter TL_RS = 4) (
    input   wire logic                          gpio_clock_i,
    input   wire logic                          gpio_reset_i,

    // Slave interface
    input   wire logic [2:0]                    gpio_a_opcode,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic [2:0]                    gpio_a_param,
    input   wire logic [3:0]                    gpio_a_size,
    input   wire logic [TL_RS-1:0]              gpio_a_source,
    input   wire logic                          gpio_a_address,
    input   wire logic [3:0]                    gpio_a_mask,
    input   wire logic [31:0]                   gpio_a_data,
    input   wire logic                          gpio_a_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic                          gpio_a_valid,
    output  wire logic                          gpio_a_ready,

    output       logic [2:0]                    gpio_d_opcode,
    output       logic [1:0]                    gpio_d_param,
    output       logic [3:0]                    gpio_d_size,
    output       logic [TL_RS-1:0]              gpio_d_source,
    output       logic                          gpio_d_denied,
    output       logic [31:0]                   gpio_d_data,
    output       logic                          gpio_d_corrupt,
    output       logic                          gpio_d_valid,
    input   wire logic                          gpio_d_ready,

    output  wire logic [15:0]                   outputs_o,
    input   wire logic [15:0]                   inputs_i
);
    wire gpio_busy;
    wire [TL_RS-1:0] working_source;
    wire [3:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire working_address;
    wire working_valid;
    skdbf #(TL_RS+4+39+1) skidbuffer (gpio_clock_i, gpio_reset_i, ~gpio_d_ready, {
        working_source,
        working_size,
        working_data,
        working_mask,
        working_opcode,
        working_address
    }, working_valid, gpio_busy, {
        gpio_a_source, gpio_a_size, gpio_a_data, gpio_a_mask, gpio_a_opcode, gpio_a_address
    }, gpio_a_valid);
    assign gpio_a_ready = ~gpio_busy;

    reg [15:0] outputs;
    
    always_ff @(posedge gpio_clock_i) begin
        if (gpio_reset_i) begin
            outputs <= 0;
        end
        else if (working_valid&gpio_d_ready&!(gpio_a_address)&(working_opcode==3'd0||working_opcode==3'd1)) begin
            outputs <= working_data[15:0];
        end
    end
    
    always_ff @(posedge gpio_clock_i) begin
        if (gpio_reset_i) begin
            gpio_d_valid <= 0;
        end else if (working_valid&gpio_d_ready) begin
            gpio_d_valid <= 1;
            gpio_d_source <= working_source;
            gpio_d_size <= working_size;
            gpio_d_denied <= 0;
            gpio_d_corrupt <= 0;
            gpio_d_opcode <= 0;
            gpio_d_param <= 0;
            gpio_d_data <= working_address ? {16'h0000, inputs_i} : {16'h0000, outputs};
        end else if (!working_valid&gpio_d_ready) begin
            gpio_d_valid <= 0;
        end
    end

    assign outputs_o = outputs;

`ifdef FORMAL
    wire [TL_RS:0] outstanding;
    tlul_slave_formal #(.AW(1), .RS(TL_RS), .MAX(2)) formal (
        gpio_clock_i,
        gpio_reset_i,
        gpio_a_opcode,
        gpio_a_param,
        gpio_a_size,
        gpio_a_source,
        gpio_a_address,
        gpio_a_mask,
        gpio_a_data,
        gpio_a_corrupt,
        gpio_a_valid,
        gpio_a_ready,
        gpio_d_opcode,
        gpio_d_param,
        gpio_d_size,
        gpio_d_source,
        gpio_d_denied,
        gpio_d_data,
        gpio_d_corrupt,
        gpio_d_valid,
        gpio_d_ready,
        outstanding
    );
`endif
endmodule

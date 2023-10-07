module openPolarisGPIO #(
    parameter TL_RS = 4,
    parameter TL_SZ = 4
    ) (
    input   wire logic                          gpio_clock_i,
    input   wire logic                          gpio_reset_i,

    // Slave interface
    input   wire logic [2:0]                    gpio_a_opcode,
    input   wire logic [2:0]                    gpio_a_param,
    input   wire logic [TL_SZ-1:0]              gpio_a_size,
    input   wire logic [TL_RS-1:0]              gpio_a_source,
    input   wire logic [5:0]                    gpio_a_address,
    input   wire logic [3:0]                    gpio_a_mask,
    input   wire logic [31:0]                   gpio_a_data,
    input   wire logic                          gpio_a_corrupt,
    input   wire logic                          gpio_a_valid,
    output  wire logic                          gpio_a_ready,

    output  wire logic [2:0]                    gpio_d_opcode,
    output  wire logic [2:0]                    gpio_d_param,
    output  wire logic [TL_SZ-1:0]              gpio_d_size,
    output  wire logic [TL_RS-1:0]              gpio_d_source,
    output  wire logic                          gpio_d_denied,
    output  wire logic [31:0]                   gpio_d_data,
    output  wire logic                          gpio_d_corrupt,
    output  wire logic                          gpio_d_valid,
    input   wire logic                          gpio_d_ready,

    output  wire logic [31:0]                   gpio_int_o,

    input   wire logic [31:0]                   gpio_input_i,
    output  wire logic [31:0]                   gpio_tristate_o,
    output  wire logic [31:0]                   gpio_output_o
);
    //! GPIO controller
    //! 0x00 pin values
    //! 0x04 pin outputs
    //! 0x08 pin output enable
    //! 0x0C rise ip
    //! 0x10 rise ie
    //! 0x14 fall ip
    //! 0x18 fall ie
    //! 0x1C low ip
    //! 0x20 low ie
    //! 0x24 high ip
    //! 0x28 high ie
    reg [31:0] pin_outputs;
    reg [31:0] pin_outen;
    reg [31:0] pin_rip;
    reg [31:0] pin_rie;
    reg [31:0] pin_fip;
    reg [31:0] pin_fie;
    reg [31:0] pin_lip;
    reg [31:0] pin_lie;
    reg [31:0] pin_hip;
    reg [31:0] pin_hie;

    reg [31:0] lsinputs;


    assign gpio_output_o = pin_outputs;
    assign gpio_tristate_o = pin_outen;

    wire [31:0] int_fall;
    wire [31:0] int_rise;
    wire [31:0] int_low;
    wire [31:0] int_high;
    for (genvar i = 0; i < 32; i++) begin : interruptCalculation
        assign int_fall[i] = lsinputs[i]&!gpio_input_i[i]&!pin_outen[i]&pin_fie[i];
        assign int_rise[i] = !lsinputs[i]&gpio_input_i[i]&!pin_outen[i]&pin_rie[i];
        assign int_low[i] = !lsinputs[i]&!gpio_input_i[i]&!pin_outen[i]&pin_lie[i];
        assign int_high[i] = lsinputs[i]&gpio_input_i[i]&!pin_outen[i]&pin_hie[i];
    end
endmodule

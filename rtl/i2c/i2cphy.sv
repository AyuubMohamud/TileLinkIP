module i2cphy (
    input   wire logic                  i2c_clock_i,

    input   wire logic [1:0]            i2c_tx_size_i,
    input   wire logic [1:0]            i2c_rx_size_i,
    input   wire logic [31:0]           i2c_tx_data_i,
    input   wire logic [21:0]           i2c_clkdiv_i,
    input   wire logic                  i2c_valid_i,

    output  wire logic                  i2c_done_o,
    output  wire logic                  i2c_busy_o,
    output  wire logic [31:0]           i2c_rx_data_o,
    output  wire logic                  i2c_abort_o,

    input   wire logic                  sda_i,
    output       logic                  sda_o,
    output       logic                  sda_t,

    input   wire logic                  scl_i,
    output       logic                  scl_o,
    output       logic                  scl_t

);
    reg [2:0] i2c_phy;
    localparam I2C_IDLE = 3'b000;
    localparam I2C_START = 3'b001;
    localparam I2C_TX = 3'b010;
    localparam I2C_AWAIT_ACK = 3'b011;
    localparam I2C_RX = 3'b100;
    localparam I2C_
    always_ff @(posedge i2c_clock_i) begin
        

    end
endmodule

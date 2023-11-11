module spiphy #(parameter MAXID = 4) (
    input   wire logic                      spi_clock_i,

    input   wire logic                      spi_tx_i,
    input   wire logic [4:0]                spi_rx_sz_i,
    input   wire logic [4:0]                spi_tx_sz_i,
    input   wire logic                      spi_rx_en_i,
    input   wire logic [$clog2(MAXID)-1:0]  spi_csid_i,
    input   wire logic [31:0]               spi_tx_data_i,
    input   wire logic [9:0]                spi_clkdiv_i,
    input   wire logic                      cpol,
    input   wire logic                      cpha,

    output       logic                      spi_done_o,
    output  wire logic                      spi_busy_o,
    output       logic [31:0]               spi_rx_o,

    input   wire logic [MAXID-1:0]  miso,
    output       logic              mosi,
    output       logic              sck,
    output       logic [MAXID-1:0]  cs_n
);

endmodule

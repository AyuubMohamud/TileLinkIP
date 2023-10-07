module polaris_spi_flash (
    input   wire logic                      lsioc_clk_i,
    input   wire logic                      lsioc_rst_i,


    input   wire logic                      lsioc_rx_vld_i,
    input   wire logic [31:0]               lsioc_rx_data_i,
    input   wire logic [2:0]                lsioc_rx_opc_i,
    output  wire logic                      lsioc_rx_busy_o,

    output       logic [1:0]                lsioc_tx_err_code_o,
    output       logic [31:0]               lsioc_tx_data_o,
    output       logic                      lsioc_tx_vld_o,
    input   wire logic                      lsioc_tx_busy_i,

    output  wire logic                      sck,
    output  wire logic                      mosi,
    input   wire logic                      miso,
    output  wire logic                      cs_n
);
    wire [34:0] working_data;
    wire working_vld;
    wire phy_busy;
    wire busy = lsioc_tx_busy_i|phy_busy;
    skdbf #(.DW(35)) lsi_skidbuffer (lsioc_clk_i, lsioc_rst_i, busy, working_data, working_vld, lsioc_rx_busy_o, {lsioc_rx_data_i, lsioc_rx_opc_i}, lsioc_rx_vld_i);
    wire [31:0] working_lsi_data = working_data[34:3];
    wire [2:0] working_lsi_opc = working_data[2:0];

    wire [7:0] data;
    wire data_vld;
    spi_flash_phy spi0 (lsioc_clk_i, working_lsi_data[23:0], working_vld&(lsioc_rx_opc_i==3'b000), phy_busy, data, data_vld, sck, mosi, miso, cs_n);

    always_ff @(posedge lsioc_clk_i) begin
        if (!busy&working_vld&data_vld) begin
            lsioc_tx_data_o <= {24'h000000, data};
            lsioc_tx_err_code_o <= {1'b0, working_lsi_opc!=3'b000};
            lsioc_tx_vld_o <= 1'b1;
        end else if (!busy&!working_vld) begin
            lsioc_tx_vld_o <= 1'b0;
        end
    end

endmodule


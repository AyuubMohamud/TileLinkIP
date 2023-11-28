module spiphy (
    input   wire logic                  spiphy_clock_i,
    
    input   wire logic                  spiphy_tx_i,
    input   wire logic [5:0]            spiphy_tx_sz_i,
    input   wire logic [5:0]            spiphy_rx_sz_i,
    input   wire logic                  spiphy_cpha_i,
    input   wire logic                  spiphy_cpol_i,
    input   wire logic                  spiphy_rx_en_i,
    input   wire logic [11:0]           spiphy_clkdiv_i,
    input   wire logic [31:0]           spiphy_tx_data_i,

    output  wire logic                  spiphy_busy_o,
    output       logic                  spiphy_done_o,
    output       logic [31:0]           spiphy_rx_data_o,

    output       logic                  sck,
    output       logic                  cs_n,
    output       logic                  mosi,
    input   wire logic                  miso
);
    reg [11:0] clkdiv_counter;
    wire pos_fst_clk, sampling, shifting;
    assign pos_fst_clk = clkdiv_counter < {1'b0, spiphy_clkdiv_i[11:1]};
    wire clk = spiphy_cpol_i ? pos_fst_clk : ~pos_fst_clk;
    assign sampling  = spiphy_cpha_i^spiphy_cpol_i ? !sck&clk : sck&!clk;
    assign shifting = spiphy_cpha_i^spiphy_cpol_i ? sck&!clk:!sck&clk;
    wire write_idle;
    always_ff @(posedge spiphy_clock_i) begin
        if (spiphy_tx_i&!spiphy_busy_o) begin
            sck <= spiphy_cpol_i;
        end else if (spiphy_busy_o) begin
            if (clkdiv_counter==(spiphy_clkdiv_i-1)) begin
                clkdiv_counter <= 0;
            end else begin
                clkdiv_counter <= clkdiv_counter + 1'b1;
            end
            sck <= write_idle ? spiphy_cpol_i : clk;
        end
    end

    reg [1:0] spi_phy_state;
    localparam SPI_IDLE = 0;
    localparam SPI_TX = 1;
    localparam SPI_RX = 2;
    initial spi_phy_state = SPI_IDLE;
    reg [5:0] bitcount;
    assign spiphy_busy_o = spi_phy_state != SPI_IDLE;
    assign write_idle = (!spiphy_rx_en_i&&spi_phy_state==SPI_TX&&((shifting&bitcount==(spiphy_tx_sz_i)&&!spiphy_cpha_i)||(sampling&&spiphy_cpha_i&&(bitcount==(spiphy_tx_sz_i))))) ||
    (spiphy_rx_en_i&&spi_phy_state==SPI_RX&&((shifting&bitcount==(spiphy_tx_sz_i)&&!spiphy_cpha_i)||(sampling&&spiphy_cpha_i&&bitcount==(spiphy_tx_sz_i))));
    always_ff @(posedge spiphy_clock_i) begin
        case (spi_phy_state)
            SPI_IDLE: begin
                if (spiphy_tx_i) begin
                    spi_phy_state <= SPI_TX;
                    spiphy_rx_data_o <= spiphy_tx_data_i;
                end
                cs_n <= 1;
                spiphy_done_o <= 0;
            end
            SPI_TX: begin
                if (shifting) begin 
                    if (bitcount==(spiphy_tx_sz_i)&&!spiphy_cpha_i) begin
                        bitcount <= 0;
                        cs_n <= !spiphy_rx_en_i;
                        spi_phy_state <= spiphy_rx_en_i ? SPI_RX : SPI_IDLE;
                        spiphy_done_o <= !spiphy_rx_en_i;
                    end else begin
                        bitcount <= bitcount + 1'b1;
                        {mosi, spiphy_rx_data_o} <= {spiphy_rx_data_o, 1'b0};
                    end
                end else if (sampling&&spiphy_cpha_i) begin
                    if (bitcount==(spiphy_tx_sz_i)) begin
                        bitcount <= 0;
                        cs_n <= !spiphy_rx_en_i;
                        spi_phy_state <= spiphy_rx_en_i ? SPI_RX : SPI_IDLE;
                        spiphy_done_o <= !spiphy_rx_en_i;
                    end
                end
            end
            SPI_RX: begin
                if (sampling) begin
                    if (bitcount==(spiphy_rx_sz_i)&&spiphy_cpha_i) begin
                        bitcount <= 0;
                        cs_n <= 1;
                        spi_phy_state <= SPI_IDLE;
                        spiphy_done_o <= 1;
                    end else begin
                        bitcount <= bitcount + 1'b1;
                        spiphy_rx_data_o <= {spiphy_rx_data_o[30:0], miso};
                    end
                end else if (shifting&&(bitcount==(spiphy_rx_sz_i))&&!spiphy_cpha_i) begin
                    bitcount <= 0;
                    cs_n <= 1;
                    spi_phy_state <= SPI_IDLE;
                    spiphy_done_o <= 1;
                end
            end
            default: begin
                
            end
        endcase
    end
endmodule

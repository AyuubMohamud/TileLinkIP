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

    input   wire logic [MAXID-1:0]          miso,
    output       logic                      mosi,
    output       logic                      sck,
    output       logic [MAXID-1:0]          cs_n
);
    reg [9:0] clk_counter;
    initial clk_counter = 0;
    reg active;
    wire wr_idle;
    initial active = 1'b0;
    wire pos_fst_clk = clk_counter < {1'b0, clk_counter[9:1]};
    wire clk = cpol ? pos_fst_clk : ~pos_fst_clk;
    initial begin
        for (integer i = 0; i < MAXID; i++) begin
            cs_n[i] = 1'b1;
        end
    end
    always_ff @(posedge spi_clock_i) begin
        if (spi_tx_i&!spi_busy_o) begin
            sck <= cpol; // set clock idle
        end else if (active) begin
            sck <= wr_idle ? cpol : clk;
            if (clk_counter==(spi_clkdiv_i-1)) begin
                clk_counter <= clk_counter + 1'b1;
            end else begin
                clk_counter <= 0;
            end
        end
    end

    reg [2:0] spi_phy_state;
    localparam SPI_IDLE = 3'b000;
    localparam SPI_CS_LOW = 3'b001;
    localparam SPI_TX = 3'b010;
    localparam SPI_RX = 3'b011;
    localparam SPI_CS_HIGH = 3'b100;
    initial spi_phy_state = SPI_IDLE;
    reg [4:0] bit_count;
    initial bit_count = 0;
    wire sample, write;
    assign sample = cpol^cpha ? !sck&clk : sck&!clk; 
    assign write = cpol^cpha ? sck&!clk : !sck&clk;
    assign wr_idle = (cpha&sample&(bit_count==spi_rx_sz_i)&(spi_phy_state==SPI_RX)) | (!cpha&sample&(spi_phy_state==SPI_CS_HIGH))|(cpha&sample&(bit_count==0)&!spi_rx_en_i&(spi_phy_state==SPI_TX));
    assign spi_busy_o = !(spi_phy_state==SPI_IDLE);
    always_ff @(posedge spi_clock_i) begin
        case (spi_phy_state)
            SPI_IDLE: begin
                if (spi_tx_i) begin
                    spi_phy_state <= SPI_CS_LOW;
                    bit_count <= spi_tx_sz_i;
                end
                spi_done_o <= 1'b0;
            end
            SPI_CS_LOW: begin
                if (!cpha) begin
                    mosi <= spi_tx_data_i[bit_count];
                    bit_count <= bit_count - 1'b1;
                end
                cs_n[spi_csid_i] <= 1'b0;
                active <= 1'b1;
                spi_phy_state <= SPI_TX;
            end
            SPI_TX: begin
                if (write) begin
                    if (bit_count!=0) begin
                        bit_count <= bit_count - 1'b1;
                    end
                    mosi <= spi_tx_data_i[bit_count];
                end else if (sample) begin
                    if (bit_count==0) begin
                        spi_phy_state <= spi_rx_en_i ? SPI_RX : SPI_CS_HIGH;
                        if (cpha) begin
                            cs_n[spi_csid_i] <= 1'b1;
                        end
                    end
                end
            end
            SPI_RX: begin
                if (sample) begin
                    if (bit_count==spi_rx_sz_i) begin
                        bit_count <= 0;
                        if (cpha) begin
                            cs_n[spi_csid_i] <= 1'b1;
                        end
                    end else begin
                        bit_count <= bit_count + 1'b1;
                    end
                    spi_rx_o <= {spi_rx_o[30:0], miso[spi_csid_i]};
                end
            end
            SPI_CS_HIGH: begin
                if (sample) begin
                    cs_n[spi_csid_i] <= 1'b1;
                end
                spi_done_o <= 1'b1;
            end
            default: begin
                
            end
        endcase
    end
endmodule

module spiphy #(parameter CS = 2) (
    input   wire logic                          spi_clock_i,
    input   wire logic                          spi_reset_i,

    input   wire logic [2:0]                    clk_div_i,
    input   wire logic [31:0]                   spi_data_i,
    input   wire logic                          spi_data_vld_i,
    input   wire logic [$clog2(CS)-1:0]         spi_cs_id_i,
    input   wire logic [1:0]                    spi_rx_bytes_i,
    input   wire logic [1:0]                    spi_tx_bytes_i,
    input   wire logic [1:0]                    spi_cl_cfg_i,

    output  wire logic                          spi_busy_o,
    output  wire logic                          spi_data_vld_o,
    output  wire logic [31:0]                   spi_data_o,

    output       logic                          sck,
    output       logic                          mosi,
    input   wire logic [CS-1:0]                 miso,
    output       logic [CS-1:0]                 cs_n                          
);
    reg [15:0] clk_div;
    reg [15:0] ref_clk;
    reg [31:0] spi_data;
    reg [$clog2(CS)-1:0] cs;
    reg [1:0] rx;
    reg [1:0] tx;
    reg [1:0] cpol_cpha;
    reg begin_tx;
    wire clk = clk_div<{1'b0,ref_clk[15:1]};
    wire sample;
    wire shift;
    always_ff @(posedge spi_clock_i) begin
        if (!spi_busy_o&spi_data_vld_i) begin
            clk_div <= 0;
            sck <= spi_cl_cfg_i[1];
        end
        else if (begin_tx) begin
            sck <= cpol_cpha[1] ? ~clk : clk;
            if (clk_div==ref_clk) begin
                clk_div <= 0;
            end else begin
                clk_div <= clk_div + 1'b1;
            end
        end
    end
    logic [15:0] clk_div_l;
    always_comb begin
        case (clk_div_i)
            3'd0: clk_div_l = 0;
            3'd1: clk_div_l = 2;
            3'd2: clk_div_l = 4;
            3'd3: clk_div_l = 8;
            3'd4: clk_div_l = 16;
            3'd5: clk_div_l = 32;
            3'd6: clk_div_l = 64;
            3'd7: clk_div_l = 128;
        endcase
    end
    always_ff @(posedge spi_clock_i) begin
        if (!spi_busy_o&spi_data_vld_i) begin
            start <= 1'b1;
        end
    end
endmodule

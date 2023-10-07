// Copyright (C) Ayuub Mohamud, 2023
// Licensed under CERN-OHL-P version 2
module spi_flash_phy (
    input   wire logic                      lsioc_clk_i,
    input   wire logic [23:0]               spi_rd_addr_i,
    input   wire logic                      rd_i,
    output  wire logic                      busy_o,
    output       logic [7:0]                data_o,
    output       logic                      data_vld_o,
    output       logic                      sck,
    output       logic                      mosi,
    input   wire logic                      miso,
    output       logic                      cs_n
);
    reg in_progress;
    reg [23:0] address;
    assign busy_o = in_progress;
    initial cs_n = 1'b1;
    initial sck = 1'b1;
    
    wire [7:0] read = 8'h03;
    wire [31:0] command = {read, address};    
    reg [1:0] SPI_STATE_MACHINE;
    localparam IDLE = 2'b00;
    localparam CMD = 2'b01;
    localparam RESP = 2'b10;
    localparam OUT = 2'b11;
    reg [4:0] counter;
    reg [7:0] data;

    always_ff @(posedge lsioc_clk_i) begin
        if (rd_i&!busy_o) begin
            in_progress <= 1'b1;
            address <= spi_rd_addr_i;
        end else if (SPI_STATE_MACHINE==OUT) begin
            in_progress <= 1'b0;
        end
    end


    always_ff @(posedge lsioc_clk_i) begin
        case (SPI_STATE_MACHINE)
            IDLE: begin
                if (rd_i&!busy_o) begin
                    SPI_STATE_MACHINE <= CMD;
                    cs_n <= 1'b0;
                    counter <= 5'b11111;
                end else begin
                    cs_n <= 1'b1;
                end
                sck <= 1'b1;
                data_vld_o <= 1'b0;
            end
            CMD: begin
                sck <= ~sck;
                if (!sck) begin
                    mosi <= command[counter];
                    counter <= counter - 1'b1;
                end
                if (counter==5'd0) begin
                    SPI_STATE_MACHINE<=RESP;
                    counter <= 5'b00111;
                end
            end
            RESP: begin
                sck <= ~sck;
                if (sck) begin
                    data <= {data[7:1], miso};
                    if (counter==5'd0) begin
                        cs_n <= 1'b1;
                        SPI_STATE_MACHINE <= OUT;
                    end else begin
                        counter <= counter - 1'b1;
                    end
                end
            end
            OUT: begin
                sck <= ~sck;
                data_vld_o <= 1'b1;
                data_o <= data;
            end
        endcase
    end
endmodule

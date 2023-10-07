// Copyright (C) Ayuub Mohamud, 2023
// Licensed under CERN-OHL-P version 2
module polaris_gpio (
    input   wire logic                      lsioc_clk_i,
    input   wire logic                      lsioc_rst_i,


    input   wire logic                      lsioc_rx_vld_i,
    input   wire logic [3:0]                lsioc_rx_sbsp_i,
    input   wire logic [31:0]               lsioc_rx_data_i,
    input   wire logic [2:0]                lsioc_rx_opc_i,
    output  wire logic                      lsioc_rx_busy_o,

    output       logic [1:0]                lsioc_tx_err_code_o,
    output       logic [31:0]               lsioc_tx_data_o,
    output       logic                      lsioc_tx_vld_o,
    input   wire logic                      lsioc_tx_busy_i,

    output  wire logic [2:0]                rgb_led0,
    output  wire logic [2:0]                rgb_led1,
    output  wire logic [2:0]                rgb_led2,
    output  wire logic [2:0]                rgb_led3,
    output  wire logic [3:0]                normal_led,

    input   wire logic                      button0,
    input   wire logic                      button1,
    input   wire logic                      button2,
    input   wire logic                      button3
);
    wire [38:0] working_data;
    wire working_vld;
    wire busy = lsioc_tx_busy_i;
    skdbf #(.DW(39)) lsi_skidbuffer (lsioc_clk_i, lsioc_rst_i, busy, working_data, working_vld, lsioc_rx_busy_o, {lsioc_rx_sbsp_i, lsioc_rx_data_i, lsioc_rx_opc_i}, lsioc_rx_vld_i);
    wire [3:0] working_lsi_sbsp = working_data[38:35];
    wire [31:0] working_lsi_data = working_data[34:3];
    wire [2:0] working_lsi_opc = working_data[2:0];
    reg [2:0] rgb0;
    reg [2:0] rgb1;
    reg [2:0] rgb2;
    reg [2:0] rgb3;
    reg [3:0] led;
    initial begin
        rgb0 = 3'b000;
        rgb1 = 3'b000;
        rgb2 = 3'b000;
        rgb3 = 3'b000;
        led = 4'b0000;
    end

    logic [3:0] read_machine;
    localparam LSIOC_WRITE = 3'b001;
    localparam LSIOC_AMOSWAP = 3'b110;
    localparam LSIOC_AMOXOR = 3'b111;
    localparam LSIOC_AMOAND = 3'b100;
    localparam LSIOC_AMOORR = 3'b101;

    localparam LSIOC_RESPONSE_OK = 2'b00;

    always_comb begin
        case (working_lsi_sbsp)
            4'h0: begin
                read_machine = {1'b0, rgb0};
            end
            4'h1: begin
                read_machine = {1'b0, rgb1};
            end
            4'h2: begin
                read_machine = {1'b0, rgb2};
            end
            4'h3: begin
                read_machine = {1'b0, rgb3};
            end
            4'h4: begin
                read_machine = {led};
            end
            4'h5: begin
                read_machine = {3'b000, button0};
            end
            4'h6: begin
                read_machine = {3'b000, button1};
            end
            4'h7: begin
                read_machine = {3'b000, button2};
            end
            4'h8: begin
                read_machine = {3'b000, button3};
            end
            default: begin
                read_machine = 4'b0000;
            end
        endcase
    end

    logic [3:0] write_value_machine;
    always_comb begin
        case (working_lsi_opc)
            LSIOC_AMOAND:   write_value_machine = read_machine&working_lsi_data[3:0];
            LSIOC_AMOORR:   write_value_machine = read_machine|working_lsi_data[3:0];
            LSIOC_AMOSWAP:  write_value_machine = working_lsi_data[3:0];
            LSIOC_AMOXOR:   write_value_machine = read_machine^working_lsi_data[3:0];
            LSIOC_WRITE:    write_value_machine = working_lsi_data[3:0];
            default: begin
                write_value_machine = 4'h0;
            end
        endcase
    end

    always_ff @(posedge lsioc_clk_i) begin
        if (working_vld&!busy&(working_lsi_opc[2]|working_lsi_opc[0])) begin
            case (working_lsi_sbsp)
                4'h0: rgb0 <=   write_value_machine[2:0];
                4'h1: rgb1 <=   write_value_machine[2:0];
                4'h2: rgb2 <=   write_value_machine[2:0];
                4'h3: rgb3 <=   write_value_machine[2:0];
                4'h4: led <=    write_value_machine;
            endcase
        end
    end

    always_ff @(posedge lsioc_clk_i) begin
        if (working_vld&!busy) begin
            lsioc_tx_data_o <= {28'h0000000, read_machine};
            lsioc_tx_err_code_o <= LSIOC_RESPONSE_OK;
            lsioc_tx_vld_o <= 1'b1;
        end
        else if (!working_vld&!busy) begin
            lsioc_tx_vld_o <= 1'b0;
        end
    end
    assign rgb_led0 = rgb0;
    assign rgb_led1 = rgb1;
    assign rgb_led2 = rgb2;
    assign rgb_led3 = rgb3;
    assign normal_led = led;
endmodule

`default_nettype none
// Copyright (C) Ayuub Mohamud, 2023
// Licensed under CERN-OHL-P version 2
module polaris_uart (
    input   wire logic                      lsioc_clk_i,
    input   wire logic                      lsioc_rst_i,


    input   wire logic                      lsioc_rx_vld_i,
    input   wire logic [1:0]                lsioc_rx_sbsp_i,
    input   wire logic [31:0]               lsioc_rx_data_i,
    input   wire logic [2:0]                lsioc_rx_opc_i,
    input   wire logic [1:0]                lsioc_rx_bmsk_i,
    output  wire logic                      lsioc_rx_busy_o,

    output       logic [1:0]                lsioc_tx_err_code_o,
    output       logic [31:0]               lsioc_tx_data_o,
    output       logic                      lsioc_tx_vld_o,
    input   wire logic                      lsioc_tx_busy_i,


    output  wire logic                      uart_tx_o,
    input   wire logic                      uart_rx_i,

    output  wire logic                      interrupt_o
);
    // Polaris UART controller CSRs
    // 32-bit SBSP 0: CSR: Control and Status
    /*
        Bit 0: Enable UART Transmission R/W
        Bit 1: Enable UART Recieval R/W
        Bit 2: Enable UART Recieval interrupts R/W
        Bit 3: TX Fifo clear R/W
        Bit 4: RX fifo clear R/W
        Bit 16-5: Clock to baud rate.        
        Bit 17: TX Fifo empty R
        Bit 18: RX fifo empty R
        Bit 19: TX Fifo full R
        Bit 20: RX fifo full R
    */
    // 32-bit SBSP 1: CSR: TX Fifo Read W, AMOs here read AMOERRs
    // 32-bit SBSP 2: CSR: RX Fifo write R, AMOs here read AMOERRs

    wire [38:0] working_data;
    wire working_vld;

    wire [31:0] working_lsioc_rx_data;
    wire [1:0] working_lsioc_rx_sbsp;
    wire [2:0] working_lsioc_rx_opc;
    wire [1:0] working_lsioc_rx_bmsk;

    assign working_lsioc_rx_sbsp = working_data[38:37];
    assign working_lsioc_rx_data = working_data[36:5];
    assign working_lsioc_rx_opc = working_data[4:2];
    assign working_lsioc_rx_bmsk = working_data[1:0];

    skdbf #(.DW(39)) skidbuffer (lsioc_clk_i, lsioc_rst_i, lsioc_tx_busy_i, working_data, working_vld, lsioc_rx_busy_o, {lsioc_rx_sbsp_i,
    lsioc_rx_data_i,
    lsioc_rx_opc_i,
    lsioc_rx_bmsk_i}, lsioc_rx_vld_i);


    reg [16:0] polaris_uart_csr;
    logic [31:0] val_read;
    logic rx_read;
    logic tx_write_vld;
    wire [7:0] rx_top;
    initial polaris_uart_csr = 17'h00000;
    localparam LSIOC_READ = 3'b000;
    localparam LSIOC_WRITE = 3'b001;
    localparam LSIOC_AMOSWAP = 3'b110;
    localparam LSIOC_AMOXOR = 3'b111;
    localparam LSIOC_AMOAND = 3'b100;
    localparam LSIOC_AMOORR = 3'b101;

    localparam LSIOC_RESPONSE_OK = 2'b00;
    localparam LSIOC_RESPONSE_AMOERR = 2'b01;
    localparam LSIOC_RESPONSE_ERR = 2'b10;
    wire rx_full, tx_full, rx_empty, tx_empty;

    polaris_uart_ip uart0 (lsioc_clk_i, lsioc_rst_i, 
    polaris_uart_csr[16:5], polaris_uart_csr[0], polaris_uart_csr[1], tx_write_vld, working_lsioc_rx_data[7:0], rx_read, rx_top, tx_full, tx_empty, rx_full, rx_empty, uart_rx_i, uart_tx_o);

    always_ff @(posedge lsioc_clk_i) begin
        if ((!working_vld&!lsioc_tx_busy_i)|lsioc_rst_i) begin
            lsioc_tx_vld_o <= 1'b0;
        end else if (working_vld&!lsioc_tx_busy_i) begin
            lsioc_tx_vld_o <= 1'b1;
        end
    end

    // Read machine
    always_comb begin
        case (working_lsioc_rx_sbsp)
            2'b00: begin
                val_read = {11'h0000, rx_full, tx_full, rx_empty, tx_empty, polaris_uart_csr};
                rx_read = 1'b0;
            end
            2'b10: begin
                val_read = {24'h000000, rx_top};
                rx_read = working_vld&!lsioc_tx_busy_i&!lsioc_rst_i&(working_lsioc_rx_opc==LSIOC_READ);
            end
            default: begin
                val_read = 32'h0000;
                rx_read = 1'b0;
            end
        endcase
    end
    // AMO machine

    logic [31:0] amo_val_written;

    always_comb begin
        case (working_lsioc_rx_opc)
            LSIOC_AMOSWAP: begin
                amo_val_written = working_lsioc_rx_data;
            end 
            LSIOC_AMOAND: begin
                amo_val_written = working_lsioc_rx_data&val_read;
            end
            LSIOC_AMOORR: begin
                amo_val_written = working_lsioc_rx_data|val_read;
            end
            LSIOC_AMOXOR: begin
                amo_val_written = working_lsioc_rx_data^val_read;
            end
            default: begin
                amo_val_written = working_lsioc_rx_data;
            end
        endcase
    end
    logic [1:0] error;
    wire atomic = working_lsioc_rx_opc[2];
    

    // Error machine    
    assign interrupt_o = polaris_uart_csr[1]&polaris_uart_csr[2]&!rx_empty;
    always_comb begin
        case (working_lsioc_rx_sbsp)
            2'b00: begin
                error = LSIOC_RESPONSE_OK;
                tx_write_vld = 1'b0;
            end 
            2'b01: begin
                error = atomic ? LSIOC_RESPONSE_AMOERR : working_lsioc_rx_opc==LSIOC_READ ? LSIOC_RESPONSE_ERR : LSIOC_RESPONSE_OK;
                tx_write_vld = (working_lsioc_rx_opc==LSIOC_WRITE) & !lsioc_tx_busy_i & working_vld&!lsioc_rst_i;
            end
            2'b10: begin
                error = atomic ? LSIOC_RESPONSE_AMOERR : working_lsioc_rx_opc==LSIOC_WRITE ? LSIOC_RESPONSE_ERR : LSIOC_RESPONSE_OK;
                tx_write_vld = 1'b0;
            end
            default: begin
                error = LSIOC_RESPONSE_ERR;
                tx_write_vld = 1'b0;
            end
        endcase
    end

    always_ff @(posedge lsioc_clk_i) begin
        if (lsioc_rst_i) begin
            lsioc_tx_data_o <= 32'h00000000;
        end else if (working_vld&!lsioc_tx_busy_i) begin
            lsioc_tx_data_o <= val_read;
        end
    end

    always_ff @(posedge lsioc_clk_i) begin
        if (lsioc_rst_i) begin
            lsioc_tx_err_code_o <= LSIOC_RESPONSE_OK;
        end else if (working_vld&!lsioc_tx_busy_i) begin
            lsioc_tx_err_code_o <= error;
        end
    end
    always_ff @(posedge lsioc_clk_i) begin
        if (lsioc_rst_i) begin
            polaris_uart_csr <= 17'h00000;
        end
        else if (working_vld&!lsioc_tx_busy_i) begin
            if ((working_lsioc_rx_sbsp==2'b00) & (atomic|working_lsioc_rx_opc[0])) begin
                polaris_uart_csr <= amo_val_written[16:0];
            end
        end
    end
endmodule

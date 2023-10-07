//! A 2x7 crossbar
// Copyright (C) Ayuub Mohamud, 2023
// Licensed under CERN-OHL-P version 2

module lsi_xbr (
    input   wire logic                      lsioc_clk_i,
    input   wire logic                      lsioc_rst_i,

    input   wire logic                      master0_lsioc_rx_vld_i,
    input   wire logic [27:0]               master0_lsioc_rx_sbsp_i,
    input   wire logic [31:0]               master0_lsioc_rx_data_i,
    input   wire logic [2:0]                master0_lsioc_rx_opc_i,
    output  wire logic                      master0_lsioc_rx_busy_o,
    output       logic [1:0]                master0_lsioc_tx_err_code_o,
    output       logic [31:0]               master0_lsioc_tx_data_o,
    output       logic                      master0_lsioc_tx_vld_o,
    input   wire logic                      master0_lsioc_tx_busy_i,

    input   wire logic                      master1_lsioc_rx_vld_i,
    input   wire logic [27:0]               master1_lsioc_rx_sbsp_i,
    input   wire logic [31:0]               master1_lsioc_rx_data_i,
    input   wire logic [2:0]                master1_lsioc_rx_opc_i,
    output  wire logic                      master1_lsioc_rx_busy_o,
    output       logic [1:0]                master1_lsioc_tx_err_code_o,
    output       logic [31:0]               master1_lsioc_tx_data_o,
    output       logic                      master1_lsioc_tx_vld_o,
    input   wire logic                      master1_lsioc_tx_busy_i,

    output       logic                      uart_lsioc_rx_vld_o,
    output       logic [1:0]                uart_lsioc_rx_sbsp_o,
    output       logic [31:0]               uart_lsioc_rx_data_o,
    output       logic [2:0]                uart_lsioc_rx_opc_o,
    input   wire logic                      uart_lsioc_rx_busy_i,
    input   wire logic [1:0]                uart_lsioc_tx_err_code_i,
    input   wire logic [31:0]               uart_lsioc_tx_data_i,
    input   wire logic                      uart_lsioc_tx_vld_i,
    output       logic                      uart_lsioc_tx_busy_o,

    output       logic                      spi_flash_lsioc_rx_vld_o,
    output       logic [31:0]               spi_flash_lsioc_rx_data_o,
    output       logic [2:0]                spi_flash_lsioc_rx_opc_o,
    input   wire logic                      spi_flash_lsioc_rx_busy_i,
    input   wire logic [1:0]                spi_flash_lsioc_tx_err_code_i,
    input   wire logic [31:0]               spi_flash_lsioc_tx_data_i,
    input   wire logic                      spi_flash_lsioc_tx_vld_i,
    output       logic                      spi_flash_lsioc_tx_busy_o,

    output       logic                      plic_rx_vld_o,
    output       logic [21:0]               plic_rx_sbsp_o,
    output       logic [31:0]               plic_rx_data_o,
    output       logic [2:0]                plic_rx_opc_o,
    input   wire logic                      plic_rx_busy_i,
    input   wire logic [1:0]                plic_tx_err_code_i,
    input   wire logic [31:0]               plic_tx_data_i,
    input   wire logic                      plic_tx_vld_i,
    output       logic                      plic_tx_busy_o,

    output       logic                      gpio_rx_vld_o,
    output       logic [3:0]                gpio_rx_sbsp_o,
    output       logic [31:0]               gpio_rx_data_o,
    output       logic [2:0]                gpio_rx_opc_o,
    input   wire logic                      gpio_rx_busy_i,
    input   wire logic [1:0]                gpio_tx_err_code_i,
    input   wire logic [31:0]               gpio_tx_data_i,
    input   wire logic                      gpio_tx_vld_i,
    output       logic                      gpio_tx_busy_o,

    output       logic                      clint_rx_vld_o,
    output       logic [15:0]               clint_rx_sbsp_o,
    output       logic [31:0]               clint_rx_data_o,
    output       logic [2:0]                clint_rx_opc_o,
    input   wire logic                      clint_rx_busy_i,
    input   wire logic [1:0]                clint_tx_err_code_i,
    input   wire logic [31:0]               clint_tx_data_i,
    input   wire logic                      clint_tx_vld_i,
    output  wire logic                      clint_tx_busy_o,

    output       logic                      eth_rx_vld_o,
    output       logic [13:0]               eth_rx_sbsp_o,
    output       logic [31:0]               eth_rx_data_o,
    output       logic [2:0]                eth_rx_opc_o,
    input   wire logic                      eth_rx_busy_i,
    input   wire logic [1:0]                eth_tx_err_code_i,
    input   wire logic [31:0]               eth_tx_data_i,
    input   wire logic                      eth_tx_vld_i,
    output       logic                      eth_tx_busy_o,

    output       logic                      sdcard_rx_vld_o,
    output       logic [12:0]               sdcard_rx_sbsp_o,
    output       logic [31:0]               sdcard_rx_data_o,
    output       logic [2:0]                sdcard_rx_opc_o,
    input   wire logic                      sdcard_rx_busy_i,
    input   wire logic [1:0]                sdcard_tx_err_code_i,
    input   wire logic [31:0]               sdcard_tx_data_i,
    input   wire logic                      sdcard_tx_vld_i,
    output       logic                      sdcard_tx_busy_o
);
    reg [6:0] lock;
    reg [6:0] lock_owner;
    reg [6:0] balance;
    wire [6:0] cycle_lock [0:1];
    reg master0_complete;
    reg master1_complete;

    reg pending_master0;
    reg pending_master1;

    reg [27:0] master0_sbsp_access;
    reg [2:0] master0_opcode;
    reg [31:0] master0_data;
    reg [27:0] master1_sbsp_access;
    reg [2:0] master1_opcode;
    reg [31:0] master1_data;
    //! Masters work with the understanding that at most one outstanding transaction may take place between them and a slave
    
    // Memory Map
    /*
        0x00000000 - 0x1FFFFFFF is system memory
        
        0x20000000 - 0x2000000F is Polaris Uart
        
        0x20100000 - 0x20100003 is Polaris SPI Flash
        
        0x20200000 - 0x2020000F is Polaris GPIO
        
        0x20300000 - 0x2030FFFF is Polaris CLINT

        0x21000000 - 0x213FFFFF is Polaris PLIC
        
        0x22000000 - 0x22003FFF is LiteX Ethernet
        
        0x23000000 - 0x23001FFF is LiteX SdCard
    */
    wire master0_busy = pending_master0;
    wire [62:0] master0_working_data;
    wire master0_working_vld;
    wire master1_busy = pending_master1;
    wire [62:0] master1_working_data;
    wire master1_working_vld;

    skdbf #(.DW(63)) master0_lsi (lsioc_clk_i, lsioc_rst_i, master0_busy, master0_working_data, master0_working_vld, master0_lsioc_rx_busy_o, {master0_lsioc_rx_sbsp_i, master0_lsioc_rx_data_i, master0_lsioc_rx_opc_i}, master0_lsioc_rx_vld_i);
    skdbf #(.DW(63)) master1_lsi (lsioc_clk_i, lsioc_rst_i, master1_busy, master1_working_data, master1_working_vld, master1_lsioc_rx_busy_o, {master1_lsioc_rx_sbsp_i, master1_lsioc_rx_data_i, master1_lsioc_rx_opc_i}, master1_lsioc_rx_vld_i);

    // Incoming request 
    always_ff @(posedge lsioc_clk_i) begin
        if (!pending_master0&!master0_busy&master0_working_vld) begin
            pending_master0 <= 1'b1;
            master0_sbsp_access <= master0_working_data[62:35];
            master0_data <= master0_working_data[34:3];
            master0_opcode <= master0_working_data[2:0];
        end 
        else if (master0_complete) begin
            pending_master0 <= 1'b0;
        end
    end
    always_ff @(posedge lsioc_clk_i) begin
        if (!pending_master1&!master1_busy&master1_working_vld) begin
            pending_master1 <= 1'b1;
            master1_sbsp_access <= master1_working_data[62:35];
            master1_data <= master1_working_data[34:3];
            master1_opcode <= master1_working_data[2:0];
        end 
        else if (master1_complete) begin
            pending_master1 <= 1'b0;
        end
    end
    

    //! Master Arbitration
    wire slave_sel_conflict;
    wire [6:0] slave_sel_master0;
    wire [6:0] slave_sel_master1;
    assign slave_sel_master0[0] = master0_lsioc_rx_sbsp_i[27:4] == 24'h200000; //! UART
    assign slave_sel_master0[1] = master0_lsioc_rx_sbsp_i[27:2] == 26'h2010000; //! SPI Flash
    assign slave_sel_master0[2] = master0_lsioc_rx_sbsp_i[27:4] == 24'h202000; //! GPIO
    assign slave_sel_master0[3] = master0_lsioc_rx_sbsp_i[27:14] == 14'h2030; //! CLINT
    assign slave_sel_master0[4] = master0_lsioc_rx_sbsp_i[27:18] == 10'h210; //! PLIC
    assign slave_sel_master0[5] = master0_lsioc_rx_sbsp_i[27:14] == 14'h2200; //! ETH
    assign slave_sel_master0[6] = master0_lsioc_rx_sbsp_i[27:15] == 13'h2300; //! SDCard

    assign slave_sel_master1[0] = master1_lsioc_rx_sbsp_i[27:4] == 24'h200000; //! UART
    assign slave_sel_master1[1] = master1_lsioc_rx_sbsp_i[27:2] == 26'h2010000; //! SPI Flash
    assign slave_sel_master1[2] = master1_lsioc_rx_sbsp_i[27:4] == 24'h202000; //! GPIO
    assign slave_sel_master1[3] = master1_lsioc_rx_sbsp_i[27:14] == 14'h2030; //! CLINT
    assign slave_sel_master1[4] = master1_lsioc_rx_sbsp_i[27:18] == 10'h210; //! PLIC
    assign slave_sel_master1[5] = master1_lsioc_rx_sbsp_i[27:14] == 14'h2200; //! ETH
    assign slave_sel_master1[6] = master1_lsioc_rx_sbsp_i[27:15] == 13'h2300; //! SDCard

    assign slave_sel_conflict = |(slave_sel_master0&slave_sel_master1);

    logic [2:0] slave_select0;
    logic [2:0] slave_select1;
    always_comb begin
        casez (slave_sel_master0)
            7'bzzzzzz1: begin
                slave_select0 = 3'b000;
            end 
            7'bzzzzz10: begin
                slave_select0 = 3'b001;
            end 
            7'bzzzz100: begin
                slave_select0 = 3'b010;
            end 
            7'bzzz1000: begin
                slave_select0 = 3'b011;
            end
            7'bzz10000: begin
                slave_select0 = 3'b100;
            end
            7'bz100000: begin
                slave_select0 = 3'b101;
            end
            7'b1000000: begin
                slave_select0 = 3'b110;
            end
            default: begin
                slave_select0 = 3'b111;
            end
        endcase
        casez (slave_sel_master1)
            7'bzzzzzz1: begin
                slave_select1 = 3'b000;
            end 
            7'bzzzzz10: begin
                slave_select1 = 3'b001;
            end 
            7'bzzzz100: begin
                slave_select1 = 3'b010;
            end 
            7'bzzz1000: begin
                slave_select1 = 3'b011;
            end
            7'bzz10000: begin
                slave_select1 = 3'b100;
            end
            7'bz100000: begin
                slave_select1 = 3'b101;
            end
            7'b1000000: begin
                slave_select1 = 3'b110;
            end
            default: begin
                slave_select1 = 3'b111;
            end
        endcase
    end
    wire slave_used0 = ~lock[slave_select0];
    wire slave_used1 = ~lock[slave_select1];

    wire master0_stalled = (slave_sel_conflict&pending_master1&pending_master0&~balance[slave_select0])|slave_used0;
    wire master1_stalled = (slave_sel_conflict&pending_master0&pending_master1&balance[slave_select1])|slave_used1;
    reg [27:0] transaction0_sbsp;
    reg transaction0_vld;
    reg [31:0] transaction0_data;
    reg [2:0] transaction0_opcode;
    reg [6:0] slave_select0_r;
    reg origin0;
    reg [27:0] transaction1_sbsp;
    reg transaction1_vld;
    reg [31:0] transaction1_data;
    reg [2:0] transaction1_opcode;
    reg [6:0] slave_select1_r;
    reg origin1;
    always_ff @(posedge lsioc_clk_i) begin
        transaction0_vld <= !(master0_stalled&master1_stalled);
        transaction0_data <= master0_stalled ? master1_data : master0_data;
        transaction0_opcode <= master0_stalled ? master1_opcode : master0_opcode;
        transaction0_sbsp <= master0_stalled ? master1_sbsp_access : master0_sbsp_access;
        slave_select0_r <= slave_sel_master0;
        origin0 <= master0_stalled ? 1'b1 : 1'b0;
    end

    always_ff @(posedge lsioc_clk_i) begin
        transaction1_vld <= !master0_stalled&!master1_stalled;
        transaction1_data <= master1_data;
        transaction1_opcode <= master1_opcode;
        transaction1_sbsp <= master1_sbsp_access;
        slave_select0_r <= slave_sel_master1;
        origin1 <= 1'b1;
    end

    always_ff @(posedge lsioc_clk_i) begin
        if (slave_sel_conflict) begin
            balance[slave_select0] <= ~balance[slave_select0];
        end
        lock[0] <= pending_master0&pending_master1 ? (slave_sel_master0[0]|slave_sel_master1[1]) : pending_master0 ? slave_sel_master0[0] : pending_master1 ? slave_sel_master1[0] : lock[0];
        lock[1] <= pending_master0&pending_master1 ? (slave_sel_master0[1]|slave_sel_master1[1]) : pending_master0 ? slave_sel_master0[1] : pending_master1 ? slave_sel_master1[1] : lock[1];
        lock[2] <= pending_master0&pending_master1 ? (slave_sel_master0[2]|slave_sel_master1[2]) : pending_master0 ? slave_sel_master0[2] : pending_master1 ? slave_sel_master1[2] : lock[2];
        lock[3] <= pending_master0&pending_master1 ? (slave_sel_master0[3]|slave_sel_master1[3]) : pending_master0 ? slave_sel_master0[3] : pending_master1 ? slave_sel_master1[3] : lock[3];
        lock[4] <= pending_master0&pending_master1 ? (slave_sel_master0[4]|slave_sel_master1[4]) : pending_master0 ? slave_sel_master0[4] : pending_master1 ? slave_sel_master1[4] : lock[4];
        lock[5] <= pending_master0&pending_master1 ? (slave_sel_master0[5]|slave_sel_master1[5]) : pending_master0 ? slave_sel_master0[5] : pending_master1 ? slave_sel_master1[5] : lock[5];
        lock[6] <= pending_master0&pending_master1 ? (slave_sel_master0[6]|slave_sel_master1[6]) : pending_master0 ? slave_sel_master0[6] : pending_master1 ? slave_sel_master1[6] : lock[6];
    end
    // Route stage

    always_ff @(posedge lsioc_clk_i) begin
        uart_lsioc_rx_vld_o <= (transaction0_vld&slave_select0_r[0]|transaction1_vld&slave_select1_r[0])&!master0_complete;
        spi_flas <= (transaction0_vld&slave_select0_r[0]|transaction1_vld&slave_select1_r[0])&!master0_complete;
        uart_lsioc_rx_vld_o <= (transaction0_vld&slave_select0_r[0]|transaction1_vld&slave_select1_r[0])&!master0_complete;
        uart_lsioc_rx_vld_o <= (transaction0_vld&slave_select0_r[0]|transaction1_vld&slave_select1_r[0])&!master0_complete;

    end

endmodule

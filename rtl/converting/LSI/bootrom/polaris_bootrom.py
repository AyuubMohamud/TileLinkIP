# Copyright (C) Ayuub Mohamud, 2023. All rights reserved.

import sys
import binascii
import os
import math

default0 = """
// Copyright (C) Ayuub Mohamud, 2023. Licenced under CERN OHL v2
module polaris_bootrom (
    input   wire logic                      lsioc_clk_i,
    input   wire logic                      lsioc_rst_i,


    input   wire logic                      lsioc_rx_vld_i,
    input   wire logic [11:0]               lsioc_rx_sbsp_i,
    input   wire logic [31:0]               lsioc_rx_data_i,
    input   wire logic [2:0]                lsioc_rx_opc_i,
    input   wire logic [1:0]                lsioc_rx_bmsk_i,
    output       logic                      lsioc_rx_busy_o,

    output       logic [1:0]                lsioc_tx_err_code_o,
    output       logic [31:0]               lsioc_tx_data_o,
    output       logic                      lsioc_tx_vld_o,
    input   wire logic                      lsioc_tx_busy_i
);
    reg [31:0] bootrom [0:4095];

    wire [48:0] working_data;
    wire working_vld;

    wire [31:0] working_lsioc_rx_data;
    wire [11:0] working_lsioc_rx_sbsp;
    wire [2:0] working_lsioc_rx_opc;
    wire [1:0] working_lsioc_rx_bmsk;

    assign working_lsioc_rx_sbsp = working_data[48:37];
    assign working_lsioc_rx_data = working_data[36:5];
    assign working_lsioc_rx_opc = working_data[4:2];
    assign working_lsioc_rx_bmsk = working_data[1:0];
    localparam LSIOC_READ = 3'b000;
    localparam LSIOC_WRITE = 3'b001;
    localparam LSIOC_AMOSWAP = 3'b110;
    localparam LSIOC_AMOXOR = 3'b111;
    localparam LSIOC_AMOAND = 3'b100;
    localparam LSIOC_AMOORR = 3'b101;

    localparam LSIOC_RESPONSE_OK = 2'b00;
    localparam LSIOC_RESPONSE_AMOERR = 2'b01;
    localparam LSIOC_RESPONSE_ERR = 2'b10;

    wire busy;
    assign busy = lsioc_tx_busy_i | (working_vld&(working_lsioc_rx_opc[2]));
    reg amo_vld;

    skdbf #(.DW(49)) skidbuffer (lsioc_clk_i, lsioc_rst_i, busy, working_data, working_vld, lsioc_rx_busy_o, {lsioc_rx_sbsp_i,
    lsioc_rx_data_i,
    lsioc_rx_opc_i,
    lsioc_rx_bmsk_i}, lsioc_rx_vld_i);

    // Read machine
    reg [31:0] val_read;
    assign lsioc_tx_data_o = lsioc_rst_i ? 32'h00000000 : val_read;

    always_ff @(posedge lsioc_clk_i) begin
        if (working_vld&!lsioc_tx_busy_i) begin
            val_read <= bootrom[working_lsioc_rx_sbsp];
        end
    end

    // AMO Machine
    logic [31:0] amo_val;
    always_comb begin
        case (working_lsioc_rx_opc)
            LSIOC_AMOSWAP: begin
                amo_val = working_lsioc_rx_data;
            end
            LSIOC_AMOORR: begin
                amo_val = working_lsioc_rx_data|val_read;
            end
            LSIOC_AMOAND: begin
                amo_val = working_lsioc_rx_data&val_read;
            end
            LSIOC_AMOXOR: begin
                amo_val = working_lsioc_rx_data^val_read;
            end
            default: begin
                amo_val = working_lsioc_rx_data;
            end
        endcase
    end

    always_ff @(posedge lsioc_clk_i) begin
        if (working_vld&(working_lsioc_rx_opc==LSIOC_WRITE)&!lsioc_tx_busy_i&!lsioc_rst_i) begin
            bootrom[working_lsioc_rx_sbsp] <= amo_val;
        end
        else if (working_vld&(working_lsioc_rx_opc[2])&!lsioc_tx_busy_i&!lsioc_rst_i) begin
            amo_vld <= 1'b1;
        end
        else if (amo_vld) begin
            bootrom[working_lsioc_rx_sbsp] <= amo_val;
            amo_vld <= 1'b0;
        end
    end

    always_ff @(posedge lsioc_clk_i) begin
        lsioc_tx_err_code_o <= LSIOC_RESPONSE_OK;
    end

    always_ff @(posedge lsioc_clk_i) begin
        if (lsioc_rst_i) begin
            lsioc_tx_vld_o <= 1'b0;
        end
        else if (amo_vld) begin
            lsioc_tx_vld_o <= 1'b1;
        end
        else if (working_vld&!lsioc_tx_busy_i&working_lsioc_rx_opc[2]) begin
            lsioc_tx_vld_o <= 1'b0;
        end
        else if (working_vld&!lsioc_tx_busy_i) begin
            lsioc_tx_vld_o <= 1'b1;
        end
    end

"""
initialStatements = ""

endmodule = "endmodule"

def copyright():
    print("Copyright (C) Ayuub Mohamud, 2023. All rights reserved")

def usage():
    print("USAGE: python3 polaris_bootrom.py name_of_some_object_file.bin")

def sizeCheck(path):
    size = os.path.getsize(path)
    if size < (1024*16):
        print("ERROR: file cannot be larger than 16KB, BOOTROM not Embedded environment")
        return 1
    else:
        print("File Size OK")
        return 0

def hexToSystemVerilog(path):
    try:
        file = open(path, "b+r")
    except OSError:
        print("Unexpected OSError exception, failed to produce file.")

    hexData = binascii.hexlify(file.read())
    for i in math.floor(len(hexData)/4):
        initialStatements.append(f"initial bootrom[{i}][7:0] = 8'h{hexData[i*4]}")
        initialStatements.append(f"initial bootrom[{i}][15:8] = 8'h{hexData[(i*4)+1]}")
        initialStatements.append(f"initial bootrom[{i}][23:16] = 8'h{hexData[(i*4)+2]}")
        initialStatements.append(f"initial bootrom[{i}][31:24] = 8'h{hexData[(i*4)+3]}")

    if len(hexData) % 4 == 0:
        return 0
    else: 
        for i in range(0, len(hexData)%4):
            initialStatements.append(f"initial bootrom[{math.ceil(len(hexData)/4)}+i)][{(i+1)*8}-1:{i*8}] = 8'h{hexData[math.floor(len(hexData/4))*4+i]}")
        return 0
    
def output(path):



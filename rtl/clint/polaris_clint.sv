// Copyright (C) Ayuub Mohamud, 2023
// Licensed under CERN-OHL-W version 2
`include "clint_defines.sv"

module polaris_clint #(parameter HARTNO = 2) (
    input   wire logic                      clint_clk_i,
    input   wire logic                      clint_rst_i,

    input   tluh::tluh_m2s                  tluh_i,
    input   wire logic                      clint_d_ready,
    output  tluh::tluh_s2m                  tluh_o,
    output  wire logic                      clint_a_ready,

    output  wire logic [HARTNO-1:0]         hart_mti,
    output  wire logic [HARTNO-1:0]         hart_msip
);
    wire [61+clint_defines::TL_RS-1:0] working_data;
    wire working_vld;
    wire busy = !clint_d_ready;
    skdbf #(.DW(61+clint_defines::TL_RS)) tl_skidbuffer (clint_clk_i, clint_rst_i, busy, working_data, working_vld, !clint_a_ready, {
        tluh_i.a_opcode, //3
        tluh_i.a_param, //3
        tluh_i.a_size, 
        tluh_i.a_source,
        tluh_i.a_address, //16
        tluh_i.a_mask, //4
        tluh_i.a_data, //32
        tluh_i.a_corrupt //1
    }, tluh_i.a_valid);
    localparam bvsize = 61+clint_defines::TL_RS-1;
    tluh::tluh_a_op working_opcode = tluh::tluh_a_op'(working_data[bvsize:bvsize-2]);
    wire [2:0] working_param = working_data[bvsize-3:bvsize-5];
    wire [1:0] working_size = working_data[bvsize-6:bvsize-7];
    wire [clint_defines::TL_RS-1:0] working_source = working_data[bvsize-8:bvsize-8-clint_defines::TL_RS+1];
    wire [15:0] working_address = working_data[bvsize-8-clint_defines::TL_RS:bvsize-8-clint_defines::TL_RS-15];
    /* verilator lint_off UNUSEDSIGNAL */
    wire [3:0] working_mask = working_data[bvsize-8-clint_defines::TL_RS-16:bvsize-8-clint_defines::TL_RS-16-3];
    /* verilator lint_on UNUSEDSIGNAL */
    wire [31:0] working_tldata = working_data[bvsize-8-clint_defines::TL_RS-16-4:bvsize-8-clint_defines::TL_RS-16-4-31];
    wire working_corrupt = working_data[0];

    localparam CSR_MTIMEL =     16'hBFF8;
    localparam CSR_MTIMEH =     16'hBFFC;


    reg [HARTNO-1:0] msip_vector;

    reg [31:0] mtimecmpl [0:HARTNO-1];
    reg [31:0] mtimecmph [0:HARTNO-1];

    reg [63:0] mtime;
    always_ff @(posedge clint_clk_i) begin
        if (clint_rst_i) begin
            mtime <= 64'h0000000000000000;
        end
        else if (working_vld&!busy&(
            working_opcode==tluh::PutFullData
            ||working_opcode==tluh::LogicalData
            )&(working_address==16'hBFF8||working_address==16'hBFFC)&!working_corrupt) begin
            mtime[31:0] <= working_address==16'hBFF8 ? write_value_machine : mtime[31:0];
            mtime[63:32] <= working_address==16'hBFFC ? write_value_machine : mtime[63:32];
        end else begin
            mtime <= mtime + 1'b1;
        end
    end
    wire msip_accessed = working_address < 16'h4000;
    logic [31:0] read_machine;
    always_comb begin
        case (working_address)
            CSR_MTIMEL:             read_machine = mtime[31:0];
            CSR_MTIMEH:             read_machine = mtime[63:32];
            default: begin
                if (msip_accessed) begin
                    read_machine = {31'h00000000, msip_vector[working_address[$clog2(HARTNO)+1:2]]};
                end else begin
                    read_machine = working_address[2] ? mtimecmph[working_address[$clog2(HARTNO)+2:3]] : mtimecmph[working_address[$clog2(HARTNO)+2:3]];
                end
            end
        endcase
    end
    logic [31:0] write_value_machine;
    always_comb begin
        case (working_opcode)
            tluh::PutFullData:   begin
                write_value_machine = working_tldata;
            end
            tluh::LogicalData:   begin
                if (working_param==3'd0) begin
                    write_value_machine = read_machine^working_tldata;
                end else if (working_param==3'd1) begin
                    write_value_machine = read_machine|working_tldata;
                end else if (working_param==3'd2) begin
                    write_value_machine = read_machine&working_tldata;
                end
                else begin
                    write_value_machine = working_tldata;
                end
            end                
            default: begin
                write_value_machine = 32'h00000000;
            end
        endcase
    end

    always_ff @(posedge clint_clk_i) begin
        if (working_vld&!busy&(            
            working_opcode==tluh::PutFullData
            ||working_opcode==tluh::LogicalData)&!working_corrupt) begin
                if (msip_accessed) begin
                    msip_vector[working_address[$clog2(HARTNO)+1:2]] <= write_value_machine[0];
                end else if (working_address<16'hBFF8) begin
                    mtimecmph[working_address[$clog2(HARTNO)+2:3]] <= working_address[3] ? write_value_machine : mtimecmph[working_address[$clog2(HARTNO)+2:3]];
                    mtimecmpl[working_address[$clog2(HARTNO)+2:3]] <= !working_address[3] ? write_value_machine : mtimecmpl[working_address[$clog2(HARTNO)+2:3]];
                end
        end
    end

    always_ff @(posedge clint_clk_i) begin
        if (working_vld&!busy) begin
            tluh_o.d_data <= read_machine;
            tluh_o.d_opcode <= working_opcode==tluh::PutFullData ? tluh::AccessAck : tluh::AccessAckData;
            tluh_o.d_size <= working_size;
            tluh_o.d_source <= working_source;
            tluh_o.d_sink <= 1'b0;
            tluh_o.d_param <= 2'b0;
            tluh_o.d_denied <= working_corrupt;
            tluh_o.d_corrupt <= 1'b0;
            tluh_o.d_valid <= 1'b1;
        end
        else if (!working_vld&!busy) begin
            tluh_o.d_valid <= 1'b0;
        end
    end
    assign hart_msip = msip_vector;
    for (genvar i = 0; i < HARTNO; i++) begin : time_comparison
        assign hart_mti[i] = mtime >= {mtimecmph, mtimecmpl};
    end
endmodule

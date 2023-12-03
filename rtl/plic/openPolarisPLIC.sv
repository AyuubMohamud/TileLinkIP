// Copyright (C) Ayuub Mohamud, 2023
// Licensed under CERN-OHL-P version 2
module openPolarisPLIC #(parameter TL_RS = 4) (
    input   wire logic                          plic_clock_i,
    input   wire logic                          plic_reset_i,

    // Slave interface
    input   wire logic [2:0]                    plic_a_opcode,
    input   wire logic [2:0]                    plic_a_param,
    input   wire logic [3:0]                    plic_a_size,
    input   wire logic [TL_RS-1:0]              plic_a_source,
    input   wire logic [21:0]                   plic_a_address,
    input   wire logic [3:0]                    plic_a_mask,
    input   wire logic [31:0]                   plic_a_data,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic                          plic_a_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic                          plic_a_valid,
    output  wire logic                          plic_a_ready,

    output       logic [2:0]                    plic_d_opcode,
    output       logic [1:0]                    plic_d_param,
    output       logic [3:0]                    plic_d_size,
    output       logic [TL_RS-1:0]              plic_d_source,
    output       logic                          plic_d_denied,
    output       logic [31:0]                   plic_d_data,
    output       logic                          plic_d_corrupt,
    output       logic                          plic_d_valid,
    input   wire logic                          plic_d_ready,

    input   wire logic [14:0]                    int_i, //! No gateway needed, only one interrupt is performed per peripheral

    output  wire logic                          hart0_meip_o,
    output  wire logic                          hart0_seip_o
);
    wire plic_busy;
    wire [TL_RS-1:0] working_source;
    wire [3:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire [21:0] working_address;
    wire [2:0] working_param;
    wire working_valid;
    skdbf #(TL_RS+4+60+4) skidbuffer (plic_clock_i, plic_reset_i, ~plic_d_ready, {
        working_source,
        working_size,
        working_data,
        working_mask,
        working_opcode,
        working_address,
        working_param
    }, working_valid, plic_busy, {
        plic_a_source, plic_a_size, plic_a_data, plic_a_mask, plic_a_opcode, plic_a_address, plic_a_param
    }, plic_a_valid);
    assign plic_a_ready = !plic_busy;
    reg source1_priority;
    reg source2_priority;
    reg source3_priority;
    reg source4_priority;
    reg source5_priority;
    reg source6_priority;
    reg source7_priority;
    reg source8_priority;
    reg source9_priority;
    reg source10_priority;
    reg source11_priority;
    reg source12_priority;
    reg source13_priority;
    reg source14_priority;
    wire [15:0] interrupt_pending = {
        int_i, 1'b0
    };

    reg [14:0] ie_m_mode_hart_0;
    reg [14:0] ie_s_mode_hart_0;
    //reg [6:0] ie_m_mode_hart_1;
    //reg [6:0] ie_s_mode_hart_1;

    reg priority_threshold_m_mode_hart_0;
    reg priority_threshold_s_mode_hart_0;
    //reg priority_threshold_m_mode_hart_1;
    //reg priority_threshold_s_mode_hart_1;

    logic [15:0] read_machine;

endmodule

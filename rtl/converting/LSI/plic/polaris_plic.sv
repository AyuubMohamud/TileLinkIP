// Copyright (C) Ayuub Mohamud, 2023
// Licensed under CERN-OHL-P version 2
module polaris_plic (
    input   wire logic                      lsioc_clk_i,
    input   wire logic                      lsioc_rst_i,


    input   wire logic                      lsioc_rx_vld_i,
    input   wire logic [21:0]               lsioc_rx_sbsp_i,
    input   wire logic [31:0]               lsioc_rx_data_i,
    input   wire logic [2:0]                lsioc_rx_opc_i,
    output  wire logic                      lsioc_rx_busy_o,

    output       logic [1:0]                lsioc_tx_err_code_o,
    output       logic [31:0]               lsioc_tx_data_o,
    output       logic                      lsioc_tx_vld_o,
    input   wire logic                      lsioc_tx_busy_i,


    input   wire logic [6:0]                int_i, //! No gateway needed, only one interrupt is performed per peripheral

    output  wire logic                      hart0_meip_o,
    output  wire logic                      hart0_seip_o
);
    wire [56:0] working_data;
    wire working_vld;
    wire busy = lsioc_tx_busy_i;
    skdbf #(.DW(57)) lsi_skidbuffer (lsioc_clk_i, lsioc_rst_i, busy, working_data, working_vld, lsioc_rx_busy_o, {lsioc_rx_sbsp_i, lsioc_rx_data_i, lsioc_rx_opc_i}, lsioc_rx_vld_i);
    wire [21:0] working_lsi_sbsp = working_data[56:35];
    wire [31:0] working_lsi_data = working_data[34:3];
    wire [2:0] working_lsi_opc = working_data[2:0];
    localparam LSIOC_WRITE = 3'b001;
    localparam LSIOC_AMOSWAP = 3'b110;
    localparam LSIOC_AMOXOR = 3'b111;
    localparam LSIOC_AMOAND = 3'b100;
    localparam LSIOC_AMOORR = 3'b101;

    localparam LSIOC_RESPONSE_OK = 2'b00;

    reg source1_priority;
    reg source2_priority;
    reg source3_priority;
    reg source4_priority;
    reg source5_priority;
    reg source6_priority;
    reg source7_priority;

    wire [7:0] interrupt_pending = {
        int_i, 1'b0
    };

    reg [6:0] ie_m_mode_hart_0;
    reg [6:0] ie_s_mode_hart_0;
    reg [6:0] ie_m_mode_hart_1;
    reg [6:0] ie_s_mode_hart_1;

    reg priority_threshold_m_mode_hart_0;
    reg priority_threshold_s_mode_hart_0;
    reg priority_threshold_m_mode_hart_1;
    reg priority_threshold_s_mode_hart_1;

    logic [7:0] read_machine;
    localparam CSR_INTERRUPT_PRIORITY_1 = 22'h000004;
    localparam CSR_INTERRUPT_PRIORITY_2 = 22'h000008;
    localparam CSR_INTERRUPT_PRIORITY_3 = 22'h00000C;
    localparam CSR_INTERRUPT_PRIORITY_4 = 22'h000010;
    localparam CSR_INTERRUPT_PRIORITY_5 = 22'h000014;
    localparam CSR_INTERRUPT_PRIORITY_6 = 22'h000018;
    localparam CSR_INTERRUPT_PRIORITY_7 = 22'h00001C;
    localparam CSR_INTERRUPT_PENDING = 22'h001000;
    localparam CSR_INTERRUPT_ENABLE_HART0_M = 22'h002000;
    localparam CSR_INTERRUPT_ENABLE_HART0_S = 22'h002080;
    localparam CSR_INTERRUPT_ENABLE_HART1_M = 22'h002100;
    localparam CSR_INTERRUPT_ENABLE_HART1_S = 22'h002180;
    localparam CSR_PRIORITY_THRESHOLD_HART0_M = 22'h200000;
    localparam CSR_CLAIM_COMPLETE_HART0_M = 22'h200004;
    localparam CSR_PRIORITY_THRESHOLD_HART0_S = 22'h201000;
    localparam CSR_CLAIM_COMPLETE_HART0_S = 22'h201004;
    localparam CSR_PRIORITY_THRESHOLD_HART1_M = 22'h202000;
    localparam CSR_CLAIM_COMPLETE_HART1_M = 22'h202004;
    localparam CSR_PRIORITY_THRESHOLD_HART1_S = 22'h203000;
    localparam CSR_CLAIM_COMPLETE_HART1_S = 22'h203004;

    logic [2:0] interrupt_claim_cxt0;
    reg [7:0] claimed_bm_cxt0;
    logic [2:0] interrupt_claim_cxt1;
    reg [7:0] claimed_bm_cxt1;
    logic [2:0] interrupt_claim_cxt2;
    reg [7:0] claimed_bm_cxt2;
    logic [2:0] interrupt_claim_cxt3;
    reg [7:0] claimed_bm_cxt3;

    wire [7:0] priorites = {source7_priority, source6_priority, source5_priority, source4_priority, source3_priority, source2_priority, source1_priority, 1'b0};
    always_comb begin
        casez ({interrupt_pending&priorites&~claimed_bm_cxt0&{ie_m_mode_hart_0,1'b0}})
            8'b1zzzzzzz: begin
                interrupt_claim_cxt0 = 3'b111;
            end 
            8'b01zzzzzz: begin
                interrupt_claim_cxt0 = 3'b110;
            end
            8'b001zzzzz: begin
                interrupt_claim_cxt0 = 3'b101;
            end
            8'b0001zzzz: begin
                interrupt_claim_cxt0 = 3'b100;
            end
            8'b00001zzz: begin
                interrupt_claim_cxt0 = 3'b011;
            end
            8'b000001zz: begin
                interrupt_claim_cxt0 = 3'b010;
            end
            8'b0000001z: begin
                interrupt_claim_cxt0 = 3'b001;
            end
            default: begin
                interrupt_claim_cxt0 = 3'b000;
            end
        endcase
        casez ({interrupt_pending&priorites&~claimed_bm_cxt1&{ie_s_mode_hart_0,1'b0}})
            8'b1zzzzzzz: begin
                interrupt_claim_cxt1 = 3'b111;
            end 
            8'b01zzzzzz: begin
                interrupt_claim_cxt1 = 3'b110;
            end
            8'b001zzzzz: begin
                interrupt_claim_cxt1 = 3'b101;
            end
            8'b0001zzzz: begin
                interrupt_claim_cxt1 = 3'b100;
            end
            8'b00001zzz: begin
                interrupt_claim_cxt1 = 3'b011;
            end
            8'b000001zz: begin
                interrupt_claim_cxt1 = 3'b010;
            end
            8'b0000001z: begin
                interrupt_claim_cxt1 = 3'b001;
            end
            default: begin
                interrupt_claim_cxt1 = 3'b000;
            end
        endcase
        casez ({interrupt_pending&priorites&~claimed_bm_cxt2&{ie_m_mode_hart_1,1'b0}})
            8'b1zzzzzzz: begin
                interrupt_claim_cxt2 = 3'b111;
            end 
            8'b01zzzzzz: begin
                interrupt_claim_cxt2 = 3'b110;
            end
            8'b001zzzzz: begin
                interrupt_claim_cxt2 = 3'b101;
            end
            8'b0001zzzz: begin
                interrupt_claim_cxt2 = 3'b100;
            end
            8'b00001zzz: begin
                interrupt_claim_cxt2 = 3'b011;
            end
            8'b000001zz: begin
                interrupt_claim_cxt2 = 3'b010;
            end
            8'b0000001z: begin
                interrupt_claim_cxt2 = 3'b001;
            end
            default: begin
                interrupt_claim_cxt2 = 3'b000;
            end
        endcase
        casez ({interrupt_pending&priorites&~claimed_bm_cxt3&{ie_s_mode_hart_1,1'b0}})
            8'b1zzzzzzz: begin
                interrupt_claim_cxt3 = 3'b111;
            end 
            8'b01zzzzzz: begin
                interrupt_claim_cxt3 = 3'b110;
            end
            8'b001zzzzz: begin
                interrupt_claim_cxt3 = 3'b101;
            end
            8'b0001zzzz: begin
                interrupt_claim_cxt3 = 3'b100;
            end
            8'b00001zzz: begin
                interrupt_claim_cxt3 = 3'b011;
            end
            8'b000001zz: begin
                interrupt_claim_cxt3 = 3'b010;
            end
            8'b0000001z: begin
                interrupt_claim_cxt3 = 3'b001;
            end
            default: begin
                interrupt_claim_cxt3 = 3'b000;
            end
        endcase
    end

    always_comb begin
        case (working_lsi_sbsp)
            CSR_INTERRUPT_PRIORITY_1:       read_machine = {7'h00, source1_priority};
            CSR_INTERRUPT_PRIORITY_2:       read_machine = {7'h00, source2_priority};
            CSR_INTERRUPT_PRIORITY_3:       read_machine = {7'h00, source3_priority};
            CSR_INTERRUPT_PRIORITY_4:       read_machine = {7'h00, source4_priority};
            CSR_INTERRUPT_PRIORITY_5:       read_machine = {7'h00, source5_priority};
            CSR_INTERRUPT_PRIORITY_6:       read_machine = {7'h00, source6_priority};
            CSR_INTERRUPT_PRIORITY_7:       read_machine = {7'h00, source7_priority};
            CSR_INTERRUPT_PENDING:          read_machine = interrupt_pending;
            CSR_INTERRUPT_ENABLE_HART0_M:   read_machine = {ie_m_mode_hart_0, 1'b0};
            CSR_INTERRUPT_ENABLE_HART0_S:   read_machine = {ie_s_mode_hart_0, 1'b0};
            CSR_INTERRUPT_ENABLE_HART1_M:   read_machine = {ie_m_mode_hart_1, 1'b0};
            CSR_INTERRUPT_ENABLE_HART1_S:   read_machine = {ie_s_mode_hart_1, 1'b0};
            CSR_PRIORITY_THRESHOLD_HART0_M: read_machine = {7'h00, priority_threshold_m_mode_hart_0};
            CSR_PRIORITY_THRESHOLD_HART0_S: read_machine = {7'h00, priority_threshold_s_mode_hart_0};
            CSR_PRIORITY_THRESHOLD_HART1_M: read_machine = {7'h00, priority_threshold_m_mode_hart_1};
            CSR_PRIORITY_THRESHOLD_HART1_S: read_machine = {7'h00, priority_threshold_s_mode_hart_1};
            CSR_CLAIM_COMPLETE_HART0_M:     read_machine = {5'b00000, interrupt_claim_cxt0};
            CSR_CLAIM_COMPLETE_HART0_S:     read_machine = {5'b00000, interrupt_claim_cxt1};
            CSR_CLAIM_COMPLETE_HART1_M:     read_machine = {5'b00000, interrupt_claim_cxt2};
            CSR_CLAIM_COMPLETE_HART1_S:     read_machine = {5'b00000, interrupt_claim_cxt3};
            default:                        read_machine = 8'h00;
        endcase
    end
    logic [7:0] write_value_machine;
    always_comb begin
        case (working_lsi_opc)
            LSIOC_AMOAND:   write_value_machine = read_machine&working_lsi_data[7:0];
            LSIOC_AMOORR:   write_value_machine = read_machine|working_lsi_data[7:0];
            LSIOC_AMOSWAP:  write_value_machine = working_lsi_data[7:0];
            LSIOC_AMOXOR:   write_value_machine = read_machine^working_lsi_data[7:0];
            LSIOC_WRITE:    write_value_machine = working_lsi_data[7:0];
            default: begin
                write_value_machine = 8'h00;
            end
        endcase
    end

    logic [7:0] decode;
    always_comb begin
        case (write_value_machine[2:0])
            3'b000: begin
                decode = 8'h00;
            end 
            3'b001: begin
                decode = 8'b00000010;
            end
            3'b010: begin
                decode = 8'b00000100;
            end
            3'b011: begin
                decode = 8'b00001000;
            end
            3'b100: begin
                decode = 8'b00010000;
            end
            3'b101: begin
                decode = 8'b00100000;
            end
            3'b110: begin
                decode = 8'b01000000;
            end
            3'b111: begin
                decode = 8'b10000000;
            end
        endcase
    end
    

    always_ff @(posedge lsioc_clk_i) begin
        if (working_vld&(working_lsi_opc[2]|working_lsi_opc[0])&!busy) begin
            case (working_lsi_sbsp)
                CSR_INTERRUPT_PRIORITY_1:       source1_priority <= write_value_machine[0];
                CSR_INTERRUPT_PRIORITY_2:       source2_priority <= write_value_machine[0];
                CSR_INTERRUPT_PRIORITY_3:       source3_priority <= write_value_machine[0];
                CSR_INTERRUPT_PRIORITY_4:       source4_priority <= write_value_machine[0];
                CSR_INTERRUPT_PRIORITY_5:       source5_priority <= write_value_machine[0];
                CSR_INTERRUPT_PRIORITY_6:       source6_priority <= write_value_machine[0];
                CSR_INTERRUPT_PRIORITY_7:       source7_priority <= write_value_machine[0];
                CSR_INTERRUPT_ENABLE_HART0_M:   ie_m_mode_hart_0 <= write_value_machine[7:1];
                CSR_INTERRUPT_ENABLE_HART0_S:   ie_s_mode_hart_0 <= write_value_machine[7:1];
                CSR_INTERRUPT_ENABLE_HART1_M:   ie_m_mode_hart_1 <= write_value_machine[7:1];
                CSR_INTERRUPT_ENABLE_HART1_S:   ie_s_mode_hart_1 <= write_value_machine[7:1];
                CSR_PRIORITY_THRESHOLD_HART0_M: priority_threshold_m_mode_hart_0 <= write_value_machine[0];
                CSR_PRIORITY_THRESHOLD_HART0_S: priority_threshold_s_mode_hart_0 <= write_value_machine[0];
                CSR_PRIORITY_THRESHOLD_HART1_M: priority_threshold_m_mode_hart_1 <= write_value_machine[0];
                CSR_PRIORITY_THRESHOLD_HART1_S: priority_threshold_s_mode_hart_1 <= write_value_machine[0];
                CSR_CLAIM_COMPLETE_HART0_M:     claimed_bm_cxt0 <= decode==claimed_bm_cxt0 ? 8'h00 : claimed_bm_cxt0;
                CSR_CLAIM_COMPLETE_HART0_S:     claimed_bm_cxt1 <= decode==claimed_bm_cxt1 ? 8'h00 : claimed_bm_cxt1;
                CSR_CLAIM_COMPLETE_HART1_M:     claimed_bm_cxt2 <= decode==claimed_bm_cxt2 ? 8'h00 : claimed_bm_cxt2;
                CSR_CLAIM_COMPLETE_HART1_S:     claimed_bm_cxt3 <= decode==claimed_bm_cxt3 ? 8'h00 : claimed_bm_cxt3;
            endcase
        end
    end

    always_ff @(posedge lsioc_clk_i) begin
        if (working_vld&!busy) begin
            lsioc_tx_data_o <= {24'h000000, read_machine};
            lsioc_tx_err_code_o <= LSIOC_RESPONSE_OK;
            lsioc_tx_vld_o <= 1'b1;
        end
        else if (!working_vld&!busy) begin
            lsioc_tx_vld_o <= 1'b0;
        end
    end
    assign hart0_meip_o = |(priorites&{8{priority_threshold_m_mode_hart_0}}&{ie_m_mode_hart_0, 1'b0}&interrupt_pending&~claimed_bm_cxt0);
    assign hart0_seip_o = |(priorites&{8{priority_threshold_s_mode_hart_0}}&{ie_s_mode_hart_0, 1'b0}&interrupt_pending&~claimed_bm_cxt1);

endmodule

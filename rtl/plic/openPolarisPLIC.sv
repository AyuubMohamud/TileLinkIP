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

    input   wire logic [6:0]                    int_i, //! No gateway needed, only one interrupt is performed per peripheral

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

    wire [7:0] interrupt_pending = {
        int_i, 1'b0
    };

    reg [6:0] ie_m_mode_hart_0;
    reg [6:0] ie_s_mode_hart_0;
    //reg [6:0] ie_m_mode_hart_1;
    //reg [6:0] ie_s_mode_hart_1;

    reg priority_threshold_m_mode_hart_0;
    reg priority_threshold_s_mode_hart_0;
    //reg priority_threshold_m_mode_hart_1;
    //reg priority_threshold_s_mode_hart_1;

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
    //localparam CSR_INTERRUPT_ENABLE_HART1_M = 22'h002100;
    //localparam CSR_INTERRUPT_ENABLE_HART1_S = 22'h002180;
    localparam CSR_PRIORITY_THRESHOLD_HART0_M = 22'h200000;
    localparam CSR_CLAIM_COMPLETE_HART0_M = 22'h200004;
    localparam CSR_PRIORITY_THRESHOLD_HART0_S = 22'h201000;
    localparam CSR_CLAIM_COMPLETE_HART0_S = 22'h201004;
    //localparam CSR_PRIORITY_THRESHOLD_HART1_M = 22'h202000;
    //localparam CSR_CLAIM_COMPLETE_HART1_M = 22'h202004;
    //localparam CSR_PRIORITY_THRESHOLD_HART1_S = 22'h203000;
    //localparam CSR_CLAIM_COMPLETE_HART1_S = 22'h203004;

    logic [2:0] interrupt_claim_cxt0;
    reg [7:0] claimed_bm_cxt0;
    logic [2:0] interrupt_claim_cxt1;
    reg [7:0] claimed_bm_cxt1;
    //logic [2:0] interrupt_claim_cxt2;
    //reg [7:0] claimed_bm_cxt2;
    //logic [2:0] interrupt_claim_cxt3;
    //reg [7:0] claimed_bm_cxt3;

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
        //casez ({interrupt_pending&priorites&~claimed_bm_cxt2&{ie_m_mode_hart_1,1'b0}})
        //    8'b1zzzzzzz: begin
        //        interrupt_claim_cxt2 = 3'b111;
        //    end 
        //    8'b01zzzzzz: begin
        //        interrupt_claim_cxt2 = 3'b110;
        //    end
        //    8'b001zzzzz: begin
        //        interrupt_claim_cxt2 = 3'b101;
        //    end
        //    8'b0001zzzz: begin
        //        interrupt_claim_cxt2 = 3'b100;
        //    end
        //    8'b00001zzz: begin
        //        interrupt_claim_cxt2 = 3'b011;
        //    end
        //    8'b000001zz: begin
        //        interrupt_claim_cxt2 = 3'b010;
        //    end
        //    8'b0000001z: begin
        //        interrupt_claim_cxt2 = 3'b001;
        //    end
        //    default: begin
        //        interrupt_claim_cxt2 = 3'b000;
        //    end
        //endcase
        //casez ({interrupt_pending&priorites&~claimed_bm_cxt3&{ie_s_mode_hart_1,1'b0}})
        //    8'b1zzzzzzz: begin
        //        interrupt_claim_cxt3 = 3'b111;
        //    end 
        //    8'b01zzzzzz: begin
        //        interrupt_claim_cxt3 = 3'b110;
        //    end
        //    8'b001zzzzz: begin
        //        interrupt_claim_cxt3 = 3'b101;
        //    end
        //    8'b0001zzzz: begin
        //        interrupt_claim_cxt3 = 3'b100;
        //    end
        //    8'b00001zzz: begin
        //        interrupt_claim_cxt3 = 3'b011;
        //    end
        //    8'b000001zz: begin
        //        interrupt_claim_cxt3 = 3'b010;
        //    end
        //    8'b0000001z: begin
        //        interrupt_claim_cxt3 = 3'b001;
        //    end
        //    default: begin
        //        interrupt_claim_cxt3 = 3'b000;
        //    end
        //endcase
    end

    always_comb begin
        case (working_address)
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
            //CSR_INTERRUPT_ENABLE_HART1_M:   read_machine = {ie_m_mode_hart_1, 1'b0};
            //CSR_INTERRUPT_ENABLE_HART1_S:   read_machine = {ie_s_mode_hart_1, 1'b0};
            CSR_PRIORITY_THRESHOLD_HART0_M: read_machine = {7'h00, priority_threshold_m_mode_hart_0};
            CSR_PRIORITY_THRESHOLD_HART0_S: read_machine = {7'h00, priority_threshold_s_mode_hart_0};
            //CSR_PRIORITY_THRESHOLD_HART1_M: read_machine = {7'h00, priority_threshold_m_mode_hart_1};
            //CSR_PRIORITY_THRESHOLD_HART1_S: read_machine = {7'h00, priority_threshold_s_mode_hart_1};
            CSR_CLAIM_COMPLETE_HART0_M:     read_machine = {5'b00000, interrupt_claim_cxt0};
            CSR_CLAIM_COMPLETE_HART0_S:     read_machine = {5'b00000, interrupt_claim_cxt1};
            //CSR_CLAIM_COMPLETE_HART1_M:     read_machine = {5'b00000, interrupt_claim_cxt2};
            //CSR_CLAIM_COMPLETE_HART1_S:     read_machine = {5'b00000, interrupt_claim_cxt3};
            default:                        read_machine = 8'h00;
        endcase
    end

    logic [7:0] decode;
    always_comb begin
        case (working_data[2:0])
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
    

    always_ff @(posedge plic_clock_i) begin
        if (working_valid&(working_opcode==3'd0||working_opcode==3'd1)&plic_d_ready) begin
            case (working_address)
                CSR_INTERRUPT_PRIORITY_1:       source1_priority <= working_data[0];
                CSR_INTERRUPT_PRIORITY_2:       source2_priority <= working_data[0];
                CSR_INTERRUPT_PRIORITY_3:       source3_priority <= working_data[0];
                CSR_INTERRUPT_PRIORITY_4:       source4_priority <= working_data[0];
                CSR_INTERRUPT_PRIORITY_5:       source5_priority <= working_data[0];
                CSR_INTERRUPT_PRIORITY_6:       source6_priority <= working_data[0];
                CSR_INTERRUPT_PRIORITY_7:       source7_priority <= working_data[0];
                CSR_INTERRUPT_ENABLE_HART0_M:   ie_m_mode_hart_0 <= working_data[7:1];
                CSR_INTERRUPT_ENABLE_HART0_S:   ie_s_mode_hart_0 <= working_data[7:1];
                //CSR_INTERRUPT_ENABLE_HART1_M:   ie_m_mode_hart_1 <= working_data[7:1];
                //CSR_INTERRUPT_ENABLE_HART1_S:   ie_s_mode_hart_1 <= working_data[7:1];
                CSR_PRIORITY_THRESHOLD_HART0_M: priority_threshold_m_mode_hart_0 <= working_data[0];
                CSR_PRIORITY_THRESHOLD_HART0_S: priority_threshold_s_mode_hart_0 <= working_data[0];
                //CSR_PRIORITY_THRESHOLD_HART1_M: priority_threshold_m_mode_hart_1 <= working_data[0];
                //CSR_PRIORITY_THRESHOLD_HART1_S: priority_threshold_s_mode_hart_1 <= working_data[0];
                CSR_CLAIM_COMPLETE_HART0_M:     claimed_bm_cxt0 <= decode==claimed_bm_cxt0 ? 8'h00 : claimed_bm_cxt0;
                CSR_CLAIM_COMPLETE_HART0_S:     claimed_bm_cxt1 <= decode==claimed_bm_cxt1 ? 8'h00 : claimed_bm_cxt1;
                //CSR_CLAIM_COMPLETE_HART1_M:     claimed_bm_cxt2 <= decode==claimed_bm_cxt2 ? 8'h00 : claimed_bm_cxt2;
                //CSR_CLAIM_COMPLETE_HART1_S:     claimed_bm_cxt3 <= decode==claimed_bm_cxt3 ? 8'h00 : claimed_bm_cxt3;
            endcase
        end
    end

    always_ff @(posedge plic_clock_i) begin
        if (working_valid&plic_d_ready) begin
            plic_d_data <= {24'h000000, read_machine};
            plic_d_opcode <= {2'b00, working_opcode==3'd4};
            plic_d_valid <= 1'b1;
            plic_d_corrupt <= 0;
            plic_d_param <= 0;
            plic_d_denied <= 0;
            plic_d_size <= working_size;
            plic_d_source <= working_source;
        end
        else if (!working_valid&plic_d_ready) begin
            plic_d_valid <= 1'b0;
        end
    end
    assign hart0_meip_o = |(priorites&{8{priority_threshold_m_mode_hart_0}}&{ie_m_mode_hart_0, 1'b0}&interrupt_pending&~claimed_bm_cxt0);
    assign hart0_seip_o = |(priorites&{8{priority_threshold_s_mode_hart_0}}&{ie_s_mode_hart_0, 1'b0}&interrupt_pending&~claimed_bm_cxt1);

endmodule

module l2logic #(parameter TL_RS = 1, parameter TL_AW = 29, parameter enableUncacheableRegions = 1,
parameter [TL_AW-1:0] cacheable_start = 28'h0, parameter [TL_AW-1:0] cacheable_end = 28'h1000) (
    input   wire logic                          l2_clock_i,
    
    input   wire logic [2:0]                    master_a_opcode,
    input   wire logic [2:0]                    master_a_param,
    input   wire logic [3:0]                    master_a_size,
    input   wire logic [TL_RS-1:0]              master_a_source,
    input   wire logic [TL_AW-1:0]              master_a_address,
    input   wire logic [15:0]                   master_a_mask,
    input   wire logic [127:0]                  master_a_data,
    input   wire logic                          master_a_corrupt,
    input   wire logic                          master_a_valid,
    output  wire logic                          master_a_ready,

    output       logic [2:0]                    master_d_opcode,
    output       logic [1:0]                    master_d_param,
    output       logic [3:0]                    master_d_size,
    output       logic [TL_RS-1:0]              master_d_source,
    output       logic                          master_d_denied,
    output       logic [127:0]                  master_d_data,
    output       logic                          master_d_corrupt,
    output       logic                          master_d_valid,
    input   wire logic                          master_d_ready,

    output       logic [2:0]                    coherentMaster_b_opcode,
    output       logic [2:0]                    coherentMaster_b_param,
    output       logic [3:0]                    coherentMaster_b_size,
    output       logic [TL_AW-1:0]              coherentMaster_b_address,
    output       logic [15:0]                   coherentMaster_b_mask,
    output       logic [127:0]                  coherentMaster_b_data,
    output       logic                          coherentMaster_b_corrupt,
    output       logic                          coherentMaster_b_valid,
    input   wire logic                          coherentMaster_b_ready,
    input   wire logic [2:0]                    coherentMaster_c_opcode,
    input   wire logic [1:0]                    coherentMaster_c_param,
    input   wire logic [3:0]                    coherentMaster_c_size,
    input   wire logic [TL_AW-1:0]              coherentMaster_c_address,
    input   wire logic [127:0]                  coherentMaster_c_data,
    input   wire logic                          coherentMaster_c_corrupt,
    input   wire logic                          coherentMaster_c_valid,
    output  wire logic                          coherentMaster_c_ready,
    input   wire logic                          coherentMaster_e_valid,
    output  wire logic                          coherentMaster_e_ready,

    output  wire logic [TL_AW-8:0]              tags_cache_line,
    input   wire logic [3:0]                    tags_set_bitvec,
    input   wire logic [3:0]                    tags_match_bitvec,
    input   wire logic [3:0]                    tags_total_match,
    input   wire logic                          tags_valid,
    input   wire logic [1:0]                    tags_set_enc,
    output  wire logic [TL_AW-8:0]              tags_cache_line_insert,
    output  wire logic [1:0]                    tags_set_to_insert_in,
    output  wire logic                          tags_insert,
    output  wire logic                          tags_insert_present,

    output  wire logic                          way0_rd_en,
    output  wire logic [10:0]                   way0_rd_addr,
    input   wire logic [127:0]                  way0_rd_data,
    output  wire logic [15:0]                   way0_wr_en,
    output  wire logic [10:0]                   way0_wr_addr,
    output  wire logic [127:0]                  way0_wr_data,
    output  wire logic                          way1_rd_en,
    output  wire logic [10:0]                   way1_rd_addr,
    input   wire logic [127:0]                  way1_rd_data,
    output  wire logic [15:0]                   way1_wr_en,
    output  wire logic [10:0]                   way1_wr_addr,
    output  wire logic [127:0]                  way1_wr_data,
    output  wire logic                          way2_rd_en,
    output  wire logic [10:0]                   way2_rd_addr,
    input   wire logic [127:0]                  way2_rd_data,
    output  wire logic [15:0]                   way2_wr_en,
    output  wire logic [10:0]                   way2_wr_addr,
    output  wire logic [127:0]                  way2_wr_data,
    output  wire logic                          way3_rd_en,
    output  wire logic [10:0]                   way3_rd_addr,
    input   wire logic [127:0]                  way3_rd_data,
    output  wire logic [15:0]                   way3_wr_en,
    output  wire logic [10:0]                   way3_wr_addr,
    output  wire logic [127:0]                  way3_wr_data,

    output       logic                          miss,
    output       logic [TL_AW-8:0]              missed_cl,
    output       logic [3:0]                    fill_way_bm,

    output       logic                          evict,
    output       logic [TL_AW-8:0]              evicted_cl,
    output       logic [3:0]                    invalidate_way_bm
);
    skdbf #(.DW())
    assign coherentMaster_e_ready = 1'b1;
    assign coherentMaster_c_ready = 1'b1;

    localparam coherence_idle = 3'b000;
    localparam cached_get = 3'b001;

    reg [2:0] coherence_state = coherence_idle;
    always_ff @(posedge l2_clock_i) begin
        case (coherence_state)
            coherence_idle: begin
                
            end
            default: begin
                
            end
        endcase
    end
endmodule

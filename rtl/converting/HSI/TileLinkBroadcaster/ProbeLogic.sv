module ProbeLogic (
    input   wire logic                      tilelink_clk_i,
    
    input   wire logic                      gen_probe_i,
    input   wire logic [27:0]               probe_addr_i,
    input   wire logic [2:0]                probe_opcode_i,
    input   wire logic [2:0]                probe_param_i,
    input   wire logic [15:0]               probe_mask_i,
    input   wire logic [2:0]                probe_size_i,
    input   wire logic [1:0]                acq_source_i,
    output  wire logic                      can_probe_o,

    output       logic [2:0]                l2_b_opcode_o ,
    output       logic [2:0]                l2_b_param_o ,
    output       logic [2:0]                l2_b_size_o ,
    output       logic                      l2_b_source_o,
    output       logic                      l2_b_unicast_o,
    output       logic [27:0]               l2_b_address_o ,
    output       logic [15:0]               l2_b_mask_o ,
    output       logic [127:0]              l2_b_data_o ,
    output       logic                      l2_b_corrupt_o ,
    output       logic                      l2_b_valid_o ,
    input   wire logic                      l2_b_ready_i ,

    input   wire logic                      release_blk_i
);
    assign can_probe_o = release_blk_i&l2_b_ready_i;

    always_ff @(posedge tilelink_clk_i) begin
        if (can_probe_o&gen_probe_i) begin
            l2_b_opcode_o <= 3'd6;
            l2_b_param_o <= probe_opcode_i==3'd6 ? probe_param_i==3'd0 ? 3'd1 : 3'd0 : 3'd0;
            l2_b_size_o <= probe_size_i;
            l2_b_source_o <= acq_source_i==2'b00;
            l2_b_unicast_o <= acq_source_i > 2'b01;
            l2_b_address_o <= probe_addr_i;
            l2_b_mask_o <= probe_mask_i;
            l2_b_data_o <= 0;
            l2_b_corrupt_o <= 0;
            l2_b_valid_o <= 1;
        end else if (l2_b_ready_i&(release_blk_i|!gen_probe_i)) begin
            l2_b_valid_o <= 0;
        end
    end
endmodule

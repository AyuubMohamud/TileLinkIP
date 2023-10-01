module TileLinkBroadcaster (
    input   wire logic                      tilelink_clk_i,

    input   wire logic [2:0]                    l2_a_opcode_i [0:3],
    input   wire logic [2:0]                    l2_a_param_i [0:3],
    input   wire logic [2:0]                    l2_a_size_i [0:3],
    input   wire logic [27:0]                   l2_a_address_i [0:3],
    input   wire logic [15:0]                   l2_a_mask_i [0:3],
    input   wire logic [127:0]                  l2_a_data_i [0:3],
    input   wire logic                          l2_a_corrupt_i [0:3],
    input   wire logic                          l2_a_valid_i [0:3],
    output  wire logic                          l2_a_ready_o [0:3],
    // Hooked up directly to Both L1Ds
    output       logic [2:0]                    l2_b_opcode_o [0:1],
    output       logic [2:0]                    l2_b_param_o [0:1],
    output       logic [2:0]                    l2_b_size_o [0:1],
    output       logic [27:0]                   l2_b_address_o [0:1],
    output       logic [15:0]                   l2_b_mask_o [0:1],
    output       logic [127:0]                  l2_b_data_o [0:1],
    output       logic                          l2_b_corrupt_o [0:1],
    output       logic                          l2_b_valid_o [0:1],
    input   wire logic                          l2_b_ready_i [0:1],
    // Hooked up directly to both L1Ds
    input   wire logic [2:0]                    l2_c_opcode_i [0:1],
    input   wire logic [2:0]                    l2_c_param_i [0:1],
    input   wire logic [2:0]                    l2_c_size_i [0:1],
    input   wire logic [27:0]                   l2_c_address_i [0:1],
    input   wire logic [127:0]                  l2_c_data_i [0:1],
    input   wire logic                          l2_c_corrupt_i [0:1],
    input   wire logic                          l2_c_valid_i [0:1],
    output  wire logic                          l2_c_ready_o [0:1],

    output       logic [2:0]                    l2_d_opcode_i [0:3],
    output       logic [2:0]                    l2_d_param_i [0:3],
    output       logic [2:0]                    l2_d_size_i [0:3],
    output       logic                          l2_d_denied_o [0:3],
    output       logic [127:0]                  l2_d_data_o [0:3],
    output       logic                          l2_d_corrupt_o [0:3],
    output       logic                          l2_d_valid_o [0:3],
    output  wire logic                          l2_d_ready_o [0:3],
    
    input   wire logic                          l2_e_valid_i [0:1],
    output  wire logic                          l2_e_ready_o [0:1],
);
    
endmodule

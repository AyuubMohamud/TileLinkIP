module ReleaseLogic (
    input   wire logic                          tilelink_clk_i,
    input   wire logic [2:0]                    l2_c_opcode_i ,
    input   wire logic [2:0]                    l2_c_param_i ,
    input   wire logic [2:0]                    l2_c_size_i ,
    input   wire logic                          l2_c_source_i,
    input   wire logic [27:0]                   l2_c_address_i ,
    input   wire logic [127:0]                  l2_c_data_i ,
    input   wire logic                          l2_c_corrupt_i ,
    input   wire logic                          l2_c_valid_i ,
    output  wire logic                          l2_c_ready_o ,

    output       logic [2:0]                    l2_d_opcode_o,
    output       logic [2:0]                    l2_d_param_o,
    output       logic [2:0]                    l2_d_size_o,
    output       logic [1:0]                    l2_d_master_o,
    output       logic                          l2_d_denied_o,
    output       logic [127:0]                  l2_d_data_o ,
    output       logic                          l2_d_corrupt_o ,
    output       logic                          l2_d_valid_o ,
    output  wire logic                          l2_d_ready_o ,    

    output       logic [2:0]                    memory_a_opcode_o,
    output       logic [2:0]                    memory_a_param_o,
    output       logic [2:0]                    memory_a_size_o,
    output       logic [27:0]                   memory_a_address_o,
    output       logic [15:0]                   memory_a_mask_o, 
    output       logic [127:0]                  memory_a_data_o, 
    output       logic                          memory_a_valid_o,
    input   wire logic                          memory_a_ready_i,

    input   wire logic [2:0]                    memory_d_opcode_i,
    input   wire logic [1:0]                    memory_d_param_i,
    input   wire logic [2:0]                    memory_d_size_i,
    input   wire logic [127:0]                  memory_d_data_i,
    input   wire logic                          memory_d_denied_i,
    input   wire logic                          memory_d_valid_i,
    output  wire logic                          memory_d_ready_o,

    output  wire logic                          release_bsy_o
);
    reg [127:0] data_buf [0:7];
    reg [1:0] fsm;
    localparam idle = 2'b00;
    localparam handle_writeback = 2'b01;

    always_ff @(posedge tilelink_clk_i) begin : ReleaseLogic
        
    end
endmodule

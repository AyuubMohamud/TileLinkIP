module coherentInterconnect #(parameter TL_AW = 28, 
                              parameter TL_RS = 3,
                              parameter TL_UH_M = 1, 
                              parameter TL_UL_M = 1,
                              parameter TL_C_M = 1,
                              parameter TL_DW = 128,
                              parameter enableUncacheableRegions = 0,
                              parameter [TL_AW-1:0] cacheable_start = 0,
                              parameter [TL_AW-1:0] cacheable_end = 0) (
    input   wire logic                                                  interconnect_clock_i,
    input   wire logic                                                  interconnect_reset_i,
    input   wire logic [3*((TL_UH_M + TL_UL_M + TL_C_M))-1:0]           interconnect_a_opcode,
    input   wire logic [3*((TL_UH_M + TL_UL_M + TL_C_M))-1:0]           interconnect_a_param,
    input   wire logic [((TL_UH_M + TL_UL_M + TL_C_M)*4)-1:0]           interconnect_a_size,
    input   wire logic [((TL_UH_M + TL_UL_M + TL_C_M)*TL_RS)-1:0]       interconnect_a_source,
    input   wire logic [(TL_AW*(TL_UH_M + TL_UL_M + TL_C_M))-1:0]       interconnect_a_address,
    input   wire logic [((TL_UH_M + TL_UL_M + TL_C_M)*(TL_DW/8))-1:0]   interconnect_a_mask,
    input   wire logic [((TL_UH_M + TL_UL_M + TL_C_M)*TL_DW)-1:0]       interconnect_a_data,
    input   wire logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_a_corrupt,
    input   wire logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_a_valid,
    output  wire logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_a_ready,

    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*3)-1:0]           interconnect_d_opcode,
    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*2)-1:0]           interconnect_d_param,
    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*4)-1:0]           interconnect_d_size,
    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*TL_RS)-1:0]       interconnect_d_source,
    output       logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_d_denied,
    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*TL_DW)-1:0]       interconnect_d_data,
    output       logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_d_corrupt,
    output       logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_d_valid,
    input   wire logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_d_ready,

    output       logic [(TL_C_M*3)-1:0]                                 coherentMaster_b_opcode,
    output       logic [(TL_C_M*3)-1:0]                                 coherentMaster_b_param,
    output       logic [(TL_C_M*4)-1:0]                                 coherentMaster_b_size,
    output       logic [(TL_C_M*TL_AW)-1:0]                             coherentMaster_b_address,
    output       logic [(TL_C_M*(TL_DW/8))-1:0]                         coherentMaster_b_mask,
    output       logic [(TL_C_M*TL_DW)-1:0]                             coherentMaster_b_data,
    output       logic [TL_C_M-1:0]                                     coherentMaster_b_corrupt,
    output       logic [TL_C_M-1:0]                                     coherentMaster_b_valid,
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_b_ready,
    input   wire logic [(TL_C_M*3)-1:0]                                 coherentMaster_c_opcode,
    input   wire logic [(TL_C_M*2)-1:0]                                 coherentMaster_c_param,
    input   wire logic [(TL_C_M*4)-1:0]                                 coherentMaster_c_size,
    input   wire logic [TL_AW-1:0]                                      coherentMaster_c_address,
    input   wire logic [(TL_C_M*TL_DW)-1:0]                             coherentMaster_c_data,
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_c_corrupt,
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_c_valid,
    output  wire logic [TL_C_M-1:0]                                     coherentMaster_c_ready,
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_e_valid,
    output  wire logic [TL_C_M-1:0]                                     coherentMaster_e_ready,

    output      logic [27:0]                                            app_addr,
    output      logic [2:0]                                             app_cmd,
    output      logic                                                   app_en,
    output      logic [127:0]                                           app_wdf_data,
    output      logic                                                   app_wdf_end,
    output      logic [15:0]                                            app_wdf_mask,
    output      logic                                                   app_wdf_wren,
    input  wire logic [127:0]                                           app_rd_data,
    input  wire logic                                                   app_rd_data_end,
    input  wire logic                                                   app_rd_data_valid,
    input  wire logic                                                   app_rdy,
    input  wire logic                                                   app_wdf_rdy
);

    wire logic [2:0]                    slave_a_opcode;
    wire logic [2:0]                    slave_a_param;
    wire logic [3:0]                    slave_a_size;
    wire logic [($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:0] slave_a_source;
    wire logic [TL_AW-1:0]              slave_a_address;
    wire logic [(TL_DW/8)-1:0]          slave_a_mask;
    wire logic [TL_DW-1:0]              slave_a_data;
    wire logic                          slave_a_corrupt;
    wire logic                          slave_a_valid;
    wire logic                          slave_a_ready;
    wire logic [2:0]                    slave_d_opcode;
    wire logic [1:0]                    slave_d_param;
    wire logic [3:0]                    slave_d_size;
    wire logic [($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:0]  slave_d_source;
    wire logic                          slave_d_denied;
    wire logic [TL_DW-1:0]              slave_d_data;
    wire logic                          slave_d_corrupt;
    wire logic                          slave_d_valid;
    wire logic                          slave_d_ready;
    TileLinkMto1 #(.M(TL_UH_M + TL_UL_M + TL_C_M), .TL_DW(TL_DW), .TL_AW(TL_AW), .TL_RS(TL_RS), .TL_SZ(4)) arbiter (interconnect_clock_i, interconnect_reset_i, interconnect_a_opcode,
    interconnect_a_param, interconnect_a_size, interconnect_a_source, interconnect_a_address, interconnect_a_mask, interconnect_a_data, interconnect_a_corrupt, 
    interconnect_a_valid, interconnect_a_ready, interconnect_d_opcode, interconnect_d_param, interconnect_d_size, interconnect_d_source, interconnect_d_denied, 
    interconnect_d_data, interconnect_d_corrupt, interconnect_d_valid, interconnect_d_ready,slave_a_opcode, slave_a_param, slave_a_size, slave_a_source, slave_a_address, 
    slave_a_mask, slave_a_data, slave_a_corrupt, slave_a_valid, slave_a_ready, slave_d_opcode, slave_d_param, slave_d_size, slave_d_source, slave_d_denied, slave_d_data, 
    slave_d_corrupt, slave_d_valid, slave_d_ready);
    assign coherentMaster_e_ready = 'hF;
    assign coherentMaster_c_ready = 'hF;

    localparam coherence_idle = 3'b000;
    
    reg [2:0] coherence_fsm;

endmodule

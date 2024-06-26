module coherentInterconnect #(parameter TL_AW = 29, 
                              parameter TL_RS = 3,
                              parameter TL_UH_M = 1, 
                              parameter TL_UL_M = 1,
                              parameter bootROM = "bootROM.mem",
                              parameter enableUncacheableRegions = 0,
                              parameter [TL_AW-1:0] cacheable_start = 0,
                              parameter [TL_AW-1:0] cacheable_end = 0) (
    input   wire logic                                         interconnect_clock_i,
    input   wire logic                                         interconnect_reset_i,
    input   wire logic [3*((TL_UH_M + TL_UL_M + 1))-1:0]       interconnect_a_opcode,
    input   wire logic [3*((TL_UH_M + TL_UL_M + 1))-1:0]       interconnect_a_param,
    input   wire logic [((TL_UH_M + TL_UL_M + 1)*4)-1:0]       interconnect_a_size,
    input   wire logic [((TL_UH_M + TL_UL_M + 1)*TL_RS)-1:0]   interconnect_a_source,
    input   wire logic [(TL_AW*(TL_UH_M + TL_UL_M + 1))-1:0]   interconnect_a_address,
    input   wire logic [((TL_UH_M + TL_UL_M + 1)*16)-1:0]      interconnect_a_mask,
    input   wire logic [((TL_UH_M + TL_UL_M + 1)*128)-1:0]     interconnect_a_data,
    input   wire logic [(TL_UH_M + TL_UL_M + 1)-1:0]           interconnect_a_corrupt,
    input   wire logic [(TL_UH_M + TL_UL_M + 1)-1:0]           interconnect_a_valid,
    output  wire logic [(TL_UH_M + TL_UL_M + 1)-1:0]           interconnect_a_ready,

    output       logic [((TL_UH_M + TL_UL_M + 1)*3)-1:0]       interconnect_d_opcode,
    output       logic [((TL_UH_M + TL_UL_M + 1)*2)-1:0]       interconnect_d_param,
    output       logic [((TL_UH_M + TL_UL_M + 1)*4)-1:0]       interconnect_d_size,
    output       logic [((TL_UH_M + TL_UL_M + 1)*TL_RS)-1:0]   interconnect_d_source,
    output       logic [(TL_UH_M + TL_UL_M + 1)-1:0]           interconnect_d_denied,
    output       logic [((TL_UH_M + TL_UL_M + 1)*128)-1:0]     interconnect_d_data,
    output       logic [(TL_UH_M + TL_UL_M + 1)-1:0]           interconnect_d_corrupt,
    output       logic [(TL_UH_M + TL_UL_M + 1)-1:0]           interconnect_d_valid,
    input   wire logic [(TL_UH_M + TL_UL_M + 1)-1:0]           interconnect_d_ready,

    output       logic [2:0]                                   coherentMaster_b_opcode,
    output       logic [2:0]                                   coherentMaster_b_param,
    output       logic [3:0]                                   coherentMaster_b_size,
    output       logic [TL_AW-1:0]                             coherentMaster_b_address,
    output       logic [15:0]                                  coherentMaster_b_mask,
    output       logic [127:0]                                 coherentMaster_b_data,
    output       logic                                         coherentMaster_b_corrupt,
    output       logic                                         coherentMaster_b_valid,
    input   wire logic                                         coherentMaster_b_ready,
    input   wire logic [2:0]                                   coherentMaster_c_opcode,
    input   wire logic [1:0]                                   coherentMaster_c_param,
    input   wire logic [3:0]                                   coherentMaster_c_size,
    input   wire logic [TL_AW-1:0]                             coherentMaster_c_address,
    input   wire logic [127:0]                                 coherentMaster_c_data,
    input   wire logic                                         coherentMaster_c_corrupt,
    input   wire logic                                         coherentMaster_c_valid,
    output  wire logic                                         coherentMaster_c_ready,
    input   wire logic                                         coherentMaster_e_valid,
    output  wire logic                                         coherentMaster_e_ready,

    input   wire logic [27:0]                                  app_addr,
    input   wire logic [2:0]                                   app_cmd,
    input   wire logic                                         app_en,
    input   wire logic [127:0]                                 app_wdf_data,
    input   wire logic                                         app_wdf_end,
    input   wire logic [15:0]                                  app_wdf_mask,
    input   wire logic                                         app_wdf_wren,
    output  wire logic [127:0]                                 app_rd_data,
    output  wire logic                                         app_rd_data_end,
    output  wire logic                                         app_rd_data_valid,
    output  wire logic                                         app_rdy,
    output  wire logic                                         app_wdf_rdy,

    // Slave interface
    input   wire logic [2:0]                                   l2_a_opcode,
    input   wire logic [2:0]                                   l2_a_param,
    input   wire logic [3:0]                                   l2_a_size,
    input   wire logic [TL_RS-1:0]                             l2_a_source,
    input   wire logic [3:0]                                   l2_a_address,
    input   wire logic [3:0]                                   l2_a_mask,
    input   wire logic [31:0]                                  l2_a_data,
    input   wire logic                                         l2_a_corrupt,
    input   wire logic                                         l2_a_valid,
    output  wire logic                                         l2_a_ready,
    output       logic [2:0]                                   l2_d_opcode,
    output       logic [1:0]                                   l2_d_param,
    output       logic [3:0]                                   l2_d_size,
    output       logic [TL_RS-1:0]                             l2_d_source,
    output       logic                                         l2_d_denied,
    output       logic [31:0]                                  l2_d_data,
    output       logic                                         l2_d_corrupt,
    output       logic                                         l2_d_valid,
    input   wire logic                                         l2_d_ready
);

    l2slave l2slave0 (interconnect_clock_i, interconnect_reset_i, l2_a_opcode, l2_a_param,l2_a_size,l2_a_source,l2_a_address,l2_a_mask,
    l2_a_data,l2_a_corrupt,l2_a_valid,l2_a_ready,l2_d_opcode,l2_d_param,l2_d_size,l2_d_source,l2_d_denied,l2_d_data,l2_d_corrupt,l2_d_valid,l2_d_ready);

    wire logic [2:0]                    slave_a_opcode;
    wire logic [2:0]                    slave_a_param;
    wire logic [3:0]                    slave_a_size;
    wire logic [($clog2(TL_UH_M + TL_UL_M + 1)+TL_RS)-1:0] slave_a_source;
    wire logic [TL_AW-1:0]              slave_a_address;
    wire logic [15:0]                   slave_a_mask;
    wire logic [127:0]                  slave_a_data;
    wire logic                          slave_a_corrupt;
    wire logic                          slave_a_valid;
    wire logic                          slave_a_ready;
    wire logic [2:0]                    slave_d_opcode;
    wire logic [1:0]                    slave_d_param;
    wire logic [3:0]                    slave_d_size;
    wire logic [($clog2(TL_UH_M + TL_UL_M + 1)+TL_RS)-1:0]  slave_d_source;
    wire logic                          slave_d_denied;
    wire logic [127:0]                  slave_d_data;
    wire logic                          slave_d_corrupt;
    wire logic                          slave_d_valid;
    wire logic                          slave_d_ready;
    TileLinkMto1 #(.M(TL_UH_M + TL_UL_M + 1), .TL_DW(128), .TL_AW(TL_AW), .TL_RS(TL_RS), .TL_SZ(4)) arbiter (interconnect_clock_i, interconnect_reset_i, interconnect_a_opcode,
    interconnect_a_param, interconnect_a_size, interconnect_a_source, interconnect_a_address, interconnect_a_mask, interconnect_a_data, interconnect_a_corrupt, 
    interconnect_a_valid, interconnect_a_ready, interconnect_d_opcode, interconnect_d_param, interconnect_d_size, interconnect_d_source, interconnect_d_denied, 
    interconnect_d_data, interconnect_d_corrupt, interconnect_d_valid, interconnect_d_ready,slave_a_opcode, slave_a_param, slave_a_size, slave_a_source, slave_a_address, 
    slave_a_mask, slave_a_data, slave_a_corrupt, slave_a_valid, slave_a_ready, slave_d_opcode, slave_d_param, slave_d_size, slave_d_source, slave_d_denied, slave_d_data, 
    slave_d_corrupt, slave_d_valid, slave_d_ready);
    wire            way0_rd_en;
    wire [10:0]     way0_rd_addr;
    wire [127:0]    way0_rd_data;
    wire [15:0]     way0_wr_en;
    wire [10:0]     way0_wr_addr;
    wire [127:0]    way0_wr_data;
    wire            way1_rd_en;
    wire [10:0]     way1_rd_addr;
    wire [127:0]    way1_rd_data;
    wire [15:0]     way1_wr_en;
    wire [10:0]     way1_wr_addr;
    wire [127:0]    way1_wr_data;
    wire            way2_rd_en;
    wire [10:0]     way2_rd_addr;
    wire [127:0]    way2_rd_data;
    wire [15:0]     way2_wr_en;
    wire [10:0]     way2_wr_addr;
    wire [127:0]    way2_wr_data;
    wire            way3_rd_en;
    wire [10:0]     way3_rd_addr;
    wire [127:0]    way3_rd_data;
    wire [15:0]     way3_wr_en;
    wire [10:0]     way3_wr_addr;
    wire [127:0]    way3_wr_data;
    // any boot rom provided must be less than 16kb
    l2ram l2way0 (interconnect_clock_i, way0_rd_en,way0_rd_addr,way0_rd_data,way0_wr_en,way0_wr_addr,way0_wr_data);
    l2ram l2way1 (interconnect_clock_i, way1_rd_en,way1_rd_addr,way1_rd_data,way1_wr_en,way1_wr_addr,way1_wr_data);
    l2ram l2way2 (interconnect_clock_i, way2_rd_en,way2_rd_addr,way2_rd_data,way2_wr_en,way2_wr_addr,way2_wr_data);
    l2ram #(.isBOOTRAM(1), .BOOTFILE("calvera.mem")) l2way3 (interconnect_clock_i, way3_rd_en,way3_rd_addr,way3_rd_data,way3_wr_en,way3_wr_addr,way3_wr_data);

    l2ddr3backend l2ddr3backend (interconnect_clock_i, app_addr, app_cmd, app_en, app_wdf_data, app_wdf_end, app_wdf_mask, app_wdf_wren, app_rd_data,
    app_rd_data_end, app_rd_data_valid, app_rdy, app_wdf_rdy);
    wire logic [TL_AW-9:0]  tags_cache_line;
    wire logic [3:0]        tags_set_bitvec;
    wire logic [3:0]        tags_match_bitvec;
    wire logic [3:0]        tags_total_match;
    wire logic              tags_valid;
    wire logic [1:0]        tags_set_enc;
    wire logic [TL_AW-9:0]  tags_cache_line_insert;
    wire logic [1:0]        tags_set_to_insert_in;
    wire logic              tags_insert;
    wire logic              tags_insert_present;
    l2tags tags (interconnect_clock_i, tags_cache_line, tags_set_bitvec, tags_match_bitvec, tags_total_match, tags_valid, tags_set_enc, 
    tags_cache_line_insert, tags_set_to_insert_in, tags_insert, tags_insert_present);


endmodule

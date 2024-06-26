module l2ddr3backend (
    input   wire logic              l2_clock_i,
    
    input   wire logic [27:0]       app_addr,
    input   wire logic [2:0]        app_cmd,
    input   wire logic              app_en,
    input   wire logic [127:0]      app_wdf_data,
    input   wire logic              app_wdf_end,
    input   wire logic [15:0]       app_wdf_mask,
    input   wire logic              app_wdf_wren,
    output  wire logic [127:0]      app_rd_data,
    output  wire logic              app_rd_data_end,
    output  wire logic              app_rd_data_valid,
    output  wire logic              app_rdy,
    output  wire logic              app_wdf_rdy
);
    
endmodule

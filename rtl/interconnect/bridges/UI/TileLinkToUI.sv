module TileLinkToUI #(parameter TL_RS = 4, parameter TL_AW = 28) (
    input   wire logic                          tilelink_clock_i,
    input   wire logic                          tilelink_reset_i,

    // Slave interface
    input   wire logic [2:0]                    ddr3_a_opcode,
    input   wire logic [2:0]                    ddr3_a_param,
    input   wire logic [3:0]                    ddr3_a_size,
    input   wire logic [TL_RS-1:0]              ddr3_a_source,
    input   wire logic [TL_AW-1:0]              ddr3_a_address,
    input   wire logic [3:0]                    ddr3_a_mask,
    input   wire logic [31:0]                   ddr3_a_data,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic                          ddr3_a_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic                          ddr3_a_valid,
    output  wire logic                          ddr3_a_ready,

    output       logic [2:0]                    ddr3_d_opcode,
    output       logic [1:0]                    ddr3_d_param,
    output       logic [3:0]                    ddr3_d_size,
    output       logic [TL_RS-1:0]              ddr3_d_source,
    output       logic                          ddr3_d_denied,
    output       logic [31:0]                   ddr3_d_data,
    output       logic                          ddr3_d_corrupt,
    output       logic                          ddr3_d_valid,
    input   wire logic                          ddr3_d_ready,
    // DDR3
    output       logic [2:0]                    app_cmd,
    output       logic [27:0]                   app_addr,
    output       logic                          app_en,
    input   wire logic                          app_rdy,
    
    input   wire logic [127:0]                  app_rd_data,
    input   wire logic                          app_rd_data_end,
    input   wire logic                          app_rd_data_valid,

    input   wire logic                          app_wdf_rdy,
    output       logic                          app_wdf_wren,
    output       logic [127:0]                  app_wdf_data,
    output       logic [15:0]                   app_wdf_mask,
    output       logic                          app_wdf_end
);
    wire ddr3_busy;
    wire bridge_busy;
    wire [TL_RS-1:0] working_source;
    wire [3:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire [TL_AW-1:0] working_address;
    wire [2:0] working_param;
    wire working_valid;
    reg awaiting_response;
    skdbf #(TL_RS+4+42+TL_AW) skidbuffer (tilelink_clock_i, tilelink_reset_i, ddr3_busy|awaiting_response, {
        working_source,
        working_size,
        working_data,
        working_mask,
        working_opcode,
        working_address,
        working_param
    }, working_valid, bridge_busy, {
        ddr3_a_source, ddr3_a_size, ddr3_a_data, ddr3_a_mask, ddr3_a_opcode, ddr3_a_address, ddr3_a_param
    }, ddr3_a_valid);
    assign ddr3_busy = (app_en&!app_rdy)|(~ddr3_d_ready);
    assign ddr3_a_ready = ~bridge_busy;
    reg [TL_RS-1:0] source;
    reg [3:0] size;
    reg [3:0] low_order;

    wire [3:0] mask = working_size==0 ? {working_address[1:0]==3, working_address[1:0]==2, 
    working_address[1:0]==1, working_address[1:0]==0} : working_size==1 ? {working_address[1], working_address[1], ~working_address[1], ~working_address[0]} :
    4'hF;
    wire [15:0] full_mask = working_address[3:2]==0 ? {12'h000, mask} : working_address[3:2]==1 ? 
    {8'h00, mask, 4'h0} : working_address==2 ? {4'h0, mask, 8'h00} : {mask, 12'h000};
    wire [31:0] data = working_size==0 ? working_address==0 ? {24'h000000, working_data[7:0]} :
    working_address==1 ? {16'h0000, working_data[7:0], 8'h00} : working_address==2 ? {8'h00, working_data[7:0], 16'h0000} :
    {working_data[7:0], 24'h000000} : working_size==1 ? working_address==0 ? {16'h0000, working_data[15:0]} : {working_data[15:0], 16'h0000}
    : working_data;
    wire [127:0] full_data = working_address[3:2] == 0 ? {96'd0, data} : working_address[3:2]==1 ? {64'd0, data, 32'd0} : working_address[3:2]==2 ?
    {32'd0, data, 64'd0} : {data, 96'd0};
    always_ff @(posedge tilelink_clock_i) begin
        if (tilelink_reset_i) begin
            app_en <= 0;
            awaiting_response <= 0;
        end else if (app_en&app_rdy) begin
            app_en <= 1'b0;
            awaiting_response <= 1'b1;
            app_wdf_wren <= app_wdf_rdy ? 0 : app_wdf_wren;
            app_wdf_end <= app_wdf_rdy ? 0 : app_wdf_end;
        end 
        else if ((app_rd_data_end&app_rd_data_valid)|(app_wdf_rdy&app_wdf_wren&app_wdf_end)) begin
            awaiting_response <= 1'b0;
            app_wdf_wren <= 0;
            app_wdf_end <= 0;
        end
        else if (working_valid&!ddr3_busy&!awaiting_response) begin
            app_addr <= {working_address[27:4], 4'h0};
            low_order <= working_address[3:0];
            app_cmd <= {2'b00, working_opcode[2]};
            app_en <= 1'b1;
            app_wdf_wren <= ~working_opcode[2];
            app_wdf_end <= ~working_opcode[2];
            app_wdf_mask <= ~full_mask;
            app_wdf_data <= full_data;
            source <= working_source;
            size <= working_size;
        end
    end
    wire [7:0] byte_select = low_order==0 ? app_rd_data[7:0] : low_order==1 ? app_rd_data[15:8] :
    low_order==2 ? app_rd_data[23:16] : low_order==3 ? app_rd_data[31:24] : low_order==4 ? app_rd_data[39:32]
    : low_order==5 ? app_rd_data[47:40] : low_order==6 ? app_rd_data[55:48] : low_order==7 ?
    app_rd_data[63:56] : low_order==8 ? app_rd_data[71:64] : low_order==9 ? app_rd_data[79:72]
    : low_order==10 ? app_rd_data[87:80] : low_order==11 ? app_rd_data[95:88] : low_order==12 ? 
    app_rd_data[103:96] : low_order==13 ? app_rd_data[111:104] : low_order==14 ? app_rd_data[119:112]:
    app_rd_data[127:120];
    wire [15:0] hw_select = low_order==0 ? app_rd_data[15:0] : low_order==2 ? app_rd_data[31:16]:
    low_order==4 ? app_rd_data[47:32] : low_order==6 ? app_rd_data[63:48] : low_order==8 ? app_rd_data[79:64]:
    low_order==10 ? app_rd_data[95:80] : low_order==12 ? app_rd_data[111:96] :app_rd_data[127:112];
    wire [31:0] word_select = low_order==0 ? app_rd_data[31:0] : low_order==4 ? app_rd_data[63:32] :
    low_order==8 ? app_rd_data[95:64] : app_rd_data[127:96];
    always_ff @(posedge tilelink_clock_i) begin
        if (ddr3_d_ready&!awaiting_response) begin
            ddr3_d_valid <= 0;
        end // ddr3_d_valid set with disregard to whether the link is ready or not.
        if ((app_rd_data_end&app_rd_data_valid)|(app_wdf_rdy&app_wdf_wren&app_wdf_end)) begin
            ddr3_d_valid <= 1;
            ddr3_d_size <= size;
            ddr3_d_source <= source;
            ddr3_d_corrupt <= 0;
            ddr3_d_denied <= 0;
            ddr3_d_param <= 0;
            ddr3_d_opcode <= {2'b00, (app_rd_data_end&app_rd_data_valid)};
            ddr3_d_data <= size==0 ? {24'h000000, byte_select} : size==1 ? {16'h0000, hw_select} : word_select;
        end
    end
endmodule

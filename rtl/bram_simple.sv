module bram_simple (
    input   wire logic          clk_i,
    input   wire logic [8:0]    rd_addr_i,
    output  wire logic [31:0]   rd_data_o,
    
    input   wire logic          wr_en_i,
    input   wire logic [8:0]   wr_addr_i,
    input   wire logic [31:0]   wr_data_i,
    input   wire logic [3:0]    wr_bm_i
);
    reg [31:0] ram [0:511];
    always_ff @(posedge clk_i) begin
        rd_data_o <= ram[rd_addr_i];
    end
    always_ff @(posedge clk_i) begin
        if (wr_en_i) begin
            ram[wr_addr_i][7:0] <= wr_bm_i[0] ? wr_data_i[7:0] : ram[wr_addr_i][7:0];
            ram[wr_addr_i][15:8] <= wr_bm_i[1] ? wr_data_i[15:8] : ram[wr_addr_i][15:8];
            ram[wr_addr_i][23:16] <= wr_bm_i[2] ? wr_data_i[23:16] : ram[wr_addr_i][23:16];
            ram[wr_addr_i][31:24] <= wr_bm_i[3] ? wr_data_i[31:24] : ram[wr_addr_i][31:24];
        end
            
    end
endmodule

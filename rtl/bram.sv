// For the sake of your own sanity, do not set the inputs combinationally in any way shape or form.
module bram (
    input   wire logic              clk200mhz_i,
    // CPU read port
    input   wire logic [10:0]       p0_rd_addr_i,
    output  logic [63:0]       p0_rd_data_o,

    // Cache manager read port
    input   wire logic [10:0]       p1_rd_addr_i,
    output  logic [63:0]       p1_rd_data_o,

    // CTMS/StoreBuffer Write Port
    input   wire logic              p0_wr_en_i,
    input   wire logic [10:0]       p0_wr_addr_i,
    input   wire logic [63:0]       p0_wr_data_i,
    input   wire logic [7:0]        p0_wr_bm_i,
    // Cache Manager write port
    input   wire logic              p1_wr_en_i,
    input   wire logic [10:0]       p1_wr_addr_i,
    input   wire logic [63:0]       p1_wr_data_i,
    input   wire logic [7:0]        p1_wr_bm_i
);
    reg port_service;
    always_ff @(posedge clk200mhz_i) begin
        port_service <= ~port_service;
    end    
    reg [63:0] ram [0:2047];
    reg [63:0] ram_read_reg;
    wire [10:0] read_address = port_service ? p1_rd_addr_i : p0_rd_addr_i;
    always_ff @(posedge clk200mhz_i) begin
        ram_read_reg <= ram[read_address];
    end
    reg [63:0] ram_read_reg2;
    always_ff @(posedge clk200mhz_i) begin
        ram_read_reg2 <= ram_read_reg;
    end
    assign p0_rd_data_o = ram_read_reg2;
    assign p1_rd_data_o = ram_read_reg;
    wire [10:0] write_address = port_service ? p1_wr_addr_i : p0_wr_addr_i;
    wire wr_en = port_service ? p1_wr_en_i : p0_wr_en_i;
    wire [63:0] wr_data = port_service ? p1_wr_data_i : p0_wr_data_i;
    wire [7:0] wr_bm = port_service ? p1_wr_bm_i : p0_wr_bm_i;
    always_ff @(posedge clk200mhz_i) begin
        if (wr_en) begin
            ram[write_address][7:0] <= wr_bm[0] ? wr_data[7:0] : ram[write_address][7:0];
            ram[write_address][15:8] <= wr_bm[1] ? wr_data[15:8] : ram[write_address][15:8];
            ram[write_address][23:16] <= wr_bm[2] ? wr_data[23:16] : ram[write_address][23:16];
            ram[write_address][31:24] <= wr_bm[3] ? wr_data[31:24] : ram[write_address][31:24];
            ram[write_address][39:32] <= wr_bm[4] ? wr_data[39:32] : ram[write_address][39:32];
            ram[write_address][47:40] <= wr_bm[5] ? wr_data[47:40] : ram[write_address][47:40];
            ram[write_address][55:48] <= wr_bm[6] ? wr_data[55:48] : ram[write_address][55:48];
            ram[write_address][63:56] <= wr_bm[7] ? wr_data[63:56] : ram[write_address][63:56];
        end
    end
endmodule

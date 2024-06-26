module l2ram #(parameter isBOOTRAM = 0, parameter BOOTFILE = "") (
    input wire clk,
    input wire rd_en,
    input wire [10:0] rd_addr,
    output logic [127:0] rd_data,
    input wire [15:0] wr_en,
    input wire [10:0] wr_addr,
    input wire [127:0] wr_data
);
    reg [127:0] sram [0:2047];
    initial begin
        if (isBOOTRAM) begin
            $readmemh(BOOTFILE,sram);
        end
    end
    always_ff @(posedge clk) begin
        if (wr_en[15]) begin
            sram[wr_addr][127:120] <= wr_data[127:120];
        end
        if (wr_en[14]) begin
            sram[wr_addr][119:112] <= wr_data[119:112];
        end
        if (wr_en[13]) begin
            sram[wr_addr][111:104] <= wr_data[111:104];
        end
        if (wr_en[12]) begin
            sram[wr_addr][103:96] <= wr_data[103:96];
        end
        if (wr_en[11]) begin
            sram[wr_addr][95:88] <= wr_data[95:88];
        end
        if (wr_en[10]) begin
            sram[wr_addr][87:80] <= wr_data[87:80];
        end
        if (wr_en[9]) begin
            sram[wr_addr][79:72] <= wr_data[79:72];
        end
        if (wr_en[8]) begin
            sram[wr_addr][71:64] <= wr_data[71:64];
        end
        if (wr_en[7]) begin
            sram[wr_addr][63:56] <= wr_data[63:56];
        end
        if (wr_en[6]) begin
            sram[wr_addr][55:48] <= wr_data[55:48];
        end
        if (wr_en[5]) begin
            sram[wr_addr][47:40] <= wr_data[47:40];
        end
        if (wr_en[4]) begin
            sram[wr_addr][39:32] <= wr_data[39:32];
        end
        if (wr_en[3]) begin
            sram[wr_addr][31:24] <= wr_data[31:24];
        end
        if (wr_en[2]) begin
            sram[wr_addr][23:16] <= wr_data[23:16];
        end
        if (wr_en[1]) begin
            sram[wr_addr][15:8] <= wr_data[15:8];
        end
        if (wr_en[0]) begin
            sram[wr_addr][7:0] <= wr_data[7:0];
        end
        if (rd_en) begin
            rd_data <= sram[rd_addr];
        end
    end    
endmodule

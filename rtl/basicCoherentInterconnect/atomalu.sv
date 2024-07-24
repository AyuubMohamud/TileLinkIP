module atomalu #(parameter TL_DW = 32) (
    input   wire logic [2:0] opcode,
    input   wire logic [2:0] param,
    input   wire logic [TL_DW-1:0] cpu_data,
    input   wire logic [TL_DW-1:0] mem_data,
    output  wire logic [TL_DW-1:0] result
);
    localparam ARITHMETIC = 3'd2;
    
    wire [TL_DW-1:0] logical_result = param==0 ? cpu_data^mem_data : param==1 ? cpu_data|mem_data : param==2 ? cpu_data&mem_data : cpu_data;

    wire gt_30;
    assign gt_30 = cpu_data[TL_DW-2:0] > mem_data[TL_DW-2:0];
    logic mts;
    logic mtu;
    always_comb begin
        case ({cpu_data[TL_DW-1], mem_data[TL_DW-1], gt_30})
            3'b000: begin
                mts = 0; mtu = 0;
            end
            3'b001: begin
                mts = 1; mtu = 1;
            end
            3'b010: begin
                mts = 1; mtu = 0;
            end
            3'b011: begin
                mts = 1; mtu = 0;
            end
            3'b100: begin
                mts = 0; mtu = 1;
            end
            3'b101: begin
                mts = 0; mtu = 1;
            end
            3'b110: begin
                mts = 1; mtu = 0;
            end
            3'b111: begin
                mts = 0; mtu = 1;
            end
        endcase
    end
    wire mt;
    assign mt = !param[1] ? mts : mtu;
    wire [TL_DW-1:0] max;
    wire [TL_DW-1:0] min;
    assign max = mt ? cpu_data : mem_data;
    assign min = !mt ? cpu_data : mem_data;
    
    wire [TL_DW-1:0] arithmetic_result = {param[2], param[0]}==2'b00 ? min : {param[2],param[0]}==2'b01 ? max : cpu_data+mem_data;
    
    assign result = opcode==ARITHMETIC ? arithmetic_result : logical_result;
endmodule

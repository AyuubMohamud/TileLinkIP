module TileLinkSerialiser #(parameter MADRBITS = 32, parameter NoRPM = 2, parameter TUL = 2
) 
(
    input   wire logic                          l2_cache_clk_i,
    input   wire logic [2:0]                    l2_a_opcode_i [0:TUL+1],
    input   wire logic [2:0]                    l2_a_param_i [0:TUL+1],
    input   wire logic [7:0]                    l2_a_size_i [0:TUL+1],
    input   wire logic [$clog2(NoRPM)-1:0]      l2_a_source_i [0:TUL+1],
    input   wire logic [MADRBITS-1:0]           l2_a_address_i [0:TUL+1],
    input   wire logic [15:0]                   l2_a_mask_i [0:TUL+1],
    input   wire logic [127:0]                  l2_a_data_i [0:TUL+1],
    input   wire logic                          l2_a_corrupt_i [0:TUL+1],
    input   wire logic                          l2_a_valid_i [0:TUL+1],
    output  wire logic                          l2_a_ready_o [0:TUL+1],   

    input   wire logic                          l2_buffers_full_i,
    output  logic [2:0]                    l2_a_opcode_o,
    output  logic [2:0]                    l2_a_param_o,
    output  logic [7:0]                    l2_a_size_o,
    output  logic [$clog2(NoRPM)+$clog2(TUL+2)-1:0] l2_a_source_o,
    output  logic [MADRBITS-1:0]           l2_a_address_o,
    output  logic [15:0]                   l2_a_mask_o,
    output  logic [127:0]                  l2_a_data_o,
    output  logic                          l2_a_corrupt_o,
    output  logic                          l2_a_valid_o
);
    // Round robin arbitration
    reg [TUL+1:0] cycle;

    initial cycle = 'd1;

    wire logic [2:0]                    wk_l2_a_opcode_i [0:TUL+1];
    wire logic [2:0]                    wk_l2_a_param_i [0:TUL+1];
    wire logic [7:0]                    wk_l2_a_size_i [0:TUL+1];
    wire logic [$clog2(NoRPM)-1:0]      wk_l2_a_source_i [0:TUL+1];
    wire logic [MADRBITS-1:0]           wk_l2_a_address_i [0:TUL+1];
    wire logic [15:0]                   wk_l2_a_mask_i [0:TUL+1];
    wire logic [127:0]                  wk_l2_a_data_i [0:TUL+1];
    wire logic                          wk_l2_a_corrupt_i [0:TUL+1];
    wire logic [TUL+1:0]                wk_l2_a_valid_i;


    for (genvar i = 0; i < TUL+2; i++) begin : skidbuffers
        skdbf #(.DW(3+3+8+$clog2(NoRPM)+MADRBITS+16+128+1)) tilelink_a (l2_cache_clk_i, 1'b0, {
            l2_a_opcode_i [i],
            l2_a_param_i [i],
            l2_a_size_i [i],
            l2_a_source_i [i],
            l2_a_address_i [i],
            l2_a_mask_i [i],
            l2_a_data_i [i],
            l2_a_corrupt_i [i]
        }, cycle[i]&!l2_buffers_full_i, l2_a_valid_i[i], {
            wk_l2_a_opcode_i [i],
            wk_l2_a_param_i [i],
            wk_l2_a_size_i [i],
            wk_l2_a_source_i [i],
            wk_l2_a_address_i [i],
            wk_l2_a_mask_i [i],
            wk_l2_a_data_i [i],
            wk_l2_a_corrupt_i [i]
        }, l2_a_ready_o[i], wk_l2_a_valid_i[i]);
    end

    logic [$clog2(TUL+2)-1:0] cycle_entry;
    always_comb begin : priority_encoder0
        bit Break;
        Break = 0;
        cycle_entry = 'x;
        for (int i = 0; i < TUL+2; i++) begin : priority_encoder0
            if (wk_l2_a_valid_i[i]&cycle[i]&!l2_buffers_full_i&!Break) begin
                cycle_entry = i;
                Break = 1;
            end
        end
    end
    
    always_ff @(posedge l2_cache_clk_i) begin
        if (!l2_buffers_full_i&|wk_l2_a_valid_i) begin
            l2_a_address_o <= wk_l2_a_address_i[cycle_entry];
            l2_a_corrupt_o <= wk_l2_a_corrupt_i[cycle_entry];
            l2_a_data_o <= wk_l2_a_data_i[cycle_entry];
            l2_a_mask_o <= wk_l2_a_mask_i[cycle_entry];
            l2_a_opcode_o <= wk_l2_a_opcode_i[cycle_entry];
            l2_a_param_o <= wk_l2_a_param_i[cycle_entry];
            l2_a_size_o <= wk_l2_a_size_i[cycle_entry];
            l2_a_source_o <= {cycle_entry, wk_l2_a_source_i[cycle_entry]};
            l2_a_valid_o <= 1'b1;
        end else begin
            l2_a_valid_o <= 1'b0;
        end
    end
    always_ff @(posedge l2_cache_clk_i) begin
        if (!l2_buffers_full_i&|wk_l2_a_valid_i) begin
            cycle <= {cycle[TUL:0], cycle[TUL+1]};
        end
    end
endmodule

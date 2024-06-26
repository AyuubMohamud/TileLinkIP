module l2tags #(parameter TL_AW = 28) (
    input   wire logic              l2_clock_i,

    input   wire logic [TL_AW-8:0]  cache_line,
    output  wire logic [3:0]        set_bitvec,
    output  wire logic [3:0]        match_bitvec,
    output  wire logic [3:0]        total_match,
    output  wire logic              valid,
    output  wire logic [1:0]        set_enc,

    input   wire logic [TL_AW-8:0]  cache_line_insert,
    input   wire logic [1:0]        set_to_insert_in,
    input   wire logic              insert,
    input   wire logic              insert_present
);
    reg [(TL_AW-7-8)-1:0] tagWay0 [0:255]; reg [(TL_AW-7-8)-1:0] tagWay1 [0:255]; reg [(TL_AW-7-8)-1:0] tagWay2 [0:255]; reg [(TL_AW-7-8)-1:0] tagWay3 [0:255];
    reg valid0 [0:255]; reg valid1 [0:255]; reg valid2 [0:255]; reg valid3 [0:255];
    initial begin
        for (integer i = 0; i < 256; i++) begin
            valid0[i] = 0; tagWay0[i] = 0;
            valid1[i] = 0; tagWay1[i] = 0;
            valid2[i] = 0; tagWay2[i] = 0;
            valid3[i] = 0; tagWay3[i] = 0;
        end
    end
    wire [7:0] index = cache_line_insert[7:0];
    always_ff @(posedge l2_clock_i) begin
        if (insert) begin
            tagWay0[index] <= set_to_insert_in==2'b00 ? cache_line_insert[TL_AW-8:8] : tagWay0[index];
            tagWay1[index] <= set_to_insert_in==2'b01 ? cache_line_insert[TL_AW-8:8] : tagWay1[index];
            tagWay2[index] <= set_to_insert_in==2'b10 ? cache_line_insert[TL_AW-8:8] : tagWay2[index];
            tagWay3[index] <= set_to_insert_in==2'b11 ? cache_line_insert[TL_AW-8:8] : tagWay3[index];
            valid0[index] <= set_to_insert_in==2'b00 ? insert_present : valid0[index];
            valid1[index] <= set_to_insert_in==2'b01 ? insert_present : valid1[index];
            valid2[index] <= set_to_insert_in==2'b10 ? insert_present : valid2[index];
            valid3[index] <= set_to_insert_in==2'b11 ? insert_present : valid3[index];
        end
    end
    wire [7:0] index_r = cache_line[7:0];
    assign set_bitvec = {valid3[index_r], valid2[index_r], valid1[index_r], valid0[index_r]};
    assign match_bitvec = {tagWay3[index_r]==cache_line[TL_AW-8:8], tagWay2[index_r]==cache_line[TL_AW-8:8],
    tagWay1[index_r]==cache_line[TL_AW-8:8],tagWay0[index_r]==cache_line[TL_AW-8:8]};
    assign total_match = set_bitvec&match_bitvec;
    assign valid = |total_match;
    assign set_enc = total_match[0] ? 2'b00 : total_match[1] ? 2'b01 : total_match[2] ? 2'b10 : 2'b11;
endmodule

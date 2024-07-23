/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
module TileLinkBC #(
    parameter N = 3,
    parameter TL_DW = 32,
    parameter TL_AW = 32,
    parameter TL_SZ = 4
) (
    input   wire logic                          tilelink_clock_i,
    input   wire logic                          tilelink_reset_i,

    input   wire logic [2:0]                    master_a_opcode,
    input   wire logic [2:0]                    master_a_param,
    input   wire logic [TL_SZ-1:0]              master_a_size,
    input   wire logic [TL_AW-1:0]              master_a_address,
    input   wire logic [TL_DW/8-1:0]            master_a_mask,
    input   wire logic [TL_DW-1:0]              master_a_data,
    input   wire logic                          master_a_corrupt,
    input   wire logic                          master_a_valid,
    output  wire logic                          master_a_ready,


    output       logic [3*(N)-1:0]              slave_a_opcode,
    output       logic [3*(N)-1:0]              slave_a_param,
    output       logic [(N*TL_SZ)-1:0]          slave_a_size,
    output       logic [(TL_AW*N)-1:0]          slave_a_address,
    output       logic [(N*TL_DW/8)-1:0]        slave_a_mask,
    output       logic [N*TL_DW-1:0]            slave_a_data,
    output       logic [N-1:0]                  slave_a_corrupt,
    output       logic [N-1:0]                  slave_a_valid,
    input   wire logic [N-1:0]                  slave_a_ready
);
    // A channel is very simple, simple address decode and forward
    wire master_stalled;
    wire [2:0]                      working_master_a_opcode;
    wire [2:0]                      working_master_a_param;
    wire [TL_SZ-1:0]                working_master_a_size;
    wire [TL_AW-1:0]                working_master_a_address;
    wire [TL_DW/8-1:0]              working_master_a_mask;
    wire [TL_DW-1:0]                working_master_a_data;
    wire                            working_master_a_corrupt;
    wire                            working_master_a_valid;
    wire busy;
    assign master_a_ready = !busy;
    skdbf #(.DW(7+TL_DW/8+TL_DW + TL_SZ + TL_AW)) skidbuffer (
        tilelink_clock_i, tilelink_reset_i, master_stalled, {
            working_master_a_opcode,
            working_master_a_param,
            working_master_a_size,
            working_master_a_address,
            working_master_a_mask,
            working_master_a_data,
            working_master_a_corrupt
        }, working_master_a_valid, busy, {
            master_a_opcode,
            master_a_param,
            master_a_size,
            master_a_address,
            master_a_mask,
            master_a_data,
            master_a_corrupt
        }, master_a_valid
    );
    assign master_stalled = ~slave_a_ready;

    for (genvar i = 0; i < N; i++) begin : slaveRequest
        always_ff @(posedge tilelink_clock_i) begin : requestPrepare
            if (tilelink_reset_i) begin
                slave_a_valid[i] <= 1'b0;
            end
            else if (working_master_a_valid&slave_a_ready[i]) begin
                slave_a_address[(TL_AW*(i+1))-1:TL_AW*(i)] <= working_master_a_address;
                slave_a_corrupt[i] <= working_master_a_corrupt;
                slave_a_data[(TL_DW*(i+1))-1:TL_DW*(i)] <= working_master_a_data;
                slave_a_mask[((TL_DW/8)*(i+1))-1:(TL_DW/8)*(i)] <= working_master_a_mask;
                slave_a_opcode[3*(i+1)-1:3*i] <= working_master_a_opcode;
                slave_a_param[3*(i+1)-1:3*i] <= working_master_a_param;
                slave_a_size[4*(i+1)-1:4*i] <= working_master_a_size;
                slave_a_valid[i] <= 1'b1;
            end else if ((!working_master_a_valid)&slave_a_ready[i]) begin
                slave_a_valid[i] <= 1'b0;
            end
        end
    end
endmodule

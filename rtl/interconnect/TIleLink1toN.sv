//! TileLink 1 master to many slaves (Non-blocking)
module TileLink1toN #(
    parameter TLS = 2, //! Number of TileLink Slaves
    parameter TL_AW = 32, //! Address width
    parameter [(TL_AW*TLS)-1:0] slave_addresses = {
        32'h00001000,
        32'h00002000
    }, //! Base addresses of mentioned slaves
    parameter [(TL_AW*TLS)-1:0] slave_end_addresses = {
        32'h00002000,
        32'h10000000
    },
    parameter TIMEOUT = 1000000, //! Timeout in cycles elapsed since recieval
    parameter TL_RS = 2, //! log base 2 of IDs per master
    parameter TL_DW = 5, //! Log base 2 of data width
    parameter TL_SZ = 4
) (
    input   wire logic                          tilelink_clock_i,
    input   wire logic                          tilelink_reset_i,

    input   wire logic [2:0]                    master_a_opcode,
    input   wire logic [2:0]                    master_a_param,
    input   wire logic [TL_SZ-1:0]              master_a_size,
    input   wire logic [TL_RS-1:0]              master_a_source,
    input   wire logic [TL_AW-1:0]              master_a_address,
    input   wire logic [(2**TL_DW)/8-1:0]       master_a_mask,
    input   wire logic [(2**TL_DW)-1:0]         master_a_data,
    input   wire logic                          master_a_corrupt,
    input   wire logic                          master_a_valid,
    output  wire logic                          master_a_ready,

    output  wire logic [2:0]                    master_d_opcode,
    output  wire logic [1:0]                    master_d_param,
    output  wire logic [TL_SZ-1:0]              master_d_size,
    output  wire logic [TL_RS-1:0]              master_d_source,
    output  wire logic                          master_d_denied,
    output  wire logic [TL_DW-1:0]              master_d_data,
    output  wire logic                          master_d_corrupt,
    output  wire logic                          master_d_valid,
    input   wire logic                          master_d_ready,


    output  wire logic [3*(TLS)-1:0]            slave_a_opcode,
    output  wire logic [3*(TLS)-1:0]            slave_a_param,
    output  wire logic [(TLS*TL_SZ)-1:0]        slave_a_size,
    output  wire logic [(TLS*TL_RS)-1:0]        slave_a_source,
    output  wire logic [(TL_AW*TLS)-1:0]        slave_a_address,
    output  wire logic [(TLS*(2**TL_DW)/8)-1:0] slave_a_mask,
    output  wire logic [TLS*(2**TL_DW)-1:0]     slave_a_data,
    output  wire logic [TLS-1:0]                slave_a_corrupt,
    output  wire logic [TLS-1:0]                slave_a_valid,
    input   wire logic [TLS-1:0]                slave_a_ready,

    input   wire logic [(TLS*3)-1:0]            slave_d_opcode,
    input   wire logic [(TLS*2)-1:0]            slave_d_param,
    input   wire logic [(TLS*TL_SZ)-1:0]        slave_d_size,
    input   wire logic [(TLS*TL_RS)-1:0]        slave_d_source,
    input   wire logic [TLS-1:0]                slave_d_denied,
    input   wire logic [TLS*(2**TL_DW)-1:0]     slave_d_data,
    input   wire logic [TLS-1:0]                slave_d_corrupt,
    input   wire logic [TLS-1:0]                slave_d_valid,
    output  wire logic [TLS-1:0]                slave_d_ready
);
    // A channel is very simple, simple address decode and forward
    wire master_stalled;
    wire [2:0]                    working_master_a_opcode;
    wire [2:0]                    working_master_a_param;
    wire [TL_SZ-1:0]              working_master_a_size;
    wire [TL_RS-1:0]              working_master_a_source;
    wire [TL_AW-1:0]              working_master_a_address;
    wire [(2**TL_DW)/8-1:0]       working_master_a_mask;
    wire [(2**TL_DW)-1:0]         working_master_a_data;
    wire                          working_master_a_corrupt;
    wire                          working_master_a_valid;
    skdbf #(.DW(7+(2**TL_DW)/8+(2**TL_DW) + TL_SZ + TL_RS + TL_AW)) skidbuffer (
        tilelink_clock_i, tilelink_reset_i, master_stalled, {
            working_master_a_opcode,
            working_master_a_param,
            working_master_a_size,
            working_master_a_source,
            working_master_a_address,
            working_master_a_mask,
            working_master_a_data,
            working_master_a_corrupt
        }, working_master_a_valid, !master_a_ready, {
            master_a_opcode,
            master_a_param,
            master_a_size,
            master_a_source,
            master_a_address,
            master_a_mask,
            master_a_data,
            master_a_corrupt
        }, master_a_valid
    );
    // Now we have passed the inputs through the skidbuffer

    wire [TLS-1:0] slave_select;
    for (genvar x = 0; x < TLS; x++) begin : address_decode
        assign slave_select[x] = ((slave_addresses[(TL_AW*(x+1))-1:(TL_AW*x)]<=working_master_a_address)&&(slave_end_addresses[(TL_AW*(x+1))-1:(TL_AW*x)]>working_master_a_address)&working_master_a_valid);
    end

    assign master_stalled = |(slave_select&~slave_a_ready);

    for (genvar i = 0; i < TLS; i++) begin : slaveRequest
        always_ff @(posedge tilelink_clock_i) begin : requestPrepare
            if (working_master_a_valid&!master_stalled&slave_select[i]) begin
                slave_a_address[(TL_AW*(i+1))-1:TL_AW*(i)] <= working_master_a_address;
                slave_a_corrupt[i] <= working_master_a_corrupt;
                slave_a_data[((2**TL_DW)*(i+1))-1:(2**TL_DW)*(i)] <= working_master_a_data;
                slave_a_mask[((2**TL_DW/8)*(i+1))-1:(2**TL_DW/8)*(i)] <= working_master_a_mask;
                slave_a_opcode[3*(i+1)-1:3*i] <= working_master_a_opcode;
                slave_a_param[3*(i+1)-1:3*i] <= working_master_a_param;
                slave_a_size[4*(i+1)-1:4*i] <= working_master_a_size;
                slave_a_source[TL_RS*(i+1)-1:TL_RS*i] <= working_master_a_source;
                slave_a_valid[i] <= 1'b1;
            end else if ((!working_master_a_valid|!slave_select[i])&!master_stalled) begin
                slave_a_valid[i] <= 1'b0;
            end
        end
    end

    // Now to route many slaves to the one master
    wire [TLS-1:0] slaveResponseStalled;
    wire [(TLS*3)-1:0]            working_slave_d_opcode;
    wire [(TLS*2)-1:0]            working_slave_d_param;
    wire [(TLS*TL_SZ)-1:0]        working_slave_d_size;
    wire [(TLS*TL_RS)-1:0]        working_slave_d_source;
    wire [TLS-1:0]                working_slave_d_denied;
    wire [TLS*(2**TL_DW)-1:0]     working_slave_d_data;
    wire [TLS-1:0]                working_slave_d_corrupt;
    wire [TLS-1:0]                working_slave_d_valid;
    for (genvar i = 0; i < TLS; i++) begin : skidbufferInstantiation
        skdbf #(.DW(7+TL_SZ+TL_RS+(2**TL_DW))) slave_skidbuffer (tilelink_clock_i, tilelink_reset_i, slaveResponseStalled[i], {
            working_slave_d_opcode[(3)*(i+1)-1:(3)*(i)],
            working_slave_d_param[(2)*(i+1)-1:(2)*(i)],
            working_slave_d_size[(TL_SZ)*(i+1)-1:(TL_SZ)*(i)],
            working_slave_d_source[(TL_RS)*(i+1)-1:(TL_RS)*(i)],
            working_slave_d_denied[i],
            working_slave_d_data[(2**TL_DW)*(i+1)-1:(2**TL_DW)*(i)],
            working_slave_d_corrupt[i]
        }, working_slave_d_valid[i], slave_d_ready[i], {
            slave_d_opcode[(3)*(i+1)-1:(3)*(i)],
            slave_d_param[(2)*(i+1)-1:(2)*(i)],
            slave_d_size[(TL_SZ)*(i+1)-1:(TL_SZ)*(i)],
            slave_d_source[(TL_RS)*(i+1)-1:(TL_RS)*(i)],
            slave_d_denied[i],
            slave_d_data[(2**TL_DW)*(i+1)-1:(2**TL_DW)*(i)],
            slave_d_corrupt[i]
        }, slave_d_valid[i]);
    end
    reg [TLS-1:0] block;

`ifdef FORMAL
    
`endif
endmodule

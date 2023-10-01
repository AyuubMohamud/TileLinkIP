package tilelink_defines;
    localparam TL_AW = 32;
    localparam TL_DW = 32;
    localparam TL_RS = 3;
    localparam TL_BW = TL_DW/8;
    localparam TL_SZ = 2;
    localparam TL_DIW = 1;
endpackage

package tluh;
    typedef enum logic [2:0] {
        Get = 3'd4,
        ArithmeticData = 3'd2,
        LogicalData = 3'd3,
        Intent = 3'd5,
        PutPartialData = 3'd1,
        PutFullData = 3'd0
    } tluh_a_op;
    typedef enum logic [2:0] {
        AccessAck = 3'd0,
        AccessAckData = 3'd1,
        HintAck = 3'd2
    } tluh_d_op;
    typedef struct packed { 
        tluh_a_op a_opcode;
        logic [2:0] a_param;
        logic [tilelink_defines::TL_SZ-1:0] a_size;
        logic [tilelink_defines::TL_RS-1:0] a_source;
        logic [tilelink_defines::TL_AW-1:0] a_address;
        logic [tilelink_defines::TL_BW-1:0] a_mask;
        logic [tilelink_defines::TL_DW-1:0] a_data;
        logic a_corrupt;
        logic a_valid;
        logic d_ready;
    } tluh_m2s;
    typedef struct packed {
        tluh_d_op d_opcode;
        logic [1:0] d_param;
        logic [tilelink_defines::TL_SZ-1:0] d_size;
        logic [tilelink_defines::TL_RS-1:0] d_source;
        logic [tilelink_defines::TL_DIW-1:0] d_sink;
        logic d_denied;
        logic [tilelink_defines::TL_DW-1:0] d_data;
        logic d_corrupt;
        logic d_valid;
        logic a_ready;
    } tluh_s2m;
endpackage
module tilelink_xbr
#(
    parameter TLS = 1, //! Number of TileLink Lightweight slaves
    parameter TLM = 1, //! Number of TileLink Masters
    parameter [(tilelink_defines::TL_AW*TLS)-1:0] slave_addresses = {
        32'hFFFF0000
    }, //! Base addresses of mentioned slaves
    parameter [(tilelink_defines::TL_AW*TLS)-1:0] slave_end_addresses = {
        32'hFFFFFFFF
    }
) 
(
    input   wire logic              tilelink_clock_i,
    input   wire logic              tilelink_reset_i,

    input   tluh::tluh_m2s          tluh_i [0:TLM-1],
    output  tluh::tluh_s2m          tluh_o [0:TLM-1],

    output  tluh::tluh_m2s          d_tluh_o [0:TLS-1],
    input   tluh::tluh_s2m          d_tluh_i [0:TLS-1]
);
    //! This is a very simple interconnect.
    //! It only supports TileLink Uncached Heavyweight/Lightweight.
    //! This interconnect is to be used for hooking up peripherals. It can also hookup DDR memory if you so wish.
    //! To modify parameters like bus width and address space size please modify the above defines
    //! Slaves may be grouped together into a common address space to reduce complexity

    wire [TLS-1:0] slave_select [0:TLM-1];
    for (genvar i = 0; i < TLM; i++) begin : address_decode
        for (genvar x = 0; x < TLS; x++) begin : address_decode
            assign slave_select[i][x] = slave_addresses[(tilelink_defines::TL_AW*(x+1))-1:(tilelink_defines::TL_AW*x)]<=tluh_i[i].a_address&&slave_end_addresses[(tilelink_defines::TL_AW*(x+1))-1:(tilelink_defines::TL_AW*x)]>tluh_i[i].a_address;
        end
    end
    //! Now it has been determined which slave a master wants access to, let us state the following properties
    //! |slave_select[x]==0 means an interconnect error, and the master must be returned a d channel packet with d_denied high by the interconnect
    //! The slave select array MUST BE onehot or zero completely
    //! |&slave_select == 1 means that some masters are trying to access the same slave device
    wire [TLS-1:0] slave_conflict = &slave_select;
    
    // We now perform conflict resolution
    reg [TLM-1:0] deprioritise [0:TLS-1]; // set for a slave when slave_conflict[i] = 1, reset when slave_conflict[i] = 0

    for (genvar i = 0; i < TLM; i++) begin
        
    end

    always_ff @(posedge tilelink_clock_i) begin
        
    end




endmodule

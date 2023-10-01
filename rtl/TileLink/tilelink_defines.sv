package tilelink_defines;
    localparam TL_AW = 32;
    localparam TL_DW = 32;
    localparam TL_RS = 3;
    localparam TL_BW = TL_DW/8;
    localparam TL_SZ = 2;
    localparam TL_DIW = 1;
endpackage

package tlul_narrow;
    typedef enum logic [2:0] {
        Get = 3'd4,
        PutPartialData = 3'd1,
        PutFullData = 3'd0
    } tlul_a_op;
    typedef enum logic [2:0] {
        AccessAck = 3'd0,
        AccessAckData = 3'd1
    } tlul_d_op;
    typedef struct packed { 
        tlul_a_op a_opcode;
        logic [2:0] a_param;
        logic [tilelink_defines::TL_SZ-1:0] a_size;
        logic [tilelink_defines::TL_RS-1:0] a_source;
        logic [tilelink_defines::TL_AW-1:0] a_address;
        logic [tilelink_defines::TL_BW-1:0] a_mask;
        logic [tilelink_defines::TL_DW-1:0] a_data;
        logic a_corrupt;
        logic a_valid;
        logic d_ready;
    } tlul_m2s;
    typedef struct packed {
        tlul_d_op d_opcode;
        logic [1:0] d_param;
        logic [tilelink_defines::TL_SZ-1:0] d_size;
        logic [tilelink_defines::TL_RS-1:0] d_source;
        logic [tilelink_defines::TL_DIW-1:0] d_sink;
        logic d_denied;
        logic [tilelink_defines::TL_DW-1:0] d_data;
        logic d_corrupt;
        logic d_valid;
        logic a_ready;
    } tlul_s2m;
endpackage
package wide_tilelink_defines;
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
        logic [wide_tilelink_defines::TL_SZ-1:0] a_size;
        logic [wide_tilelink_defines::TL_RS-1:0] a_source;
        logic [wide_tilelink_defines::TL_AW-1:0] a_address;
        logic [wide_tilelink_defines::TL_BW-1:0] a_mask;
        logic [wide_tilelink_defines::TL_DW-1:0] a_data;
        logic a_corrupt;
        logic a_valid;
        logic d_ready;
    } tluh_m2s;
    typedef struct packed {
        tluh_d_op d_opcode;
        logic [1:0] d_param;
        logic [wide_tilelink_defines::TL_SZ-1:0] d_size;
        logic [wide_tilelink_defines::TL_RS-1:0] d_source;
        logic [wide_tilelink_defines::TL_DIW-1:0] d_sink;
        logic d_denied;
        logic [wide_tilelink_defines::TL_DW-1:0] d_data;
        logic d_corrupt;
        logic d_valid;
        logic a_ready;
    } tluh_s2m;
endpackage


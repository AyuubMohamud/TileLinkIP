/* verilator lint_off DECLFILENAME */
package clint_defines;
    localparam TL_AW = 16;
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
        logic [clint_defines::TL_SZ-1:0] a_size;
        logic [clint_defines::TL_RS-1:0] a_source;
        logic [clint_defines::TL_AW-1:0] a_address;
        logic [clint_defines::TL_BW-1:0] a_mask;
        logic [clint_defines::TL_DW-1:0] a_data;
        logic a_corrupt;
        logic a_valid;
    } tluh_m2s;
    typedef struct packed {
        tluh_d_op d_opcode;
        logic [1:0] d_param;
        logic [clint_defines::TL_SZ-1:0] d_size;
        logic [clint_defines::TL_RS-1:0] d_source;
        logic [clint_defines::TL_DIW-1:0] d_sink;
        logic d_denied;
        logic [clint_defines::TL_DW-1:0] d_data;
        logic d_corrupt;
        logic d_valid;
    } tluh_s2m;
endpackage


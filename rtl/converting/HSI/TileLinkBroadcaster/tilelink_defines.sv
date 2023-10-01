package wide_tilelink_defines;
    localparam TL_AW = 28;
    localparam TL_DW = 128;
    localparam TL_RS = 2;
    localparam TL_BW = TL_DW/8;
    localparam TL_SZ = 3;
    localparam TL_DIW = 1;
endpackage
package tluh_wide;
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

package tlc; // We use a seperate interconnect for coherent memory
    typedef enum logic [2:0] {
        AcquireBlock = 3'd6,
        AcquirePerm = 3'd7
    } tlc_a_op;
    typedef enum logic [2:0] {
        ProbeBlock = 3'd6,
        ProbePerm = 3'd7
    } tlc_b_op;
    typedef enum logic [2:0] {
        ProbeAck = 3'd4,
        ProbeAckData = 3'd5,
        Release = 3'd6,
        ReleaseData = 3'd7
    } tlc_c_op;
    typedef enum logic [2:0] {
        Grant = 3'd4,
        GrantData = 3'd5
    } tlc_d_op;
    typedef enum logic [2:0] {
        NtoB = 3'd0,
        NtoT = 3'd1,
        BtoT = 3'd2
    } tlc_grow;
    typedef enum logic [1:0] { 
        toN = 2'd0,
        toB = 2'd1,
        toT = 2'd2
    } tlc_cap;
    typedef enum logic [2:0] {
        TtoB = 3'd0,
        TtoN = 3'd1,
        BtoN = 3'd2,
        TtoT = 3'd3,
        BtoB = 3'd4,
        NtoN = 3'd5
    } tlc_sr;
    typedef struct packed { 
        tlc_a_op a_opcode;
        tlc_grow a_param;
        logic [wide_tilelink_defines::TL_SZ-1:0] a_size;
        logic [wide_tilelink_defines::TL_RS-1:0] a_source;
        logic [wide_tilelink_defines::TL_AW-1:0] a_address;
        logic [wide_tilelink_defines::TL_BW-1:0] a_mask;
        logic [wide_tilelink_defines::TL_DW-1:0] a_data;
        logic a_corrupt;
        logic a_valid;
        logic d_ready;
        logic b_ready;
        tlc_c_op c_opcode;
        tlc_sr c_param;
        logic [wide_tilelink_defines::TL_SZ-1:0] c_size;
        logic [wide_tilelink_defines::TL_RS-1:0] c_source;
        logic [wide_tilelink_defines::TL_AW-1:0] c_address;
        logic [wide_tilelink_defines::TL_BW-1:0] c_mask;
        logic [wide_tilelink_defines::TL_DW-1:0] c_data;
        logic c_corrupt;
        logic c_valid;
        logic [wide_tilelink_defines::TL_DIW-1:0] e_sink;
        logic e_valid;
    } tluh_m2s;
    typedef struct packed {
        tlc_d_op d_opcode;
        tlc_cap d_param;
        logic [wide_tilelink_defines::TL_SZ-1:0] d_size;
        logic [wide_tilelink_defines::TL_RS-1:0] d_source;
        logic [wide_tilelink_defines::TL_DIW-1:0] d_sink;
        logic d_denied;
        logic [wide_tilelink_defines::TL_DW-1:0] d_data;
        logic d_corrupt;
        logic d_valid;
        logic a_ready;
        logic c_ready;
        logic e_ready;
        tlc_b_op b_opcode;
        tlc_cap b_param;
        logic [wide_tilelink_defines::TL_SZ-1:0] b_size;
        logic [wide_tilelink_defines::TL_RS-1:0] b_source;
        logic [wide_tilelink_defines::TL_AW-1:0] b_address;
        logic [wide_tilelink_defines::TL_BW-1:0] b_mask;
        logic [wide_tilelink_defines::TL_DW-1:0] b_data;
        logic b_corrupt;
        logic b_valid;

    } tluh_s2m;
endpackage

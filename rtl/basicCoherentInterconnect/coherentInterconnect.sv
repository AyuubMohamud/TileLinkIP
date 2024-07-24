/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off WIDTHTRUNC */
module coherentInterconnect #(parameter TL_AW = 28, 
                              parameter TL_RS = 3,
                              parameter TL_UH_M = 1, 
                              parameter TL_UL_M = 1,
                              parameter TL_C_M = 2,
                              parameter TL_DW = 128) (
    input   wire logic                                                  interconnect_clock_i,
    input   wire logic                                                  interconnect_reset_i,
    input   wire logic [3*((TL_UH_M + TL_UL_M + TL_C_M))-1:0]           interconnect_a_opcode,
    input   wire logic [3*((TL_UH_M + TL_UL_M + TL_C_M))-1:0]           interconnect_a_param,
    input   wire logic [((TL_UH_M + TL_UL_M + TL_C_M)*4)-1:0]           interconnect_a_size,
    input   wire logic [((TL_UH_M + TL_UL_M + TL_C_M)*TL_RS)-1:0]       interconnect_a_source,
    input   wire logic [(TL_AW*(TL_UH_M + TL_UL_M + TL_C_M))-1:0]       interconnect_a_address,
    input   wire logic [((TL_UH_M + TL_UL_M + TL_C_M)*(TL_DW/8))-1:0]   interconnect_a_mask,
    input   wire logic [((TL_UH_M + TL_UL_M + TL_C_M)*TL_DW)-1:0]       interconnect_a_data,
    input   wire logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_a_corrupt,
    input   wire logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_a_valid,
    output  wire logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_a_ready,

    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*3)-1:0]           interconnect_d_opcode,
    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*2)-1:0]           interconnect_d_param,
    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*4)-1:0]           interconnect_d_size,
    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*TL_RS)-1:0]       interconnect_d_source,
    output       logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_d_denied,
    output       logic [((TL_UH_M + TL_UL_M + TL_C_M)*TL_DW)-1:0]       interconnect_d_data,
    output       logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_d_corrupt,
    output       logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_d_valid,
    input   wire logic [(TL_UH_M + TL_UL_M + TL_C_M)-1:0]               interconnect_d_ready,

    output       logic [(TL_C_M*3)-1:0]                                 coherentMaster_b_opcode,
    output       logic [(TL_C_M*3)-1:0]                                 coherentMaster_b_param,
    output       logic [(TL_C_M*4)-1:0]                                 coherentMaster_b_size,
    output       logic [(TL_C_M*TL_AW)-1:0]                             coherentMaster_b_address,
    output       logic [(TL_C_M*(TL_DW/8))-1:0]                         coherentMaster_b_mask,
    output       logic [(TL_C_M*TL_DW)-1:0]                             coherentMaster_b_data,
    output       logic [TL_C_M-1:0]                                     coherentMaster_b_corrupt,
    output       logic [TL_C_M-1:0]                                     coherentMaster_b_valid,
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_b_ready,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic [(TL_C_M*3)-1:0]                                 coherentMaster_c_opcode,
    input   wire logic [(TL_C_M*2)-1:0]                                 coherentMaster_c_param,
    input   wire logic [(TL_C_M*4)-1:0]                                 coherentMaster_c_size,
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_c_denied,
    input   wire logic [(TL_C_M*TL_DW)-1:0]                             coherentMaster_c_data,
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_c_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_c_valid,
    output  wire logic [TL_C_M-1:0]                                     coherentMaster_c_ready,
    input   wire logic [TL_C_M-1:0]                                     coherentMaster_e_valid,
    output  wire logic [TL_C_M-1:0]                                     coherentMaster_e_ready,

    output       logic [2:0]                                            memory_a_opcode,
    output       logic [2:0]                                            memory_a_param,
    output       logic [3:0]                                            memory_a_size,
    output       logic                                                  memory_a_source,
    output       logic [TL_AW-1:0]                                      memory_a_address,
    output       logic [TL_DW/8-1:0]                                    memory_a_mask,
    output       logic [TL_DW-1:0]                                      memory_a_data,
    output       logic                                                  memory_a_corrupt,
    output       logic                                                  memory_a_valid,
    input   wire logic                                                  memory_a_ready,

    input   wire logic [2:0]                                            memory_d_opcode,
    input   wire logic [1:0]                                            memory_d_param,
    input   wire logic [3:0]                                            memory_d_size,
    input   wire logic                                                  memory_d_source,
    input   wire logic                                                  memory_d_denied,
    input   wire logic [TL_DW-1:0]                                      memory_d_data,
    input   wire logic                                                  memory_d_corrupt,
    input   wire logic                                                  memory_d_valid,
    output  wire logic                                                  memory_d_ready
);
    localparam ACQUIREBLOCK = 3'd6;
    localparam GET = 3'd4;
    reg [TL_AW-7:0] reserved_address [0:TL_C_M-1];
    reg [TL_C_M-1:0] reservation_valid;
    wire logic [2:0]                    slave_a_opcode;
    /* verilator lint_off UNUSEDSIGNAL */
    wire logic [2:0]                    slave_a_param;
    wire logic [3:0]                    slave_a_size; 
    /**
        IMPORTANT WARNING: TL_C_M is ASSUMED to be the first TL_C_M IDs after TL_RS
    **/
    wire logic [($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:0] slave_a_source;
    wire logic [TL_AW-1:0]              slave_a_address;
    wire logic [(TL_DW/8)-1:0]          slave_a_mask;
    wire logic [TL_DW-1:0]              slave_a_data;
    wire logic                          slave_a_corrupt;
    /* verilator lint_on UNUSEDSIGNAL */
    wire logic                          slave_a_valid;
    wire logic                          slave_a_ready;
    logic [2:0]                         slave_d_opcode;
    logic [1:0]                         slave_d_param;
    logic [3:0]                         slave_d_size;
    logic [($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:0]  slave_d_source;
    logic                               slave_d_denied;
    logic [TL_DW-1:0]                   slave_d_data;
    logic                               slave_d_corrupt;
    logic                               slave_d_valid;
    wire logic                          slave_d_ready;

    TileLinkMto1 #(.M(TL_UH_M + TL_UL_M + TL_C_M), .TL_DW(TL_DW), .TL_AW(TL_AW), .TL_RS(TL_RS), .TL_SZ(4)) arbiter (interconnect_clock_i, interconnect_reset_i, interconnect_a_opcode,
    interconnect_a_param, interconnect_a_size, interconnect_a_source, interconnect_a_address, interconnect_a_mask, interconnect_a_data, interconnect_a_corrupt, 
    interconnect_a_valid, interconnect_a_ready, interconnect_d_opcode, interconnect_d_param, interconnect_d_size, interconnect_d_source, interconnect_d_denied, 
    interconnect_d_data, interconnect_d_corrupt, interconnect_d_valid, interconnect_d_ready,slave_a_opcode, slave_a_param, slave_a_size, slave_a_source, slave_a_address, 
    slave_a_mask, slave_a_data, slave_a_corrupt, slave_a_valid, slave_a_ready, slave_d_opcode, slave_d_param, slave_d_size, slave_d_source, slave_d_denied, slave_d_data, 
    slave_d_corrupt, slave_d_valid, slave_d_ready);
    assign coherentMaster_e_ready = 'hF;
    /* verilator lint_off UNUSEDSIGNAL */
    wire [2:0]                  working_memory_d_opcode;
    wire [1:0]                  working_memory_d_param;
    wire [3:0]                  working_memory_d_size;
    wire                        working_memory_d_source;
    wire                        working_memory_d_denied;
    wire [TL_DW-1:0]            working_memory_d_data;
    wire                        working_memory_d_corrupt;
    /* verilator lint_on UNUSEDSIGNAL */
    wire                        working_memory_d_valid;
    wire                        master_d_busy;
    assign memory_d_ready = ~master_d_busy;
    skdbf #(.DW(140)) ddr3skid (interconnect_clock_i, interconnect_reset_i, !slave_d_ready, {working_memory_d_opcode,
    working_memory_d_param,
    working_memory_d_size,
    working_memory_d_source,
    working_memory_d_denied,
    working_memory_d_data,
    working_memory_d_corrupt}, working_memory_d_valid, master_d_busy, {memory_d_opcode,
    memory_d_param,
    memory_d_size,
    memory_d_source,
    memory_d_denied,
    memory_d_data,
    memory_d_corrupt}, memory_d_valid);

    logic [2:0]                         coherence_b_opcode;
    logic [2:0]                         coherence_b_param;
    logic [3:0]                         coherence_b_size;
    logic [TL_AW-1:0]                   coherence_b_address;
    logic [TL_DW/8-1:0]                 coherence_b_mask;
    logic [TL_DW-1:0]                   coherence_b_data;
    logic                               coherence_b_corrupt;
    logic                               coherence_b_valid;
    wire logic                          coherence_b_ready;
    reg memory_response = 0;
    generate
        for (genvar i = 0; i < TL_C_M; i++) begin : _
            assign coherentMaster_c_ready[i] = (&coherentMaster_c_valid)&memory_response;
        end
    endgenerate
    
    
    generate if (TL_C_M > 1) begin : _ml
        TileLinkBC #(TL_C_M, TL_DW, TL_AW, 4) Deserialise (interconnect_clock_i, interconnect_reset_i,
        coherence_b_opcode, coherence_b_param, coherence_b_size, coherence_b_address, coherence_b_mask, coherence_b_data, coherence_b_corrupt, 
        coherence_b_valid, coherence_b_ready, coherentMaster_b_opcode, coherentMaster_b_param, coherentMaster_b_size, 
        coherentMaster_b_address, coherentMaster_b_mask, coherentMaster_b_data, coherentMaster_b_corrupt, coherentMaster_b_valid, coherentMaster_b_ready);
    end else begin : case_of_one
        assign coherentMaster_b_opcode=coherence_b_opcode;
        assign coherentMaster_b_param=coherence_b_param;
        assign coherentMaster_b_size=coherence_b_size;
        assign coherentMaster_b_address=coherence_b_address;
        assign coherentMaster_b_mask=coherence_b_mask;
        assign coherentMaster_b_data=coherence_b_data;
        assign coherentMaster_b_corrupt=coherence_b_corrupt;
        assign coherentMaster_b_valid=coherence_b_valid;
        assign coherence_b_ready=coherentMaster_b_ready;
    end
    endgenerate

    localparam interconnect_coherence_idle = 3'b000;
    localparam interconnect_read_memory = 3'b001;
    localparam interconnect_write_memory = 3'b010;
    localparam interconnect_await_ack = 3'b111;
    localparam interconnect_read_atomic = 3'b100;
    localparam interconnect_write_atomic = 3'b101;

    reg [2:0] interconnect_coherence_fsm = interconnect_coherence_idle;
    assign slave_a_ready = interconnect_coherence_fsm!=interconnect_coherence_idle;
    reg [($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:0] source = 0;
    reg [3:0] size = 0; reg [11:0] counter = 0; reg lr_sc = 0;
    reg [TL_DW-1:0] saved_data = 0; reg [2:0] saved_opcode = 0; reg [2:0] saved_param = 0;
    logic [11:0] number_to_write;
    wire [TL_C_M-1:0] grant_reservation;
    wire [TL_C_M-1:0] invalidate_reservation;
    wire [TL_C_M-1:0] successful_invalidate;
    generate
        for (genvar i = 0; i < TL_C_M; i++) begin : drive_reservations
            assign grant_reservation[i] = (interconnect_coherence_fsm==interconnect_read_memory)&(source[($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:TL_RS]==TL_C_M)&(lr_sc);
            assign invalidate_reservation[i] = (interconnect_coherence_fsm==interconnect_write_memory||
            interconnect_coherence_fsm==interconnect_write_atomic)&(memory_a_address[TL_AW-1:7]==reserved_address[i])
            && ((source[($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:TL_RS]!=TL_C_M)||((source[($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:TL_RS]==TL_C_M)&lr_sc));
            assign successful_invalidate[i] = (interconnect_coherence_fsm==interconnect_write_memory||
            interconnect_coherence_fsm==interconnect_write_atomic)&(memory_a_address[TL_AW-1:7]==reserved_address[i])
            &&(source[($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:TL_RS]==TL_C_M)&lr_sc&&reservation_valid[i];
            always_ff @(posedge interconnect_clock_i) begin
                if (interconnect_reset_i) begin
                    reserved_address[i] <= 0;
                    reservation_valid[i] <= 0;
                end else begin
                    if (grant_reservation[i]) begin
                        reserved_address[i] <= memory_a_address;
                        reservation_valid[i] <= 1;
                    end else if (invalidate_reservation[i]) begin
                        reservation_valid[i] <= 0;
                    end
                end
            end
        end
    endgenerate
    always_comb begin
        case (slave_a_size)
            4'd0: begin // 1 byte
                number_to_write = 0;
            end 
            4'd1: begin // 2 bytes
                number_to_write = 0;
            end
            4'd2: begin // 4 bytes
                number_to_write = 0;
            end 
            4'd3: begin // 8 bytes
                number_to_write = 0; // Minus 2 as when we have recieved 
            end
            4'd4: begin // 16 bytes
                number_to_write = TL_DW >= 128 ? 12'd0 : 128/TL_DW - 1;
            end
            4'd5: begin // 32 bytes
                number_to_write = TL_DW >= 256 ? 12'd0 : 256/TL_DW - 1;
            end
            4'd6: begin // 64 bytes
                number_to_write = 512/TL_DW - 1;
            end
            4'd7: begin // 128 bytes
                number_to_write = 1024/TL_DW - 1;
            end
            4'd8: begin // 256 bytes
                number_to_write = 2048/TL_DW - 1;
            end
            4'd9: begin // 512 bytes
                number_to_write = 4096/TL_DW - 1;
            end
            4'd10: begin // 1 kilobyte
                number_to_write = 8192/TL_DW - 1;
            end
            4'd11: begin // 2 kilobytes
                number_to_write = 16384/TL_DW - 1;
            end
            4'd12: begin // 4 kilobytes
                number_to_write = 32768/TL_DW - 1;
            end
            default: begin
                number_to_write = 12'd0;
            end
        endcase
    end
    /**
        How AMOs work:

        AMO Request comes here after CPU invalidates its own copy of cache line -> This fsm does the operation with the CPU provided data,
        goes through to DDR3

        This interconnect extends TileLink with the following:
        PutFullData with param = 1 is a store-conditional
        Get with param = 1 is a load-reserved

    **/
    wire [TL_DW-1:0] atom_result;
    atomalu #(.TL_DW(TL_DW)) alu (saved_opcode, saved_param, saved_data, working_memory_d_data, atom_result);
    wire origin_uncached = source[($clog2(TL_UH_M + TL_UL_M + TL_C_M)+TL_RS)-1:TL_RS]>($clog2(TL_C_M)-1);
    always_ff @(posedge interconnect_clock_i) begin
        case (interconnect_coherence_fsm)
            interconnect_coherence_idle: begin
                slave_d_valid <= slave_d_ready ? 1'b0 : slave_d_valid;
                if (slave_a_valid) begin
                    if (slave_a_opcode==ACQUIREBLOCK) begin
                        // Note, this can never be for an uncacheable block (obviously)
                        interconnect_coherence_fsm <= interconnect_read_memory;
                        memory_a_address <= slave_a_address;
                        memory_a_opcode <= 3'd4;
                        memory_a_size <= 4'd7;
                        memory_a_source <= 0;
                        memory_a_corrupt <= 0;
                        memory_a_param <= 0;
                        memory_a_valid <= 1;
                    end else if (slave_a_opcode==GET) begin
                        interconnect_coherence_fsm <= interconnect_read_memory;
                        memory_a_address <= slave_a_address;
                        memory_a_opcode <= 3'd4;
                        memory_a_size <= slave_a_size;
                        memory_a_source <= 0;
                        memory_a_corrupt <= 0;
                        memory_a_valid <= 1;
                        lr_sc <= slave_a_param[0];
                    end else if (slave_a_opcode==3'd0) begin
                        interconnect_coherence_fsm <= interconnect_write_memory;
                        memory_a_address <= slave_a_address;
                        memory_a_opcode <= 3'd0;
                        memory_a_size <= slave_a_size;
                        memory_a_source <= 0;
                        memory_a_corrupt <= 0;
                        memory_a_mask <= slave_a_mask;
                        memory_a_data <= slave_a_data;
                        memory_a_valid <= 1;
                        coherence_b_opcode <= 0;
                        coherence_b_param <= 0;
                        coherence_b_size <= slave_a_size;
                        coherence_b_address <= slave_a_address;
                        coherence_b_mask <= slave_a_mask;
                        coherence_b_data <= slave_a_data;
                        coherence_b_corrupt <= 0;
                        coherence_b_valid <= 1;
                    end else begin
                        memory_a_address <= slave_a_address;
                        memory_a_opcode <= 3'd4;
                        memory_a_size <= slave_a_size;
                        memory_a_source <= 0;
                        memory_a_corrupt <= 0;
                        memory_a_mask <= slave_a_mask;
                        memory_a_data <= slave_a_data;
                        memory_a_valid <= 1;
                        interconnect_coherence_fsm <= interconnect_read_atomic;
                    end
                    source <= slave_a_source;
                    size <= slave_a_size;
                    counter <= number_to_write;
                end
            end
            interconnect_read_memory: begin
                memory_a_valid <= memory_a_ready ? 1'b0 : memory_a_valid;
                if (working_memory_d_valid&(!slave_d_valid|slave_d_ready)) begin
                    slave_d_valid <= 1;
                    slave_d_data <= working_memory_d_data;
                    slave_d_denied <= 0; slave_d_corrupt <= 0; slave_d_param <= 0;
                    slave_d_source <= source; slave_d_size <= size;
                    slave_d_opcode <= 1;
                end else if ((!slave_d_valid|slave_d_ready)) begin
                    slave_d_valid <= 0;
                end
                if ((counter==0)&working_memory_d_valid&(!slave_d_valid|slave_d_ready)) begin
                    interconnect_coherence_fsm <= origin_uncached ? interconnect_coherence_idle : interconnect_await_ack;
                    lr_sc <= 0;
                end else if (working_memory_d_valid&(!slave_d_valid|slave_d_ready)) begin
                    counter <= counter - 1;
                end
            end
            interconnect_write_memory: begin
                memory_a_valid <= memory_a_ready ? 1'b0 : memory_a_valid;
                coherence_b_valid <= coherence_b_ready ? 1'b0 : coherence_b_valid;
                if (working_memory_d_valid) begin
                    memory_response <= 1;
                end
                if (coherentMaster_c_ready) begin
                    lr_sc <= 0;
                    memory_response <= 0;
                    slave_d_valid <= 1;
                    slave_d_data <= 0;
                    slave_d_denied <= lr_sc&!(|successful_invalidate); slave_d_corrupt <= 0; slave_d_param <= 0;
                    slave_d_source <= source; slave_d_size <= size;
                    slave_d_opcode <= 0;
                    interconnect_coherence_fsm <= origin_uncached ? interconnect_coherence_idle : interconnect_await_ack;
                    lr_sc <= 0;
                end
            end
            interconnect_read_atomic: begin
                memory_a_valid <= memory_a_ready ? 1'b0 : memory_a_valid;
                if (working_memory_d_valid) begin
                    interconnect_coherence_fsm <= interconnect_write_atomic;
                    memory_a_address <= slave_a_address;
                    memory_a_opcode <= 3'd0;
                    memory_a_size <= $clog2(TL_DW/8);
                    memory_a_source <= 0;
                    memory_a_corrupt <= 0;
                    memory_a_mask <= 'hF;
                    memory_a_data <= atom_result;
                    memory_a_valid <= 1;
                    saved_data <= working_memory_d_data;
                    coherence_b_opcode <= 0;
                    coherence_b_param <= 0;
                    coherence_b_size <= $clog2(TL_DW/8);
                    coherence_b_address <= memory_a_address;
                    coherence_b_mask <= 'hF;
                    coherence_b_data <= atom_result;
                    coherence_b_corrupt <= 0;
                    coherence_b_valid <= 1;
                end
            end
            interconnect_write_atomic: begin
                memory_a_valid <= memory_a_ready ? 1'b0 : memory_a_valid;
                coherence_b_valid <= coherence_b_ready ? 1'b0 : coherence_b_valid;
                if (working_memory_d_valid) begin
                    memory_response <= 1;
                end
                if (coherentMaster_c_ready) begin
                    memory_response <= 0;
                    slave_d_valid <= 1;
                    slave_d_data <= saved_data;
                    slave_d_denied <= 0; slave_d_corrupt <= 0; slave_d_param <= 0;
                    slave_d_source <= source; slave_d_size <= size;
                    slave_d_opcode <= 1;
                    interconnect_coherence_fsm <= origin_uncached ? interconnect_coherence_idle : interconnect_await_ack;
                    lr_sc <= 0;
                end
            end
            interconnect_await_ack: begin
                slave_d_valid <= slave_d_ready ? 1'b0 : slave_d_valid;
                if (|coherentMaster_e_valid) begin
                    interconnect_coherence_fsm <= interconnect_coherence_idle;
                end
            end
            default: begin
                
            end
        endcase
    end
endmodule
/* verilator lint_on WIDTHEXPAND */
/* verilator lint_on WIDTHTRUNC */

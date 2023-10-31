module openPolarisSRAM #(
    parameter TL_RS = 4,
    parameter TL_AW = 2
    ) (
    input   wire logic                          sram_clock_i,
    input   wire logic                          sram_reset_i,

    // Slave interface
    input   wire logic [2:0]                    sram_a_opcode,
    input   wire logic [2:0]                    sram_a_param,
    input   wire logic [3:0]                    sram_a_size,
    input   wire logic [TL_RS-1:0]              sram_a_source,
    input   wire logic [TL_AW-1:0]              sram_a_address,
    input   wire logic [3:0]                    sram_a_mask,
    input   wire logic [31:0]                   sram_a_data,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic                          sram_a_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic                          sram_a_valid,
    output  wire logic                          sram_a_ready,

    output       logic [2:0]                    sram_d_opcode,
    output       logic [1:0]                    sram_d_param,
    output       logic [3:0]                    sram_d_size,
    output       logic [TL_RS-1:0]              sram_d_source,
    output       logic                          sram_d_denied,
    output       logic [31:0]                   sram_d_data,
    output       logic                          sram_d_corrupt,
    output       logic                          sram_d_valid,
    input   wire logic                          sram_d_ready
);
    reg [31:0] sram [0:2**TL_AW-1];
    reg reset;
    initial reset = 0;
    reg pause;
    initial pause = 0;
    reg burst;
    initial burst = 0;
    reg read;
    initial read = 0;
    reg atomic_in_progress;
    initial atomic_in_progress = 0;
    wire sram_busy;
    wire [TL_RS-1:0] working_source;
    wire [3:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire [TL_AW-1:0] working_address;
    wire [2:0] working_param;
    wire working_valid;
    skdbf #(TL_RS+4+42+TL_AW) skidbuffer (sram_clock_i, sram_reset_i|reset, ~sram_d_ready|reset|pause|read, {
        working_source,
        working_size,
        working_data,
        working_mask,
        working_opcode,
        working_address,
        working_param
    }, working_valid, sram_busy, {
        sram_a_source, sram_a_size, sram_a_data, sram_a_mask, sram_a_opcode, sram_a_address, sram_a_param
    }, sram_a_valid);
    assign sram_a_ready = ~sram_busy;

    // This supports all features of TLUL/TLUH

    localparam Get = 3'd4;
    localparam PutFullData = 3'd0;
    localparam PutPartialData = 3'd1;
    localparam ArithmeticData = 3'd2;
    localparam LogicalData = 3'd3;

    /*
        If Burst contiguity is assumed, mask is contigous for atomics etc
    */

    reg [11:0] burst_counters;
    logic [11:0] number_to_write;
    reg [11:0] addresser;
    initial addresser = 0;
    initial burst_counters = 0;
    always_comb begin
        case (working_size)
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
                number_to_write = 12'd0; // Minus 2 as when we have recieved 
            end
            4'd4: begin // 16 bytes
                number_to_write = 12'd2;
            end
            4'd5: begin // 32 bytes
                number_to_write = 12'd6;
            end
            4'd6: begin // 64 bytes
                number_to_write = 12'd14;
            end
            4'd7: begin // 128 bytes
                number_to_write = 12'd30;
            end
            4'd8: begin // 256 bytes
                number_to_write = 12'd62;
            end
            4'd9: begin // 512 bytes
                number_to_write = 12'd126;
            end
            4'd10: begin // 1 kilobyte
                number_to_write = 12'd254;
            end
            4'd11: begin // 2 kilobytes
                number_to_write = 12'd510;
            end
            4'd12: begin // 4 kilobytes
                number_to_write = 12'd1022;
            end
            default: begin
                number_to_write = 12'd0;
            end
        endcase
    end 
    reg [3:0] sizer;
    initial sizer = 0;
    reg [TL_RS-1:0] sourcer;
    initial sourcer = 0;
    reg [TL_AW-1:0] read_addresser;
    initial read_addresser = 0;
    always_ff @(posedge sram_clock_i) begin
        if ((working_valid|read|pause)&!(~sram_d_ready|reset)) begin
            if (!burst) begin
                burst_counters <= working_opcode==LogicalData||working_opcode==ArithmeticData ? number_to_write+1 : number_to_write;
                addresser <= (working_size > 4'd2) ? working_opcode==LogicalData||working_opcode==ArithmeticData ? addresser : addresser + 1'b1 : addresser;
                burst <= working_size > 4'd2;
                read <= (working_opcode==Get)&&(working_size > 4'd2);
                sizer <= working_size;
                sourcer <= working_source;
                read_addresser <= working_address;
                atomic_in_progress <= (working_opcode==LogicalData||working_opcode==ArithmeticData)&(working_size > 4'd2);
            end else if ((atomic_in_progress&pause||!atomic_in_progress)) begin
                if (burst_counters != 0) begin
                    burst_counters <= burst_counters - 1'b1;
                    addresser <= addresser + 1'b1;
                end else begin
                    addresser <= 12'd0;
                    burst <= 1'b0;
                    read <= 1'b0;
                    atomic_in_progress <= 1'b0;
                end
            end
        end
    end
    reg arithmetic;
    initial arithmetic = 0;
    reg [2:0] param;
    initial param = 0;
    reg [31:0] data;
    initial data = 0;
    always_ff @(posedge sram_clock_i) begin : pause_logic
        if (sram_reset_i|reset) begin
            pause <= 1'b0;
        end
        else if (working_valid&!(~sram_d_ready|pause)) begin
            pause <= working_opcode == ArithmeticData||working_opcode == LogicalData;
            arithmetic <= working_opcode == ArithmeticData;
            param <= working_param;
            data <= working_data;
        end else if (pause&sram_d_ready) begin
            pause <= 1'b0;
        end
    end
    reg [TL_AW-1:0] counter;
    initial counter = 0;
    logic [31:0] atomic;
    always_comb begin
        case ({arithmetic, param})
            4'b0000: begin
                atomic = sram_d_data^data;
            end
            4'b0001: begin
                atomic = sram_d_data|data;
            end
            4'b0010: begin
                atomic = sram_d_data&data;
            end
            4'b0011: begin
                atomic = data;
            end
            4'b1100: begin
                atomic = sram_d_data+data;
            end
            default: begin
                atomic = 0;
            end
        endcase
    end
    wire [TL_AW-1:0] sram_address = reset ? counter : read ? read_addresser+addresser[(TL_AW<12 ? TL_AW-1 : 11) : 0] : burst ? working_address+addresser[(TL_AW<12 ? TL_AW-1 : 11) : 0] : working_address;
    wire [31:0] sram_data = reset ? 32'h00000000 : pause ? atomic : working_data;
    wire [3:0] wr_enable = {
        (reset)|((pause||working_valid&(working_opcode==PutFullData||working_opcode==PutPartialData)&working_mask[3])&sram_d_ready),
        (reset)|((pause||working_valid&(working_opcode==PutFullData||working_opcode==PutPartialData)&working_mask[2])&sram_d_ready),
        (reset)|((pause||working_valid&(working_opcode==PutFullData||working_opcode==PutPartialData)&working_mask[1])&sram_d_ready),
        (reset)|((pause||working_valid&(working_opcode==PutFullData||working_opcode==PutPartialData)&working_mask[0])&sram_d_ready)
    };
    always_ff @(posedge sram_clock_i) begin
        sram[sram_address][7:0] <= wr_enable[0] ? sram_data[7:0] : sram[sram_address][7:0];
        sram[sram_address][15:8] <= wr_enable[1] ? sram_data[15:8] : sram[sram_address][15:8];
        sram[sram_address][23:16] <= wr_enable[2] ? sram_data[23:16] : sram[sram_address][23:16];
        sram[sram_address][31:24] <= wr_enable[3] ? sram_data[31:24] : sram[sram_address][31:24];
    end
    always_ff @(posedge sram_clock_i) begin : sram_reset_logic
        case (reset)
            1'b0: begin
                reset <= sram_reset_i;
                counter <= 0;
            end
            1'b1: begin
                counter <= counter + 1'b1;
                reset <= !(&counter);
            end
        endcase
    end
    
    always_ff @(posedge sram_clock_i) begin
        if (sram_reset_i|reset) begin
            sram_d_valid <= 1'b0;
        end
        else if ((working_valid|read)&!(pause|~sram_d_ready)) begin
            sram_d_corrupt <= 1'b0;
            sram_d_denied <= 1'b0;
            sram_d_opcode <= read ? 3'd1 : working_opcode==PutFullData||working_opcode==PutPartialData ? 3'd0 : 3'd1;
            sram_d_param <= 2'b0;
            sram_d_size <= read ? sizer : working_size;
            sram_d_source <= read ? sourcer : working_source;
            sram_d_valid <= 1'b1;
            sram_d_data <= sram[sram_address];
        end
        else if (working_valid&pause) begin
            sram_d_valid <= sram_d_valid&!sram_d_ready;
        end else if (!working_valid&(!read|pause)&sram_d_ready) begin
            sram_d_valid <= 1'b0;
        end
    end
`ifdef FORMAL
    reg past_valid;
    (* anyconst *)  wire [TL_AW-1:0] f_addr;
    reg [31:0] f_data;
    initial begin
        assume(sram_reset_i == 1'b0);
        assume(pause == 1'b0);
        assume(burst == 1'b0);
        assume(read == 1'b0);
        assume(reset == 1'b0);
        assume(burst_counters==0);
        assume(sram_a_ready==1'b1);
        past_valid = 1'b0;
        assume(sram_d_data == 0);
        for (integer i = 0; i < 2**TL_AW; i++) begin
            sram[i] = 0;
        end
        f_data = 0;
    end
    always_comb begin
        assume(slave_a_opcode!=3'd2&&slave_a_opcode!=3'd3&&slave_a_opcode!=3'd7);
    end
    always_ff @(posedge sram_clock_i) begin
        past_valid <= 1'b1;
    end
//
    // Verify normal reads
    always_ff @(posedge sram_clock_i) begin
        if (past_valid) begin
            if ($past(working_opcode)==Get && !$past(~sram_d_ready|reset|pause|read|burst) && !$past(working_size>4'd2) && $past(working_valid) && !sram_reset_i && !reset&&($past(working_address==f_addr))) begin
                assert(sram_d_data==f_data);
                assert(sram_d_valid);
            end
        end
    end
    // Verify normal writes
    always_ff @(posedge sram_clock_i) begin
        if (sram_reset_i|reset) begin
            f_data <= 0;
        end else begin
            if (((working_opcode)==PutFullData||(working_opcode)==PutPartialData) && !(~sram_d_ready|reset|pause|read|burst) && !(working_size>4'd2) && working_valid && (f_addr==working_address)) begin
                if (working_mask[0]) begin
                    f_data[7:0] <= sram_data[7:0];
                end else begin
                    f_data[7:0] <= f_data[7:0];
                end
                if (working_mask[1]) begin
                    f_data[15:8] <= sram_data[15:8];
                end else begin
                    f_data[15:8] <= f_data[15:8];
                end
                if (working_mask[2]) begin
                    f_data[23:16] <= sram_data[23:16];
                end else begin
                    f_data[23:16] <= f_data[23:16];
                end
                if (working_mask[3]) begin
                    f_data[31:24] <= sram_data[31:24];
                end else begin
                    f_data[31:24] <= f_data[31:24];
                end   
        end
        end
    end

    wire [TL_RS:0] outstanding;
    initial assume(sram_a_ready == sram_d_ready);
    tluh_slave_formal #(.AW(TL_AW), .RS(TL_RS), .MAX(2), .ATOMIC(0), .BURST(1)) formal (
        sram_clock_i,
        sram_reset_i|reset,
        sram_a_opcode,
        sram_a_param,
        sram_a_size,
        sram_a_source,
        sram_a_address,
        sram_a_mask,
        sram_a_data,
        sram_a_corrupt,
        sram_a_valid,
        sram_a_ready,
        sram_d_opcode,
        sram_d_param,
        sram_d_size,
        sram_d_source,
        sram_d_denied,
        sram_d_data,
        sram_d_corrupt,
        sram_d_valid,
        sram_d_ready,
        burst_counters,
        outstanding
    );

`endif
endmodule

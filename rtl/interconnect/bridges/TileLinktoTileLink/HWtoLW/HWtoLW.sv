module HWtoLW #(parameter TL_RS = 4, parameter TL_AW = 28) (
    input   wire logic                          tilelink_clock_i,
    input   wire logic                          tilelink_reset_i,
    // Slave interface
    input   wire logic [2:0]                    hw_a_opcode,
    input   wire logic [2:0]                    hw_a_param,
    input   wire logic [3:0]                    hw_a_size,
    input   wire logic [TL_RS-1:0]              hw_a_source,
    input   wire logic [TL_AW-1:0]              hw_a_address,
    input   wire logic [3:0]                    hw_a_mask,
    input   wire logic [31:0]                   hw_a_data,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic                          hw_a_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic                          hw_a_valid,
    output  wire logic                          hw_a_ready,

    output       logic [2:0]                    hw_d_opcode,
    output       logic [1:0]                    hw_d_param,
    output       logic [3:0]                    hw_d_size,
    output       logic [TL_RS-1:0]              hw_d_source,
    output       logic                          hw_d_denied,
    output       logic [31:0]                   hw_d_data,
    output       logic                          hw_d_corrupt,
    output       logic                          hw_d_valid,
    input   wire logic                          hw_d_ready,

    output       logic [2:0]                    lw_a_opcode,
    output       logic [2:0]                    lw_a_param,
    output       logic [3:0]                    lw_a_size,
    output       logic [TL_AW-1:0]              lw_a_address,
    output       logic [3:0]                    lw_a_mask,
    output       logic [31:0]                   lw_a_data,
    output       logic [TL_RS-1:0]              lw_a_source,
    output       logic                          lw_a_corrupt,
    output       logic                          lw_a_valid,
    input   wire logic                          lw_a_ready,

    input   wire logic [2:0]                    lw_d_opcode,
    input   wire logic [1:0]                    lw_d_param,
    input   wire logic [3:0]                    lw_d_size,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic                          lw_d_denied,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic [31:0]                   lw_d_data,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic                          lw_d_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic [TL_RS-1:0]              lw_d_source,
    input   wire logic                          lw_d_valid,
    output  wire logic                          lw_d_ready
);
    
    wire bridge_busy;
    wire [TL_RS-1:0] working_source;
    wire [3:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire [TL_AW-1:0] working_address;
    wire [2:0] working_param;
    wire working_valid;
    reg [11:0] read_burst_counter;
    reg read_burst;
    wire lw_busy = read_burst|~lw_a_ready;
    reg [TL_AW-1:0] addresser;
    assign hw_a_ready = ~bridge_busy;
    skdbf #(TL_RS+4+42+TL_AW) skidbuffer (tilelink_clock_i, tilelink_reset_i, lw_busy|read_burst, {
        working_source,
        working_size,
        working_data,
        working_mask,
        working_opcode,
        working_address,
        working_param
    }, working_valid, bridge_busy, {
        hw_a_source, hw_a_size, hw_a_data, hw_a_mask, hw_a_opcode, hw_a_address, hw_a_param
    }, hw_a_valid);
    logic [11:0] number_to_write;
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
                number_to_write = 0; // Minus 2 as when we have recieved 
            end
            4'd4: begin // 16 bytes
                number_to_write = 2;
            end
            4'd5: begin // 32 bytes
                number_to_write = 6;
            end
            4'd6: begin // 64 bytes
                number_to_write = 512/32 - 2;
            end
            4'd7: begin // 128 bytes
                number_to_write = 1024/32 - 2;
            end
            4'd8: begin // 256 bytes
                number_to_write = 2048/32 - 2;
            end
            4'd9: begin // 512 bytes
                number_to_write = 4096/32 - 2;
            end
            4'd10: begin // 1 kilobyte
                number_to_write = 8192/32 - 2;
            end
            4'd11: begin // 2 kilobytes
                number_to_write = 16384/32 - 2;
            end
            4'd12: begin // 4 kilobytes
                number_to_write = 32768/32 - 2;
            end
            default: begin
                number_to_write = 12'd0;
            end
        endcase
    end 
    wire [TL_AW-1:0] current_address = addresser+4;
    always_ff @(posedge tilelink_clock_i) begin
        if (lw_a_ready&(read_burst)) begin
            lw_a_valid <= 1;
            lw_a_address <= current_address;
            lw_a_corrupt <= 0;
            lw_a_opcode <= 3'd4;
            lw_a_param <= 0;
            lw_a_size <= 4'd2;
            read_burst_counter <= read_burst_counter==0 ? 0 : read_burst_counter-1;
            read_burst <= read_burst_counter!=0;
        end
        else if (lw_a_ready&(working_valid)) begin
            lw_a_valid <= 1;
            lw_a_address <= read_burst ? current_address : working_address;
            lw_a_corrupt <= 0;
            lw_a_opcode <= working_opcode;
            lw_a_data <= working_data;
            lw_a_mask <= working_mask;
            lw_a_param <= working_param;
            lw_a_size <= working_size > 4'd2 ? 4'd2 : working_size;
            lw_a_source <= working_source;
            read_burst <= (working_opcode==4)&&(working_size>4'd2);
            addresser <= working_address;
            read_burst_counter <= number_to_write;
        end else if (lw_a_ready&!(working_valid|read_burst)) begin
            lw_a_valid <= 0;
        end
    end
    // count acknowledgements, set write ack when acknowledgement can be sent to hw
    wire [TL_RS-1:0] lw_working_source;
    wire [3:0] lw_working_size;
    wire [31:0] lw_working_data;
    wire [2:0] lw_working_opcode;
    wire [1:0] lw_working_param;
    wire lw_working_valid;
    wire hw_busy = ~hw_d_ready;
    wire hw_bridge_busy;

    assign lw_d_ready = ~hw_bridge_busy;
    skdbf #(TL_RS+4+37) skidbuffer2 (tilelink_clock_i, tilelink_reset_i, hw_busy, {
        lw_working_source,
        lw_working_size,
        lw_working_data,
        lw_working_opcode,
        lw_working_param
    }, lw_working_valid, hw_bridge_busy, {
        lw_d_source, lw_d_size, lw_d_data, lw_d_opcode, lw_d_param
    }, lw_d_valid);
    always_ff @(posedge tilelink_clock_i) begin
        if (hw_d_ready&((lw_working_valid))) begin
            hw_d_valid <= 1;
            hw_d_corrupt <= 0;
            hw_d_data <= lw_working_data;
            hw_d_opcode <= lw_working_opcode;
            hw_d_param <= lw_working_param;
            hw_d_denied <= 0;
            hw_d_size <= lw_working_size;
            hw_d_source <= lw_working_source;
        end else if (hw_d_ready&~(lw_working_valid)) begin
            hw_d_valid <= 0;
        end
    end 
endmodule

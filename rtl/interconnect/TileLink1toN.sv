//! TileLink 1 master to many slaves (Non-blocking)

module TileLink1toN #(
    parameter [(32*2)-1:0] slave_addresses = {
        32'h00001000,
        32'h00002000
    }, //! Base addresses of mentioned slaves
    parameter [(32*2)-1:0] slave_end_addresses = {
        32'h00002000,
        32'h10000000
    }
) (
    input   wire logic                          tilelink_clock_i,
    input   wire logic                          tilelink_reset_i,

    input   wire logic [2:0]                    master_a_opcode,
    input   wire logic [2:0]                    master_a_param,
    input   wire logic [4-1:0]              master_a_size,
    input   wire logic [4-1:0]              master_a_source,
    input   wire logic [32-1:0]              master_a_address,
    input   wire logic [(2**5)/8-1:0]       master_a_mask,
    input   wire logic [(2**5)-1:0]         master_a_data,
    input   wire logic                          master_a_corrupt,
    input   wire logic                          master_a_valid,
    output  wire logic                          master_a_ready,

    output  wire logic [2:0]                    master_d_opcode,
    output  wire logic [1:0]                    master_d_param,
    output  wire logic [4-1:0]              master_d_size,
    output  wire logic [4-1:0]              master_d_source,
    output  wire logic                          master_d_denied,
    output  wire logic [(2**5)-1:0]         master_d_data,
    output  wire logic                          master_d_corrupt,
    output  wire logic                          master_d_valid,
    input   wire logic                          master_d_ready,


    output  wire logic [3*(2)-1:0]            slave_a_opcode,
    output  wire logic [3*(2)-1:0]            slave_a_param,
    output  wire logic [(2*4)-1:0]        slave_a_size,
    output  wire logic [(2*4)-1:0]        slave_a_source,
    output  wire logic [(32*2)-1:0]        slave_a_address,
    output  wire logic [(2*(2**5)/8)-1:0] slave_a_mask,
    output  wire logic [2*(2**5)-1:0]     slave_a_data,
    output  wire logic [2-1:0]                slave_a_corrupt,
    output  wire logic [2-1:0]                slave_a_valid,
    input   wire logic [2-1:0]                slave_a_ready,

    input   wire logic [(2*3)-1:0]            slave_d_opcode,
    input   wire logic [(2*2)-1:0]            slave_d_param,
    input   wire logic [(2*4)-1:0]        slave_d_size,
    input   wire logic [(2*4)-1:0]        slave_d_source,
    input   wire logic [2-1:0]                slave_d_denied,
    input   wire logic [2*(2**5)-1:0]     slave_d_data,
    input   wire logic [2-1:0]                slave_d_corrupt,
    input   wire logic [2-1:0]                slave_d_valid,
    output  wire logic [2-1:0]                slave_d_ready
);
    // A channel is very simple, simple address decode and forward
    wire master_stalled;
    wire [2:0]                    working_master_a_opcode;
    wire [2:0]                    working_master_a_param;
    wire [4-1:0]              working_master_a_size;
    wire [4-1:0]              working_master_a_source;
    wire [32-1:0]              working_master_a_address;
    wire [(2**5)/8-1:0]       working_master_a_mask;
    wire [(2**5)-1:0]         working_master_a_data;
    wire                          working_master_a_corrupt;
    wire                          working_master_a_valid;
    wire busy;
    assign master_a_ready = !busy;
    skdbf #(.DW(7+(2**5)/8+(2**5) + 4 + 4 + 32)) skidbuffer (
        tilelink_clock_i, tilelink_reset_i, master_stalled, {
            working_master_a_opcode,
            working_master_a_param,
            working_master_a_size,
            working_master_a_source,
            working_master_a_address,
            working_master_a_mask,
            working_master_a_data,
            working_master_a_corrupt
        }, working_master_a_valid, busy, {
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

    wire [2-1:0] slave_select;
    for (genvar x = 0; x < 2; x++) begin : address_decode
        assign slave_select[x] = ((slave_addresses[(32*(x+1))-1:(32*x)]<=working_master_a_address)&&(slave_end_addresses[(32*(x+1))-1:(32*x)]>working_master_a_address)&working_master_a_valid);
    end

    assign master_stalled = |(slave_select&~slave_a_ready);

    for (genvar i = 0; i < 2; i++) begin : slaveRequest
        always_ff @(posedge tilelink_clock_i) begin : requestPrepare
            if (tilelink_reset_i) begin
                slave_a_valid[i] <= 1'b0;
            end
            else if (working_master_a_valid&!master_stalled&slave_select[i]) begin
                slave_a_address[(32*(i+1))-1:32*(i)] <= working_master_a_address;
                slave_a_corrupt[i] <= working_master_a_corrupt;
                slave_a_data[((2**5)*(i+1))-1:(2**5)*(i)] <= working_master_a_data;
                slave_a_mask[((2**5/8)*(i+1))-1:(2**5/8)*(i)] <= working_master_a_mask;
                slave_a_opcode[3*(i+1)-1:3*i] <= working_master_a_opcode;
                slave_a_param[3*(i+1)-1:3*i] <= working_master_a_param;
                slave_a_size[4*(i+1)-1:4*i] <= working_master_a_size;
                slave_a_source[4*(i+1)-1:4*i] <= working_master_a_source;
                slave_a_valid[i] <= 1'b1;
            end else if ((!working_master_a_valid|!slave_select[i])&!master_stalled) begin
                slave_a_valid[i] <= 1'b0;
            end
        end
    end

    // Now to route many slaves to the one master
    wire [2-1:0] slaveResponseStalled;
    wire [(2*3)-1:0]            working_slave_d_opcode;
    wire [(2*2)-1:0]            working_slave_d_param;
    wire [(2*4)-1:0]        working_slave_d_size;
    wire [(2*4)-1:0]        working_slave_d_source;
    wire [2-1:0]                working_slave_d_denied;
    wire [2*(2**5)-1:0]     working_slave_d_data;
    wire [2-1:0]                working_slave_d_corrupt;
    wire [2-1:0]                working_slave_d_valid;
    wire [2-1:0]                working_slave_d_busy;
    assign slave_d_ready = ~working_slave_d_busy;
    for (genvar i = 0; i < 2; i++) begin : skidbufferInstantiation
        skdbf #(.DW(7+4+4+(2**5))) slave_skidbuffer (tilelink_clock_i, tilelink_reset_i, slaveResponseStalled[i], {
            working_slave_d_opcode[(3)*(i+1)-1:(3)*(i)],
            working_slave_d_param[(2)*(i+1)-1:(2)*(i)],
            working_slave_d_size[(4)*(i+1)-1:(4)*(i)],
            working_slave_d_source[(4)*(i+1)-1:(4)*(i)],
            working_slave_d_denied[i],
            working_slave_d_data[(2**5)*(i+1)-1:(2**5)*(i)],
            working_slave_d_corrupt[i]
        }, working_slave_d_valid[i], working_slave_d_busy[i], {
            slave_d_opcode[(3)*(i+1)-1:(3)*(i)],
            slave_d_param[(2)*(i+1)-1:(2)*(i)],
            slave_d_size[(4)*(i+1)-1:(4)*(i)],
            slave_d_source[(4)*(i+1)-1:(4)*(i)],
            slave_d_denied[i],
            slave_d_data[(2**5)*(i+1)-1:(2**5)*(i)],
            slave_d_corrupt[i]
        }, slave_d_valid[i]);
    end
    reg [2-1:0] block; //! When a slave responds at the same time as others, a slave is selected, which can respond and the others are stalled,
                         //! Then the slave is blocked to let other slaves respond until no more conflicts are found, hence the register is reset
    reg lock; reg [2-1:0] locked_slave_select;
    reg [11:0] burst_counters;
    logic [$clog2(2)-1:0] bitscan;
    logic once;
    logic twoormore;
    wire burst = once&master_d_ready&(resp_size>{$clog2((2**5)/8)}[4-1:0])|lock;
    wire burst_ending = burst_counters==0 && lock;
    logic [2:0] resp_opcode;
    logic [1:0] resp_param;
    logic [4-1:0] resp_size;
    logic [4-1:0] resp_id;
    logic [(2**5)-1:0] resp_data;
    logic resp_denied;
    logic resp_corrupt;
    always_comb begin
        bitscan = 'x;
        once = 'x;
        for (integer n = 0; n < 2; n++) begin
            if (working_slave_d_valid[n]&(lock?locked_slave_select[n]:!block[n])) begin
                bitscan = n[$clog2(2)-1:0];
                once = 1'b1;
                break;
            end else begin
                once = 1'b0;
                bitscan = 0;
            end
        end
    end
    always_comb begin
        twoormore = 'x;
        for (integer n = 0; n < 2; n++) begin
            if (working_slave_d_valid[n]&&(n[$clog2(2)-1:0]!=bitscan)&&once) begin
                twoormore = 1'b1;
                break;
            end else begin
                twoormore = 1'b0;
            end
        end
    end
    	always_comb begin
		casez (working_slave_d_valid&(lock?locked_slave_select:~block))
			2'bz1: resp_data = working_slave_d_data[31:0];
			2'b10: resp_data = working_slave_d_data[63:32];
			default: resp_data = 0;
		endcase
	end	always_comb begin
		casez (working_slave_d_valid&(lock?locked_slave_select:~block))
			2'bz1: resp_opcode = working_slave_d_opcode[2:0];
			2'b10: resp_opcode = working_slave_d_opcode[5:3];
			default: resp_opcode = 0;
		endcase
	end	always_comb begin
		casez (working_slave_d_valid&(lock?locked_slave_select:~block))
			2'bz1: resp_param = working_slave_d_param[1:0];
			2'b10: resp_param = working_slave_d_param[3:2];
			default: resp_param = 0;
		endcase
	end	always_comb begin
		casez (working_slave_d_valid&(lock?locked_slave_select:~block))
			2'bz1: resp_denied = working_slave_d_denied[0:0];
			2'b10: resp_denied = working_slave_d_denied[1:1];
			default: resp_denied = 0;
		endcase
	end	always_comb begin
		casez (working_slave_d_valid&(lock?locked_slave_select:~block))
			2'bz1: resp_id = working_slave_d_source[3:0];
			2'b10: resp_id = working_slave_d_source[7:4];
			default: resp_id = 0;
		endcase
	end	always_comb begin
		casez (working_slave_d_valid&(lock?locked_slave_select:~block))
			2'bz1: resp_size = working_slave_d_size[3:0];
			2'b10: resp_size = working_slave_d_size[7:4];
			default: resp_size = 0;
		endcase
	end	always_comb begin
		casez (working_slave_d_valid&(lock?locked_slave_select:~block))
			2'bz1: resp_corrupt = working_slave_d_corrupt[0:0];
			2'b10: resp_corrupt = working_slave_d_corrupt[1:1];
			default: resp_corrupt = 0;
		endcase
	end

    always_ff @(posedge tilelink_clock_i) begin
        lock <= tilelink_reset_i ? 1'b0 : lock ? !burst_ending : once&master_d_ready&(resp_size>{$clog2((2**5)/8)}[4-1:0]);
        for (integer x = 0; x < 2; x++) begin
            locked_slave_select[x] <= tilelink_reset_i ? 1'b0 : x[$clog2(2)-1:0]==bitscan && once && burst;
        end
    end
    always_ff @(posedge tilelink_clock_i) begin
        for (integer n = 0; n < 2; n++) begin
            block[n] <= tilelink_reset_i ? 1'b0 : !twoormore&(!burst|burst&burst_ending) ? 1'b0 : twoormore&&(n[$clog2(2)-1:0]==bitscan);
        end
    end
    logic [11:0] number_to_write;

    
    always_comb begin
        case (resp_size)
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
    
    always_ff @(posedge tilelink_clock_i) begin
        if (tilelink_reset_i) begin
            burst_counters <= 0;
        end
        else if (burst&!lock&once&master_d_ready) begin 
            burst_counters <= number_to_write;
        end else if (lock&once&master_d_ready&!burst_ending) begin
            burst_counters <= burst_counters - 1;
        end
    end

    always_ff @(posedge tilelink_clock_i) begin
        if (tilelink_reset_i) begin
            master_d_valid <= 1'b0;
        end
        else if (once&master_d_ready) begin
            master_d_corrupt <= resp_corrupt;
            master_d_data <= resp_data;
            master_d_denied <= resp_denied;
            master_d_source <= resp_id;
            master_d_opcode <= resp_opcode;
            master_d_param <= resp_param;
            master_d_size <= resp_size;
            master_d_valid <= 1'b1;
        end else if (!once&master_d_ready) begin
            master_d_valid <= 1'b0;
        end
    end

    for (genvar n = 0; n < 2; n++) begin : stallLogic
        assign slaveResponseStalled[n] = (!master_d_ready)|(twoormore&&(n[$clog2(2)-1:0]!=bitscan));
    end
`ifdef FORMAL

`endif
endmodule


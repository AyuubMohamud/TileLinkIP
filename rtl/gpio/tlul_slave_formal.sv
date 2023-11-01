module tlul_slave_formal #(parameter AW = 32, parameter RS = 4, parameter [RS:0] MAX = 2) (
    input   wire logic                          slave_clock_i,
    input   wire logic                          slave_reset_i,

    // Slave interface
    input   wire logic [2:0]                    slave_a_opcode,
    input   wire logic [2:0]                    slave_a_param,
    input   wire logic [3:0]                    slave_a_size,
    input   wire logic [RS-1:0]                 slave_a_source,
    input   wire logic [AW-1:0]                 slave_a_address,
    input   wire logic [3:0]                    slave_a_mask,
    input   wire logic [31:0]                   slave_a_data,
    input   wire logic                          slave_a_corrupt,
    input   wire logic                          slave_a_valid,
    input   wire logic                          slave_a_ready,

    input   wire logic [2:0]                    slave_d_opcode,
    input   wire logic [1:0]                    slave_d_param,
    input   wire logic [3:0]                    slave_d_size,
    input   wire logic [RS-1:0]                 slave_d_source,
    input   wire logic                          slave_d_denied,
    input   wire logic [31:0]                   slave_d_data,
    input   wire logic                          slave_d_corrupt,
    input   wire logic                          slave_d_valid,
    input   wire logic                          slave_d_ready,

    output  logic      [RS:0]                 outstanding_transactions_o
);
    reg past_valid_f;
    reg [RS:0] total_transactions;
    assign outstanding_transactions_o = total_transactions;
    initial past_valid_f = 0;
    initial begin
        total_transactions = 0;
        assume(slave_d_valid==0);
        assume(slave_d_denied==0);
    end
    always_ff @(posedge slave_clock_i) begin
        past_valid_f <= 1'b1;
    end
    // Here we ensure bus properties are assumed and asserted for slaves correctly
    always_comb begin
        assume(slave_a_size<=4'd2);
        assume(slave_a_opcode==3'd4||slave_a_opcode==3'd1||slave_a_opcode==3'd0); // only get, pfd, ppd supported
        
    end
    // bus stability properties
    always_ff @(posedge slave_clock_i) begin : assumptions
        if (past_valid_f&$past(slave_a_valid)&!$past(slave_a_ready)&$past(!slave_reset_i)) begin
            assume($stable(slave_a_data));
            assume($stable(slave_a_address));
            assume($stable(slave_a_corrupt));
            assume($stable(slave_a_mask));
            assume($stable(slave_a_opcode));
            assume($stable(slave_a_param));
            assume($stable(slave_a_size));
            assume($stable(slave_a_source));
            assume($stable(slave_a_valid));
        end
    end

    always_ff @(posedge slave_clock_i) begin : assertions
        if (past_valid_f&$past(slave_d_valid)&!$past(slave_d_ready)&$past(!slave_reset_i)) begin
            assert($stable(slave_d_data));
            assert($stable(slave_d_corrupt));
            assert($stable(slave_d_opcode));
            assert($stable(slave_d_param));
            assert($stable(slave_d_size));
            assert($stable(slave_d_source));
            assert($stable(slave_d_denied));
            assert($stable(slave_d_valid));
        end
    end

    always_ff @(posedge slave_clock_i) begin : resp_guarentee
        if (!slave_reset_i) begin
            case ({slave_a_valid&slave_a_ready, slave_d_ready&slave_d_valid})
                2'b00: begin
                    total_transactions <= total_transactions;
                end
                2'b01: begin
                    total_transactions <= total_transactions-1'b1;
                end
                2'b10: begin
                    total_transactions <= total_transactions+1'b1;
                end
                2'b11: begin
                    total_transactions <= total_transactions;
                end
            endcase
        end else begin
            total_transactions <= 0;
        end
        assert(total_transactions <= MAX);
    end
endmodule

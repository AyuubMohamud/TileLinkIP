module spitest (
    input wire logic clk100mhz,

    input wire logic miso,
    output wire logic mosi,
    output wire logic cs_n,
    output wire logic sck,

    output wire logic [3:0] led
);
    reg tx;
    wire done;
    wire [31:0] data;
    wire busy;
    spiphy spiphy0 (clk100mhz, tx, 5'd7, 5'd7, 1'b1, 32'b00000000000000000000000011101110, 10'd100, 1'b0, 1'b0, done, busy, data, miso, mosi, sck, cs_n);

    reg state;
    reg [31:0] r_data;
    assign led[0] = r_data[7:0] == 8'h91;
    assign led[1] = r_data[7:0] == 8'h92;
    assign led[2] = r_data[4];
    assign led[3] = r_data[7];
    always_ff @(posedge clk100mhz) begin
        case (state)
            1'b0: begin
                if (!busy) begin
                    tx <= 1'b1;
                    state <= 1'b1;
                end
            end
            1'b1: begin
                if (done) begin
                    r_data <= data;
                end
            end
        endcase
    end

endmodule

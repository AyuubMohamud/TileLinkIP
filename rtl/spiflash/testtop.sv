module testtop (
    input  wire clk100mhz,
    output wire [3:0] regular_led,
    output wire [2:0] rgb1,
    output wire [2:0] rgb2,
    output wire [2:0] rgb3,
    output wire [2:0] rgb4,
    output wire flash_sck,
    output wire flash_mosi,
    input  wire flash_miso,
    output wire flash_cs_n

);
    assign regular_led[3] = 1;
    reg [2:0] leddrive = 0;
    reg [2:0] leddrive1 = 0;
    reg [2:0] leddrive2 = 0;
    reg [2:0] leddrive3 = 0;
    reg [1:0] fsm = 0;
    reg tx = 0;
    assign regular_led[1:0] = fsm;
    assign regular_led[2] = 0;
    assign rgb1 = leddrive;
    assign rgb2 = leddrive1;
    assign rgb3 = leddrive2;
    assign rgb4 = leddrive3;
    wire busy, enqueue; wire [31:0] data;
    flashphy spiflashphy (clk100mhz, tx, 24'h400000, 4'd2, busy, enqueue, data, flash_cs_n, flash_mosi, flash_miso, flash_sck);
    always_ff @(posedge clk100mhz) begin
        case (fsm)
            2'b00: begin
                if (!busy) begin
                    tx <= 1;
                    fsm <= 2'b01;
                end
            end
            2'b01: begin
                tx <= 0;
                if (enqueue) begin
                    leddrive <= data[7:0]==8'h31 ? 3'b010 : 3'b100;
                    leddrive1 <= data[15:8]==8'h31 ? 3'b010 : 3'b100;
                    leddrive2 <= data[23:16]==8'h31 ? 3'b010 : 3'b100;
                    leddrive3 <= data[31:24]==8'h31 ? 3'b010 : 3'b100;
                end
            end             
        endcase
    end
endmodule

module sdclkgen (
    input   wire logic              sdctrl_clock_i, // minimum 2xsdclk
    
    input   wire logic [7:0]        sddiv_i,
    input   wire logic              nsddiv_i,
    output  wire logic              able_o,

    output  wire logic              sdclk_o
);
    reg [7:0] sddiv;
    initial sddiv = 8'd250;

    reg [7:0] counter;
    assign sdclk_o = counter < {1'b0, sddiv[7:1]};

    always_ff @(posedge sdctrl_clock_i) begin
        if (counter==sddiv-1 && nsddiv_i) begin
            sddiv <= sddiv_i;
        end
    end
    assign able_o = counter==sddiv-1;

    always_ff @(posedge sdctrl_clock_i) begin
        if (counter==sddiv-1) begin
            counter <= 0;
        end else begin
            counter <= counter + 1'b1;
        end
    end
endmodule

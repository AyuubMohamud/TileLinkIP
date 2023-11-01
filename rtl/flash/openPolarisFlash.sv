module openPolarisFlash #(
    parameter TL_RS = 4
    )  (
    input   wire logic                          fctrl_clock_i,
    input   wire logic                          fctrl_reset_i,

    // Slave interface
    input   wire logic [3:0]                    fctrl_a_size,
    input   wire logic [TL_RS-1:0]              fctrl_a_source,
    input   wire logic [23:0]                   fctrl_a_address,
    input   wire logic                          fctrl_a_valid,
    output  wire logic                          fctrl_a_ready,

    output       logic [2:0]                    fctrl_d_opcode,
    output       logic [1:0]                    fctrl_d_param,
    output       logic [3:0]                    fctrl_d_size,
    output       logic [TL_RS-1:0]              fctrl_d_source,
    output       logic                          fctrl_d_denied,
    output       logic [31:0]                   fctrl_d_data,
    output       logic                          fctrl_d_corrupt,
    output       logic                          fctrl_d_valid,
    input   wire logic                          fctrl_d_ready,

    input   wire logic                          miso,
    output       logic                          mosi,
    output       logic                          sck,
    output       logic                          cs_n
);
    initial mosi = 0;
    initial sck = 1;
    initial cs_n = 1;
    wire fctrl_busy;
    wire [TL_RS-1:0] working_source;
    wire [3:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire [23:0] working_address;
    wire working_valid;
    reg busy;
    skdbf #(TL_RS+24+4) skidbuffer (fctrl_clock_i, fctrl_reset_i, ~fctrl_d_ready|busy, {
        working_source,
        working_size,
        working_address
    }, working_valid, fctrl_busy, {
        fctrl_a_source, fctrl_a_size, fctrl_a_address
    }, fctrl_a_valid);
    
    assign fctrl_a_ready = ~fctrl_busy;
    
    initial busy = 0;
    reg cmd;
    initial cmd = 0;
    reg [31:0] spi_cmd;
    reg [TL_RS-1:0] source;
    initial source = 0;
    reg [3:0] size;
    initial size = 0;
    reg [4:0] counter;
    initial counter = 0;
    reg fin;
    initial fin = 0;
    always_ff @(posedge fctrl_clock_i) begin
        if (fctrl_reset_i) begin
            cs_n <= 1'b1;
            sck <= 1'b1;
            busy <= 0;
            spi_cmd <= 0;
            source <= 0;
            size <= 0;
        end
        else if (working_valid&!(~fctrl_d_ready|busy)) begin : begin_SPI
            cs_n <= 1'b0;
            sck <= 1'b1;
            busy <= 1;
            cmd <= 1;
            spi_cmd <= {8'h03, working_address};
            source <= working_source;
            size <= working_size;
            fin <= 0;
        end else if (busy&cmd&!fin) begin
            sck <= ~sck;
            if (~sck) begin
                mosi <= spi_cmd[31];
            end
            spi_cmd <= {spi_cmd[30:0], 1'b0};
            if (counter==5'b11111 && sck) begin
                counter <= 0;
                cmd <= 0;
            end else if (~sck) begin
                counter <= counter + 1'b1;
            end
        end else if (busy&!cmd&!fin) begin
            if (sck) begin
                {spi_cmd} <= {spi_cmd[30:0], miso};
            end
            if (counter==5'b11111 && ~sck) begin
                cmd <= 0;
                cs_n <= 1;
                fin <= 1;
            end else if (sck) begin
                counter <= counter + 1'b1;
            end
            sck <= ~sck;
        end else if (busy&fin&!(~fctrl_d_ready)) begin
            sck <= 1'b1;
            fctrl_d_corrupt <= 0;
            fctrl_d_data <= spi_cmd;
            fctrl_d_denied <= 0;
            fctrl_d_opcode <= 0;
            fctrl_d_param <= 0;
            fctrl_d_size <= size;
            fctrl_d_source <= source;
            fctrl_d_valid <= 1;
            busy <= 0;
        end else if (fctrl_d_ready&!working_valid) begin
            fctrl_d_valid <= 0;
        end
    end
endmodule

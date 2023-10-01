module final_test (
    input   wire logic          clk100mhz,

    input   wire logic          uart_rx_i,
    output  wire logic          uart_tx_o
);
    reg reset;
    reg lsioc_vld;
    reg [31:0] lsioc_data;
    reg [1:0] lsioc_sbsp;
    reg [2:0] lsioc_opc;
    reg [1:0] lsioc_bmsk;
    initial lsioc_bmsk = 2'b00;

    wire rx_busy;
    wire busy = 1'b0;

    wire [1:0] error;
    wire [31:0] data;
    wire vld;
    wire interrupt;
    polaris_uart uart_controller0 (clk100mhz, reset, 
    lsioc_vld, lsioc_sbsp, lsioc_data, lsioc_opc, lsioc_bmsk, rx_busy, 
    error, data, vld, busy, uart_tx_o, uart_rx_i, interrupt);

    reg [2:0] STATE;
    reg pending;
    localparam INIT = 3'b000;
    localparam CONFIGURE = 3'b001;
    localparam TK_INPUT = 3'b010;
    localparam SPIT_INPUT_OUT0= 3'b011;
    localparam SPIT_INPUT_OUT_WAIT = 3'b100;
    reg config_process;
    always_ff @(posedge clk100mhz) begin
        case (STATE)
            INIT: begin
                lsioc_vld <= 1'b0;
                reset <= 1'b1;
            end 
            CONFIGURE: begin
                if (!lsioc_vld) begin
                    reset <= 1'b0;
                    lsioc_vld <= 1'b1;
                    lsioc_data <= 32'h00006c80|32'h00000007;
                    lsioc_opc <= 3'b001;
                    lsioc_sbsp <= 2'b00;
                    config_process <= 1'b1;
                end else if (config_process) begin
                    lsioc_vld <= 1'b0;
                    if (vld && (error == 2'b00)) begin
                        STATE <= TK_INPUT;
                    end else begin
                        STATE <= CONFIGURE;
                    end
                end
            end
            TK_INPUT: begin
                if (interrupt&!pending) begin
                    lsioc_vld <= 1'b1;
                    lsioc_opc <= 3'b000;
                    lsioc_sbsp <= 2'b10;
                    lsioc_bmsk <= 2'b00;
                    pending <= 1'b1;
                    STATE <= SPIT_INPUT_OUT0;
                end else begin
                    lsioc_vld <= 1'b0;
                    STATE <= TK_INPUT;
                end
            end
            SPIT_INPUT_OUT0: begin
                pending <= 1'b0;
                lsioc_vld <= 1'b0;
                if (vld && (error == 2'b00)) begin
                    lsioc_vld <= 1'b1;
                    lsioc_opc <= 3'b001;
                    lsioc_sbsp <= 2'b01;
                    lsioc_data <= data;
                    lsioc_bmsk <= 2'b00;
                    STATE <= SPIT_INPUT_OUT_WAIT;
                end else begin
                    STATE <= SPIT_INPUT_OUT0;
                end
            end
            SPIT_INPUT_OUT_WAIT: begin
                lsioc_vld <= 1'b0;
                STATE <= TK_INPUT;
            end
            default: begin
                STATE <= INIT;
            end
        endcase
    end
endmodule

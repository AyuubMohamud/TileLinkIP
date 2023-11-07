module sdcmdphy (
    input   wire logic                  sdctrl_clock_i,
    // from sdgencmd
    input   wire logic [47:0]           sdcmd_i,
    input   wire logic [1:0]            sdresp_class_i,
    input   wire logic                  start_i,
    output  wire logic [135:0]          sdresp_o,
    output  wire logic                  finish_o,

    // sddatphy

    // sdclkgen
    input   wire logic                  sdclk_i,
    // sdcard
    output       logic                  sdclk,
    output       logic                  cmd,
    input        logic                  resp,
    output       logic                  o_en
);
    
    reg [2:0] sdphy_state;
    initial cmd = 1'b1;
    initial o_en = 1'b1;
    initial sdclk = 1'b1;
    localparam INITIALISE = 3'b000;
    localparam IDLE = 3'b001;
    localparam WRITECMD = 3'b010;
    localparam READ = 3'b011;
    localparam AWAIT = 3'b100;

    initial sdphy_state = INITIALISE;

    wire rising_edge = !sdclk&sdclk_i;
    wire falling_edge = !sdclk_i&sdclk;

    reg [7:0] counter;
    initial counter = 1;
    reg [47:0] command;
    reg [1:0] response_len;
    reg [135:0] response;
    reg start_resp = 1'b0;
    always_ff @(posedge sdctrl_clock_i) begin
        case (sdphy_state)
            INITIALISE: begin
                cmd <= 1'b1;
                o_en <= 1'b1;
                if (falling_edge) begin
                    if (counter==8'd73) begin
                        counter <= 0;
                        sdphy_state <= IDLE;
                    end
                end else if (rising_edge) begin
                    counter <= counter + 1'b1;
                end
            end
            IDLE: begin
                if (start_i) begin
                    command <= sdcmd_i;
                    counter <= 8'd47;
                    response_len <= sdresp_class_i;
                end
            end
            WRITECMD: begin
                if (falling_edge) begin
                    cmd <= command[counter[5:0]];
                    if (counter!=8'd0) begin
                        counter <= counter - 1'b1;
                    end else begin
                        counter <= 8'hff;
                    end
                end
                else if (rising_edge) begin
                    if (counter == 8'hff) begin
                        counter <= response_len == 2'b00 ? 8'd47 : 8'd135;
                        sdphy_state <= READ;
                    end
                end
            end
            READ: begin
                if (rising_edge) begin
                    if (!start_resp) begin
                        if (!sd)
                    end
                end
            end
            AWAIT: begin
                
            end
            default : sdphy_state <= 0;
        endcase
    end
endmodule

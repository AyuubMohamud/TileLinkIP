module openPolarisWatchdog #(
    parameter TL_RS = 4,
    parameter TL_SZ = 4,
    parameter NOC = 2
    ) (
    input   wire logic                          watchdog_clock_i,
    input   wire logic                          watchdog_reset_i,

    // Slave interface
    input   wire logic [2:0]                    watchdog_a_opcode,
    /* verilator lint_off UNUSEDSIGNAL */
    input   wire logic [2:0]                    watchdog_a_param,
    input   wire logic [TL_SZ-1:0]              watchdog_a_size,
    input   wire logic [TL_RS-1:0]              watchdog_a_source,
    input   wire logic [$clog2(8*NOC)+1:0]      watchdog_a_address,
    input   wire logic [3:0]                    watchdog_a_mask,
    input   wire logic [31:0]                   watchdog_a_data,
    input   wire logic                          watchdog_a_corrupt,
    /* verilator lint_on UNUSEDSIGNAL */
    input   wire logic                          watchdog_a_valid,
    output  wire logic                          watchdog_a_ready,

    output       logic [2:0]                    watchdog_d_opcode,
    output       logic [1:0]                    watchdog_d_param,
    output       logic [TL_SZ-1:0]              watchdog_d_size,
    output       logic [TL_RS-1:0]              watchdog_d_source,
    output       logic                          watchdog_d_denied,
    output       logic [31:0]                   watchdog_d_data,
    output       logic                          watchdog_d_corrupt,
    output       logic                          watchdog_d_valid,
    input   wire logic                          watchdog_d_ready,

    output  wire logic [NOC-1:0]                irq_o,
    output  wire logic                          crm_o
);
    wire watchdog_busy;
    wire [TL_RS-1:0] working_source;
    wire [TL_SZ-1:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire [$clog2(NOC*8)+1:0] working_address;
    wire working_valid;
    skdbf #(TL_RS+TL_SZ+39+$clog2(NOC*8)+2) skidbuffer (watchdog_clock_i, watchdog_reset_i, ~watchdog_d_ready, {
        working_source,
        working_size,
        working_data,
        working_mask,
        working_opcode,
        working_address
    }, working_valid, watchdog_busy, {
        watchdog_a_source, watchdog_a_size, watchdog_a_data, watchdog_a_mask, watchdog_a_opcode, watchdog_a_address
    }, watchdog_a_valid);
    assign watchdog_a_ready = ~watchdog_busy;

    reg [NOC-1:0] enable_watchdog;
    reg [63:0] petting_timer [0:NOC-1];
    reg [63:0] watchdog_timer [0:NOC-1];

    wire [$clog2(NOC)-1:0] index = working_address[$clog2(NOC*8)+1:5];

    always_ff @(posedge watchdog_clock_i) begin
        if (watchdog_reset_i) begin
            enable_watchdog <= 0;
        end else if (watchdog_d_ready&working_valid&(working_address[4:2]==3'b000)&(working_opcode==3'd0||working_opcode==3'd1)) begin
            enable_watchdog[index] <= working_data[0];
        end
    end

    for (genvar i = 0; i < NOC; i++) begin : petting_timer_manage
        always_ff @(posedge watchdog_clock_i) begin
            if (watchdog_reset_i) begin
                petting_timer[i] <= 64'd0;
            end else if (watchdog_d_ready&working_valid&(working_address[4:2]==3'b001)&(working_opcode==3'd0||working_opcode==3'd1) && (index==i)) begin
                petting_timer[i][31:0] <= working_data;
            end else if (watchdog_d_ready&working_valid&(working_address[4:2]==3'b010)&(working_opcode==3'd0||working_opcode==3'd1) && (index==i)) begin
                petting_timer[i][63:32] <= working_data;
            end else if (petting_timer[i]!=0 && enable_watchdog[i]) begin
                petting_timer[i] <= petting_timer[i] - 1'b1;
            end
        end
    end

    for (genvar i = 0; i < NOC; i++) begin : watchdog_timer_manage
        always_ff @(posedge watchdog_clock_i) begin
            if (watchdog_reset_i) begin
                watchdog_timer[i] <= 64'd0;
            end else if (watchdog_d_ready&working_valid&(working_address[4:2]==3'b011)&(working_opcode==3'd0||working_opcode==3'd1) && (index==i)) begin
                watchdog_timer[i][31:0] <= working_data;
            end else if (watchdog_d_ready&working_valid&(working_address[4:2]==3'b100)&(working_opcode==3'd0||working_opcode==3'd1) && (index==i)) begin
                watchdog_timer[i][63:32] <= working_data;
            end else if (petting_timer[i]==0 && watchdog_timer[i]!=0 && enable_watchdog[i]) begin
                watchdog_timer[i] <= watchdog_timer[i] - 1'b1;
            end
        end
    end

    for (genvar i = 0; i < NOC; i++) begin : petIrq
        assign irq_o[i] = (petting_timer[i]==0)&&enable_watchdog[i];
    end

    wire [NOC-1:0] reset_system;
    for (genvar i = 0; i < NOC; i++) begin : crmIrq
        assign reset_system[i] = (watchdog_timer[i]==0)&&enable_watchdog[i];
    end
    assign crm_o = |reset_system;


    always_ff @(posedge watchdog_clock_i) begin
        if (watchdog_reset_i) begin
            watchdog_d_valid <= 1'b0;
        end
        else if (working_valid&&watchdog_d_ready) begin
            watchdog_d_corrupt <= 1'b0;
            watchdog_d_opcode <= {2'b00, watchdog_a_opcode==3'd4};
            watchdog_d_param <= 2'b00;
            watchdog_d_size <= 4'd2;
            watchdog_d_source <= working_source;
            case (watchdog_a_address[4:2])
                3'b000: begin
                    watchdog_d_data <= {31'd0, enable_watchdog[index]};
                    watchdog_d_denied <= 1'b0;
                end 
                3'b001: begin
                    watchdog_d_data <= petting_timer[index][31:0];
                    watchdog_d_denied <= 1'b0;
                end
                3'b010: begin
                    watchdog_d_data <= petting_timer[index][63:32];
                    watchdog_d_denied <= 1'b0;
                end
                3'b011: begin
                    watchdog_d_data <= watchdog_timer[index][31:0];
                    watchdog_d_denied <= 1'b0;
                end
                3'b100: begin
                    watchdog_d_data <= watchdog_timer[index][63:32];
                    watchdog_d_denied <= 1'b0;
                end
                default: begin
                    watchdog_d_data <= 0;
                    watchdog_d_denied <= 1'b1;
                end
            endcase
            watchdog_d_valid <= 1'b1;
        end
        else if (!working_valid&&watchdog_d_ready) begin
            watchdog_d_valid <= 1'b0;
        end
    end
`ifdef FORMAL
    wire [TL_RS:0] outstanding;
    tlul_slave_formal #(.AW(4), .RS(TL_RS), .MAX(2)) formal (
        watchdog_clock_i,
        watchdog_reset_i,
        watchdog_a_opcode,
        watchdog_a_param,
        watchdog_a_size,
        watchdog_a_source,
        watchdog_a_address,
        watchdog_a_mask,
        watchdog_a_data,
        watchdog_a_corrupt,
        watchdog_a_valid,
        watchdog_a_ready,
        watchdog_d_opcode,
        watchdog_d_param,
        watchdog_d_size,
        watchdog_d_source,
        watchdog_d_denied,
        watchdog_d_data,
        watchdog_d_corrupt,
        watchdog_d_valid,
        watchdog_d_ready,
        outstanding
    );
`endif
endmodule

/* verilator lint_off WIDTHTRUNC */
/* verilator lint_off WIDTHEXPAND */
module tilelink_xbr
#(
    parameter TLS = 2, //! Number of TileLink Slaves
    parameter TLM = 2, //! Number of TileLink Masters    
    parameter TL_AW = 32, //! Address width
    parameter [(TL_AW*TLS)-1:0] slave_addresses = {
        32'h00001000,
        32'h00002000
    }, //! Base addresses of mentioned slaves
    parameter [(TL_AW*TLS)-1:0] slave_end_addresses = {
        32'h00002000,
        32'h10000000
    },
    parameter TIMEOUT = 1000000, //! Timeout in cycles elapsed since recieval
    parameter TL_RS = 2, //! log base 2 of IDs per master
    parameter TL_DW = 5, //! Log base 2 of data width
    parameter TL_SZ = 4
) 
(
    input   wire logic                      tilelink_clock_i,
    input   wire logic                      tilelink_reset_i,

    input   wire logic [2:0]                a_opcode [0:TLM-1],
    input   wire logic [2:0]                a_param [0:TLM-1],
    input   wire logic [TL_SZ-1:0]          a_size [0:TLM-1],
    input   wire logic [TL_RS-1:0]          a_source [0:TLM-1],
    input   wire logic [TL_AW-1:0]          a_address [0:TLM-1],
    input   wire logic [(2**TL_DW)/8-1:0]   a_mask [0:TLM-1],
    input   wire logic [2**(TL_DW)-1:0]     a_data [0:TLM-1],
    input   wire logic                      a_corrupt [0:TLM-1],
    input   wire logic                      a_valid [0:TLM-1],
    output  wire logic                      a_ready [0:TLM-1],

    output  wire logic [2:0]                d_opcode [0:TLM-1],
    output  wire logic [2:0]                d_param [0:TLM-1],
    output  wire logic [TL_SZ-1:0]          d_size [0:TLM-1],
    output  wire logic [TL_RS-1:0]          d_source [0:TLM-1],
    output  wire logic                      d_denied [0:TLM-1],
    output  wire logic [2**(TL_DW)-1:0]     d_data [0:TLM-1],
    output  wire logic                      d_corrupt [0:TLM-1],
    output  wire logic                      d_valid [0:TLM-1],
    input   wire logic                      d_ready [0:TLM-1],

    output       logic [2:0]                sa_opcode [0:TLS-1],
    output       logic [2:0]                sa_param [0:TLS-1],
    output       logic [TL_SZ-1:0]          sa_size [0:TLS-1],
    output       logic [TL_RS+$clog2(TLM)-1:0]          sa_source [0:TLS-1],
    output       logic [TL_AW-1:0]          sa_address [0:TLS-1],
    output       logic [(2**TL_DW)/8-1:0]   sa_mask [0:TLS-1],
    output       logic [2**(TL_DW)-1:0]     sa_data [0:TLS-1],
    output       logic                      sa_corrupt [0:TLS-1],
    output       logic                      sa_valid [0:TLS-1],
    input   wire logic                      sa_ready [0:TLS-1],

    input   wire logic [2:0]                sd_opcode [0:TLS-1],
    input   wire logic [2:0]                sd_param [0:TLS-1],
    input   wire logic [TL_SZ-1:0]          sd_size [0:TLS-1],
    input   wire logic [TL_RS-1:0]          sd_source [0:TLS-1],
    input   wire logic                      sd_denied [0:TLS-1],
    input   wire logic [2**(TL_DW)-1:0]     sd_data [0:TLS-1],
    input   wire logic                      sd_corrupt [0:TLS-1],
    input   wire logic                      sd_valid [0:TLS-1],
    output  wire logic                      sd_ready [0:TLS-1]
);
    //! This is a very simple interconnect.
    //! It only supports TileLink Uncached Heavyweight/Lightweight.
    //! This interconnect is to be used for hooking up peripherals. It can also hookup DDR memory if you so wish.
    //! To modify parameters like bus width and address space size please modify the above defines
    //! Slaves may be grouped together into a common address space to reduce complexity

    //! INTERCONNECT Requirements:
    /**
        - A master may have 2^(LB2IDPM) requests
        - A master is assumed to not reuse IDs while waiting for a response
        - Address and size are aligned to each other (Tilelink Requirement), mask does not have to be contiguous.
        - 2^(x_size) is the number of bytes the requests requires, reducing figuring out bursts to shifts
        - No combinational paths between signals
        - Responses may appear out of order however requests are not out of order. If multiple masters request a slave the interconnect reverts to round robin.
        - Timeout is defined for every 2^(LB2IDPM)*TLM and starts when a transaction is recieved and stops when a transaction is responded to.
        - Should the timeout elapse, then a d_denied is sent through.
    **/
    wire [TLM-1:0] master_stalled;
    reg [TLM-1:0] deprioritise [0:TLS-1];
    wire [6+TL_SZ+TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8):0] master_skdata [0:TLM-1];
    wire [TLM-1:0] master_skdata_valid;
    for (genvar i = 0; i < TLM; i++) begin : skidbuffer_instantiation
        skdbf #(6+TL_SZ+TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8)+1) tilelink_buffer (
            tilelink_clock_i, tilelink_reset_i, master_stalled[i], master_skdata[i], master_skdata_valid[i], !a_ready[i], {
                a_opcode [i],
                a_param [i],
                a_size [i],
                a_source [i],
                a_address [i],
                a_mask [i],
                a_data [i],
                a_corrupt [i]
            }, a_valid[i]
        );
    end

    wire [2:0] master_opcode [0:TLM-1];
    wire [2:0] master_param [0:TLM-1];
    wire [TL_SZ-1:0] master_size [0:TLM-1];
    wire [TL_RS-1:0] master_source [0:TLM-1];
    wire [TL_AW-1:0] master_address [0:TLM-1];
    wire [((2**TL_DW)/8)-1:0] master_mask [0:TLM-1];
    wire [(2**TL_DW)-1:0] master_data [0:TLM-1];
    wire [TLM-1:0]  master_corrupt;
    for (genvar i = 0; i < TLM; i++) begin : skidbuffer_assignment
        assign master_opcode[i] = master_skdata[i][6+TL_SZ+TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8):4+TL_SZ+TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8)];
        assign master_param[i] = master_skdata[i][3+TL_SZ+TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8):1+TL_SZ+TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8)];
        assign master_size[i] = master_skdata[i][TL_SZ+TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8):1+TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8)];
        assign master_source[i] = master_skdata[i][TL_RS+TL_AW+(2**TL_DW)+((2**TL_DW)/8):1+TL_AW+(2**TL_DW)+((2**TL_DW)/8)];
        assign master_address[i] = master_skdata[i][TL_AW+(2**TL_DW)+((2**TL_DW)/8):1+(2**TL_DW)+((2**TL_DW)/8)];
        assign master_mask[i] = master_skdata[i][(2**TL_DW)+((2**TL_DW)/8):(2**TL_DW)+1];
        assign master_data[i] = master_skdata[i][(2**TL_DW):1];
        assign master_corrupt[i] = master_skdata[i][0];
    end

    
    wire [TLS-1:0] slave_select [0:TLM-1];
    for (genvar i = 0; i < TLM; i++) begin : address_decode
        for (genvar x = 0; x < TLS; x++) begin : address_decode
            assign slave_select[i][x] = ((slave_addresses[(TL_AW*(x+1))-1:(TL_AW*x)]<=master_address[i])&&(slave_end_addresses[(TL_AW*(x+1))-1:(TL_AW*x)]>master_address[i])&master_skdata_valid[i]);
        end
    end
    wire [TLM-1:0] master_error;
    for (genvar i = 0; i < TLM; i++) begin : check_for_error
        assign master_error[i] = !(|slave_select[i]); //! This signal means a master must be denied access completely
    end
    logic [TLS-1:0] twoormore;
    logic [TLS-1:0] once;
    logic [$clog2(TLM)-1:0] bitscan [0:TLS-1];
    wire [TLM-1:0] slave_select_inv [0:TLS-1];
    for (genvar x = 0; x < TLS; x++) begin : invertx
        for (genvar y = 0; y < TLM; y++) begin : inverty
            assign slave_select_inv[x][y] = slave_select[y][x];
        end
    end
    for (genvar i = 0; i < TLS; i++) begin : slave_conflict_detect
        always_comb begin
            bitscan[i] = 'x;
            once[i] = 'x;
            for (integer x = 0; x < TLM; x++) begin
                if (slave_select[x][i]&!deprioritise[i][x]) begin
                    bitscan[i] = TLM;
                    once[i] = 1'b1;
                    break;
                end else begin
                    once[i] = 1'b0;
                    bitscan[i] = 0;
                end
            end
        end
        always_comb begin
            twoormore[i] = 'x;
            for (integer x = 0; x < TLM; x++) begin
                if (slave_select[x][i]&&(x!=bitscan[i])&&once) begin
                    twoormore[i] = 1'b1;
                    break;
                end else begin
                    twoormore[i] = 1'b0;
                end
            end
        end
    end

    
    wire [TLS-1:0] burst_in_progress;
    reg [TLS-1:0] isBurst;
    wire [TLS-1:0] burst_ending;
    reg [$clog2((4096/((2**TL_DW)/8)))-1:0] burst_counters [0:TLS-1];
    logic [$clog2((4096/((2**TL_DW)/8)))-1:0] number_to_write[0:TLS-1];

    for (genvar i = 0; i < TLS; i++) begin : determineBurst
        assign burst_in_progress[i] = (master_size[bitscan[i]] > $clog2(8*(TL_DW-3)));
    end
    for (genvar i = 0; i < TLS; i++) begin : determineEOB
        assign burst_ending[i] = burst_counters[i]==0;
    end

    // copy burst data somewhere
    for (genvar i = 0; i < TLS; i++) begin : calculateSize
        always_comb begin
            case (master_size[bitscan[i]])
                4'd0: begin // 1 byte
                    number_to_write[i] = 0;
                end 
                4'd1: begin // 2 bytes
                    number_to_write[i] = 0;
                end
                4'd2: begin // 4 bytes
                    number_to_write[i] = 0;
                end 
                4'd3: begin // 8 bytes
                    number_to_write[i] = (64/((2**TL_DW)/8)) - 2; // Minus 2 as when we have recieved 
                end
                4'd4: begin // 16 bytes
                    number_to_write[i] = (128/((2**TL_DW)/8)) - 2;
                end
                4'd5: begin // 32 bytes
                    number_to_write[i] = (256/((2**TL_DW)/8)) - 2;
                end
                4'd6: begin // 64 bytes
                    number_to_write[i] = (512/((2**TL_DW)/8)) - 2;
                end
                4'd7: begin // 128 bytes
                    number_to_write[i] = (1024/((2**TL_DW)/8)) - 2;
                end
                4'd8: begin // 256 bytes
                    number_to_write[i] = (2048/((2**TL_DW)/8)) - 2;
                end
                4'd9: begin // 512 bytes
                    number_to_write[i] = (4096/((2**TL_DW)/8)) - 2;
                end
                4'd10: begin // 1 kilobyte
                    number_to_write[i] = (8192/((2**TL_DW)/8)) - 2;
                end
                4'd11: begin // 2 kilobytes
                    number_to_write[i] = (16384/((2**TL_DW)/8)) - 2;
                end
                4'd12: begin // 4 kilobytes
                    number_to_write[i] = (32768/((2**TL_DW)/8)) - 2;
                end
                default: begin
                    number_to_write[i] = 0;
                end
            endcase
        end
    end
    for (genvar i = 0; i < TLS; i++) begin : burstControlReg
        always_ff @(posedge tilelink_clock_i) begin
            isBurst[i] <= |slave_select_inv[i]&sd_ready[i]&burst_ending[i] ? 1'b0 : |slave_select_inv[i]&sa_ready[i]&burst_in_progress[i]; //! placeholder fix
        end
    end
    for (genvar i = 0; i < TLS; i++) begin : burstControl
        always_ff @(posedge tilelink_clock_i) begin
            if (|slave_select_inv[i]&sa_ready[i]&burst_in_progress[i]) begin
                burst_counters[i] <= number_to_write[i];
            end else if (|slave_select_inv[i]&sa_ready[i]&isBurst[i]) begin
                burst_counters[i] <= burst_counters[i] - ((2**TL_DW)/8);
            end
        end
    end
    for (genvar i = 0; i < TLS; i++) begin : pushReqToSlave
        always_ff @(posedge tilelink_clock_i) begin
            if (|slave_select_inv[i]&sa_ready[i]) begin
                sa_address[i] <= master_address[bitscan[i]];
                sa_corrupt[i] <= master_corrupt[bitscan[i]];
                sa_data[i] <= master_data[bitscan[i]];
                sa_mask[i] <= master_mask[bitscan[i]];
                sa_opcode[i] <= master_opcode[bitscan[i]];
                sa_param[i] <= master_param[bitscan[i]];
                sa_size[i] <= master_size[bitscan[i]];
                sa_source[i] <= {bitscan[i], master_source[bitscan[i]]};
                sa_valid[i] <= 1'b1;
            end else if (!(|slave_select_inv[i])&sa_ready[i]) begin
                sa_valid[i] <= 1'b0;
            end
            //need tie breaker for when depriotise [i] == slave_select[i]
            if (|slave_select_inv[i]&sa_ready[i]) begin
               for (integer x = 0; x < TLM; x++) begin
                    deprioritise[i][x] <= twoormore[i] ? (x==bitscan[i])&!(burst_in_progress[i]&!burst_ending[i]) : 1'b0; 
               end 
            end else if (!(|slave_select_inv[i])&sa_ready[i]) begin
                for (integer x = 0; x < TLM; x++) begin
                    deprioritise[i][x] <= 1'b0; 
               end 
            end
        end
    end

    // determine who is stalled
    for (genvar i = 0; i < TLM; i++) begin : determineMasters
        logic [$clog2(TLM)-1:0] selected_master;
        always_comb begin
            selected_master = 'x;
            for (integer x = 0; x < TLS; x++) begin
                if (slave_select[i][x]) begin
                    selected_master = bitscan[x];
                end
            end
        end
        assign master_stalled[i] = selected_master!=i;
    end
`ifdef FORMAL
`endif


endmodule
/* verilator lint_on WIDTHTRUNC */
/* verilator lint_on WIDTHEXPAND */

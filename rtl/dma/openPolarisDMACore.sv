module openPolarisDMACore #(
    parameter TL_AW = 32
) (
    input   wire logic                          dmac_clock_i,
    input   wire logic                          dmac_reset_i,

    input   wire logic                          dmac_tx_i,
    input   wire logic [TL_AW-1:0]              dmac_source_address_i,
    input   wire logic [TL_AW-1:0]              dmac_dest_address_i,
    input   wire logic [TL_AW-1:0]              dmac_bytes_tx_i,
    input   wire logic                          dmac_stationary_rd_i,
    input   wire logic                          dmac_stationary_wr_i,
    output  wire logic                          dmac_busy_o,
    output       logic                          dmac_done_o,
    output       logic                          dmac_err_o,

    output       logic [2:0]                    dma_a_opcode,
    output       logic [2:0]                    dma_a_param,
    output       logic [3:0]                    dma_a_size,
    output       logic [TL_AW-1:0]              dma_a_address,
    output       logic [3:0]                    dma_a_mask,
    output       logic [31:0]                   dma_a_data,
    output       logic                          dma_a_corrupt,
    output       logic                          dma_a_valid,
    input   wire logic                          dma_a_ready,

    input   wire logic [2:0]                    dma_d_opcode,
    input   wire logic [1:0]                    dma_d_param,
    input   wire logic [3:0]                    dma_d_size,
    input   wire logic                          dma_d_denied,
    input   wire logic [31:0]                   dma_d_data,
    input   wire logic                          dma_d_corrupt,
    input   wire logic                          dma_d_valid,
    output  wire logic                          dma_d_ready
);
    assign dma_d_ready = 1;
    reg [TL_AW-1:0] bytesRemaining; // for not crossing cache line reasons maximum burst request size is 128 bytes

    wire write_fifo = dma_d_ready&dma_d_valid&(dma_d_opcode==1);
    wire full;
    wire read_fifo;
    wire [31:0] read_data;
    wire empty;
    sfifo #(.DW(32), .FW(32)) fifo (dmac_clock_i, dmac_reset_i, write_fifo, dma_d_data, full, read_fifo, read_data, empty);

    reg [TL_AW-1:0] current_source_address;
    reg [TL_AW-1:0] current_destination_address;

    reg [1:0] dma_state;
    localparam IDLE = 2'b00;
    localparam DMA_READ = 2'b01;
    localparam DMA_AWAIT = 2'b10;
    localparam DMA_WRITE = 2'b11;

    logic [3:0] max_burst_size_from_dest_addr;
    logic [TL_AW-1:0] bytes_0;
    assign dmac_busy_o = dma_state!=IDLE;
    always_comb begin
        casez (current_destination_address[6:0])
            7'bzzzzzz1: begin
                max_burst_size_from_dest_addr = 4'd0;
                bytes_0 = 1;
            end
            7'bzzzzz10: begin
                max_burst_size_from_dest_addr = 4'd1;
                bytes_0 = 2;
            end
            7'bzzzz100: begin
                max_burst_size_from_dest_addr = 4'd2;
                bytes_0 = 4;
            end
            7'bzzz1000: begin
                max_burst_size_from_dest_addr = 4'd3;
                bytes_0 = 8;
            end
            7'bzz10000: begin
                max_burst_size_from_dest_addr = 4'd4;
                bytes_0 = 16;
            end
            7'bz100000: begin
                max_burst_size_from_dest_addr = 4'd5;
                bytes_0 = 32;
            end
            7'b1000000: begin
                max_burst_size_from_dest_addr = 4'd6;
                bytes_0 = 64;
            end
            default: begin
                max_burst_size_from_dest_addr = 4'd7;
                bytes_0 = 128;
            end
        endcase
    end
    logic [3:0] max_burst_size_from_src_addr;
    logic [TL_AW-1:0] bytes_1;
    always_comb begin
        casez (current_source_address[6:0])
            7'bzzzzzz1: begin
                max_burst_size_from_src_addr = 4'd0;
                bytes_1 = 1;
            end
            7'bzzzzz10: begin
                max_burst_size_from_src_addr = 4'd1;
                bytes_1 = 2;
            end
            7'bzzzz100: begin
                max_burst_size_from_src_addr = 4'd2;
                bytes_1 = 4;
            end
            7'bzzz1000: begin
                max_burst_size_from_src_addr = 4'd3; bytes_1 = 8;
            end
            7'bzz10000: begin
                max_burst_size_from_src_addr = 4'd4; bytes_1 = 16;
            end
            7'bz100000: begin
                max_burst_size_from_src_addr = 4'd5; bytes_1 = 32;
            end
            7'b1000000: begin
                max_burst_size_from_src_addr = 4'd6; bytes_1 = 64;
            end
            default: begin
                max_burst_size_from_src_addr = 4'd7; bytes_1 = 128;
            end
        endcase
    end
    logic [3:0] max_burst_size_from_remainder;
    logic [TL_AW-1:0] bytes_2;
    always_comb begin
        casez (bytesRemaining[6:0])
            7'bzzzzzz1: begin
                max_burst_size_from_remainder = 4'd0; bytes_2 = 1;
            end
            7'bzzzzz10: begin
                max_burst_size_from_remainder = 4'd1; bytes_2 = 2;
            end
            7'bzzzz100: begin
                max_burst_size_from_remainder = 4'd2; bytes_2 = 4;
            end
            7'bzzz1000: begin
                max_burst_size_from_remainder = 4'd3; bytes_2 = 8;
            end
            7'bzz10000: begin
                max_burst_size_from_remainder = 4'd4; bytes_2 = 16;
            end
            7'bz100000: begin
                max_burst_size_from_remainder = 4'd5; bytes_2 = 32;
            end
            7'b1000000: begin
                max_burst_size_from_remainder = 4'd6; bytes_2 = 64;
            end
            default: begin
                max_burst_size_from_remainder = 4'd7; bytes_2 = 128;
            end
        endcase
    end
    wire [3:0] min_stage1 = max_burst_size_from_dest_addr < max_burst_size_from_src_addr ? max_burst_size_from_dest_addr : max_burst_size_from_src_addr;
    wire [3:0] minimum = max_burst_size_from_remainder < min_stage1 ? max_burst_size_from_remainder : min_stage1;
    wire [TL_AW-1:0] min_stage1_bsize = max_burst_size_from_dest_addr < max_burst_size_from_src_addr ? bytes_0 : bytes_1;
    wire [TL_AW-1:0] minimum_bytes = max_burst_size_from_remainder < min_stage1 ? bytes_2 : min_stage1_bsize;
    reg [7:0] byte_count;
    reg [7:0] count_store;
    reg [3:0] size_store;
    reg [5:0] ack_store;
    reg [5:0] count_ack;
    assign read_fifo = dma_a_ready && (byte_count!=count_store);
    always_ff @(posedge dmac_clock_i) begin
        case (dma_state)
            IDLE: begin
                if (dmac_tx_i) begin
                    bytesRemaining <= dmac_bytes_tx_i;
                    current_source_address <= dmac_source_address_i;
                    current_destination_address <= dmac_dest_address_i;
                    dma_state <= DMA_READ;
                end
            end
            DMA_READ: begin
                if (dma_a_ready && (bytesRemaining != 0)) begin
                    dma_a_address <= current_source_address;
                    dma_a_corrupt <= 0;
                    dma_a_opcode <= 3'd4;
                    dma_a_param <= 0;
                    dma_a_data <= 0;
                    dma_a_mask <= 0;
                    dma_a_size <= minimum;
                    dma_a_valid <= 1;
                    dma_state <= DMA_AWAIT;
                    current_source_address <= dmac_stationary_rd_i ? current_source_address : current_source_address + minimum_bytes;
                    bytesRemaining <= bytesRemaining - minimum_bytes;
                    byte_count <= 0;
                    count_store <= minimum_bytes[7:0];
                    size_store <= minimum;
                end else if (bytesRemaining==0) begin
                    dmac_done_o <= 1;
                    dmac_err_o <= 0;
                    dma_state <= IDLE;
                end
            end
            DMA_AWAIT: begin
                dma_a_valid <= 0;
                if (byte_count == count_store) begin
                    dma_state <= DMA_WRITE;
                    byte_count <= 0;
                    ack_store <= count_store[7:2] + {4'h0, |count_store[1:0]};
                end else if (dma_d_ready&dma_d_valid) begin
                    byte_count <= byte_count + (dma_a_size >= 2 ? 4 : dma_a_size == 1 ? 2 : 1);
                end
            end
            DMA_WRITE: begin
                if (dma_a_ready && (byte_count!=count_store)) begin
                    dma_a_address <= current_destination_address;
                    dma_a_corrupt <= 0;
                    dma_a_data <= read_data;
                    dma_a_mask <= 4'b1111;
                    dma_a_opcode <= 3'd0;
                    dma_a_param <= 0;
                    dma_a_size <= size_store;
                    dma_a_valid <= 1;
                    byte_count <= byte_count + (dma_a_size >= 2 ? 4 : dma_a_size == 1 ? 2 : 1);
                    current_destination_address <= dmac_stationary_wr_i ? current_destination_address : (size_store >= 2 ? 4 : size_store == 1 ? 2 : 1);
                end
                else if (byte_count==count_store) begin
                    if (count_ack==ack_store) begin
                        dma_state <= DMA_READ;
                        count_ack <= 0;
                    end
                    dma_a_valid <= 0;
                end
                if (dma_d_valid&dma_d_ready&(dma_d_opcode==0)) begin
                    count_ack <= count_ack + 1;
                end
            end
        endcase
    end
endmodule

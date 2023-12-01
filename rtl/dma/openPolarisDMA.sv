module openPolarisDMA
#(
    parameter NoC = 2, //! Number of channels to generate
    parameter TL_RS = 4
)
(
    input   wire logic                      dma_clock_i,
    input   wire logic                      dma_reset_i,

    // Slave interface
    input   wire logic [2:0]                dma_a_opcode,
    input   wire logic [2:0]                dma_a_param,
    input   wire logic [3:0]                dma_a_size,
    input   wire logic [TL_RS-1:0]          dma_a_source,
    input   wire logic [$clog2(NoC*('h80))-1:0]   dma_a_address,
    input   wire logic [3:0]                dma_a_mask,
    input   wire logic [31:0]               dma_a_data,
    input   wire logic                      dma_a_corrupt,
    input   wire logic                      dma_a_valid,
    output  wire logic                      dma_a_ready,

    output  wire logic [2:0]                dma_d_opcode,
    output  wire logic [2:0]                dma_d_param,
    output  wire logic [3:0]                dma_d_size,
    output  wire logic [TL_RS-1:0]          dma_d_source,
    output  wire logic                      dma_d_denied,
    output  wire logic [31:0]               dma_d_data,
    output  wire logic                      dma_d_corrupt,
    output  wire logic                      dma_d_valid,
    input   wire logic                      dma_d_ready,

    output       logic [(3*NoC)-1:0]        sa_opcode ,
    output       logic [(3*NoC)-1:0]        sa_param ,
    output       logic [(4*NoC)-1:0]    sa_size ,
    output       logic [(TL_RS*NoC)-1:0]    sa_source ,
    output       logic [(32*NoC)-1:0]    sa_address ,
    output       logic [NoC*(4)-1:0] sa_mask ,
    output       logic [(32*NoC)-1:0] sa_data ,
    output       logic [NoC-1:0]            sa_corrupt ,
    output       logic [NoC-1:0]            sa_valid ,
    input   wire logic [NoC-1:0]            sa_ready ,

    input   wire logic [(3*NoC)-1:0]        sd_opcode,
    input   wire logic [(2*NoC)-1:0]        sd_param,
    input   wire logic [(4*NoC)-1:0]    sd_size,
    input   wire logic [(TL_RS*NoC)-1:0]    sd_source,
    input   wire logic [NoC-1:0]            sd_denied,
    input   wire logic [(32*NoC)-1:0] sd_data,
    input   wire logic [NoC-1:0]            sd_corrupt,
    input   wire logic [NoC-1:0]            sd_valid,
    output  wire logic [NoC-1:0]            sd_ready,

    output  wire logic [(NoC*2)-1:0]        irq_cmp_o
);
    //! Configurable multi-channel DMA controller
    //! Address calculation: every 0x80 lies a new channel
    //! DMACTRL = DMA_BASE + (0x80*CNO) + 0x00
    //! DMANEXTSRC = DMA_BASE + (0x80*CNO) + 0x04
    //! DMANEXTDEST = DMA_BASE + (0x80*CNO) + 0x08
    //! DMANEXTSIZE = DMA_BASE + (0x80*CNO) + 0x0C
    //! DMATX = DMA_BASE + (0x80*CNO) + 0x10
    wire dma_busy;
    wire [TL_RS-1:0] working_source;
    wire [3:0] working_size;
    wire [31:0] working_data;
    wire [3:0] working_mask;
    wire [2:0] working_opcode;
    wire [$clog2(NoC*('h80))-1:0] working_address;
    wire working_valid;
    skdbf #(TL_RS+4+39+$clog2(NoC*('h80))) skidbuffer (dma_clock_i, dma_reset_i, ~dma_d_ready, {
        working_source,
        working_size,
        working_data,
        working_mask,
        working_opcode,
        working_address
    }, working_valid, dma_busy, {
        dma_a_source, dma_a_size, dma_a_data, dma_a_mask, dma_a_opcode, dma_a_address
    }, dma_a_valid);

    reg [3:0] dmactrl [0:NoC-1]; // IE, IP, RXS, TXS
    reg [31:0] dmasrc [0:NoC-1];
    reg [31:0] dmadest [0:NoC-1];
    reg [31:0] dmasize [0:NoC-1];
    wire [$clog2(NoC)-1:0] referenced_core = working_address[$clog2(NoC*('h80))-1:$clog2(('h80))];
    wire [NoC-1:0] start;
    wire [NoC-1:0] busy;
    wire [NoC-1:0] done;
    wire [NoC-1:0] err;
    for (genvar i = 0; i < NoC; i++) begin : generateDMACores
        openPolarisDMACore #(.TL_AW(32)) core (dma_clock_i, dma_reset_i, start[i], dmasrc[i],
        dmadest[i], dmasize[i], dmactrl[i][0], dmactrl[i][1], busy[i], done[i], err[i],
        sa_opcode[3*(i+1)-1:3*i], sa_param[3*(i+1)-1:3*i], sa_size[4*(i+1)-1:4*i], sa_address[32*(i+1)-1:32*i], 
        sa_mask[4*(i+1)-1:4*i], sa_data[32*(i+1)-1:32*i], sa_corrupt[i], sa_valid[i], sa_ready[i],
        sd_opcode[3*(i+1)-1:3*i], sd_param[2*(i+1)-1:2*i], sd_size[4*(i+1)-1:4*i], 
        sd_denied[i], sd_data[32*(i+1)-1:32*i], sd_corrupt[i], sd_valid[i], sd_ready[i]
        );
        assign sa_source[TL_RS*(i+1)-1:TL_RS*i] = 0;
    end

    always_ff @(posedge dma_clock_i) begin
        if (dma_d_ready&working_valid&(working_address[$clog2('h80)-1:0]=='h04)&(working_opcode==3'd0)) begin
            dmasrc[referenced_core] <= working_data;
        end
        if (dma_d_ready&working_valid&(working_address[$clog2('h80)-1:0]=='h08)&(working_opcode==3'd0)) begin
            dmadest[referenced_core] <= working_data;
        end
        if (dma_d_ready&working_valid&(working_address[$clog2('h80)-1:0]=='h0C)&(working_opcode==3'd0)) begin
            dmasize[referenced_core] <= working_data;
        end
        if (dma_d_ready&working_valid&(working_address[$clog2('h80)-1:0]==8'h00)&(working_opcode==3'd0)) begin
            
        end
    end

endmodule

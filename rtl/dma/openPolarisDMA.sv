module openPolarisDMA
#(
    parameter NoC = 2, //! Number of channels to generate
    parameter TL_AW = 32,
    parameter TL_DW = 32,
    parameter TL_RS = 4,
    parameter TL_SZ = 4
)
(
    input   wire logic                      dma_clock_i,
    input   wire logic                      dma_reset_i,

    // Slave interface
    input   wire logic [2:0]                dma_a_opcode,
    input   wire logic [2:0]                dma_a_param,
    input   wire logic [TL_SZ-1:0]          dma_a_size,
    input   wire logic [TL_RS-1:0]          dma_a_source,
    input   wire logic [$clog2(NoC*('h80))-1:0]   dma_a_address,
    input   wire logic [3:0]                dma_a_mask,
    input   wire logic [31:0]               dma_a_data,
    input   wire logic                      dma_a_corrupt,
    input   wire logic                      dma_a_valid,
    output  wire logic                      dma_a_ready,

    output  wire logic [2:0]                dma_d_opcode,
    output  wire logic [2:0]                dma_d_param,
    output  wire logic [TL_SZ-1:0]          dma_d_size,
    output  wire logic [TL_RS-1:0]          dma_d_source,
    output  wire logic                      dma_d_denied,
    output  wire logic [31:0]               dma_d_data,
    output  wire logic                      dma_d_corrupt,
    output  wire logic                      dma_d_valid,
    input   wire logic                      dma_d_ready,

    output       logic [(3*NoC)-1:0]        sa_opcode ,
    output       logic [(3*NoC)-1:0]        sa_param ,
    output       logic [(TL_SZ*NoC)-1:0]    sa_size ,
    output       logic [(TL_RS*NoC)-1:0]    sa_source ,
    output       logic [(TL_AW*NoC)-1:0]    sa_address ,
    output       logic [NoC*((2**TL_DW)/8)-1:0] sa_mask ,
    output       logic [(2**(TL_DW)*NoC)-1:0] sa_data ,
    output       logic [NoC-1:0]            sa_corrupt ,
    output       logic [NoC-1:0]            sa_valid ,
    input   wire logic [NoC-1:0]            sa_ready ,

    input   wire logic [(3*NoC)-1:0]        sd_opcode,
    input   wire logic [(3*NoC)-1:0]        sd_param,
    input   wire logic [(TL_SZ*NoC)-1:0]    sd_size,
    input   wire logic [(TL_RS*NoC)-1:0]    sd_source,
    input   wire logic [NoC-1:0]            sd_denied,
    input   wire logic [(2**(TL_DW)*NoC)-1:0] sd_data,
    input   wire logic [NoC-1:0]            sd_corrupt,
    input   wire logic [NoC-1:0]            sd_valid,
    output  wire logic [NoC-1:0]            sd_ready,

    output  wire logic [(NoC*2)-1:0]        irq_o
);
    //! Configurable multi-channel DMA controller
    //! Address calculation: every 0x80 lies a new channel
    //! DMACTRL = DMA_BASE + (0x80*CNO) + 0x0
    //! DMANEXTSRC = DMA_BASE + (0x80*CNO) + 0x4
    //! DMANEXTDEST = DMA_BASE + (0x80*CNO) + 0x0C
    //! DMANEXTSIZE = DMA_BASE + (0x80*CNO) + 0x14
    //! DMACURRSRC = DMA_BASE + (0x80*CNO) + 0x1C
    //! DMACURRDEST = DMA_BASE + (0x80*CNO) + 0x24
    //! DMACURRSIZE = DMA_BASE + (0x80*CNO) + 0x2C



endmodule

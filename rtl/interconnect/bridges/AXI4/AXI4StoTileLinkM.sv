module AXI4StoTileLinkM #(
    parameter CAW = 28,
    parameter CDW = 32,
    parameter CIW = 4
) (
    input   wire logic                  axi_aclk_i,
    input   wire logic                  axi_aresetn_i,

    output       logic [CIW-1:0]        axi_arid_o,
    output       logic [CAW-1:0]        axi_araddr_o,
    output       logic [7:0]            axi_arlen_o,
    

);
    
endmodule

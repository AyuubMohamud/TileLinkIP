module TileLinkMtoAXI4S #(
    parameter CAW = 28,
    parameter CDW = 32,
    parameter CIW = 4
) (
    input   wire logic                          axi_aclk,
    input   wire logic                          axi_aresetn,

    input   wire logic [2:0]                    master_a_opcode,
    input   wire logic [2:0]                    master_a_param,
    input   wire logic [3:0]                    master_a_size,
    input   wire logic [CIW-1:0]                master_a_source,
    input   wire logic [CAW-1:0]                master_a_address,
    input   wire logic [CDW/8-1:0]              master_a_mask,
    input   wire logic [CDW-1:0]                master_a_data,
    input   wire logic                          master_a_corrupt,
    input   wire logic                          master_a_valid,
    output  wire logic                          master_a_ready,

    output       logic [2:0]                    master_d_opcode,
    output       logic [1:0]                    master_d_param,
    output       logic [3:0]                    master_d_size,
    output       logic [CIW-1:0]                master_d_source,
    output       logic                          master_d_denied,
    output       logic [CDW-1:0]                master_d_data,
    output       logic                          master_d_corrupt,
    output       logic                          master_d_valid,
    input   wire logic                          master_d_ready,

    output       logic [CIW-1:0]                axi_arid,
    output       logic [CAW-1:0]                axi_araddr,
    output       logic [7:0]                    axi_arlen,
    output       logic [2:0]                    axi_arsize,
    output       logic [1:0]                    axi_arburst,
    output       logic                          axi_arlock,
    output       logic [3:0]                    axi_arcache,
    output       logic [2:0]                    axi_arprot,
    output       logic                          axi_arvalid,
    input   wire logic                          axi_arready,

    input   wire logic [CIW-1:0]                axi_rid,
    input   wire logic [CDW-1:0]                axi_rdata,
    input   wire logic [1:0]                    axi_rresp,
    input   wire logic                          axi_rlast,
    input   wire logic                          axi_rvalid,
    output       logic                          axi_rready,

    output       logic [CIW-1:0]                axi_awid,
    output       logic [CAW-1:0]                axi_awaddr,
    output       logic [7:0]                    axi_awlen,
    output       logic [2:0]                    axi_awsize,
    output       logic [1:0]                    axi_awburst,
    output       logic                          axi_awlock,
    output       logic [3:0]                    axi_awcache,
    output       logic [2:0]                    axi_awprot,
    output       logic                          axi_awvalid,
    input   wire logic                          axi_awready,

    output       logic [CDW-1:0]                axi_wdata,
    output       logic [CDW/8-1:0]              axi_wstrb,
    output       logic                          axi_wlast,
    output       logic                          axi_wvalid,
    input   wire logic                          axi_wready,

    input   wire logic [CIW-1:0]                axi_bid,
    input   wire logic [1:0]                    axi_bresp,
    input   wire logic                          axi_bvalid,
    output       logic                          axi_bready
);      
    // No atomics support
    wire bridge_busy;
    wire [2:0]       working_master_a_opcode;
    wire [2:0]       working_master_a_param;
    wire [3:0]       working_master_a_size;
    wire [CIW-1:0]   working_master_a_source;
    wire [CAW-1:0]   working_master_a_address;
    wire [CDW/8-1:0] working_master_a_mask;
    wire [CDW-1:0]   working_master_a_data;
    wire             working_master_a_corrupt;
    wire             working_master_a_valid;
    wire bridge_processing;
    assign master_a_ready = ~bridge_busy;
    skdbf #(.DW(11+CIW+CAW+CDW/8+CDW)) skdbf (axi_aclk, ~axi_aresetn, bridge_processing, {working_master_a_opcode, working_master_a_param, working_master_a_size, working_master_a_source, working_master_a_address, working_master_a_mask, working_master_a_data, working_master_a_corrupt},
    working_master_a_valid, bridge_busy, {master_a_opcode, master_a_param, master_a_size, master_a_source, master_a_address, master_a_mask, master_a_data, master_a_corrupt}, master_a_valid);

    logic [7:0] amount_to_push;
    always_comb begin
        case (master_a_size)
            4'd5: begin
                amount_to_push = 1;
            end
            4'd6: begin
                amount_to_push = 3;
            end
            4'd7: begin
                amount_to_push = 7;
            end
            4'd8: begin
                amount_to_push = 15;
            end
            4'd9: begin
                amount_to_push = 31;
            end
            4'd10: begin
                amount_to_push = 63;
            end
            4'd11: begin
                amount_to_push = 127;
            end
            4'd12: begin
                amount_to_push = 255;
            end
            default: begin
                amount_to_push = 0;
            end
        endcase
    end
    reg [2:0] bridge_fsm;
    wire write_request_accepted = axi_awvalid&axi_awready;
    wire write_data_accepted = axi_wready&axi_wvalid;
    wire read_request_accepted = axi_arvalid&axi_arready;
    logic [3:0]                     r_master_a_size;
    logic [CIW-1:0]                 r_master_a_source;
    logic [CDW/8-1:0]               r_master_a_mask;
    logic [CDW-1:0]                 r_master_a_data;
    reg [7:0] burst_counter;
    assign axi_bready = master_d_ready;
    assign axi_rready = master_d_ready;
    assign bridge_processing = (bridge_fsm!=3'b000)&&(bridge_fsm!=3'b010);
    always_ff @(posedge axi_aclk) begin
        case (bridge_fsm)
            3'b000: begin
                r_master_a_data <= working_master_a_data;
                r_master_a_mask <= working_master_a_mask;
                r_master_a_size <= working_master_a_size;
                burst_counter <= amount_to_push;
                r_master_a_source <= working_master_a_source;
                if (working_master_a_valid&&(working_master_a_opcode==3'd0|working_master_a_opcode==3'd1)) begin
                    axi_awid <= 0;
                    axi_awaddr <= working_master_a_address;
                    axi_awlen <= amount_to_push;
                    axi_awsize <= 4;
                    axi_awburst <= 2'b01;
                    axi_awlock <= 0;
                    axi_awcache <= 0;
                    axi_awprot <= 0;
                    axi_awvalid <= 1;
                    bridge_fsm <= 3'b001;
                end else if (working_master_a_valid&&(working_master_a_opcode==3'd4)) begin
                    axi_arid <= 0;
                    axi_araddr <= working_master_a_address;
                    axi_arlen <= amount_to_push;
                    axi_arsize <= 4;
                    axi_arburst <= 2'b01;
                    axi_arlock <= 0;
                    axi_arcache <= 0;
                    axi_arprot <= 0;
                    axi_arvalid <= 1;
                    bridge_fsm <= 3'b101;
                end
            end
            3'b001: begin
                if (write_request_accepted) begin
                    axi_awvalid <= 0;
                    axi_wdata <= r_master_a_data;
                    axi_wstrb <= r_master_a_mask;
                    axi_wlast <= burst_counter == 0;
                    axi_wvalid <= 1;
                    bridge_fsm <= 3'b011;
                end
            end
            3'b010: begin
                axi_wvalid <= 1;
                axi_wdata <= master_a_data;
                axi_wstrb <= master_a_mask;
                axi_wlast <= burst_counter == 0;
                bridge_fsm <= 3'b011;
            end
            3'b011: begin
                if (write_data_accepted) begin
                    axi_wvalid <= 0;
                    if (amount_to_push==0) begin
                        bridge_fsm <= 3'b100;
                    end else begin
                        burst_counter <= burst_counter - 1'b1;
                        bridge_fsm <= 3'b010;
                    end
                end
            end
            3'b100: begin
                if (axi_bready&&axi_bvalid&&(axi_bid==0)) begin
                    master_d_denied <= axi_bresp != 0;
                    master_d_opcode <= 0;
                    master_d_valid <= 1;
                    master_d_size <= r_master_a_size;
                    master_d_source <= r_master_a_source;
                    bridge_fsm <= 3'b000;
                end
            end
            3'b101: begin
                if (read_request_accepted) begin
                    axi_arvalid <= 0;
                    bridge_fsm <= 3'b110;
                end
            end
            3'b110: begin
                if (axi_rready&&axi_rvalid&&(axi_rid==0)) begin
                    master_d_data <= axi_rdata;
                    master_d_valid <= 1;
                    master_d_opcode <= 1;
                    master_d_size <= r_master_a_size;
                    master_d_source <= r_master_a_source;
                    master_d_denied <= axi_rresp != 0;
                    bridge_fsm <= axi_rlast ? 3'b000 : 3'b101;
                end
            end
            default: begin
                
            end
        endcase
    end

endmodule

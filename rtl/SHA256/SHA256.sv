module SHA256 (
    input   wire logic              sha256_clock_i,
    input   wire logic              sha256_reset_i,

    input   wire logic [511:0]      sha256_message_i,
    input   wire logic              sha256_calc_i,
    input   wire logic              valid_i,
    output  wire logic              accept_o,


);
    function [31:0] sum256_0;
        input [31:0] x;
        sum256_0 = {x[1:0], x[31:2]}^{x[12:0], x[31:13]}^{x[21:0],x[31:22]};
    endfunction
    function [31:0] sum256_1;
        input [31:0] x;
        sum256_1 = {x[5:0], x[31:6]}^{x[10:0],x[31:11]}^{x[24:0], x[31:25]};
    endfunction
    function [31:0] sigma256_0;
        input [31:0] x;
        sigma256_0 = {x[6:0],x[31:7]}^{x[17:0],x[31:18]}^{3'b000, x[31:3]};
    endfunction
    function [31:0] sigma256_1;
        input [31:0] x;
        sigma256_1 = {x[16:0],x[31:17]}^{x[18:0],x[31:19]}^{10'd0, x[31:10]};
    endfunction
    function [31:0] ch256;
        input [31:0] x,y,z;
        ch256 = (x&y)^(~x&z);
    endfunction
    function [31:0] maj256;
        input [31:0] x,y,z;
        maj256 = (x&y)^(x&z)^(y&z);
    endfunction
    reg [31:0] h0;
    reg [31:0] h1;
    reg [31:0] h2;
    reg [31:0] h3;
    reg [31:0] h4;
    reg [31:0] h5;
    reg [31:0] h6;
    reg [31:0] h7;
    reg [31:0] a;
    reg [31:0] b;
    reg [31:0] c;
    reg [31:0] d;
    reg [31:0] e;
    reg [31:0] f;
    reg [31:0] g;
    reg [31:0] h;

    reg [31:0] const_table [0:63];
    reg [31:0] message_schedule [0:63];
    localparam await_message = 3'b000;
    localparam message_schedule_prepare = 3'b001;
    reg [2:0] sha256_hash_calc_fsm = await_message;

    reg [5:0] t = 0;
    wire [31:0] message_select;
    assign message_select = t==0 ? sha256_message_i[31:0] : t==1 ? sha256_message_i[63:32] :
    t == 2 ? sha256_message_i[95:64] : t==3 ? sha256_message_i[127:96] : t==4 ? sha256_message_i[159:128] :
    t==5 ? sha256_message_i[191:160] : t==6 ? sha256_message_i[223:192] : t==7 ? sha256_message_i[255:224] :
    t==8 ? sha256_message_i[287:256] : t==9 ? sha256_message_i[319:288] : t==10 ? sha256_message_i[351:320]:
    t==11 ? sha256_message_i[383:352] : t==12 ? sha256_message_i[415:384] : t==13 ? sha256_message_i[447:416]:
    t==14 ? sha256_message_i[479:448] : sha256_message_i[511:480];

    reg [1:0] count = 0;
    wire [31:0] acc = count==1 ? sum256_0(message_schedule[t-15]) : message_schedule[t-16];

    always_ff @(posedge sha256_clock_i) begin
        if (sha256_reset_i) begin
            sha256_hash_calc_fsm <= await_message;
            a <= 32'h6a09e667;
            b <= 32'hbb67ae85;
            c <= 32'h3c6ef372;
            d <= 32'ha54ff53a;
            e <= 32'h510e527f;
            f <= 32'h9b05688c;
            g <= 32'h1f83d9ab;
            h <= 32'h5be0cd19;
            h0<= 32'h6a09e667;
            h1<= 32'hbb67ae85;
            h2<= 32'h3c6ef372;
            h3<= 32'ha54ff53a;
            h4<= 32'h510e527f;
            h5<= 32'h9b05688c;
            h6<= 32'h1f83d9ab;
            h7<= 32'h5be0cd19;
        end else begin
            case (sha256_hash_calc_fsm)
                await_message: begin
                    
                end
                message_schedule_prepare: begin
                    if (t<16) begin
                        message_schedule[t] <= message_select;
                        t <= t + 1;
                    end else begin
                        if (count==0) begin
                            message_schedule[t] <= sum256_1(message_schedule[t-2]) + message_schedule[t-7];
                            count <= count + 1;
                        end else if (count==1) begin
                            message_schedule[t] <= message_schedule[t] + acc;
                            count <= count + 1;
                        end else if (count==2) begin
                            message_schedule[t] <= message_schedule[t] + acc;
                            count <= 0;
                            t <= t + 1;
                        end
                    end
                    if ((count==2)&(t==63)) begin
                        
                    end
                end
            endcase
        end
    end
endmodule

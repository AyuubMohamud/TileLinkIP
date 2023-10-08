module something (
	input 	wire logic [11:0] someinput,
	input 	wire logic [3:0] valid,
	output 	wire logic [2:0] someoutput

);
	always_comb begin
		casez (valid)
			4'bzzz1: someoutput = someinput[2:0];
			4'bzz10: someoutput = someinput[5:3];
			4'bz100: someoutput = someinput[8:6];
			4'b1000: someoutput = someinput[11:9];
			default: someoutput = 0;
		endcase
	end

endmodule


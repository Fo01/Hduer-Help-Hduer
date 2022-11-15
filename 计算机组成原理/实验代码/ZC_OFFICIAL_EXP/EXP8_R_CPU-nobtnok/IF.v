`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:43:51 02/26/2014 
// Design Name: 
// Module Name:    IF 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module IF_M(
    input clk,
    input rst,
    output [31:0] Inst_code
//    output [31:0] PC_out
    );
	reg [31:0] PC;
	wire [31:0] PC_new;
	
	ROM_B Inst_ROM (
	  .clka(clk), // input clka
	  .addra(PC[7:2]), // input [5 : 0] addra
	  .douta(Inst_code) // output [31 : 0] douta
	);
	
	assign PC_new = PC + 4;
//	assign PC_out = {24'b0,PC[7:0]};
	
	always @(negedge clk or posedge rst)
	begin
		if (rst)
			PC <= 32'h0000_0000;
		else
			PC <= PC_new;
	end;

endmodule

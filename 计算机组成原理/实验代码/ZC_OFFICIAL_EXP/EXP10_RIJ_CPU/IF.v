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
	 input [31:0] PC_next,
    output [31:0] Inst_code,
	 output reg[31:0] PC,
    output [31:0] PC_new
    );
		
	ROM_B Inst_ROM (
	  .clka(clk), // input clka
	  .addra(PC[7:2]), // input [5 : 0] addra
	  .douta(Inst_code) // output [31 : 0] douta
	);
	
	assign PC_new = PC + 4;
	
	always @(negedge clk or posedge rst)
	begin
		if (rst)
			PC <= 32'h0000_0000;
		else
			PC <= PC_next;
	end;

endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:12:52 02/26/2014 
// Design Name: 
// Module Name:    IF_Exp 
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
module IF_Exp(
	input clk,
	input rst,
	input [1:0] SW,
	output reg [7:0] LED
    );

	wire [31:0] Inst_code,PC_out;

	IF_M		My_CPU_IF(clk,rst,Inst_code,PC_out);
	
	always @(*)
	begin
		case (SW[1:0])
			2'b00:	LED = Inst_code[7:0];
			2'b01:	LED = Inst_code[15:8];			
			2'b10:	LED = Inst_code[23:16];
			2'b11:	LED = Inst_code[31:24];			
		endcase
	end;

endmodule

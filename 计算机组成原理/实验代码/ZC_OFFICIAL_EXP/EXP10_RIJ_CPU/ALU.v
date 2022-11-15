`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:09:25 02/04/2014 
// Design Name: 
// Module Name:    ALU_8F 
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
module ALU(
    input [31:0] A,
    input [31:0] B,
    input [2:0] ALU_OP,
    output reg [31:0] F,
    output ZF,
    output OF
    );
	
	parameter Zero_32 = 32'h0000_0000, One_32 = 32'h0000_0001;//常量0和1,32位数据
	reg C32;

	always @(*)
	begin
		C32 = 1'b0;
		case (ALU_OP)			//ALU的功能选择控制线
			3'b000:	F = A & B;
			3'b001:	F = A | B;			
			3'b010:	F = A ^ B;
			3'b011:	F = ~(A | B);
			3'b100:	{C32,F} = A + B;
			3'b101:	{C32,F} = A - B;
			3'b110:	F = (A < B) ? One_32 : Zero_32;
			3'b111:	F = B << A;
			default: F = Zero_32;
		endcase
	end
	assign ZF = (F == Zero_32) ? 1'b1 : 1'b0;
	assign OF = ((ALU_OP==3'b100)||(ALU_OP==3'b101))&&(A[31] ^ B[31] ^ F[31] ^ C32);

endmodule

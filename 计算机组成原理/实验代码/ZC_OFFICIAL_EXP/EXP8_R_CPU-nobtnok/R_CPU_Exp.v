`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:40:14 03/02/2014 
// Design Name: 
// Module Name:    R_CPU_Exp 
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
module R_CPU_Exp(
    input clk,
    input rst,
	 input [1:0] SW,			//选择输出ALU_F的4个字节
	 output reg [7:0] LED			//显示某个字节
    );
	 
	wire clk;
	wire [31:0] ALU_F;
	
	R_CPU My_CPU(
    .clk(clk),
    .rst(rst),
	 .ALU_F(ALU_F)			//为显示指令运算结果用
    );
	 
	always @(*)
	begin
		case (SW[1:0])
			2'b00:	LED = ALU_F[7:0];
			2'b01:	LED = ALU_F[15:8];			
			2'b10:	LED = ALU_F[23:16];
			2'b11:	LED = ALU_F[31:24];			
		endcase
	end;

endmodule

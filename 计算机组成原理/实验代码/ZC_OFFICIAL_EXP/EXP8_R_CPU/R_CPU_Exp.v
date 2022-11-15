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
    input clk_100MHz,
	 input Step_BTN,
    input rst,
	 input [2:0] SW,			//选择输出ALU_F的4个字节
	 output reg [7:0] LED			//显示某个字节
    );
	 
	wire clk,ZF,OF;
	wire [31:0] ALU_F;
	
	BTN_OK My_BTN(
	 .clk_100MHz(clk_100MHz),
	 .BTN(Step_BTN),
	 .BTN_Out(clk)
	 );
	
	R_CPU My_CPU(
    .clk(clk),
    .rst(rst),
	 .FR_ZF(ZF),
	 .FR_OF(OF),
	 .ALU_F(ALU_F)			//为显示指令运算结果用
    );
	 
	always @(*)
	begin
		case (SW[2:0])
			3'b000:	LED = ALU_F[7:0];
			3'b001:	LED = ALU_F[15:8];			
			3'b010:	LED = ALU_F[23:16];
			3'b011:	LED = ALU_F[31:24];	
			3'b100:	begin LED[7] = OF;	LED[0] = ZF;	LED[6:1] = 6'b0;	end
			default:	LED = 8'b0;
		endcase
	end;

endmodule

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
module RIJ_CPU_Exp(
    input clk_100MHz,
	 input Step_BTN,
    input rst,
	 input [3:0] SW,			//选择输出ALU_F的4个字节
	 output reg [7:0] LED			//显示某个字节
    );
	 
	wire clk,ZF,OF;
	wire [31:0] ALU_F,Mem_R_Data,PC;
	
	
	BTN_OK My_BTN(
	 .clk_100MHz(clk_100MHz),
	 .BTN(Step_BTN),
	 .BTN_Out(clk)
	 );
	
	RIJ_CPU My_CPU(
    .clk(clk),
	 .clk_ram(clk_100MHz),
    .rst(rst),
	 .FR_ZF(ZF),
	 .FR_OF(OF),
	 .ALU_F(ALU_F),
	 .Mem_R_Data(Mem_R_Data),	//为显示指令运算结果用
	 .PC(PC)
    );
	 
	always @(*)
	begin
		case (SW[3:0])
			4'b0000:	LED = ALU_F[7:0];
			4'b0001:	LED = ALU_F[15:8];			
			4'b0010:	LED = ALU_F[23:16];
			4'b0011:	LED = ALU_F[31:24];	
			4'b0100:	LED = Mem_R_Data[7:0];
			4'b0101:	LED = Mem_R_Data[15:8];			
			4'b0110:	LED = Mem_R_Data[23:16];
			4'b0111:	LED = Mem_R_Data[31:24];	
			4'b1000:	begin LED[7] = OF;	LED[0] = ZF;	LED[6:1] = 6'b0;	end
			4'b1100:	LED = PC[7:0];
			4'b1101:	LED = PC[15:8];			
			4'b1110:	LED = PC[23:16];
			4'b1111:	LED = PC[31:24];			
			default:	LED = 8'b0;
		endcase
	end;

endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:31:55 02/07/2014 
// Design Name: 
// Module Name:    REG_Exp 
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
module REG_Exp(
    input Clk,
    input Reset,
    input [4:0] Reg_Addr,	//�Ĵ�����ַ
    input Write_Reg,			//д�ź�
    input [1:0] Sel,			//ѡ��д�����ݻ�����������ֽڵĿ����ź�
	 input AB,					//ѡ���A�˿ڻ���B�˿�
    output reg [7:0] LED	//��ʾ�������ݵ��ֽ�
    );
	
    reg [31:0] W_Data;	
    wire [31:0] R_Data_A,R_Data_B,LED_Data;
	
	REG Register(Clk,Reset,Reg_Addr,Reg_Addr,Reg_Addr,W_Data,Write_Reg,R_Data_A,R_Data_B);
	assign LED_Data = AB ? R_Data_A : R_Data_B;
	
	always @(*)
	begin
		if (Write_Reg)
			begin
				case (Sel)
					2'b00:	W_Data = 32'h1234_5678;
					2'b01:	W_Data = 32'h89AB_CDEF;	
					2'b10:	W_Data = 32'h7766_AABB;	
					2'b11:	W_Data = 32'h2014_0316;	
					default:	W_Data = 32'h0000_0000;
				endcase
			end
		else W_Data = 32'h1122_3344;
	end
	
	always @(*)
	begin
		case (Sel)
			2'b00:	LED = LED_Data[7:0];
			2'b01:	LED = LED_Data[15:8];
			2'b10:	LED = LED_Data[23:16];
			2'b11:	LED = LED_Data[31:24];	
			default:	LED = 8'b0000_0000;
		endcase
	end
	
endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:23:04 02/04/2014 
// Design Name: 
// Module Name:    ALU_8F_EXP 
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
module ALU_8F_EXP(
    input [2:0] ALU_OP,
    input [2:0] AB_SW,
    input [2:0] F_LED_SW,
	 output reg [7:0] LED
    );

    reg [31:0] A,B;
	 wire [31:0] F;
    wire ZF,OF;	 
	 
	 ALU_8F ALU_UUT(A,B,ALU_OP,F,ZF,OF);
	 
	 always @(*)
	 begin
		case (AB_SW)		//使用3位开关，选择指定的8组测试数据
			3'b000:	begin A = 32'h0000_0000;	B = 32'hFFFF_FFFF;	end
			3'b001:	begin A = 32'h0000_0003;	B = 32'h0000_0607;	end
			3'b010:	begin A = 32'h8000_0000;	B = 32'h8000_0000;	end
			3'b011:	begin A = 32'h7FFF_FFFF;	B = 32'h7FFF_FFFF;	end
			3'b100:	begin A = 32'hFFFF_FFFF;	B = 32'hFFFF_FFFF;	end
			3'b101:	begin A = 32'h8000_0000;	B = 32'hFFFF_FFFF;	end
			3'b110:	begin A = 32'hFFFF_FFFF;	B = 32'h8000_0000;	end
			3'b111:	begin A = 32'h1234_5678;	B = 32'h3333_2222;	end
			default:	begin A = 32'h9ABC_DEF0;	B = 32'h1111_2222;	end
		endcase
	 end
	 
	 always @(*)
	 begin
		case (F_LED_SW)		
		//使用2位开关(F_LED_SW[1:0])，和一个按钮（F_LED_SW[2]），选择显示32位运算结果的4个字节（按钮松开,F_LED_SW[2]==0）
		//或者显示运算结果的状态ZF和OF（按钮按下,F_LED_SW[2]==1）
			3'b000:	LED = F[7:0];
			3'b001:	LED = F[15:8];
			3'b010:	LED = F[23:16];
			3'b011:	LED = F[31:24];
			default: begin LED[7] = ZF; LED[0] = OF;	LED[6:1] = 6'b0;	end
			// F_LED_SW[2]==1，则显示ZF和OF
		endcase
	 end	 
	 
endmodule

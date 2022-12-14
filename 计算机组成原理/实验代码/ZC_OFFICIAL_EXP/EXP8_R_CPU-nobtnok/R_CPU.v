`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:43:49 03/02/2014 
// Design Name: 
// Module Name:    R_CPU 
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
module R_CPU(
    input clk,
    input rst,
	 output [31:0] ALU_F			//为显示指令运算结果用
    );

	wire [31:0] Inst_code;
//	wire [31:0] PC_out;
	wire [4:0] Rs,Rt,Rd;
	wire [5:0] OP,func;
	wire [31:0] ALU_A,ALU_B;
	reg Write_Reg;
	wire ZF,OF;
	reg FR_ZF,FR_OF;
	reg [2:0] ALU_OP;

	IF_M	My_IF(
		.clk(clk),
		.rst(rst),
		.Inst_code(Inst_code)
//		.PC_out(PC_out)
    );
	
	assign OP =  Inst_code[31:26];
	assign Rs =  Inst_code[25:21];
	assign Rt =  Inst_code[20:16];
	assign Rd =  Inst_code[15:11];
	assign func =  Inst_code[5:0];		

	REGS	My_REG(
    .Clk(~clk),
    .Reset(rst),
    .R_Addr_A(Rs),
    .R_Addr_B(Rt),
    .W_Addr(Rd),
    .W_Data(ALU_F),
    .Write_Reg(Write_Reg),
    .R_Data_A(ALU_A),
    .R_Data_B(ALU_B)
    );
	 
	 ALU My_ALU(
		.A(ALU_A),
		.B(ALU_B),
		.ALU_OP(ALU_OP),
		.F(ALU_F),
		.ZF(ZF),
		.OF(OF)
    );

	always @(*)
	begin
		ALU_OP = 3'b000;
		Write_Reg = 1'b0;
		if (OP==6'b000000)
			begin
				Write_Reg = 1'b1;
				case (func)
					6'b100000:	ALU_OP = 3'b100; 
					6'b100010:	ALU_OP = 3'b101;
					6'b100100:	ALU_OP = 3'b000;
					6'b100101:	ALU_OP = 3'b001;
					6'b100110:	ALU_OP = 3'b010;
					6'b100111:	ALU_OP = 3'b011;
					6'b101011:	ALU_OP = 3'b110;
					6'b000100:	ALU_OP = 3'b111;
					default:		ALU_OP = 3'b000;
				endcase
			end
		else ALU_OP = 3'b000;
	end;
	
	always @(negedge clk)
	begin
		FR_ZF <= ZF;
		FR_OF <= OF;
	end;
	
endmodule

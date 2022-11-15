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
module RI_CPU(
    input clk,
	 input clk_ram,
    input rst,
	 output reg FR_ZF,
	 output reg FR_OF,
	 output [31:0] ALU_F,		//为显示指令运算结果用
	 output [31:0] Mem_R_Data	//为显示指令运算结果用
    );

	wire [31:0] Inst_code;
//	wire [31:0] PC_out;
	wire [4:0] Rs,Rt,Rd,Reg_W_Addr;
	wire [5:0] OP,func;
	wire [31:0] ALU_A,ALU_B;
	reg Write_Reg,Mem_Write;
	wire ZF,OF;
	reg Set_ZF,Set_OF;
	reg [2:0] ALU_OP;
	wire [31:0] imm_Data,Reg_Data_B,Reg_W_Data,Mem_W_Data;
	wire [15:0] imm_off;
	wire [5:0] Mem_Addr;
	
	reg rd_rt_s,imm_s,rt_imm_s,alu_mem_s;

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
	assign imm_off =  Inst_code[15:0];
	
	assign Reg_W_Addr = (rd_rt_s) ? Rt : Rd;	
	
	assign imm_Data = (imm_s) ? {{16{imm_off[15]}},imm_off}:{{16{1'b0}},imm_off};
	assign ALU_B = (rt_imm_s) ? imm_Data : Reg_Data_B;
	assign Reg_W_Data = (alu_mem_s) ? Mem_R_Data : ALU_F;
	assign Mem_Addr = ALU_F[7:2];
	assign Mem_W_Data = Reg_Data_B;

	REGS	My_REG(
    .Clk(~clk),
    .Reset(rst),
    .R_Addr_A(Rs),
    .R_Addr_B(Rt),
    .W_Addr(Reg_W_Addr),
    .W_Data(Reg_W_Data),
    .Write_Reg(Write_Reg),
    .R_Data_A(ALU_A),
    .R_Data_B(Reg_Data_B)
    );
	 
	 ALU My_ALU(
		.A(ALU_A),
		.B(ALU_B),
		.ALU_OP(ALU_OP),
		.F(ALU_F),
		.ZF(ZF),
		.OF(OF)
    );

	RAM_B My_RAM (
	  .clka(clk_ram), // input clka
	  .wea(Mem_Write), // input [0 : 0] wea
	  .addra(Mem_Addr), // input [5 : 0] addra
	  .dina(Mem_W_Data), // input [31 : 0] dina
	  .douta(Mem_R_Data) // output [31 : 0] douta
	);

	always @(posedge rst or negedge clk)
	begin
		if (rst)
			begin
				FR_ZF <= 1'b0;
				FR_OF <= 1'b0;				
			end
		else	
			begin
				if (Set_ZF) FR_ZF <= ZF;
				if (Set_OF) FR_OF <= OF;
			end
	end;
	
	always @(*)
	begin
		ALU_OP = 3'b100;			//默认做加法
		Write_Reg = 1'b1;			//默认写寄存器
		Set_ZF = 1'b1;				//默认影响结果为零标志位
		Set_OF = 1'b0;				//默认不影响溢出标志位
		rd_rt_s = 1'b0;			//默认写入rd指明的寄存器
		imm_s = 1'b0;				//默认对立即数/偏移量数据进行0扩展
		rt_imm_s = 1'b0;			//默认读出rt寄存器的数据送ALU_B
		alu_mem_s = 1'b0;			//默认将ALU运算结果写入目的寄存器	
		Mem_Write = 1'b0;			//默认不写存储器		
		if (OP==6'b000000)
			begin
				case (func)
					6'b100000:	Set_OF = 1'b1;			//add
					6'b100010:	begin ALU_OP = 3'b101;	Set_OF = 1'b1; end	//sub
					6'b100100:	ALU_OP = 3'b000;		//and
					6'b100101:	ALU_OP = 3'b001;		//or
					6'b100110:	ALU_OP = 3'b010;		//xor
					6'b100111:	ALU_OP = 3'b011;		//nor
					6'b101011:	ALU_OP = 3'b110;		//sltu
					6'b000100:	ALU_OP = 3'b111;		//sll
				endcase
			end
		else 
			begin
				case(OP)
					6'b001000:	begin rd_rt_s = 1'b1;	rt_imm_s = 1'b1;		
											imm_s = 1'b1;		Set_OF = 1'b1;
									end	//addi
					6'b001100:	begin ALU_OP = 3'b000; 	rd_rt_s = 1'b1;	rt_imm_s = 1'b1;	end	//andi
					6'b001110:	begin ALU_OP = 3'b010; 	rd_rt_s = 1'b1;	rt_imm_s = 1'b1;	end	//xori
					6'b001011:	begin ALU_OP = 3'b110; 	rd_rt_s = 1'b1;	rt_imm_s = 1'b1;	end	//sltiu
					6'b100011:	begin rd_rt_s = 1'b1;	imm_s = 1'b1;	
											rt_imm_s = 1'b1;	alu_mem_s = 1'b1;	Set_ZF = 1'b0;
									end	//lw
					6'b101011:	begin imm_s = 1'b1;		rt_imm_s = 1'b1;	
											Mem_Write = 1'b1;	Write_Reg = 1'b0;	Set_ZF = 1'b0;
									end	//sw
				endcase
			end
	end
	
endmodule

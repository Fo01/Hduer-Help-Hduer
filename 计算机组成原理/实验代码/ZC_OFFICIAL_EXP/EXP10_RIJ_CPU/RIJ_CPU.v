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
module RIJ_CPU(
    input clk,
	 input clk_ram,
    input rst,
	 output reg FR_ZF,
	 output reg FR_OF,
	 output [31:0] ALU_F,		//为显示指令运算结果用
	 output [31:0] Mem_R_Data,	//为显示指令运算结果用
	 output [31:0] PC
    );

	wire 	[31:0] Inst_code;
	wire 	[4:0] Rs,Rt,Rd,Reg_W_Addr;
	wire 	[5:0] OP,func;
	wire 	[25:0] address;
	wire 	[31:0] ALU_A,ALU_B;
	reg 	Write_Reg,Mem_Write;
	wire 	ZF,OF;
	reg 	Set_ZF,Set_OF;
	reg 	[2:0] ALU_OP;
	wire 	[31:0] imm_Data,Reg_Data_A,Reg_Data_B,Reg_W_Data,Mem_W_Data;
	wire 	[15:0] imm_off;
	wire 	[5:0] Mem_Addr;
	reg 	imm_s,rt_imm_s;
	reg[1:0]	w_r_s,wr_data_s;
	
	wire 	[31:0] PC_new;
	reg 	[31:0] PC_next;
	reg 	[1:0] PC_s;
	
	IF_M	My_IF(
		.clk(clk),
		.rst(rst),
		.PC_next(PC_next),
		.Inst_code(Inst_code),
		.PC(PC),
		.PC_new(PC_new)
    );
	
	assign OP =  Inst_code[31:26];
	assign Rs =  Inst_code[25:21];
	assign Rt =  Inst_code[20:16];
	assign Rd =  Inst_code[15:11];
	assign func =  Inst_code[5:0];
	assign imm_off =  Inst_code[15:0];
	assign address =  Inst_code[25:0];
	
	assign Reg_W_Addr = (w_r_s[1]) ? 5'b11111 : ((w_r_s[0]) ? Rt : Rd );
	assign Reg_W_Data = (wr_data_s[1]) ? PC_new : ((wr_data_s[0]) ? Mem_R_Data : ALU_F);
	
	assign imm_Data = (imm_s) ? {{16{imm_off[15]}},imm_off}:{{16{1'b0}},imm_off};
	assign ALU_A = Reg_Data_A;
	assign ALU_B = (rt_imm_s) ? imm_Data : Reg_Data_B;
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
    .R_Data_A(Reg_Data_A),
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
	
	always @(*)
		case (PC_s)
			2'b00:	PC_next <= PC_new;
			2'b01:	PC_next <= Reg_Data_A;
			2'b10:	PC_next <= PC_new + (imm_Data<<2);
			2'b11:	PC_next <= {PC_new[31:28], address, 2'b00};
		endcase

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
		w_r_s = 2'b00;				//默认写入rd指明的寄存器
		imm_s = 1'b0;				//默认对立即数/偏移量数据进行0扩展
		rt_imm_s = 1'b0;			//默认读出rt寄存器的数据送ALU_B
		wr_data_s = 2'b00;		//默认将ALU运算结果写入目的寄存器	
		Mem_Write = 1'b0;			//默认不写存储器		
		PC_s = 2'b00;				//默认PC自增4
		
		if (OP==6'b000000)  //9条R型指令，含jr指令
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
					6'b001000:	begin	PC_s = 2'b01;	Write_Reg = 1'b0;	end		//jr
				endcase
			end
		else 
			begin
				case(OP)			
				//4条I型计算指令
					6'b001000:	begin w_r_s = 2'b01;		rt_imm_s = 1'b1;		
											imm_s = 1'b1;		Set_OF = 1'b1;
									end	//addi
					6'b001100:	begin ALU_OP = 3'b000; 	w_r_s = 2'b01;	rt_imm_s = 1'b1;	end	//andi
					6'b001110:	begin ALU_OP = 3'b010; 	w_r_s = 2'b01;	rt_imm_s = 1'b1;	end	//xori
					6'b001011:	begin ALU_OP = 3'b110; 	w_r_s = 2'b01;	rt_imm_s = 1'b1;	end	//sltiu
				//2条I型存数/取数指令
					6'b100011:	begin w_r_s = 2'b01;		imm_s = 1'b1;	
											rt_imm_s = 1'b1;	wr_data_s = 2'b01;	Set_ZF = 1'b0;
									end	//lw
					6'b101011:	begin imm_s = 1'b1;		rt_imm_s = 1'b1;	
											Mem_Write = 1'b1;	Write_Reg = 1'b0;		Set_ZF = 1'b0;
									end	//sw
				//2条I型转移指令
					6'b000100:	begin 
										Write_Reg = 1'b0;		ALU_OP = 3'b101;	imm_s = 1'b1;
										if (ZF)	PC_s = 2'b10;								
									end	//beq
					6'b000101:	begin 
										Write_Reg = 1'b0;		ALU_OP = 3'b101;	imm_s = 1'b1;
										if (!ZF)	PC_s = 2'b10;						
									end	//bne
				//2条J型转移指令
					6'b000010:	begin 
										Write_Reg = 1'b0;		PC_s = 2'b11;	end	//j				
					6'b000011:	begin 
										PC_s = 2'b11;	
										w_r_s = 2'b1x;			wr_data_s = 2'b1x;
									end	//jal						
				endcase
			end
	end
	
endmodule

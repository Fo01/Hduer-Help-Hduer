`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    02:26:38 12/26/2020 
// Design Name: 
// Module Name:    Instruction 
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
module Instruction(clk,rst,
    pc,pc_new,inst_code,
	 op,rs,rt,rd,shamt,func,imm,addr
    );
	 input clk,rst; //
	 output reg [31:0] pc;
	 output [31:0] pc_new;
	 output [31:0] inst_code;
	 
	 always @(negedge clk)
	     if (rst) pc<=32'h0000_0000;
		  else pc<=pc_new;
	 assign pc_new=pc+4;
	 
	 Inst_ROM ROM_Instruction_Instance(
	     .clka(clk),
		  .addra(pc[7:2]),
		  .douta(inst_code));
    
	 output [5:0] op,func;
	 output [4:0] rs,rt,rd,shamt;
	 output [15:0] imm;
	 output [25:0] addr;
	 assign op=inst_code[31:26];
	 assign rs=inst_code[25:21];
	 assign rt=inst_code[20:16];
	 assign rd=inst_code[15:11];
	 assign shamt=inst_code[10:6];
	 assign func=inst_code[5:0];
	 assign imm=inst_code[15:0];
	 assign addr=inst_code[25:0];
endmodule

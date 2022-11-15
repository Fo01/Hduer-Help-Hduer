`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   02:42:59 12/26/2020
// Design Name:   Instruction
// Module Name:   E:/Computer Orgnization/EXP5_MEM/EXP7_INSTRUCTION/Simu.v
// Project Name:  EXP7_INSTRUCTION
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Instruction
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Simu;

	// Inputs
	reg clk;
	reg rst;

	// Outputs
	wire [31:0] pc;
	wire [31:0] pc_new;
	wire [31:0] inst_code;
	wire [5:0] op;
	wire [4:0] rs;
	wire [4:0] rt;
	wire [4:0] rd;
	wire [4:0] shamt;
	wire [5:0] func;
	wire [15:0] imm;
	wire [25:0] addr;

	// Instantiate the Unit Under Test (UUT)
	Instruction uut (
		.clk(clk), 
		.rst(rst), 
		.pc(pc), 
		.pc_new(pc_new), 
		.inst_code(inst_code), 
		.op(op), 
		.rs(rs), 
		.rt(rt), 
		.rd(rd), 
		.shamt(shamt), 
		.func(func), 
		.imm(imm), 
		.addr(addr)
	);
	always #25 clk=~clk;
	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
      #10;
		rst=0;
		// Wait 100 ns for global reset to finish
        
		// Add stimulus here

	end
      
endmodule


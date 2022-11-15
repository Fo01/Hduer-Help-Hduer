`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:42:39 11/22/2018
// Design Name:   ALU_REG
// Module Name:   C:/Users/Thinkpad/Desktop/experiment/EXP4_ALU_REG/teat2.v
// Project Name:  EXP4_ALU_REG
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALU_REG
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module teat2;

	// Inputs
	reg Clk;
	reg Reset;
	reg [4:0] R_Addr_A;
	reg [4:0] R_Addr_B;
	reg [4:0] W_Addr;
	reg Write_Reg;
	reg [2:0] ALU_OP;

	// Outputs
	wire ZF;
	wire OF;
	wire R_Data_A;
	wire R_Data_B;
	wire W_Data;

	// Instantiate the Unit Under Test (UUT)
	ALU_REG uut (
		.Clk(Clk), 
		.Reset(Reset), 
		.R_Addr_A(R_Addr_A), 
		.R_Addr_B(R_Addr_B), 
		.W_Addr(W_Addr), 
		.Write_Reg(Write_Reg), 
		.ALU_OP(ALU_OP), 
		.ZF(ZF), 
		.OF(OF), 
		.R_Data_A(R_Data_A), 
		.R_Data_B(R_Data_B), 
		.W_Data(W_Data)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Reset = 0;
		R_Addr_A = 0;
		R_Addr_B = 0;
		W_Addr = 5'b00001;
		Write_Reg = 1;
		ALU_OP = 0;	
		#100;
		
		Clk = 0;
		Reset = 0;
		R_Addr_A = 0;
		R_Addr_B = 0;
		W_Addr = 5'b00010;
		Write_Reg = 1;
		ALU_OP = 0;	
		#100;
		
		Clk = 0;
		Reset = 0;
		R_Addr_A = 5'b00001;
		R_Addr_B = 5'b00010;
		W_Addr = 5'b00011;
		Write_Reg = 0;
		ALU_OP = 0;	
		#100;

	end
      
endmodule


`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:18:36 11/22/2018
// Design Name:   MIPS_REG
// Module Name:   C:/Users/Thinkpad/Desktop/experiment/EXP4_ALU_REG/test4.v
// Project Name:  EXP4_ALU_REG
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: MIPS_REG
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test4;

	// Inputs
	reg Clk;
	reg Reset;
	reg [4:0] R_Addr_A;
	reg [4:0] R_Addr_B;
	reg [4:0] W_Addr;
	reg [31:0] W_Data;
	reg Write_Reg;

	// Outputs
	wire [31:0] R_Data_A;
	wire [31:0] R_Data_B;

	// Instantiate the Unit Under Test (UUT)
	MIPS_REG uut (
		.Clk(Clk), 
		.Reset(Reset), 
		.R_Addr_A(R_Addr_A), 
		.R_Addr_B(R_Addr_B), 
		.W_Addr(W_Addr), 
		.W_Data(W_Data), 
		.Write_Reg(Write_Reg), 
		.R_Data_A(R_Data_A), 
		.R_Data_B(R_Data_B)
	);

	initial begin
		// Initialize Inputs
		
		// ²âÊÔ¼Ä´æÆ÷¶ÑµÄÊý¾Ý¶ÁÐ´
		
		Clk = 1;
		Reset = 0;
		R_Addr_A = 5'b00000;
		R_Addr_B = 5'b00000;
		W_Addr = 5'b00001;
		W_Data = 32'h 2345_2345;
		Write_Reg = 1;		
		#100;
		
		Clk = 0;
		Reset = 0;
		R_Addr_A = 5'b00001;
		R_Addr_B = 5'b00000;
		W_Addr = 5'b00001;
		W_Data = 32'h 2345_2345;
		Write_Reg = 0;		
		#100;
		
		Clk = 1;
		Reset = 0;
		R_Addr_A = 5'b00000;
		R_Addr_B = 5'b00010;
		W_Addr = 5'b00010;
		W_Data = 32'h 2345_2345;
		Write_Reg = 1;		
		#100;
		
		Clk = 0;
		Reset = 0;
		R_Addr_A = 5'b00001;
		R_Addr_B = 5'b00010;
		W_Addr = 5'b00010;
		W_Data = 32'h 2345_2345;
		Write_Reg = 0;		
		#100;
		
		Clk = 1;
		Reset = 0;
		R_Addr_A = 5'b00001;
		R_Addr_B = 5'b00010;
		W_Addr = 5'b00010;
		W_Data = 32'h 2345_2345;
		Write_Reg = 1;		
		#100;
		
		
        
		// Add stimulus here

	end
      
endmodule


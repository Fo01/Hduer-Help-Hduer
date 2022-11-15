`timescale 1ns / 1p

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:45:17 11/09/2018
// Design Name:   ALU_8F_EXP
// Module Name:   C:/Users/Thinkpad/Desktop/experiment/EXP3_ALU/test.v
// Project Name:  ALU
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALU_8F_EXP
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test;

	// Inputs
	reg [2:0] ALU_OP;
	reg [2:0] AB_SW;
	reg [2:0] F_LED_SW;

	// Outputs
	wire [7:0] LED;

	// Instantiate the Unit Under Test (UUT)
	ALU_8F_EXP uut (
		.ALU_OP(ALU_OP), 
		.AB_SW(AB_SW), 
		.F_LED_SW(F_LED_SW), 
		.LED(LED)
	);

	initial begin
		// Initialize Inputs
		ALU_OP = 0;
		AB_SW = 0;
		F_LED_SW = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		ALU_OP=000; AB_SW=010; F_LED_SW=000;
		#100;
		
		ALU_OP=000; AB_SW=010; F_LED_SW=100;
		#100;
		
		ALU_OP=000; AB_SW=010; F_LED_SW=001;
		#100;
		
		ALU_OP=100; AB_SW=010; F_LED_SW=000;
		#100;
		
		ALU_OP=100; AB_SW=010; F_LED_SW=100;
		#100;
		
		ALU_OP=100; AB_SW=010; F_LED_SW=001;
		#100;
	end
      
endmodule


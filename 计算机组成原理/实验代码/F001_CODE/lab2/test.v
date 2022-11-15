`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   00:18:32 11/27/2020
// Design Name:   More_Add
// Module Name:   E:/Computer Orgnization/lab2/test.v
// Project Name:  lab2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: More_Add
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
	reg [3:0] a;
	reg [3:0] b;
	reg cin;

	// Outputs
	wire [3:0] f;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	More_Add uut (
		.a(a), 
		.b(b), 
		.f(f), 
		.cin(cin), 
		.cout(cout)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;
		cin = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		a=0111; b=0111; cin=1;
		#100;
		a=0111; b=0111; cin=0;
		#100;
		a=0100; b=1101; cin=1;
		#100;
		a=0100; b=1101; cin=0;
		#100;
		a=0100; b=1001; cin=1;
		#100;
		a=0100; b=1001; cin=0;
		#100;
		a=0010; b=1101; cin=1;
		#100;
		a=0010; b=1101; cin=0;
		#100;
	end
      
endmodule


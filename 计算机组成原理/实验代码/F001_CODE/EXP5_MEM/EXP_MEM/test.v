`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:14:24 12/11/2020
// Design Name:   RAM_B
// Module Name:   E:/Computer Orgnization/EXP5_MEM/EXP_MEM/test.v
// Project Name:  EXP_MEM
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: RAM_B
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
	reg clka;
	reg [0:0] wea;
	reg [5:0] addra;
	reg [31:0] dina;

	// Outputs
	wire [31:0] douta;

	// Instantiate the Unit Under Test (UUT)
	RAM_B uut (
		.clka(clka), 
		.wea(wea), 
		.addra(addra), 
		.dina(dina), 
		.douta(douta)
	);

	initial begin
		// Initialize Inputs
		clka = 0;
		wea = 0;
		addra = 0;
		dina = 0;

		// Wait 100 ns for global reset to finish
		#100;
		clka = 1;
		wea = 0;
		addra = 6'b000001;
		dina = 32'h0000_0003;
		
		#100;
		clka = 0;
		wea = 0;
		addra = 6'b000001;
		dina = 32'h0000_0003;
		
		#100;
		clka = 1;
		wea = 0;
		addra = 6'b000010;
		dina = 32'h0000_0003;
		
		#100;
		clka = 0;
		wea = 0;
		addra = 6'b000010;
		dina = 32'h0000_0003;
		
		#100;
		clka = 1;
		wea = 0;
		addra = 6'b000011;
		dina = 32'h0000_0003;
		
		#100;
		clka = 0;
		wea = 0;
		addra = 6'b000011;
		dina = 32'h0000_0003;
		
		#100;
		clka = 1;
		wea = 0;
		addra = 6'b000100;
		dina = 32'h0000_0003;
		
		#100;
		clka = 0;
		wea = 0;
		addra = 6'b000100;
		dina = 32'h0000_0003;
		
		#100;
		clka = 1;
		wea = 0;
		addra = 6'b000101;
		dina = 32'h0000_0003;
		
		#100;
		clka = 0;
		wea = 0;
		addra = 6'b000101;
		dina = 32'h0000_0003;
		
		#100;
		clka = 1;
		wea = 0;
		addra = 6'b000110;
		dina = 32'h0000_0003;
		
		#100;
		clka = 0;
		wea = 0;
		addra = 6'b000110;
		dina = 32'h0000_0003;
		
		#100;
		clka = 1;
		wea = 0;
		addra = 6'b000111;
		dina = 32'h0000_0003;
		
		#100;
		clka = 0;
		wea = 0;
		addra = 6'b000111;
		dina = 32'h0000_0003;
		
		#100;
		clka = 1;
		wea = 0;
		addra = 6'b001000;
		dina = 32'h0000_0003;     //read first data
		
		#100;
		clka= 0 ;
		
		#100;
		clka = 1;
		wea = 1;
		addra = 6'b000001;
		dina = 32'h0000_0003;
		
		#100;
		clka= 0 ;
		
		#100;
		clka = 1;
		wea = 1;
		addra = 6'b000010;
		dina = 32'h0000_0004;
		
		#100;
		clka=0;
		
		#100;
		clka = 1;
		wea = 1;
		addra = 6'b000011;
		dina = 32'h0000_0005;
		
		#100;
		clka=0;
		
		#100;
		clka = 1;
		wea = 1;
		addra = 6'b000100;
		dina = 32'h0000_0006;
		
		#100;
		clka=0;
		
		#100;
		clka = 1;
		wea = 1;
		addra = 6'b000101;
		dina = 32'h0000_0007;
		
		#100;
		clka=0;
		
		#100;
		clka = 1;
		wea = 1;
		addra = 6'b000110;
		dina = 32'h0000_0008;
		
		#100;
		clka=0;
		
		#100;
		clka = 1;
		wea = 1;
		addra = 6'b000111;
		dina = 32'h0000_0009;
		
		#100;
		clka=0;
		
		#100;
		clka = 1;
		wea = 1;
		addra = 6'b001000;
		dina = 32'h0000_000a;//rewrite all the data
		// Add stimulus here

	end
      
endmodule


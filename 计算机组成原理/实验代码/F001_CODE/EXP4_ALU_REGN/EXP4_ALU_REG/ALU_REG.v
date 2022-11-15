`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:15:30 02/07/2014 
// Design Name: 
// Module Name:    ALU_REG 
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
module ALU_REG(
    input Clk,
    input Reset,
    input [4:0] R_Addr_A,   
    input [4:0] R_Addr_B,   
    input [4:0] W_Addr,    
    input Write_Reg,       
    input [2:0] ALU_OP,   
    output ZF,            
    output OF,             
	 output [31:0] R_Data_A,
	 output [31:0] R_Data_B,
	 output [31:0] W_Data
    );

	
	assign R_Data_A = 32'h0000_0000;
	assign R_Data_B = 32'h0000_0000;
	assign W_Data = 32'h1010_0100;
	
	
	MIPS_REG Registers(Clk,Reset,R_Addr_A,R_Addr_B,W_Addr,W_Data,Write_Reg,R_Data_A,R_Data_B);
	
	
	ALU_8F MIPS_ALU(R_Data_A,R_Data_B,ALU_OP,W_Data,ZF,OF);  
	
	

endmodule

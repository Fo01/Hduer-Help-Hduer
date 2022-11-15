`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:12:07 02/07/2014 
// Design Name: 
// Module Name:    REG 
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
module REGS(
    input Clk,
    input Reset,
    input [4:0] R_Addr_A,
    input [4:0] R_Addr_B,
    input [4:0] W_Addr,
    input [31:0] W_Data,
    input Write_Reg,
    output [31:0] R_Data_A,
    output [31:0] R_Data_B
    );
	
	reg [31:0] REG_Files[1:31];
	integer i;
	
	assign R_Data_A = (R_Addr_A==5'b00000)? 32'h0000_0000 : REG_Files[R_Addr_A];
	assign R_Data_B = (R_Addr_B==5'b00000)? 32'h0000_0000 : REG_Files[R_Addr_B];
	
	always @(posedge Clk or posedge Reset)
	begin
		if(Reset)
			begin
				for(i=1;i<=31;i=i+1)
					REG_Files[i]<= 32'h0000_0000;
			end
		else
			begin
				if ((Write_Reg) &&(W_Addr != 5'b00000))
					REG_Files[W_Addr] <= W_Data;
			end
	end

endmodule

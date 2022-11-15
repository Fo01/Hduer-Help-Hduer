`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    09:41:18 12/10/2013 
// Design Name: 
// Module Name:    FA 
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
module FA(
    input Ai,
    input Bi,
    input Cin,
    output Fi,
    output Cout
    );
	 
	wire T1,T2,T3,T4;
	
	xor 	xor1(Fi,Ai,Bi,Cin);
	and 	and1(T2,Ai,Bi);
	or 	or1(T3,Ai,Bi);
   and 	and2(T4,T3,Cin);
	or 	or2(Cout,T2,T4);
	
endmodule

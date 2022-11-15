`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:23:06 02/04/2014 
// Design Name: 
// Module Name:    CLAA 
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
module CLAA(
    input [3:0] A,
    input [3:0] B,
    input C0,
    output [3:0] F,
    output C4
    );
	 wire [3:0] G,P;
	 wire [3:1] C;
	  
	 assign	G[0] = A[0]&& B[0];
	 assign	P[0] = A[0]|| B[0];
	 assign	G[1] = A[1]&& B[1];
	 assign	P[1] = A[1]|| B[1];
	 assign	G[2] = A[2]&& B[2];
	 assign	P[2] = A[2]|| B[2];	 
	 assign	G[3] = A[3]&& B[3];
	 assign	P[3] = A[3]|| B[3];	
	 
	 assign	C[1] = G[0] || (P[0] && C0);		 
	 assign	C[2] = G[1] || (P[1] && G[0]) || (P[1] && P[0] && C0);		 	 
	 assign	C[3] = G[2] || (P[2] && G[1]) || (P[2] && P[1] && G[0]) || (P[2] && P[1] && P[0] && C0);
	 assign	C4	  = G[3] || (P[3] && G[2]) || (P[3] && P[2] && G[1]) || (P[3] && P[2] && P[1] && G[0]) || (P[3] && P[2] && P[1] && P[0] && C0);	 
	 
	 FA FA0(A[0],B[0],C0,F[0],);
	 FA FA1(A[1],B[1],C[1],F[1],);
	 FA FA2(A[2],B[2],C[2],F[2],);
	 FA FA3(A[3],B[3],C[3],F[3],);

endmodule

`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:37:57 02/10/2014 
// Design Name: 
// Module Name:    Mem_IP_Exp 
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
module Mem_IP_Exp(
	input Clk_m,
	input Mem_Write,
	input [7:0] Mem_Addr,
	output reg [7:0] LED
    );

	wire[31:0] M_R_Data;
	reg[31:0] M_W_Data;

	RAM_B		Data_RAM (
	  .clka(Clk_m), 				// input clka
	  .wea(Mem_Write), 			// input [0 : 0] wea
	  .addra(Mem_Addr[7:2]), 	// input [5 : 0] addra
	  .dina(M_W_Data), 			// input [31 : 0] dina
	  .douta(M_R_Data) 			// output [31 : 0] douta
	);
	
	always @(*)
	begin
		if (!Mem_Write)
			begin
				case (Mem_Addr[1:0])
					2'b00:	LED = M_R_Data[7:0];
					2'b01:	LED = M_R_Data[15:8];
					2'b10:	LED = M_R_Data[23:16];
					2'b11:	LED = M_R_Data[31:24];
					default:	LED = 8'b0000_0000;
				endcase
				M_W_Data = 32'hffff_ffff;
			end
		else
			begin
				LED = 8'b0000_0000;
				case (Mem_Addr[1:0])
					2'b00:	M_W_Data = 32'h1111_2222;
					2'b01:	M_W_Data = 32'h3333_4444;
					2'b10:	M_W_Data = 32'h5555_6666;
					2'b11:	M_W_Data = 32'hffff_1234;
					default:	M_W_Data = 32'h7777_8888;
				endcase
			end
	end;

endmodule

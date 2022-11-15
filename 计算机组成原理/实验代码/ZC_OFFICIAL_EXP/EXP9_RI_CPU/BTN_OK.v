`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:45:02 03/02/2014 
// Design Name: 
// Module Name:    BTN_OK 
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
module BTN_OK(
    input clk_100MHz,
    input BTN,
    output reg BTN_Out
    );

	reg BTN1,BTN2;
	wire BTN_Down;
	reg [21:0] cnt;
	reg BTN_20ms_1,BTN_20ms_2;
	wire BTN_Up;
	
	always @(posedge clk_100MHz)
	begin
		BTN1 <= BTN;
		BTN2 <= BTN1;
	end
	assign BTN_Down = (~BTN2)&& BTN1 ; //��0��1������
	
	always @(posedge clk_100MHz)
	begin
		if (BTN_Down) 
			begin
				cnt <= 22'b0;
				BTN_Out <= 1'b1;
			end
		else	cnt <= cnt+1'b1;
		if (cnt==22'h20000) BTN_20ms_1 <= BTN;
		BTN_20ms_2 <= BTN_20ms_1;
		if (BTN_Up) BTN_Out <= 1'b0;
	end
	
	assign BTN_Up = BTN_20ms_2 && (~BTN_20ms_1);//��1��0
	
endmodule

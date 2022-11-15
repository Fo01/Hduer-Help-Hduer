////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 1995-2011 Xilinx, Inc.  All rights reserved.
////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor: Xilinx
// \   \   \/     Version: O.87xd
//  \   \         Application: netgen
//  /   /         Filename: ALU_8F_EXP_synthesis.v
// /___/   /\     Timestamp: Wed Feb 05 20:38:52 2014
// \   \  /  \ 
//  \___\/\___\
//             
// Command	: -intstyle ise -insert_glbl true -w -dir netgen/synthesis -ofmt verilog -sim ALU_8F_EXP.ngc ALU_8F_EXP_synthesis.v 
// Device	: xc6slx16-3-csg324
// Input file	: ALU_8F_EXP.ngc
// Output file	: D:\Logic\ZC_EXP\EXP2_ALU\netgen\synthesis\ALU_8F_EXP_synthesis.v
// # of Modules	: 1
// Design Name	: ALU_8F_EXP
// Xilinx        : D:\Xilinx\13.4\ISE_DS\ISE\
//             
// Purpose:    
//     This verilog netlist is a verification model and uses simulation 
//     primitives which may not represent the true implementation of the 
//     device, however the netlist is functionally correct and should not 
//     be modified. This file cannot be synthesized and should only be used 
//     with supported simulation tools.
//             
// Reference:  
//     Command Line Tools User Guide, Chapter 23 and Synthesis and Simulation Design Guide, Chapter 6
//             
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns/1 ps

module ALU_8F_EXP (
ALU_OP, AB_SW, F_LED_SW, LED
);
  input [2 : 0] ALU_OP;
  input [2 : 0] AB_SW;
  input [2 : 0] F_LED_SW;
  output [7 : 0] LED;
  wire ALU_OP_2_IBUF_0;
  wire ALU_OP_1_IBUF_1;
  wire ALU_OP_0_IBUF_2;
  wire AB_SW_2_IBUF_3;
  wire AB_SW_1_IBUF_4;
  wire AB_SW_0_IBUF_5;
  wire F_LED_SW_2_IBUF_6;
  wire F_LED_SW_1_IBUF_7;
  wire F_LED_SW_0_IBUF_8;
  wire \F[7] ;
  wire \F[6] ;
  wire \F[5] ;
  wire \F[3] ;
  wire \F[2] ;
  wire \F[0] ;
  wire \F[15] ;
  wire \F[14] ;
  wire \F[13] ;
  wire \F[12] ;
  wire \F[11] ;
  wire \F[10] ;
  wire \F[9] ;
  wire \F[8] ;
  wire \F[23] ;
  wire \F[22] ;
  wire \F[21] ;
  wire \F[20] ;
  wire \F[19] ;
  wire \F[18] ;
  wire \F[17] ;
  wire \F[16] ;
  wire \F[31] ;
  wire \F[30] ;
  wire \F[29] ;
  wire \F[28] ;
  wire \F[27] ;
  wire \F[26] ;
  wire \F[25] ;
  wire \F[24] ;
  wire LED_7_OBUF_39;
  wire LED_6_OBUF_40;
  wire LED_5_OBUF_41;
  wire LED_4_OBUF_42;
  wire LED_3_OBUF_43;
  wire LED_2_OBUF_44;
  wire LED_1_OBUF_45;
  wire LED_0_OBUF_46;
  wire Mram__n0036;
  wire Mram__n003610;
  wire Mram__n003611;
  wire Mram__n003631;
  wire Mram__n003633;
  wire \ALU_UUT/Mmux_F16211 ;
  wire \ALU_UUT/Sh112 ;
  wire \ALU_UUT/Sh351 ;
  wire \ALU_UUT/Mmux_F114_55 ;
  wire \ALU_UUT/Mmux_F113_56 ;
  wire \ALU_UUT/Mmux_F112_57 ;
  wire \ALU_UUT/Mmux_F_3_58 ;
  wire \ALU_UUT/Mmux_F_4_59 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<15>_123 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<11>_124 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<11> ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi11 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<10>_127 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<10> ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi10 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<9>_130 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<9> ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi9 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<8>_133 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<8> ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi8 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<7>_136 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<7> ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi7 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<6>_139 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<6>_140 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi6_141 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<5>_142 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<5>_143 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi5_144 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<4>_145 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<4>_146 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi4_147 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<3>_148 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<3> ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi3 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<2>_151 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<2> ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi2_153 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<1>_154 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<1>_155 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi1_156 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<0>_157 ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<0> ;
  wire \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi ;
  wire \ALU_UUT/Sh52 ;
  wire \ALU_UUT/Sh50 ;
  wire \ALU_UUT/Sh31 ;
  wire \ALU_UUT/Sh30 ;
  wire \ALU_UUT/Sh17 ;
  wire \ALU_UUT/_n0039 ;
  wire Mmux_LED8;
  wire Mmux_LED81_296;
  wire Mmux_LED82_297;
  wire Mmux_LED83_298;
  wire Mmux_LED85;
  wire Mmux_LED86_300;
  wire Mmux_LED87_301;
  wire N2;
  wire N4;
  wire N6;
  wire N8;
  wire N10;
  wire N12;
  wire \ALU_UUT/Mmux_F12 ;
  wire \ALU_UUT/Mmux_F25 ;
  wire \ALU_UUT/Mmux_F251_310 ;
  wire \ALU_UUT/Mmux_F253 ;
  wire \ALU_UUT/Mmux_F111 ;
  wire \ALU_UUT/Mmux_F115_313 ;
  wire \ALU_UUT/Mmux_F22 ;
  wire \ALU_UUT/Mmux_F221_315 ;
  wire \ALU_UUT/Mmux_F224 ;
  wire \ALU_UUT/Mmux_F24_317 ;
  wire \ALU_UUT/Mmux_F231 ;
  wire \ALU_UUT/Mmux_F211 ;
  wire \ALU_UUT/Mmux_F41 ;
  wire \ALU_UUT/Mmux_F201 ;
  wire \ALU_UUT/Mmux_F27 ;
  wire \ALU_UUT/Mmux_F313_323 ;
  wire \ALU_UUT/Mmux_F261_324 ;
  wire \ALU_UUT/Mmux_F262_325 ;
  wire \ALU_UUT/Mmux_F9 ;
  wire \ALU_UUT/Mmux_F8 ;
  wire \ALU_UUT/Mmux_F7 ;
  wire \ALU_UUT/Mmux_F15 ;
  wire \ALU_UUT/Mmux_F14 ;
  wire \ALU_UUT/Mmux_F13 ;
  wire \ALU_UUT/Mmux_F121_332 ;
  wire \ALU_UUT/Mmux_F10 ;
  wire \ALU_UUT/Mmux_F191 ;
  wire \ALU_UUT/Mmux_F181 ;
  wire \ALU_UUT/Mmux_F171 ;
  wire \ALU_UUT/Mmux_F161 ;
  wire \ALU_UUT/Mmux_F291 ;
  wire \ALU_UUT/Mmux_F282 ;
  wire \ALU_UUT/Madd_n0035_lut<0>1_357 ;
  wire N20;
  wire N22;
  wire N24;
  wire N25;
  wire [31 : 0] \ALU_UUT/Madd_n0035_cy ;
  wire [31 : 1] \ALU_UUT/Madd_n0035_lut ;
  wire [31 : 0] \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy ;
  wire [31 : 0] \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut ;
  wire [31 : 0] \ALU_UUT/n0035 ;
  wire [32 : 0] \ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT ;
  VCC   XST_VCC (
    .P(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [31])
  );
  GND   XST_GND (
    .G(\ALU_UUT/Madd_n0035_lut [31])
  );
  MUXF7   \ALU_UUT/Mmux_F_2_f7  (
    .I0(\ALU_UUT/Mmux_F_4_59 ),
    .I1(\ALU_UUT/Mmux_F_3_58 ),
    .S(ALU_OP_2_IBUF_0),
    .O(\F[0] )
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<31>  (
    .CI(\ALU_UUT/Madd_n0035_cy [30]),
    .LI(\ALU_UUT/Madd_n0035_lut [31]),
    .O(\ALU_UUT/n0035 [31])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<31>  (
    .CI(\ALU_UUT/Madd_n0035_cy [30]),
    .DI(Mram__n003631),
    .S(\ALU_UUT/Madd_n0035_lut [31]),
    .O(\ALU_UUT/Madd_n0035_cy [31])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<30>  (
    .CI(\ALU_UUT/Madd_n0035_cy [29]),
    .LI(\ALU_UUT/Madd_n0035_lut [30]),
    .O(\ALU_UUT/n0035 [30])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<30>  (
    .CI(\ALU_UUT/Madd_n0035_cy [29]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [30]),
    .O(\ALU_UUT/Madd_n0035_cy [30])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<29>  (
    .CI(\ALU_UUT/Madd_n0035_cy [28]),
    .LI(\ALU_UUT/Madd_n0035_lut [29]),
    .O(\ALU_UUT/n0035 [29])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<29>  (
    .CI(\ALU_UUT/Madd_n0035_cy [28]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [29]),
    .O(\ALU_UUT/Madd_n0035_cy [29])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<28>  (
    .CI(\ALU_UUT/Madd_n0035_cy [27]),
    .LI(\ALU_UUT/Madd_n0035_lut [28]),
    .O(\ALU_UUT/n0035 [28])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<28>  (
    .CI(\ALU_UUT/Madd_n0035_cy [27]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [28]),
    .O(\ALU_UUT/Madd_n0035_cy [28])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<27>  (
    .CI(\ALU_UUT/Madd_n0035_cy [26]),
    .LI(\ALU_UUT/Madd_n0035_lut [27]),
    .O(\ALU_UUT/n0035 [27])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<27>  (
    .CI(\ALU_UUT/Madd_n0035_cy [26]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [27]),
    .O(\ALU_UUT/Madd_n0035_cy [27])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<26>  (
    .CI(\ALU_UUT/Madd_n0035_cy [25]),
    .LI(\ALU_UUT/Madd_n0035_lut [26]),
    .O(\ALU_UUT/n0035 [26])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<26>  (
    .CI(\ALU_UUT/Madd_n0035_cy [25]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [26]),
    .O(\ALU_UUT/Madd_n0035_cy [26])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<25>  (
    .CI(\ALU_UUT/Madd_n0035_cy [24]),
    .LI(\ALU_UUT/Madd_n0035_lut [25]),
    .O(\ALU_UUT/n0035 [25])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<25>  (
    .CI(\ALU_UUT/Madd_n0035_cy [24]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [25]),
    .O(\ALU_UUT/Madd_n0035_cy [25])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<24>  (
    .CI(\ALU_UUT/Madd_n0035_cy [23]),
    .LI(\ALU_UUT/Madd_n0035_lut [24]),
    .O(\ALU_UUT/n0035 [24])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<24>  (
    .CI(\ALU_UUT/Madd_n0035_cy [23]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [24]),
    .O(\ALU_UUT/Madd_n0035_cy [24])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<23>  (
    .CI(\ALU_UUT/Madd_n0035_cy [22]),
    .LI(\ALU_UUT/Madd_n0035_lut [23]),
    .O(\ALU_UUT/n0035 [23])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<23>  (
    .CI(\ALU_UUT/Madd_n0035_cy [22]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [23]),
    .O(\ALU_UUT/Madd_n0035_cy [23])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<22>  (
    .CI(\ALU_UUT/Madd_n0035_cy [21]),
    .LI(\ALU_UUT/Madd_n0035_lut [22]),
    .O(\ALU_UUT/n0035 [22])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<22>  (
    .CI(\ALU_UUT/Madd_n0035_cy [21]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [22]),
    .O(\ALU_UUT/Madd_n0035_cy [22])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<21>  (
    .CI(\ALU_UUT/Madd_n0035_cy [20]),
    .LI(\ALU_UUT/Madd_n0035_lut [21]),
    .O(\ALU_UUT/n0035 [21])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<21>  (
    .CI(\ALU_UUT/Madd_n0035_cy [20]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [21]),
    .O(\ALU_UUT/Madd_n0035_cy [21])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<20>  (
    .CI(\ALU_UUT/Madd_n0035_cy [19]),
    .LI(\ALU_UUT/Madd_n0035_lut [20]),
    .O(\ALU_UUT/n0035 [20])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<20>  (
    .CI(\ALU_UUT/Madd_n0035_cy [19]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [20]),
    .O(\ALU_UUT/Madd_n0035_cy [20])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<19>  (
    .CI(\ALU_UUT/Madd_n0035_cy [18]),
    .LI(\ALU_UUT/Madd_n0035_lut [19]),
    .O(\ALU_UUT/n0035 [19])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<19>  (
    .CI(\ALU_UUT/Madd_n0035_cy [18]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [19]),
    .O(\ALU_UUT/Madd_n0035_cy [19])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<18>  (
    .CI(\ALU_UUT/Madd_n0035_cy [17]),
    .LI(\ALU_UUT/Madd_n0035_lut [18]),
    .O(\ALU_UUT/n0035 [18])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<18>  (
    .CI(\ALU_UUT/Madd_n0035_cy [17]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [18]),
    .O(\ALU_UUT/Madd_n0035_cy [18])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<17>  (
    .CI(\ALU_UUT/Madd_n0035_cy [16]),
    .LI(\ALU_UUT/Madd_n0035_lut [17]),
    .O(\ALU_UUT/n0035 [17])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<17>  (
    .CI(\ALU_UUT/Madd_n0035_cy [16]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [17]),
    .O(\ALU_UUT/Madd_n0035_cy [17])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<16>  (
    .CI(\ALU_UUT/Madd_n0035_cy [15]),
    .LI(\ALU_UUT/Madd_n0035_lut [16]),
    .O(\ALU_UUT/n0035 [16])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<16>  (
    .CI(\ALU_UUT/Madd_n0035_cy [15]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [16]),
    .O(\ALU_UUT/Madd_n0035_cy [16])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<15>  (
    .CI(\ALU_UUT/Madd_n0035_cy [14]),
    .LI(\ALU_UUT/Madd_n0035_lut [15]),
    .O(\ALU_UUT/n0035 [15])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<15>  (
    .CI(\ALU_UUT/Madd_n0035_cy [14]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [15]),
    .O(\ALU_UUT/Madd_n0035_cy [15])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<14>  (
    .CI(\ALU_UUT/Madd_n0035_cy [13]),
    .LI(\ALU_UUT/Madd_n0035_lut [14]),
    .O(\ALU_UUT/n0035 [14])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<14>  (
    .CI(\ALU_UUT/Madd_n0035_cy [13]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [14]),
    .O(\ALU_UUT/Madd_n0035_cy [14])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<13>  (
    .CI(\ALU_UUT/Madd_n0035_cy [12]),
    .LI(\ALU_UUT/Madd_n0035_lut [13]),
    .O(\ALU_UUT/n0035 [13])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<13>  (
    .CI(\ALU_UUT/Madd_n0035_cy [12]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [13]),
    .O(\ALU_UUT/Madd_n0035_cy [13])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<12>  (
    .CI(\ALU_UUT/Madd_n0035_cy [11]),
    .LI(\ALU_UUT/Madd_n0035_lut [12]),
    .O(\ALU_UUT/n0035 [12])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<12>  (
    .CI(\ALU_UUT/Madd_n0035_cy [11]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [12]),
    .O(\ALU_UUT/Madd_n0035_cy [12])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<11>  (
    .CI(\ALU_UUT/Madd_n0035_cy [10]),
    .LI(\ALU_UUT/Madd_n0035_lut [11]),
    .O(\ALU_UUT/n0035 [11])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<11>  (
    .CI(\ALU_UUT/Madd_n0035_cy [10]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [11]),
    .O(\ALU_UUT/Madd_n0035_cy [11])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<10>  (
    .CI(\ALU_UUT/Madd_n0035_cy [9]),
    .LI(\ALU_UUT/Madd_n0035_lut [10]),
    .O(\ALU_UUT/n0035 [10])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<10>  (
    .CI(\ALU_UUT/Madd_n0035_cy [9]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [10]),
    .O(\ALU_UUT/Madd_n0035_cy [10])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<9>  (
    .CI(\ALU_UUT/Madd_n0035_cy [8]),
    .LI(\ALU_UUT/Madd_n0035_lut [9]),
    .O(\ALU_UUT/n0035 [9])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<9>  (
    .CI(\ALU_UUT/Madd_n0035_cy [8]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [9]),
    .O(\ALU_UUT/Madd_n0035_cy [9])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<8>  (
    .CI(\ALU_UUT/Madd_n0035_cy [7]),
    .LI(\ALU_UUT/Madd_n0035_lut [8]),
    .O(\ALU_UUT/n0035 [8])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<8>  (
    .CI(\ALU_UUT/Madd_n0035_cy [7]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [8]),
    .O(\ALU_UUT/Madd_n0035_cy [8])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<7>  (
    .CI(\ALU_UUT/Madd_n0035_cy [6]),
    .LI(\ALU_UUT/Madd_n0035_lut [7]),
    .O(\ALU_UUT/n0035 [7])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<7>  (
    .CI(\ALU_UUT/Madd_n0035_cy [6]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [7]),
    .O(\ALU_UUT/Madd_n0035_cy [7])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<6>  (
    .CI(\ALU_UUT/Madd_n0035_cy [5]),
    .LI(\ALU_UUT/Madd_n0035_lut [6]),
    .O(\ALU_UUT/n0035 [6])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<6>  (
    .CI(\ALU_UUT/Madd_n0035_cy [5]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [6]),
    .O(\ALU_UUT/Madd_n0035_cy [6])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<5>  (
    .CI(\ALU_UUT/Madd_n0035_cy [4]),
    .LI(\ALU_UUT/Madd_n0035_lut [5]),
    .O(\ALU_UUT/n0035 [5])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<5>  (
    .CI(\ALU_UUT/Madd_n0035_cy [4]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [5]),
    .O(\ALU_UUT/Madd_n0035_cy [5])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<4>  (
    .CI(\ALU_UUT/Madd_n0035_cy [3]),
    .LI(\ALU_UUT/Madd_n0035_lut [4]),
    .O(\ALU_UUT/n0035 [4])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<4>  (
    .CI(\ALU_UUT/Madd_n0035_cy [3]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [4]),
    .O(\ALU_UUT/Madd_n0035_cy [4])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<3>  (
    .CI(\ALU_UUT/Madd_n0035_cy [2]),
    .LI(\ALU_UUT/Madd_n0035_lut [3]),
    .O(\ALU_UUT/n0035 [3])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<3>  (
    .CI(\ALU_UUT/Madd_n0035_cy [2]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Madd_n0035_lut [3]),
    .O(\ALU_UUT/Madd_n0035_cy [3])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<2>  (
    .CI(\ALU_UUT/Madd_n0035_cy [1]),
    .LI(\ALU_UUT/Madd_n0035_lut [2]),
    .O(\ALU_UUT/n0035 [2])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<2>  (
    .CI(\ALU_UUT/Madd_n0035_cy [1]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Madd_n0035_lut [2]),
    .O(\ALU_UUT/Madd_n0035_cy [2])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<1>  (
    .CI(\ALU_UUT/Madd_n0035_cy [0]),
    .LI(\ALU_UUT/Madd_n0035_lut [1]),
    .O(\ALU_UUT/n0035 [1])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<1>  (
    .CI(\ALU_UUT/Madd_n0035_cy [0]),
    .DI(Mram__n0036),
    .S(\ALU_UUT/Madd_n0035_lut [1]),
    .O(\ALU_UUT/Madd_n0035_cy [1])
  );
  XORCY   \ALU_UUT/Madd_n0035_xor<0>  (
    .CI(\ALU_UUT/Madd_n0035_lut [31]),
    .LI(\ALU_UUT/Madd_n0035_lut<0>1_357 ),
    .O(\ALU_UUT/n0035 [0])
  );
  MUXCY   \ALU_UUT/Madd_n0035_cy<0>  (
    .CI(\ALU_UUT/Madd_n0035_lut [31]),
    .DI(Mram__n0036),
    .S(\ALU_UUT/Madd_n0035_lut<0>1_357 ),
    .O(\ALU_UUT/Madd_n0035_cy [0])
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<11>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<10>_127 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi11 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<11> ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<11>_124 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<10>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<9>_130 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi10 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<10> ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<10>_127 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<9>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<8>_133 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi9 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<9> ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<9>_130 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<8>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<7>_136 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi8 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<8> ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<8>_133 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<7>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<6>_139 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi7 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<7> ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<7>_136 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<6>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<5>_142 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi6_141 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<6>_140 ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<6>_139 )
  );
  LUT4 #(
    .INIT ( 16'h9009 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<6>  (
    .I0(\ALU_UUT/Sh112 ),
    .I1(Mram__n003610),
    .I2(\ALU_UUT/Sh17 ),
    .I3(Mram__n003611),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<6>_140 )
  );
  LUT4 #(
    .INIT ( 16'h08AE ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi6  (
    .I0(Mram__n003611),
    .I1(Mram__n003610),
    .I2(\ALU_UUT/Sh112 ),
    .I3(\ALU_UUT/Sh17 ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi6_141 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<5>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<4>_145 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi5_144 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<5>_143 ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<5>_142 )
  );
  LUT4 #(
    .INIT ( 16'h9009 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<5>  (
    .I0(\ALU_UUT/Sh351 ),
    .I1(Mram__n003610),
    .I2(\ALU_UUT/Sh112 ),
    .I3(Mram__n003611),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<5>_143 )
  );
  LUT4 #(
    .INIT ( 16'h08AE ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi5  (
    .I0(Mram__n003611),
    .I1(Mram__n003610),
    .I2(\ALU_UUT/Sh351 ),
    .I3(\ALU_UUT/Sh112 ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi5_144 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<4>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<3>_148 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi4_147 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<4>_146 ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<4>_145 )
  );
  LUT4 #(
    .INIT ( 16'h9009 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<4>  (
    .I0(\ALU_UUT/Sh112 ),
    .I1(Mram__n003611),
    .I2(Mram__n003633),
    .I3(Mram__n003610),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<4>_146 )
  );
  LUT4 #(
    .INIT ( 16'h08AE ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi4  (
    .I0(Mram__n003610),
    .I1(Mram__n003611),
    .I2(\ALU_UUT/Sh112 ),
    .I3(Mram__n003633),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi4_147 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<3>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<2>_151 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi3 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<3> ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<3>_148 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<2>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<1>_154 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi2_153 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<2> ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<2>_151 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<1>  (
    .CI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<0>_157 ),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi1_156 ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<1>_155 ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<1>_154 )
  );
  LUT4 #(
    .INIT ( 16'h9009 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<1>  (
    .I0(\ALU_UUT/Sh351 ),
    .I1(Mram__n003611),
    .I2(\ALU_UUT/Sh112 ),
    .I3(Mram__n003610),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<1>_155 )
  );
  LUT4 #(
    .INIT ( 16'h08AE ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi1  (
    .I0(Mram__n003610),
    .I1(Mram__n003611),
    .I2(\ALU_UUT/Sh351 ),
    .I3(\ALU_UUT/Sh112 ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi1_156 )
  );
  MUXCY   \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<0>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [31]),
    .DI(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi ),
    .S(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<0> ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<0>_157 )
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<32>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [31]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [31]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [32])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<31>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [30]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [31]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [31])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<31>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [30]),
    .DI(Mram__n003631),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [31]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [31])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<30>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [29]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [30]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [30])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<30>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [29]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [30]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [30])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<29>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [28]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [29]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [29])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<29>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [28]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [29]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [29])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<28>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [27]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [28]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [28])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<28>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [27]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [28]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [28])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<27>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [26]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [27]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [27])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<27>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [26]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [27]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [27])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<26>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [25]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [26]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [26])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<26>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [25]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [26]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [26])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<25>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [24]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [25]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [25])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<25>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [24]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [25]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [25])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<24>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [23]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [24]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [24])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<24>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [23]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [24]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [24])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<23>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [22]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [23]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [23])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<23>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [22]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [23]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [23])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<22>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [21]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [22]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [22])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<22>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [21]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [22]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [22])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<21>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [20]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [21]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [21])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<21>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [20]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [21]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [21])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<20>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [19]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [20]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [20])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<20>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [19]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [20]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [20])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<19>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [18]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [19]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [19])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<19>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [18]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [19]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [19])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<18>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [17]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [18]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [18])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<18>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [17]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [18]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [18])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<17>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [16]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [17]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [17])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<17>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [16]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [17]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [17])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<16>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [15]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [16]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [16])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<16>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [15]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [16]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [16])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<15>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [14]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [15]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [15])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<15>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [14]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [15]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [15])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<14>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [13]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [14]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [14])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<14>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [13]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [14]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [14])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<13>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [12]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [13]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [13])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<13>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [12]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [13]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [13])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<12>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [11]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [12]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [12])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<12>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [11]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [12]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [12])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<11>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [10]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [11]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [11])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<11>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [10]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [11]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [11])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<10>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [9]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [10]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [10])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<10>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [9]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [10]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [10])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<9>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [8]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [9]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [9])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<9>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [8]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [9]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [9])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<8>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [7]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [8]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [8])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<8>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [7]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [8]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [8])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<7>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [6]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [7]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [7])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<7>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [6]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [7]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [7])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<6>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [5]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [6]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [6])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<6>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [5]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [6]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [6])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<5>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [4]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [5]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [5])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<5>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [4]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [5]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [5])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<4>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [3]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [4]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [4])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<4>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [3]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [4]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [4])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<3>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [2]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [3]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [3])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<3>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [2]),
    .DI(Mram__n003610),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [3]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [3])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<2>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [1]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [2]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [2])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<2>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [1]),
    .DI(Mram__n003611),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [2]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [2])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<1>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [0]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [1]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [1])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<1>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [0]),
    .DI(Mram__n0036),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [1]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [1])
  );
  XORCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_xor<0>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [31]),
    .LI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [0]),
    .O(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [0])
  );
  MUXCY   \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy<0>  (
    .CI(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [31]),
    .DI(Mram__n0036),
    .S(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [0]),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_cy [0])
  );
  LUT2 #(
    .INIT ( 4'h6 ))
  Mram__n00361 (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_2_IBUF_3),
    .O(Mram__n0036)
  );
  LUT3 #(
    .INIT ( 8'hD8 ))
  Mram__n0036101 (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(Mram__n003610)
  );
  LUT3 #(
    .INIT ( 8'h72 ))
  Mram__n0036311 (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(Mram__n003631)
  );
  LUT3 #(
    .INIT ( 8'h72 ))
  Mram__n0036321 (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Sh351 )
  );
  LUT3 #(
    .INIT ( 8'hBA ))
  Mram__n0036331 (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(Mram__n003633)
  );
  LUT3 #(
    .INIT ( 8'hD8 ))
  Mram__n0036371 (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Sh17 )
  );
  LUT3 #(
    .INIT ( 8'h64 ))
  Mram__n0036111 (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_2_IBUF_3),
    .I2(AB_SW_1_IBUF_4),
    .O(Mram__n003611)
  );
  LUT3 #(
    .INIT ( 8'h64 ))
  Mram__n0036351 (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_2_IBUF_3),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Sh112 )
  );
  LUT3 #(
    .INIT ( 8'h10 ))
  \ALU_UUT/Mmux_F1181  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_2_IBUF_0),
    .O(\ALU_UUT/Mmux_F113_56 )
  );
  LUT3 #(
    .INIT ( 8'h80 ))
  \ALU_UUT/Mmux_F1141  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .O(\ALU_UUT/Mmux_F114_55 )
  );
  LUT3 #(
    .INIT ( 8'h40 ))
  \ALU_UUT/Mmux_F1121  (
    .I0(ALU_OP_1_IBUF_1),
    .I1(ALU_OP_0_IBUF_2),
    .I2(ALU_OP_2_IBUF_0),
    .O(\ALU_UUT/Mmux_F112_57 )
  );
  LUT3 #(
    .INIT ( 8'hD8 ))
  Mmux_LED81 (
    .I0(F_LED_SW_1_IBUF_7),
    .I1(\F[23] ),
    .I2(\F[7] ),
    .O(Mmux_LED8)
  );
  LUT6 #(
    .INIT ( 64'h5551151144400400 ))
  Mmux_LED82 (
    .I0(F_LED_SW_2_IBUF_6),
    .I1(F_LED_SW_0_IBUF_8),
    .I2(F_LED_SW_1_IBUF_7),
    .I3(\F[15] ),
    .I4(\F[31] ),
    .I5(Mmux_LED8),
    .O(Mmux_LED81_296)
  );
  LUT4 #(
    .INIT ( 16'h0001 ))
  Mmux_LED83 (
    .I0(\F[17] ),
    .I1(\F[3] ),
    .I2(\F[18] ),
    .I3(\F[19] ),
    .O(Mmux_LED82_297)
  );
  LUT6 #(
    .INIT ( 64'h0000000000000010 ))
  Mmux_LED84 (
    .I0(\F[20] ),
    .I1(\F[21] ),
    .I2(Mmux_LED82_297),
    .I3(\ALU_UUT/Mmux_F115_313 ),
    .I4(\F[2] ),
    .I5(\F[0] ),
    .O(Mmux_LED83_298)
  );
  LUT6 #(
    .INIT ( 64'h0000000000000001 ))
  Mmux_LED86 (
    .I0(\F[12] ),
    .I1(\F[11] ),
    .I2(\F[13] ),
    .I3(\F[14] ),
    .I4(\F[15] ),
    .I5(\F[5] ),
    .O(Mmux_LED85)
  );
  LUT6 #(
    .INIT ( 64'h0000000000000010 ))
  Mmux_LED87 (
    .I0(\ALU_UUT/Mmux_F262_325 ),
    .I1(\F[7] ),
    .I2(F_LED_SW_2_IBUF_6),
    .I3(\F[8] ),
    .I4(\F[9] ),
    .I5(\F[10] ),
    .O(Mmux_LED86_300)
  );
  LUT6 #(
    .INIT ( 64'h0000000000040000 ))
  Mmux_LED88 (
    .I0(\F[6] ),
    .I1(Mmux_LED85),
    .I2(\F[22] ),
    .I3(\F[16] ),
    .I4(Mmux_LED86_300),
    .I5(\F[23] ),
    .O(Mmux_LED87_301)
  );
  LUT3 #(
    .INIT ( 8'h1D ))
  Mmux_LED7_SW0 (
    .I0(\F[6] ),
    .I1(F_LED_SW_0_IBUF_8),
    .I2(\F[14] ),
    .O(N2)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED7 (
    .I0(F_LED_SW_2_IBUF_6),
    .I1(F_LED_SW_1_IBUF_7),
    .I2(\F[22] ),
    .I3(F_LED_SW_0_IBUF_8),
    .I4(\F[30] ),
    .I5(N2),
    .O(LED_6_OBUF_40)
  );
  LUT3 #(
    .INIT ( 8'h1D ))
  Mmux_LED6_SW0 (
    .I0(\F[5] ),
    .I1(F_LED_SW_0_IBUF_8),
    .I2(\F[13] ),
    .O(N4)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED6 (
    .I0(F_LED_SW_2_IBUF_6),
    .I1(F_LED_SW_1_IBUF_7),
    .I2(\F[21] ),
    .I3(F_LED_SW_0_IBUF_8),
    .I4(\F[29] ),
    .I5(N4),
    .O(LED_5_OBUF_41)
  );
  LUT3 #(
    .INIT ( 8'h1D ))
  Mmux_LED5_SW0 (
    .I0(\ALU_UUT/Mmux_F262_325 ),
    .I1(F_LED_SW_0_IBUF_8),
    .I2(\F[12] ),
    .O(N6)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED5 (
    .I0(F_LED_SW_2_IBUF_6),
    .I1(F_LED_SW_1_IBUF_7),
    .I2(\F[20] ),
    .I3(F_LED_SW_0_IBUF_8),
    .I4(\F[28] ),
    .I5(N6),
    .O(LED_4_OBUF_42)
  );
  LUT3 #(
    .INIT ( 8'h1D ))
  Mmux_LED4_SW0 (
    .I0(\F[3] ),
    .I1(F_LED_SW_0_IBUF_8),
    .I2(\F[11] ),
    .O(N8)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED4 (
    .I0(F_LED_SW_2_IBUF_6),
    .I1(F_LED_SW_1_IBUF_7),
    .I2(\F[19] ),
    .I3(F_LED_SW_0_IBUF_8),
    .I4(\F[27] ),
    .I5(N8),
    .O(LED_3_OBUF_43)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED3 (
    .I0(F_LED_SW_2_IBUF_6),
    .I1(F_LED_SW_1_IBUF_7),
    .I2(\F[18] ),
    .I3(F_LED_SW_0_IBUF_8),
    .I4(\F[26] ),
    .I5(N10),
    .O(LED_2_OBUF_44)
  );
  LUT3 #(
    .INIT ( 8'h1D ))
  Mmux_LED2_SW0 (
    .I0(\ALU_UUT/Mmux_F115_313 ),
    .I1(F_LED_SW_0_IBUF_8),
    .I2(\F[9] ),
    .O(N12)
  );
  LUT6 #(
    .INIT ( 64'h4440004055511151 ))
  Mmux_LED2 (
    .I0(F_LED_SW_2_IBUF_6),
    .I1(F_LED_SW_1_IBUF_7),
    .I2(\F[17] ),
    .I3(F_LED_SW_0_IBUF_8),
    .I4(\F[25] ),
    .I5(N12),
    .O(LED_1_OBUF_45)
  );
  LUT5 #(
    .INIT ( 32'hFFFFF888 ))
  \ALU_UUT/Mmux_F113  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [10]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Mmux_F113_56 ),
    .I3(\ALU_UUT/n0035 [10]),
    .I4(\ALU_UUT/Mmux_F12 ),
    .O(\F[10] )
  );
  LUT5 #(
    .INIT ( 32'h11141440 ))
  \ALU_UUT/Mmux_F251  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(\ALU_UUT/Sh112 ),
    .I3(Mram__n003610),
    .I4(ALU_OP_0_IBUF_2),
    .O(\ALU_UUT/Mmux_F25 )
  );
  LUT5 #(
    .INIT ( 32'hFFFFF888 ))
  \ALU_UUT/Mmux_F252  (
    .I0(\ALU_UUT/Mmux_F113_56 ),
    .I1(\ALU_UUT/n0035 [3]),
    .I2(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [3]),
    .I3(\ALU_UUT/Mmux_F112_57 ),
    .I4(\ALU_UUT/Mmux_F25 ),
    .O(\ALU_UUT/Mmux_F251_310 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFF20000000 ))
  \ALU_UUT/Mmux_F255  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/_n0039 ),
    .I2(ALU_OP_1_IBUF_1),
    .I3(ALU_OP_2_IBUF_0),
    .I4(\ALU_UUT/Mmux_F253 ),
    .I5(\ALU_UUT/Mmux_F251_310 ),
    .O(\F[3] )
  );
  LUT5 #(
    .INIT ( 32'hFFFFF888 ))
  \ALU_UUT/Mmux_F115  (
    .I0(\ALU_UUT/Mmux_F113_56 ),
    .I1(\ALU_UUT/n0035 [1]),
    .I2(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [1]),
    .I3(\ALU_UUT/Mmux_F112_57 ),
    .I4(\ALU_UUT/Mmux_F111 ),
    .O(\ALU_UUT/Mmux_F115_313 )
  );
  LUT5 #(
    .INIT ( 32'h11141440 ))
  \ALU_UUT/Mmux_F221  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(\ALU_UUT/Sh351 ),
    .I3(Mram__n003611),
    .I4(ALU_OP_0_IBUF_2),
    .O(\ALU_UUT/Mmux_F22 )
  );
  LUT5 #(
    .INIT ( 32'hFFFFF888 ))
  \ALU_UUT/Mmux_F222  (
    .I0(\ALU_UUT/Mmux_F113_56 ),
    .I1(\ALU_UUT/n0035 [2]),
    .I2(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [2]),
    .I3(\ALU_UUT/Mmux_F112_57 ),
    .I4(\ALU_UUT/Mmux_F22 ),
    .O(\ALU_UUT/Mmux_F221_315 )
  );
  LUT6 #(
    .INIT ( 64'h88FD0075CCA84420 ))
  \ALU_UUT/Mmux_F242  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_0_IBUF_2),
    .I2(\ALU_UUT/n0035 [31]),
    .I3(ALU_OP_1_IBUF_1),
    .I4(\ALU_UUT/Mmux_F24_317 ),
    .I5(Mram__n003631),
    .O(\F[31] )
  );
  LUT5 #(
    .INIT ( 32'h11141440 ))
  \ALU_UUT/Mmux_F62  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(\ALU_UUT/Sh112 ),
    .I3(Mram__n003611),
    .I4(ALU_OP_0_IBUF_2),
    .O(\ALU_UUT/Mmux_F27 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F63  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [15]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Madd_n0035_lut [31]),
    .I3(\ALU_UUT/Mmux_F27 ),
    .I4(\ALU_UUT/Mmux_F113_56 ),
    .I5(\ALU_UUT/n0035 [15]),
    .O(\F[15] )
  );
  LUT5 #(
    .INIT ( 32'hAF0DAA08 ))
  \ALU_UUT/Mmux_F232  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [30]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Madd_n0035_lut [31]),
    .I4(\ALU_UUT/n0035 [30]),
    .O(\ALU_UUT/Mmux_F231 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F233  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh112 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F231 ),
    .O(\F[30] )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F54  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [14]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Madd_n0035_lut [31]),
    .I3(\ALU_UUT/Mmux_F25 ),
    .I4(\ALU_UUT/Mmux_F113_56 ),
    .I5(\ALU_UUT/n0035 [14]),
    .O(\F[14] )
  );
  LUT5 #(
    .INIT ( 32'hAF0DAA08 ))
  \ALU_UUT/Mmux_F212  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [29]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Madd_n0035_lut [31]),
    .I4(\ALU_UUT/n0035 [29]),
    .O(\ALU_UUT/Mmux_F211 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F213  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh17 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F211 ),
    .O(\F[29] )
  );
  LUT5 #(
    .INIT ( 32'h11141440 ))
  \ALU_UUT/Mmux_F42  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(\ALU_UUT/Sh17 ),
    .I3(Mram__n003611),
    .I4(ALU_OP_0_IBUF_2),
    .O(\ALU_UUT/Mmux_F41 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F43  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [13]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Madd_n0035_lut [31]),
    .I3(\ALU_UUT/Mmux_F41 ),
    .I4(\ALU_UUT/Mmux_F113_56 ),
    .I5(\ALU_UUT/n0035 [13]),
    .O(\F[13] )
  );
  LUT5 #(
    .INIT ( 32'hAF0DAA08 ))
  \ALU_UUT/Mmux_F202  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [28]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Madd_n0035_lut [31]),
    .I4(\ALU_UUT/n0035 [28]),
    .O(\ALU_UUT/Mmux_F201 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F203  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh17 ),
    .I4(Mram__n003610),
    .I5(\ALU_UUT/Mmux_F201 ),
    .O(\F[28] )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F35  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [12]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Madd_n0035_lut [31]),
    .I3(\ALU_UUT/Mmux_F25 ),
    .I4(\ALU_UUT/Mmux_F113_56 ),
    .I5(\ALU_UUT/n0035 [12]),
    .O(\F[12] )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F24  (
    .I0(\ALU_UUT/Mmux_F113_56 ),
    .I1(\ALU_UUT/n0035 [11]),
    .I2(\ALU_UUT/Madd_n0035_lut [31]),
    .I3(\ALU_UUT/Mmux_F27 ),
    .I4(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [11]),
    .I5(\ALU_UUT/Mmux_F112_57 ),
    .O(\F[11] )
  );
  LUT5 #(
    .INIT ( 32'h11141440 ))
  \ALU_UUT/Mmux_F313  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(Mram__n003633),
    .I3(Mram__n003610),
    .I4(ALU_OP_0_IBUF_2),
    .O(\ALU_UUT/Mmux_F313_323 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F314  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [9]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Madd_n0035_lut [31]),
    .I3(\ALU_UUT/Mmux_F313_323 ),
    .I4(\ALU_UUT/Mmux_F113_56 ),
    .I5(\ALU_UUT/n0035 [9]),
    .O(\F[9] )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F304  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [8]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Madd_n0035_lut [31]),
    .I3(\ALU_UUT/Mmux_F27 ),
    .I4(\ALU_UUT/Mmux_F113_56 ),
    .I5(\ALU_UUT/n0035 [8]),
    .O(\F[8] )
  );
  LUT6 #(
    .INIT ( 64'h7775575522200200 ))
  \ALU_UUT/Mmux_F262  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/n0035 [4]),
    .I4(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [4]),
    .I5(\ALU_UUT/Mmux_F261_324 ),
    .O(\ALU_UUT/Mmux_F262_325 )
  );
  LUT6 #(
    .INIT ( 64'hAF0D0D0DAA080808 ))
  \ALU_UUT/Mmux_F91  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [18]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Mmux_F16211 ),
    .I4(\ALU_UUT/Sh50 ),
    .I5(\ALU_UUT/n0035 [18]),
    .O(\ALU_UUT/Mmux_F9 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F92  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh112 ),
    .I4(Mram__n003610),
    .I5(\ALU_UUT/Mmux_F9 ),
    .O(\F[18] )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F82  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh17 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F8 ),
    .O(\F[17] )
  );
  LUT6 #(
    .INIT ( 64'hAF0D0D0DAA080808 ))
  \ALU_UUT/Mmux_F71  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [16]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Mmux_F16211 ),
    .I4(AB_SW_2_IBUF_3),
    .I5(\ALU_UUT/n0035 [16]),
    .O(\ALU_UUT/Mmux_F7 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F72  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh17 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F7 ),
    .O(\F[16] )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F152  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh112 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F15 ),
    .O(\F[23] )
  );
  LUT6 #(
    .INIT ( 64'hAF0D0D0DAA080808 ))
  \ALU_UUT/Mmux_F141  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [22]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Mmux_F16211 ),
    .I4(\ALU_UUT/Sh30 ),
    .I5(\ALU_UUT/n0035 [22]),
    .O(\ALU_UUT/Mmux_F14 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F142  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh112 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F14 ),
    .O(\F[22] )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F132  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh17 ),
    .I4(Mram__n003610),
    .I5(\ALU_UUT/Mmux_F13 ),
    .O(\F[21] )
  );
  LUT6 #(
    .INIT ( 64'hAF0D0D0DAA080808 ))
  \ALU_UUT/Mmux_F121  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [20]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Mmux_F16211 ),
    .I4(\ALU_UUT/Sh52 ),
    .I5(\ALU_UUT/n0035 [20]),
    .O(\ALU_UUT/Mmux_F121_332 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F122  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh17 ),
    .I4(Mram__n003610),
    .I5(\ALU_UUT/Mmux_F121_332 ),
    .O(\F[20] )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F102  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh112 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F10 ),
    .O(\F[19] )
  );
  LUT5 #(
    .INIT ( 32'hAF0DAA08 ))
  \ALU_UUT/Mmux_F192  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [27]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Madd_n0035_lut [31]),
    .I4(\ALU_UUT/n0035 [27]),
    .O(\ALU_UUT/Mmux_F191 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F193  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh112 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F191 ),
    .O(\F[27] )
  );
  LUT5 #(
    .INIT ( 32'hAF0DAA08 ))
  \ALU_UUT/Mmux_F182  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [26]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Madd_n0035_lut [31]),
    .I4(\ALU_UUT/n0035 [26]),
    .O(\ALU_UUT/Mmux_F181 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F183  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh112 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F181 ),
    .O(\F[26] )
  );
  LUT5 #(
    .INIT ( 32'hAF0DAA08 ))
  \ALU_UUT/Mmux_F172  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [25]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Madd_n0035_lut [31]),
    .I4(\ALU_UUT/n0035 [25]),
    .O(\ALU_UUT/Mmux_F171 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F173  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh17 ),
    .I4(Mram__n003610),
    .I5(\ALU_UUT/Mmux_F171 ),
    .O(\F[25] )
  );
  LUT5 #(
    .INIT ( 32'hAF0DAA08 ))
  \ALU_UUT/Mmux_F162  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [24]),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Madd_n0035_lut [31]),
    .I4(\ALU_UUT/n0035 [24]),
    .O(\ALU_UUT/Mmux_F161 )
  );
  LUT6 #(
    .INIT ( 64'hBBBEBEEA11141440 ))
  \ALU_UUT/Mmux_F163  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(ALU_OP_0_IBUF_2),
    .I3(\ALU_UUT/Sh17 ),
    .I4(Mram__n003611),
    .I5(\ALU_UUT/Mmux_F161 ),
    .O(\F[24] )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F294  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [7]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Mmux_F291 ),
    .I3(\ALU_UUT/Mmux_F27 ),
    .I4(\ALU_UUT/Mmux_F113_56 ),
    .I5(\ALU_UUT/n0035 [7]),
    .O(\F[7] )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFF8FFF8FFF8 ))
  \ALU_UUT/Mmux_F284  (
    .I0(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [6]),
    .I1(\ALU_UUT/Mmux_F112_57 ),
    .I2(\ALU_UUT/Mmux_F282 ),
    .I3(\ALU_UUT/Mmux_F25 ),
    .I4(\ALU_UUT/Mmux_F113_56 ),
    .I5(\ALU_UUT/n0035 [6]),
    .O(\F[6] )
  );
  IBUF   ALU_OP_2_IBUF (
    .I(ALU_OP[2]),
    .O(ALU_OP_2_IBUF_0)
  );
  IBUF   ALU_OP_1_IBUF (
    .I(ALU_OP[1]),
    .O(ALU_OP_1_IBUF_1)
  );
  IBUF   ALU_OP_0_IBUF (
    .I(ALU_OP[0]),
    .O(ALU_OP_0_IBUF_2)
  );
  IBUF   AB_SW_2_IBUF (
    .I(AB_SW[2]),
    .O(AB_SW_2_IBUF_3)
  );
  IBUF   AB_SW_1_IBUF (
    .I(AB_SW[1]),
    .O(AB_SW_1_IBUF_4)
  );
  IBUF   AB_SW_0_IBUF (
    .I(AB_SW[0]),
    .O(AB_SW_0_IBUF_5)
  );
  IBUF   F_LED_SW_2_IBUF (
    .I(F_LED_SW[2]),
    .O(F_LED_SW_2_IBUF_6)
  );
  IBUF   F_LED_SW_1_IBUF (
    .I(F_LED_SW[1]),
    .O(F_LED_SW_1_IBUF_7)
  );
  IBUF   F_LED_SW_0_IBUF (
    .I(F_LED_SW[0]),
    .O(F_LED_SW_0_IBUF_8)
  );
  OBUF   LED_7_OBUF (
    .I(LED_7_OBUF_39),
    .O(LED[7])
  );
  OBUF   LED_6_OBUF (
    .I(LED_6_OBUF_40),
    .O(LED[6])
  );
  OBUF   LED_5_OBUF (
    .I(LED_5_OBUF_41),
    .O(LED[5])
  );
  OBUF   LED_4_OBUF (
    .I(LED_4_OBUF_42),
    .O(LED[4])
  );
  OBUF   LED_3_OBUF (
    .I(LED_3_OBUF_43),
    .O(LED[3])
  );
  OBUF   LED_2_OBUF (
    .I(LED_2_OBUF_44),
    .O(LED[2])
  );
  OBUF   LED_1_OBUF (
    .I(LED_1_OBUF_45),
    .O(LED[1])
  );
  OBUF   LED_0_OBUF (
    .I(LED_0_OBUF_46),
    .O(LED[0])
  );
  LUT6 #(
    .INIT ( 64'hD5F791B3C4E680A2 ))
  \ALU_UUT/Mmux_F_3  (
    .I0(ALU_OP_1_IBUF_1),
    .I1(ALU_OP_0_IBUF_2),
    .I2(\ALU_UUT/Madd_n0035_lut [31]),
    .I3(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<15>_123 ),
    .I4(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [0]),
    .I5(\ALU_UUT/n0035 [0]),
    .O(\ALU_UUT/Mmux_F_3_58 )
  );
  LUT6 #(
    .INIT ( 64'h0514144025341440 ))
  \ALU_UUT/Mmux_F112  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(Mram__n003610),
    .I2(ALU_OP_1_IBUF_1),
    .I3(\ALU_UUT/Sh351 ),
    .I4(ALU_OP_0_IBUF_2),
    .I5(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [31]),
    .O(\ALU_UUT/Mmux_F12 )
  );
  LUT6 #(
    .INIT ( 64'h0000000000040000 ))
  Mmux_LED810_SW0 (
    .I0(\F[28] ),
    .I1(Mmux_LED87_301),
    .I2(\F[29] ),
    .I3(\F[30] ),
    .I4(Mmux_LED83_298),
    .I5(\F[31] ),
    .O(N20)
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFF00010000 ))
  Mmux_LED810 (
    .I0(\F[24] ),
    .I1(\F[25] ),
    .I2(\F[26] ),
    .I3(\F[27] ),
    .I4(N20),
    .I5(Mmux_LED81_296),
    .O(LED_7_OBUF_39)
  );
  LUT5 #(
    .INIT ( 32'hF7D5A280 ))
  \ALU_UUT/Mmux_F254  (
    .I0(Mram__n003611),
    .I1(Mram__n003610),
    .I2(\ALU_UUT/Sh31 ),
    .I3(\ALU_UUT/Sh351 ),
    .I4(\ALU_UUT/Sh112 ),
    .O(\ALU_UUT/Mmux_F253 )
  );
  LUT6 #(
    .INIT ( 64'h11011111DDCDDDDD ))
  Mmux_LED3_SW0 (
    .I0(\ALU_UUT/Mmux_F221_315 ),
    .I1(F_LED_SW_0_IBUF_8),
    .I2(\ALU_UUT/Mmux_F114_55 ),
    .I3(\ALU_UUT/_n0039 ),
    .I4(\ALU_UUT/Mmux_F224 ),
    .I5(\F[10] ),
    .O(N10)
  );
  LUT6 #(
    .INIT ( 64'hFFD8D8D800D8D8D8 ))
  \ALU_UUT/Sh5011  (
    .I0(Mram__n0036),
    .I1(\ALU_UUT/Sh17 ),
    .I2(\ALU_UUT/Sh112 ),
    .I3(Mram__n003611),
    .I4(Mram__n003610),
    .I5(\ALU_UUT/Sh30 ),
    .O(\ALU_UUT/Sh50 )
  );
  LUT5 #(
    .INIT ( 32'h01000000 ))
  \ALU_UUT/Mmux_F292  (
    .I0(Mram__n003611),
    .I1(Mram__n003610),
    .I2(Mram__n003631),
    .I3(\ALU_UUT/Mmux_F114_55 ),
    .I4(\ALU_UUT/Sh351 ),
    .O(\ALU_UUT/Mmux_F291 )
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<30>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [30])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<29>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [29])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<28>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [28])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<27>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [27])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<26>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [26])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<25>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [25])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<24>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [24])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<23>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [23])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<22>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [22])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<21>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [21])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<20>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [20])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<19>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [19])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<18>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [18])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<17>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [17])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<16>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [16])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<15>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [15])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<14>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [14])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<13>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [13])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<12>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [12])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<11>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [11])
  );
  LUT3 #(
    .INIT ( 8'hD8 ))
  \ALU_UUT/Madd_n0035_lut<10>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_2_IBUF_3),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [10])
  );
  LUT3 #(
    .INIT ( 8'h64 ))
  \ALU_UUT/Madd_n0035_lut<9>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Madd_n0035_lut [9])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<8>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [8])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<7>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [7])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<6>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [6])
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<5>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [5])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<4>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [4])
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<3>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Madd_n0035_lut [3])
  );
  LUT3 #(
    .INIT ( 8'h64 ))
  \ALU_UUT/Madd_n0035_lut<2>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Madd_n0035_lut [2])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<30>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [30])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<29>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [29])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<28>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [28])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<27>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [27])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<26>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [26])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<25>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [25])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<24>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [24])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<23>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [23])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<22>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [22])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<21>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [21])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<20>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [20])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<19>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [19])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<18>  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [18])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<17>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [17])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<16>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [16])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<15>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [15])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<14>  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [14])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<13>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [13])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<12>  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [12])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<11>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [11])
  );
  LUT3 #(
    .INIT ( 8'h1D ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<10>  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [10])
  );
  LUT3 #(
    .INIT ( 8'h9B ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<9>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [9])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<8>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [8])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<7>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [7])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<6>  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [6])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<5>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [5])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<4>  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [4])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<3>  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [3])
  );
  LUT3 #(
    .INIT ( 8'h9B ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<2>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [2])
  );
  LUT5 #(
    .INIT ( 32'h65686858 ))
  \ALU_UUT/Mmux_F261  (
    .I0(ALU_OP_1_IBUF_1),
    .I1(ALU_OP_0_IBUF_2),
    .I2(AB_SW_2_IBUF_3),
    .I3(AB_SW_0_IBUF_5),
    .I4(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Mmux_F261_324 )
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<11>1  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<11> )
  );
  LUT3 #(
    .INIT ( 8'h40 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi111  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_2_IBUF_3),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi11 )
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<10>1  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<10> )
  );
  LUT3 #(
    .INIT ( 8'h40 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi101  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi10 )
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<8>1  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<8> )
  );
  LUT3 #(
    .INIT ( 8'h40 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi81  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_2_IBUF_3),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi8 )
  );
  LUT6 #(
    .INIT ( 64'h5555557500000020 ))
  \ALU_UUT/Mmux_F241  (
    .I0(ALU_OP_1_IBUF_1),
    .I1(Mram__n003610),
    .I2(\ALU_UUT/Sh31 ),
    .I3(Mram__n003611),
    .I4(Mram__n003631),
    .I5(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [31]),
    .O(\ALU_UUT/Mmux_F24_317 )
  );
  LUT3 #(
    .INIT ( 8'hA8 ))
  \ALU_UUT/Madd_n0035_lut<1>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut [1])
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<1>  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [1])
  );
  LUT3 #(
    .INIT ( 8'hD7 ))
  \ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut<0>  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Msub_GND_2_o_GND_2_o_sub_7_OUT_lut [0])
  );
  LUT3 #(
    .INIT ( 8'h40 ))
  \ALU_UUT/Sh301  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_2_IBUF_3),
    .I2(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Sh30 )
  );
  LUT3 #(
    .INIT ( 8'h18 ))
  \ALU_UUT/Sh311  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_2_IBUF_3),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Sh31 )
  );
  LUT6 #(
    .INIT ( 64'h0541144005411404 ))
  \ALU_UUT/Mmux_F114  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(AB_SW_2_IBUF_3),
    .I2(ALU_OP_1_IBUF_1),
    .I3(ALU_OP_0_IBUF_2),
    .I4(AB_SW_0_IBUF_5),
    .I5(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Mmux_F111 )
  );
  LUT3 #(
    .INIT ( 8'h28 ))
  \ALU_UUT/Madd_n0035_lut<0>1  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Madd_n0035_lut<0>1_357 )
  );
  LUT6 #(
    .INIT ( 64'hFFFFFFFF20000000 ))
  \ALU_UUT/Mmux_F226  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(\ALU_UUT/_n0039 ),
    .I2(ALU_OP_1_IBUF_1),
    .I3(ALU_OP_0_IBUF_2),
    .I4(\ALU_UUT/Mmux_F224 ),
    .I5(\ALU_UUT/Mmux_F221_315 ),
    .O(\F[2] )
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi91  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi9 )
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi71  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi7 )
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi31  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi3 )
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi21  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi2_153 )
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<9>1  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<9> )
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<7>1  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<7> )
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<3>1  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<3> )
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<2>1  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<2> )
  );
  LUT3 #(
    .INIT ( 8'h40 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi2  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_2_IBUF_3),
    .I2(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lutdi )
  );
  LUT3 #(
    .INIT ( 8'h1F ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<0>1  (
    .I0(AB_SW_1_IBUF_4),
    .I1(AB_SW_0_IBUF_5),
    .I2(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_lut<0> )
  );
  LUT5 #(
    .INIT ( 32'h96183692 ))
  \ALU_UUT/Mmux_F_4  (
    .I0(AB_SW_2_IBUF_3),
    .I1(ALU_OP_1_IBUF_1),
    .I2(AB_SW_0_IBUF_5),
    .I3(ALU_OP_0_IBUF_2),
    .I4(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/Mmux_F_4_59 )
  );
  LUT2 #(
    .INIT ( 4'hE ))
  \ALU_UUT/out1  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .O(\ALU_UUT/_n0039 )
  );
  LUT2 #(
    .INIT ( 4'h8 ))
  \ALU_UUT/Sh5211  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_2_IBUF_3),
    .O(\ALU_UUT/Sh52 )
  );
  LUT4 #(
    .INIT ( 16'hF820 ))
  \ALU_UUT/Mmux_F225  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .I3(\ALU_UUT/Sh50 ),
    .O(\ALU_UUT/Mmux_F224 )
  );
  LUT3 #(
    .INIT ( 8'h10 ))
  \ALU_UUT/Mmux_F162111  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(ALU_OP_1_IBUF_1),
    .O(\ALU_UUT/Mmux_F16211 )
  );
  LUT3 #(
    .INIT ( 8'hD8 ))
  \ALU_UUT/Mmux_F274_SW0  (
    .I0(ALU_OP_0_IBUF_2),
    .I1(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [5]),
    .I2(\ALU_UUT/n0035 [5]),
    .O(N22)
  );
  LUT6 #(
    .INIT ( 64'h3336366211141440 ))
  \ALU_UUT/Mmux_F274  (
    .I0(ALU_OP_2_IBUF_0),
    .I1(ALU_OP_1_IBUF_1),
    .I2(Mram__n003610),
    .I3(\ALU_UUT/Sh17 ),
    .I4(ALU_OP_0_IBUF_2),
    .I5(N22),
    .O(\F[5] )
  );
  LUT4 #(
    .INIT ( 16'h5410 ))
  \ALU_UUT/Mmux_F131  (
    .I0(ALU_OP_1_IBUF_1),
    .I1(ALU_OP_0_IBUF_2),
    .I2(\ALU_UUT/n0035 [21]),
    .I3(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [21]),
    .O(\ALU_UUT/Mmux_F13 )
  );
  LUT4 #(
    .INIT ( 16'h5410 ))
  \ALU_UUT/Mmux_F151  (
    .I0(ALU_OP_1_IBUF_1),
    .I1(ALU_OP_0_IBUF_2),
    .I2(\ALU_UUT/n0035 [23]),
    .I3(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [23]),
    .O(\ALU_UUT/Mmux_F15 )
  );
  LUT4 #(
    .INIT ( 16'h5410 ))
  \ALU_UUT/Mmux_F101  (
    .I0(ALU_OP_1_IBUF_1),
    .I1(ALU_OP_0_IBUF_2),
    .I2(\ALU_UUT/n0035 [19]),
    .I3(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [19]),
    .O(\ALU_UUT/Mmux_F10 )
  );
  LUT4 #(
    .INIT ( 16'h5410 ))
  \ALU_UUT/Mmux_F81  (
    .I0(ALU_OP_1_IBUF_1),
    .I1(ALU_OP_0_IBUF_2),
    .I2(\ALU_UUT/n0035 [17]),
    .I3(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [17]),
    .O(\ALU_UUT/Mmux_F8 )
  );
  LUT6 #(
    .INIT ( 64'h1000000000000000 ))
  \ALU_UUT/Mmux_F283  (
    .I0(AB_SW_2_IBUF_3),
    .I1(AB_SW_1_IBUF_4),
    .I2(ALU_OP_2_IBUF_0),
    .I3(ALU_OP_1_IBUF_1),
    .I4(ALU_OP_0_IBUF_2),
    .I5(AB_SW_0_IBUF_5),
    .O(\ALU_UUT/Mmux_F282 )
  );
  LUT4 #(
    .INIT ( 16'h5F40 ))
  \ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<15>  (
    .I0(AB_SW_0_IBUF_5),
    .I1(AB_SW_1_IBUF_4),
    .I2(AB_SW_2_IBUF_3),
    .I3(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<11>_124 ),
    .O(\ALU_UUT/Mcompar_A[31]_B[31]_LessThan_8_o_cy<15>_123 )
  );
  MUXF7   Mmux_LED13 (
    .I0(N24),
    .I1(N25),
    .S(F_LED_SW_2_IBUF_6),
    .O(LED_0_OBUF_46)
  );
  LUT6 #(
    .INIT ( 64'hFD75B931EC64A820 ))
  Mmux_LED13_F (
    .I0(F_LED_SW_0_IBUF_8),
    .I1(F_LED_SW_1_IBUF_7),
    .I2(\F[8] ),
    .I3(\F[24] ),
    .I4(\F[16] ),
    .I5(\F[0] ),
    .O(N24)
  );
  LUT6 #(
    .INIT ( 64'h0404040808040808 ))
  Mmux_LED13_G (
    .I0(\F[31] ),
    .I1(ALU_OP_2_IBUF_0),
    .I2(ALU_OP_1_IBUF_1),
    .I3(ALU_OP_0_IBUF_2),
    .I4(\ALU_UUT/Madd_n0035_cy [31]),
    .I5(\ALU_UUT/GND_2_o_GND_2_o_sub_7_OUT [32]),
    .O(N25)
  );
endmodule


`ifndef GLBL
`define GLBL

`timescale  1 ps / 1 ps

module glbl ();

    parameter ROC_WIDTH = 100000;
    parameter TOC_WIDTH = 0;

//--------   STARTUP Globals --------------
    wire GSR;
    wire GTS;
    wire GWE;
    wire PRLD;
    tri1 p_up_tmp;
    tri (weak1, strong0) PLL_LOCKG = p_up_tmp;

    wire PROGB_GLBL;
    wire CCLKO_GLBL;

    reg GSR_int;
    reg GTS_int;
    reg PRLD_int;

//--------   JTAG Globals --------------
    wire JTAG_TDO_GLBL;
    wire JTAG_TCK_GLBL;
    wire JTAG_TDI_GLBL;
    wire JTAG_TMS_GLBL;
    wire JTAG_TRST_GLBL;

    reg JTAG_CAPTURE_GLBL;
    reg JTAG_RESET_GLBL;
    reg JTAG_SHIFT_GLBL;
    reg JTAG_UPDATE_GLBL;
    reg JTAG_RUNTEST_GLBL;

    reg JTAG_SEL1_GLBL = 0;
    reg JTAG_SEL2_GLBL = 0 ;
    reg JTAG_SEL3_GLBL = 0;
    reg JTAG_SEL4_GLBL = 0;

    reg JTAG_USER_TDO1_GLBL = 1'bz;
    reg JTAG_USER_TDO2_GLBL = 1'bz;
    reg JTAG_USER_TDO3_GLBL = 1'bz;
    reg JTAG_USER_TDO4_GLBL = 1'bz;

    assign (weak1, weak0) GSR = GSR_int;
    assign (weak1, weak0) GTS = GTS_int;
    assign (weak1, weak0) PRLD = PRLD_int;

    initial begin
	GSR_int = 1'b1;
	PRLD_int = 1'b1;
	#(ROC_WIDTH)
	GSR_int = 1'b0;
	PRLD_int = 1'b0;
    end

    initial begin
	GTS_int = 1'b1;
	#(TOC_WIDTH)
	GTS_int = 1'b0;
    end

endmodule

`endif


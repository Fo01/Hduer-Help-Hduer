%
% FUNCTION 2.2 : "cp0201_repcode"
%
% Introduces a repetition code for the stream of 'bits' in
%  input:
% 'Ns' identical binary values are generated from the same
%  bit
% 'repbits' represents the output binary sequence
%
% Programmed by tingcong ye
%

function [repbits]=cp0201_repcode(bits,Ns)

% ----------------------------------------------
% Step One - Introduction of the repetition code
% ----------------------------------------------

numbits = length(bits);

temprect=ones(1,Ns);
temp1=zeros(1,numbits*Ns);
temp1(1:Ns:1+Ns*(numbits-1))=bits;
temp2=conv(temp1,temprect);
repbits=temp2(1:Ns*numbits);

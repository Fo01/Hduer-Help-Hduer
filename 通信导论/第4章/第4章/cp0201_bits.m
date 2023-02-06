%
% FUNCTION 2.1 : "cp0201_bits"
%
% Generates a stream of equiprobable binary values ('bits')
% The number of bits ('numbits') is an input parameter
%
% Programmed by tingcong ye
%

function [bits]=cp0201_bits(numbits)

% --------------------------------------------
% Step One - Generation of the reference pulse
% --------------------------------------------

bits=rand(1,numbits)>0.5;

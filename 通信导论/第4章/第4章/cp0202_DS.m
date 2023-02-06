%
% FUNCTION 2.7 : "cp0202_DS"
%
% Generates a random Direct Sequence code
% with periodicity 'Np'
%
% Programmed by tingcong ye
%

function [DScode]=cp0202_DS(Np);

% ------------------------------------
% Step One - Generation of the DS code
% ------------------------------------

DScode = ((rand(1,Np)>0.5).*2)-ones(1,Np);

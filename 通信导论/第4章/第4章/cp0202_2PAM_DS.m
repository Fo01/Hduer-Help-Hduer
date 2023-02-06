%
% FUNCTION 2.8 : "cp0202_2PAM_DS"
%
% Introduces the DS code given by 'DScode'
% and implements binary PAM modulation
% 'seq' is the input binary strem
% 'fc' is the sampling frequency for the generated signal

% 'Ts' is the average pulse repetition time
% 'DScode' is the Direct Sequence Code
%
% The function generates two output streams  
% '2PPMDSseq' is the output with both TH and 2PPM
% 'DSseq' is the output with the TH only
%
% Programmed by tingcong ye
%

function [PAMDSseq,DSseq] = ...
   cp0202_2PAM_DS(seq,fc,Ts,DScode)


% --------------------------------------------------
% Step One - Implementation of the 2PPM+DS modulator
% --------------------------------------------------

dt = 1 ./ fc;                       % sampling period
framesamples = floor(Ts ./ dt);     % number of samples
                                    % between pulses

DSp = length(DScode);               % DS-code periodicity

totlength = framesamples*length(seq);
PAMDSseq = zeros(1,totlength);
DSseq = zeros(1,totlength);

% ------------------------------------------------
% Step Two - main loop for introducing DS and 2PAM
% ------------------------------------------------

for k = 1 : length(seq)
    
    % uniform pulse position
    index = 1 + (k-1)*framesamples;
    
    % introduction of DS
    kDS = DScode(1+mod(k-1,DSp));
    
    DSseq(index)=kDS;
        
    % introduction of 2PAM
            PAMDSseq(index) = kDS*((seq(k)*2)-1);
        
end % for k = 1 : length(seq)

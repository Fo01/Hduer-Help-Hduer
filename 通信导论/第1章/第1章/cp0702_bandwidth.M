%
% FUNCTION 7.7 : "cp0702_bandwidth"
%
% Evaluates the bandwidth of the input 'signal' with
% sampling rate 'dt'
% Bandwidth is evaluated according to the given 'threshold'
% (in dB)
% 'BW' is the bandwidth
% 'f_high' is the higher limit
% 'f_low' is the lower limit
%
% Programmed by Guerino Giancola / Luca De Nardis
%

function [Ess,f_high,f_low,BW] = ...
   cp0702_bandwidth(signal,dt,threshold)

% ---------------------------------------------------------
% Step One - Evaluation of the single-sided Energy Spectral
%            Density
% ---------------------------------------------------------

% sampling frequency
fs = 1 / dt;
% frequency smoothing factor
frequencysmoothingfactor = 8;
% number of samples (i.e. size of the FFT)
N = frequencysmoothingfactor * length(signal);
% fundamental frequency
df = 1 / (N * dt);

% double-sided MATLAB amplitude spectrum
X = fft(signal, N);
% conversion from MATLAB spectrum to Fourier spectrum
X = X/N;
% DOUBLE-SIDED ENERGY SPECTRAL DENSITY
E = abs(X).^2/(df^2);
% SINGLE-SIDED ENERGY SPECTRAL DENSITY
Ess = 2.*E(1:floor(N/2));

% ------------------------------------------------
% Step Two - Evaluation of the frequency bandwidth
% ------------------------------------------------

% Epeak is the peak value of the ESD
[Epeak,index] = max(Ess);
% peak frequency
f_peak = index * df;

% Eth is the value of the ESD corresponding to the given
% threshold
Eth = Epeak*10^(threshold/10);

% iterative algorithm for evaluating high and low
% frequencies

imax = index;
E0h = Ess(index);

while (E0h>Eth)&(imax<=(N/2))
    imax = imax + 1;
    E0h = Ess(imax);
end

f_high = (imax-1) * df;             % High Frequency

imin = index;
E0l = Ess(index);

while (E0l>Eth)&(imin>1)&(index>1)
    imin = imin - 1;
    E0l = Ess(imin);
end 

f_low = (min(index,imin)-1) * df;   % Low Frequency

% end of iterative algorithm

% Signal Frequency Bandwidth
BW = f_high - f_low;

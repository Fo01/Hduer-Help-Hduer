%
% FUNCTION 7.6 : "cp0702_Gaussian_derivatives_
%  10dB_bandwidth"
%
% Analysis of -10 dB of the first 15 derivatives of the
% Gaussian pulse as a function of the shape factor 
%
% 'smp' samples of the Gaussian pulse are considered, in
% the time interval 'Tmax - Tmin' 
%
% The function receives in input:
% 1) the minimum value of the shape factor 'alphamin'
% 2) the increase step 'alphastep'
% 3) the number of values to be investigated
%    'N_alphavalues'
%
% The function computes the Energy Spectral Densities of
% the first 15 derivatives of the Gaussian pulse for the
% 'alpha' value received in input, and then evaluates and
% plots the -10 dB bandwidth for each derivative
% 
% Programmed by tingcong ye

function cp0702_Gaussian_derivatives_10dB_bandwidth(...
   alphamin, alphastep, N_alphavalues)

% -----------------------------------------------
% Step Zero - Input parameters and Initialization
% -----------------------------------------------

smp = 4096;             % number of samples
alpha = alphamin;       % Gaussian pulse form factor
Tmin = -4e-9;           % Lower time limit
Tmax = 4e-9;            % Upper time limit
threshold = -10;        % Threshold (in dB) used to compute
                        %  the bandwidth

t=linspace(Tmin,Tmax,smp);% Inizialization of the time axis
dt = (Tmax - Tmin) / smp; % sampling period

for j=1:N_alphavalues

    factor(j)=alpha;
    
    for i=1:15

% -------------------------------------------
% Step One - Pulse waveform in the time domain
% -------------------------------------------
        derivative(i,:) =...
           cp0702_analytical_waveforms(t,i,alpha);
        derivative(i,:) = derivative(i,:) / ...
           max(abs(derivative(i,:)));

% -------------------------------------------
% Step Two - Analysis in the frequency domain and
%            evaluation of -10 dB Bandwidth
% -------------------------------------------

         [Ess,f_high,f_low,BW] = ...
            cp0702_bandwidth(derivative(i,:),dt,threshold);
        minus10dbBand(i,j)=BW;

    end
    %Increase of alpha value for the next step
    alpha = alpha + alphastep;
end

% -----------------------------
% Step Three - Graphical output
% -----------------------------

F=figure(1);
plot(factor,minus10dbBand');
axis([2e-10 12e-10 1e9 6e9]);
AX=gca;
set(AX,'FontSize',12);
X=xlabel('\alpha [s]');
set(X,'FontSize',14);
Y=ylabel('-10 dB Bandwidth [Hz]');
set(Y,'FontSize',14);
grid on
derivebehaviour = {'Increasing differentiation order'};
text(7e-10, 3e9, derivebehaviour,'BackgroundColor',...
   [1 1 1]);
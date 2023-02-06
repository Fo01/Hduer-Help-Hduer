%
% FUNCTION 7.5 : "cp0702_Gaussian_derivatives_peak
% frequency"
%
% Analysis of peak frequency of the first 15 derivatives of
% the Gaussian pulse as a function of the shape factor 
%
% 'smp' samples of the Gaussian pulse are considered, in
% the time interval 'Tmax - Tmin'.
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
% plots the peak frequency for each derivative
% 
% Programmed by tingcong ye

function cp0702_Gaussian_derivatives_peak_frequency...
   (alphamin, alphastep, N_alphavalues)

% ----------------------------
% Step Zero - Input parameters
% ----------------------------

smp = 1024;             % number of samples
alpha = alphamin;       % Gaussian pulse form factor
Tmin = -4e-9;           % Lower time limit
Tmax = 4e-9;            % Upper time limit

dt = (Tmax-Tmin) / smp; % sampling period
fs = 1/dt               % sampling frequency
N = smp;                % number of samples (i.e. size of
                        %  the FFT)
df = 1 / (N * dt);      % fundamental frequency

x=linspace(Tmin,Tmax,smp);
F=figure(1);

for j=1:N_alphavalues
    
    factor(j)=alpha;
    for i=1:15

% ----------------------------------------------
% Step One - Amplitude-normalized pulse waveform
%            in the time domain
% ----------------------------------------------

    derivative(i,:) = ...
       cp0702_analytical_waveforms(x,i,alpha);
    derivative(i,:) = derivative(i,:) / ...
       max(abs(derivative(i,:)));

% ----------------------------------------------------
% Step Two - Analysis in the frequency domain and peak
%            frequency evaluation 
% ----------------------------------------------------

        % double-sided MATLAB amplitude spectrum
        X=fft(derivative(i,:),N);
        % conversion from MATLAB spectrum to Fourier
        % spectrum
        X=X/N;
        % DOUBLE-SIDED ESD
        E = fftshift(abs(X).^2/(df^2));
        % SINGLE-SIDED ESD
        Ess = 2 * E((N/2+1):N);
        
        positivefrequency=linspace(0,(fs/2),N/2);
        
        % evaluation of the peak frequency (frequency at
        % which the ESD assumes the maximum value)
        [peak,peakelementindex]=max(Ess);
  
   peakfrequency(i,j) = ...
      positivefrequency(peakelementindex);
    end
    % Increase of alpha value for the next step
    alpha = alpha + alphastep; end

% ----------------------------------------
% Step Three - Graphical output formatting
% ----------------------------------------

PT=plot(factor,peakfrequency');
set(PT,'LineWidth',[2]);
AX=gca;
set(AX,'FontSize',12);
X=xlabel('\alpha [s]');
set(X,'FontSize',14);
Y=ylabel('Peak frequency [Hz]');
set(Y,'FontSize',14);
axis([2e-10 14e-10 0 12e9]);
derivebehaviour = {'Increasing differentiation order'}; 
text(5e-10, 6e9, derivebehaviour,'BackgroundColor',...
   [1 1 1]);
text(1.15e-9, 0.5e9, '1^{st} derivative',...
   'BackgroundColor', [1 1 1]);
text(1.15e-9, 2.4e9,'15^{th} derivative','BackgroundColor', [1 1 1]);

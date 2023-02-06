%
% FUNCTION 7.4 : "cp0702_Gaussian_derivatives_ESD"
%
% Analysis of Energy Spectral Densities of the first 15
% derivatives of the Gaussian pulse
%
% 'smp' samples of the Gaussian pulse are considered, in
% the time interval 'Tmax - Tmin' 
%
% The function receives in input the value of the shape
% factor 'alpha'
%
% The function computes and plots the Energy Spectral
% Densities of the first 15 derivatives of the Gaussian
% pulse for the 'alpha' value received in input
% 
% Programmed by tingcong ye

function cp0702_Gaussian_derivatives_ESD(alpha)

% -----------------------------------------------
% Step Zero - Input parameters and Initialization
% -----------------------------------------------

smp = 1024;           % number of samples
Tmin = -4e-9;         % Lower time limit
Tmax = 4e-9;          % Upper time limit
alpha=0.714e-9;
N = smp;              % number of samples (i.e. size of
                      %  the FFT)
dt = (Tmax-Tmin) / N; % sampling period
fs = 1/dt;            % sampling frequency
df = 1 / (N * dt);    % fundamental frequency

t=linspace(Tmin,Tmax,smp); % Inizialization of the time
                           % axis

F=figure(1);
set(F,'Position',[100 190 650 450]);

for i=1:15

% ------------------------------------------------------
% Step One - Amplitude-normalized pulse waveforms in the
%            time domain
% ------------------------------------------------------

    % Determination of the i-th derivative
    derivative(i,:)=cp0702_analytical_waveforms(t,i,alpha);
    % Amplitude normalization of the i-th derivative
    derivative(i,:)=derivative(i,:) / ...
       max(abs(derivative(i,:)));

% ----------------------------------------------------
% Step Two - Analysis in the frequency domain and data
%            plotting
% ----------------------------------------------------

    % double-sided MATLAB amplitude spectrum
    X=fft(derivative(i,:),N);
    % conversion from MATLAB spectrum to Fourier spectrum
    X=X/N;
    % DOUBLE-SIDED ESD
    E = fftshift(abs(X).^2/(df^2));
    % SINGLE-SIDED ESD
    Ess = 2 * E((N/2+1):N);
    frequency=linspace((-fs/2),(fs/2),N); 
    
    % Positive frequency axis
    positivefrequency=linspace(0,(fs/2),N/2);
    PF=semilogy(positivefrequency,Ess);
    set(PF,'LineWidth',[2]);
    hold on
end

% ----------------------------------------
% Step Three - Graphical output formatting
% ----------------------------------------

axis([0 1.25e10 1e-55 1e-15]);
AX=gca;
set(AX,'FontSize',12);
GT=title('Frequency domain');
set(GT,'FontSize',14);
X=xlabel('Frequency [Hz]');
set(X,'FontSize',14);
Y=ylabel('ESD  [(V^2)*sec/Hz]');
set(Y,'FontSize',14);
alphavalue = {'\alpha = 0.714 ns'};
derivebehaviour = {'Increasing differentiation order'}; 
text(7e9, 1e-28, derivebehaviour,'BackgroundColor',...
   [1 1 1]);
text(0.5e9, 3e-17, '1^{st} derivative',...
   'BackgroundColor', [1 1 1]);
text(4e9, 3e-17, '15^{th} derivative',...
   'BackgroundColor', [1 1 1]);
text(2e9,10e-48,alphavalue,'BackgroundColor', [1 1 1]);

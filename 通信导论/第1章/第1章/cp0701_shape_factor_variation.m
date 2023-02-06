%
% FUNCTION 7.1 : "cp0701_shape_factor_variation"
%
% Effect of shape factor variation on pulse width and
% Energy Spectral Density of the Gaussian pulse
%
% The pulse amplitude is set to 'A'
% 'smp' samples of the Gaussian pulse are considered, in
% the time interval 'Tmax - Tmin' 
%
% The function receives in input:
% 1) the minimum value of the shape factor 'alphamin'
% 2) the increase step 'alphastep'
% 3) the number of values to be investigated
%  'N_alphavalues'
%
% The function plots for each value of alpha the waveform
% and the corresponding ESD 
% 
% Programmed by tingcong ye

function cp0701_shape_factor_variation(alphamin,alphastep, N_alphavalues)

% -------------------------------------------
% Step Zero - Input parameters and Initialize
% -------------------------------------------

A = 1;                     % pulse amplitude [V]
smp = 1024;                % number of samples
Tmin = -4e-9;              % Lower time interval limit
Tmax = 4e-9;               % Upper time interval limit
alphamin=0.414e-9;
alphastep=0.1e-9;
N_alphavalues=7;
alpha = alphamin;          % Inizialization of the shape
                           %  factor
t=linspace(Tmin,Tmax,smp); % Inizialization of the time
                           %  axis

for i=1:N_alphavalues

% --------------------------------------------
% Step One - Pulse waveform in the time domain
% --------------------------------------------

    % Pulse waveform definition
    pulse=-A*exp(-2*pi*(t/alpha).^2);

% -------------------------------------------
% Step Two - Analysis in the frequency domain
% -------------------------------------------

    dt = (Tmax-Tmin) / smp;     % sampling period
    fs = 1/dt                   % sampling frequency
    N = smp;                    % number of samples (i.e.
                                %  size of the FFT)
    df = 1 / (N * dt);          % fundamental frequency

    X=fft(pulse);               % double-sided MATLAB
                                %  amplitude spectrum
    X=X/N;                      % conversion from MATLAB
                                %  spectrum to Fourier
                                %  spectrum
    E = fftshift(abs(X).^2/(df^2)); % DOUBLE-SIDED ESD
    Ess = 2*E((N/2+1):N);           % SINGLE-SIDED ESD
    
% -----------------------------
% Step Three - Graphical output
% -----------------------------

% Time Domain Representation

    figure(1);
    PT=plot(t,pulse);
    set(PT,'LineWidth',[2]);
    AX=gca;
    set(AX,'FontSize',12);
    T=title('Time domain');
    set(T,'FontSize',14);
    X=xlabel('Time [s]');
    set(X,'FontSize',14);
    Y=ylabel('Amplitude [V]');
    set(Y,'FontSize',14);
    alphabehaviour = {'Increasing \alpha'}; 
    text(0.75e-9, -0.5, alphabehaviour,...
       'BackgroundColor', [1 1 1]);
    axis([-2e-9 2e-9 -1.2 1.2]);
    hold on
    
% Frequency Domain Representation

    figure(2);
    positivefrequency=linspace(0,(fs/2),N/2);
    PF=semilogy(positivefrequency,Ess);
    set(PF,'LineWidth',[2]);
    AX=gca;
    set(AX,'FontSize',12);
    T=title('Frequency domain');
    set(T,'FontSize',14);
    X=xlabel('Frequency [Hz]');
    set(X,'FontSize',14);
    Y=ylabel('ESD  [(V^2)*sec/Hz]');
    set(Y,'FontSize',14);
    axis([0 20e9 1e-60 1e-10]);
    text(7.5e9, 1e-25, alphabehaviour,...
       'BackgroundColor', [1 1 1]);
    hold on

    alpha = alpha + alphastep;% Increase of alpha value for
                              % the next step
end
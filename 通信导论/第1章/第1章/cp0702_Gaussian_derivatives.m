%
% FUNCTION 7.2 : "cp0702_Gaussian_derivatives"
%
% Analysis of waveforms of the Gaussian pulse and its first
% 15 derivatives
%
% The pulse amplitude is set to 'A'
% 'smp' samples of the Gaussian pulse are considered, in
% the time interval 'Tmax - Tmin' 
%
% The function receives in input the value of the shape
% factor 'alpha'
%
% The function plots in a 4 by 4 grid the waveform of the
% Gaussian pulse and of its first 15 derivatives for the
% 'alpha' received in input
% 
% Programmed by tingcong ye

function cp0702_Gaussian_derivatives(alpha)

% -----------------------------------------------
% Step Zero - Input parameters and Initialization
% -----------------------------------------------

A = 1;                            % pulse amplitude [V]
smp = 1024;                       % number of samples
Tmin = -4e-9;                     % Lower time limit
Tmax = 4e-9;                      % Upper time limit

alpha=0.714e-9;
t=linspace(Tmin,Tmax,smp);        % Inizialization of the
                                  %  time axis
pulse=-A*exp(-2*pi*(t/alpha).^2); % Pulse waveform
                                  %  definition

F=figure(1);
set(F,'Position',[100 190 850 450]);
subplot(4,4,1);
PT=plot(t,pulse);
axis([-2e-9 2e-9 -1 1]);
set(gca,'XTick',0);
set(gca,'XTickLabel',{});

for i=1:15
    % Determination of the i-th derivative
    derivative(i,:) = ...
       cp0702_analytical_waveforms(t,i,alpha);

    % Amplitude normalization of the i-th derivative
    derivative(i,:) = derivative(i,:) / ...
       max(abs(derivative(i,:)));

% -----------------------------------------------
% Step One - Graphical Output
% -----------------------------------------------

    subplot(4,4,i+1);
    PT=plot(t,derivative(i,:));
    axis([-2e-9 2e-9 -1 1]);
    if(i < 12)
        set(gca,'XTick',0);
        set(gca,'XTickLabel',{});
    end
    if(mod(i,4) ~= 0)
        set(gca,'YTickLabel',{});
    end
end
h = axes('Position',[0 0 1 1],'Visible','off');
set(gcf,'CurrentAxes',h);
text(.5,0.02,'Time[s]','FontSize',12)
text(0.05,0.4,'Amplitude [V]','FontSize',12,...
   'Rotation', 90);
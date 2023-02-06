%
% FUNCTION : "the second derivative Gaussian pulse"
%
% Generates the energy normalized pulse waveform
%
% Special case of the second derivative Gaussian pulse:
% SCHOLTZ'S MONOCYCLE
%
% *********************************************************
% ref:
% Scholtz R.A. "Multiple Access with Time-Hopping Impulse
%               Modulation"  
% in Proceedings of MILCOM'93, 1993, pp. 679-691
% *********************************************************
%
% 'fc' is the sampling frequency
% 'Tm' is the pulse duration
% 'tau' is the shaping parameter
%
% Programmed by tingcong ye
%


function [w0]= cp0201_waveform(fc,Tm,tau);

% ------------------------------------
% Step One - Pulse Waveform Generation
% ------------------------------------

dt = 1 / fc;            % reference sampling period
OVER = floor(Tm/dt);    % number of samples representing
                        %  the pulse

e = mod(OVER,2);
kbk = floor(OVER/2);
tmp = linspace(dt,Tm/2,kbk);
s = (1-4.*pi.*((tmp./tau).^2)).* ...
     exp(-2.*pi.*((tmp./tau).^2));

if e                % OVER is odd
    for k=1:length(s)
        y(kbk+1)=1;
        y(kbk+1+k)=s(k);
        y(kbk+1-k)=s(k);
    end
else                % OVER is even
    for k=1:length(s)
        y(kbk+k)=s(k);
        y(kbk+1-k)=s(k);
    end
end

E = sum((y.^2).*dt);     % pulse energy
w0 = y ./ (E^0.5);       % energy normalization

%fc=10e10;
%Tm=0.9e-9;
%tau1=0.2e-9;
%tau2=0.3e-9;
%tau3=0.4e-9;
%[a1]=cp0201_waveform(fc,Tm,tau1);
%[a2]=cp0201_waveform(fc,Tm,tau2);
%[a3]=cp0201_waveform(fc,Tm,tau3);

%time=linspace(-Tm/2,Tm/2,length(a1));
%P=plot(time,a1,time,a2,time,a3);







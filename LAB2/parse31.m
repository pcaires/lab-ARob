%Editar o ficheiro mat a carregar.
clear
load sensorsD.mat
%-------------------------------------------------
dT = sensors.signal1.time(2)-sensors.signal1.time(1);
endTime = 25; %seconds
startTime = 0.1; %seconds
startPlot = round(startTime/dT);
endPlot = round(endTime/dT);

treatedTimeSeries = [sensors.signal1.time(startPlot:endPlot) sensors.signal1.data(startPlot:endPlot,:) sensors.signal2.data(startPlot:endPlot,:)  ]; 
treatedTimeSeries(:,2:4) = treatedTimeSeries(:,2:4)/100; % as acelerações estão em cm/s^2 
%Plot block
figure(31)
plot( treatedTimeSeries(:,1), treatedTimeSeries(: , 5:7) );
legend('\omega_x','\omega_y','\omega_z') 
title('Dados dos giroscópios')
xlabel('tempo(s)')
ylabel('rad/s^2')
grid on
figure(32)
plot( treatedTimeSeries(:,1), treatedTimeSeries(: , 2:4) );
legend('a_x','a_y','a_z')
title('Dados dos acelerómetros')
xlabel('tempo(s)')
ylabel('m/s^2')
%enter plot details later

%Mean of time series
MeanData1 = mean( treatedTimeSeries(:,2:7) );
CovarianceData1 = cov( treatedTimeSeries(:,2:7) );
disp(CovarianceData1);

%COV([A B C]) = [COV(A,A) COV(A,B) COV(A,C)]
%               [COV(B,A) COV(B,B) COV(B,C)]
%               [COV(C,A) COV(C,B) COV(C,C)]
% e COV(X,X) = VAR(X) 

%pitch and roll from inclinometer data
g = 9.81;%m/s^2
thetaRaw  =  (asin((treatedTimeSeries(:, 2))/g));%pitch
phiRaw = (asin((treatedTimeSeries(:, 3))./(-g*cos(thetaRaw))));%roll
phiRaw = (atan( treatedTimeSeries(:, 3)./treatedTimeSeries(:, 4)) );
%Plot block para 3.4
figure(33)
plot (treatedTimeSeries(:, 1), rad2deg(thetaRaw), treatedTimeSeries(:, 1), rad2deg(phiRaw))
legend('raw pitch (deg)','raw roll (deg)') 
%end plot block
%KALMAN
A=0;
B=1;
C=1;
D=0;

Ts = dT;
sys = ss(A, B, C, D);

Q = CovarianceData1(1,1);
R = CovarianceData1(5,5);
Q=0.008;
R=0.0017;
N = 0;
[kalmf,L,~,Mx,Z]= kalman(sys,Q,R,N);
GyrosEST = [treatedTimeSeries(:,1) treatedTimeSeries(:,6)*3.14/180];
AccelIn = [treatedTimeSeries(:,1) thetaRaw];
kalmf = kalmf(1,:);

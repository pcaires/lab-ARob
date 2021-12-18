%Editar o ficheiro mat a carregar.
clear
load sensorsD.mat
%-------------------------------------------------
dT = sensors.signal1.time(2)-sensors.signal1.time(1);
endTime = 25; %seconds
startTime = 0.1; %seconds
startPlot = round(startTime/dT);
endPlot = round(endTime/dT);
%treatedTimeSeries = [time ax ay az wx wy wz]
treatedTimeSeries = [sensors.signal1.time(startPlot:endPlot) sensors.signal1.data(startPlot:endPlot,:) sensors.signal2.data(startPlot:endPlot,:)  ]; 
treatedTimeSeries(:,2:4) = treatedTimeSeries(:,2:4)/100; % conversão das acelerações para m/s^2 
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
%disp(CovarianceData1);
%COV([A B C]) = [COV(A,A) COV(A,B) COV(A,C)]
%               [COV(B,A) COV(B,B) COV(B,C)]
%               [COV(C,A) COV(C,B) COV(C,C)]
% e COV(X,X) = VAR(X) 

%pitch and roll from inclinometer data
g = 9.81;%m/s^2
thetaRaw  = [treatedTimeSeries(:,1)  asin((treatedTimeSeries(:, 2))./g)];%pitch
%phiRaw = [treatedTimeSeries(:,1) asin((treatedTimeSeries(:, 3))./(-g*cos(thetaRaw(:,2))))];%roll
phiRaw = [treatedTimeSeries(:,1) (atan(treatedTimeSeries(:, 3)+0.6979)./treatedTimeSeries(:, 4))] ;

%Plot block para 3.4
figure(33)
plot (thetaRaw(:,1), rad2deg(thetaRaw(:,2)), phiRaw(:,1), rad2deg(phiRaw(:,2)))
legend('raw pitch (deg)','raw roll (deg)') 
%end plot block

%KALMAN
%State-space
A=[0 -1
   0 0];
B=[1
   0];
C=[1 0];

D=[0];

H=[0 0];

G=eye(2);

sys = ss(A, [B G], C, [D H]);

%Q -> inverso da credibilidade no giroscopio, R-> inverso da credibilidade no accelerómetro
%PITCH
%Qpitch = CovarianceData1(1,1);

QpitchPitch = 0.0093; %retirado da experiencia C
Qpitch = [QpitchPitch 0;
          0 20*QpitchPitch];

Rpitch=20*QpitchPitch;

[kalmfpitch,Lpitch,Ppitch]= kalman(sys,Qpitch,Rpitch);
kalmfpitch = kalmfpitch(1,:);
sizeData = size(treatedTimeSeries(:,6),1);
GyrosESTpitch= timeseries ([zeros(sizeData,1) treatedTimeSeries(:,6)*3.14/180], treatedTimeSeries(:,1));
Accelpitch = timeseries (thetaRaw, treatedTimeSeries(:,1));


%ROLL
QrollRoll = 0.0073; %retirado da experiencia C
Qroll = [QrollRoll 0;
         0 20*QrollRoll];
    
%Qroll = 0.0750;
Rroll = 20*QrollRoll;


[kalmfroll,Lroll,Proll]= kalman(sys,Qroll,Rroll);

sizeData2 = size(treatedTimeSeries(:,5),1);

GyrosESTroll= timeseries ([zeros(sizeData2,1) treatedTimeSeries(:,5)*3.14/180], treatedTimeSeries(:,1));
Accelroll = timeseries (phiRaw, treatedTimeSeries(:,1));


Qconst = 0.01;
Qtest = [Qconst 0; 
         0   Qconst];
Rtest = Qconst;
[kalmftest,Ltest,Ptest]= kalman(sys,Qtest,Rtest);
%Editar o ficheiro mat a carregar.
clear
load sensorsD.mat
%-------------------------------------------------
dT = sensors.time(2)-sensors.time(1);
endTime = 22; %seconds
startTime = 0.01; %seconds
startPlot = round(startTime/dT);
endPlot = round(endTime/dT);
%treatedTimeSeries = [time ax ay az wx wy wz]
treatedTimeSeries = [sensors.time(startPlot:endPlot) sensors.data(startPlot:endPlot,:)]; 
treatedTimeSeries(:,2:4) = treatedTimeSeries(:,2:4)/100; % conversão das acelerações para m/s^2
treatedTimeSeries(:,5:7) = deg2rad(treatedTimeSeries(:,5:7));%conversao para radianos
treatedTimeSeries(:,2) = treatedTimeSeries(:,2)+0.3253; 
treatedTimeSeries(:,3) = treatedTimeSeries(:,3);%-0.1897; 
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
thetaRaw  = [treatedTimeSeries(:,1)  asin((treatedTimeSeries(:, 2))./g)];%pitch
phiRaw = [treatedTimeSeries(:,1) asin((treatedTimeSeries(:, 3))./(-g*cos(thetaRaw(:,2))))];%roll
%phiRaw = [treatedTimeSeries(:,1) (atan(treatedTimeSeries(:, 3))./treatedTimeSeries(:, 4))];

%Plot block para 3.4
figure(33)
plot (thetaRaw(:,1), rad2deg(thetaRaw(:,2)), pitch_roll.time(startPlot:endPlot), pitch_roll.data(startPlot:endPlot,1))
legend('raw pitch (deg)','real pitch (deg)') 
figure(34)
plot (phiRaw(:,1), rad2deg(phiRaw(:,2)), pitch_roll.time(startPlot:endPlot), pitch_roll.data(startPlot:endPlot,2))
legend('raw roll (deg)','real roll (deg)') 
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

QpitchPitch = 0.0055; %retirado da experiencia C
Qpitch = [QpitchPitch 0;
          0 0.2*QpitchPitch];
Rpitch=2*QpitchPitch;

[kalmfpitch,Lpitch,P]= kalman(sys,Qpitch,Rpitch);
GyrosESTpitch= timeseries (treatedTimeSeries(:,6), treatedTimeSeries(:,1));
Accelpitch = timeseries (thetaRaw(:,2), treatedTimeSeries(:,1));

%ROLL
QrollRoll = 0.0105; %retirado da experiencia C
Qroll = [QrollRoll 0;
         0 0.2*QrollRoll];
    
Rroll = 150*QrollRoll;

[kalmfroll,Lroll,P]= kalman(sys,Qroll,Rroll);
GyrosESTroll= timeseries (treatedTimeSeries(:,5), treatedTimeSeries(:,1));
Accelroll = timeseries (phiRaw(:,2), treatedTimeSeries(:,1));


%%TEST
Qconst = 0.01;
Qtest = [Qconst 0; 
         0   0.2*Qconst];
Rtest = 2*Qconst;
[kalmftest,Ltest,Ptest]= kalman(sys,Qtest,Rtest);

out = sim('KalmanDados');

figure(41)
plot (out.phi.time, rad2deg(out.phi.data(:,1)), pitch_roll.time(startPlot:endPlot), pitch_roll.data(startPlot:endPlot,2))
legend('Estimado','Real')
title('Rolamento')
xlabel('Tempo(s)')
ylabel('\phi (deg)')

figure(42)
plot (out.theta.time, rad2deg(out.theta.data(:,1)), pitch_roll.time(startPlot:endPlot), pitch_roll.data(startPlot:endPlot,1))
legend('Estimado','Real')
title('Picada')
xlabel('Tempo(s)')
ylabel('\theta (deg)')

figure(43)
plot(out.theta.time, rad2deg(out.theta.data(:,3)))
legend('Enviesamento estimado - b_y')

figure(44)
plot(out.phi.time,rad2deg(out.phi.data(:,3)))
legend('Enviesamento estimado - b_x')
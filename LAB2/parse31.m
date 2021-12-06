%Editar o ficheiro mat a carregar.

load sensorsD.mat
dT = sensors.signal1.time(2)-sensors.signal1.time(1);
endTime = 30; %seconds
startTime = 0.1; %seconds
startPlot = round(startTime/dT);
endPlot = round(endTime/dT);

treatedTimeSeries = [sensors.signal1.time(startPlot:endPlot) sensors.signal1.data(startPlot:endPlot,:) sensors.signal2.data(startPlot:endPlot,:)  ]; 
%Plot block
figure(31)
plot( treatedTimeSeries(:,1), treatedTimeSeries(: , 2:7) );
grid on
%enter plot details later

%%Mean of time series

MeanData1 = mean( treatedTimeSeries(:,2:7) );
CovarianceData1 = cov( treatedTimeSeries(:,2:7) );
disp(CovarianceData1);




%COV([A B C]) = [COV(A,A) COV(A,B) COV(A,C)]
%               [COV(B,A) COV(B,B) COV(B,C)]
%               [COV(C,A) COV(C,B) COV(C,C)]
% e COV(X,X) = VAR(X) 

%accels
g = 981;
theta  =  (asin((treatedTimeSeries(:, 2))/g));
phi = (asin((treatedTimeSeries(:, 3))./(g*cos(theta))));
figure(2)
plot (treatedTimeSeries(:, 1), rad2deg(theta), treatedTimeSeries(:, 1), rad2deg(phi))


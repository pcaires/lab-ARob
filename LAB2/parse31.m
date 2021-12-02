%Editar o ficheiro mat a carregar.

load sensorsA.mat
dT = sensors.signal1.time(2)-sensors.signal1.time(1);
endTime = 30; %seconds
startTime = 0.1; %seconds
startPlot = round(startTime/dT);
endPlot = round(endTime/dT);

treatedTimeSeries = [sensors.signal1.time(startPlot:endPlot) sensors.signal1.data(startPlot:endPlot,:) sensors.signal2.data(startPlot:endPlot,:)  ]; 
%Plot block
figure(31)
plot( treatedTimeSeries(:,1), treatedTimeSeries(: , 2:7) );
%enter plot details later

%%Mean of time series

MeanData1 = mean( treatedTimeSeries(:,2:7) );
CovarianceData1 = cov( treatedTimeSeries(:,2:7) );
disp(CovarianceData1);

%COV([A B C]) = [COV(A,A) COV(A,B) COV(A,C)]
%               [COV(B,A) COV(B,B) COV(B,C)]
%               [COV(C,A) COV(C,B) COV(C,C)]
% e COV(X,X) = VAR(X) 
load sensorsA.mat
dT = sensors.signal1.time(2)-sensors.signal1.time(1);
endTime = 30; %seconds
startTime = 0.1; %seconds
startPlot = round(startTime/dT);
endPlot = round(endTime/dT);

treatedTimeSeries = [sensors.signal1.time(startPlot:endPlot) sensors.signal1.data(startPlot:endPlot,:)  ]; 

%Plot block
figure(31)
plot( treatedTimeSeries(:,1),treatedTimeSeries(:,2:4) );
%enter plot details later

%%Mean of time series

MeanData1 = mean(treatedTimeSeries(:,2:4));
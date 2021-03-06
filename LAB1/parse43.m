load 43.mat
targetStart = 14;
targetFinish = 19; 
start = round(targetStart/sampleTime);
finish = round(targetFinish/sampleTime);
figure(1)
hold on
plot(time,states.signals.values(:,2));
plot(time,pitchref.signals.values)
%plot(time(start:finish),states.signals.values(start:finish,2))
plot(simout.time,simout.signals.values)
title('Picada')
ylabel('\theta(rad)')
xlabel('Tempo(s)')
legend('Resposta de Picada experimental','ReferĂȘncia de Picada','Resposta de Picada H(s)','location', 'southeast')
hold off
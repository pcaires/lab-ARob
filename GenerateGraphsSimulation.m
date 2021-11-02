figure (1)
plot(tout, states.signals.values(:, 9))
title('Altitude em fun��o do tempo')
ylabel('Altitude (m)')
xlabel('Tempo (s)')
hold on

%generate a step vector
plot(stepSimout.time,stepSimout.signals.values)

hold off
legend('Resposta em Simula��o', 'Refer�ncia','location', 'southeast')
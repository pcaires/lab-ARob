figure (1)
plot(tout, states.signals.values(:, 9))
title('Altitude em função do tempo')
ylabel('Altitude (m)')
xlabel('Tempo (s)')
hold on
plot(tout, states.signals.values(:, ))

%plot(time, states4.signals.values(:, 9))
legend('Simulação')
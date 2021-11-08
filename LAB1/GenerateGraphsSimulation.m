i=1;
for i=1:4
    if i==1
        load sim1.mat
    elseif i==2
        load sim2.mat
    elseif i==3
        load sim3.mat
    elseif i==4
        load sim4.mat   
    end
    
    figure (i)
    plot(tout, states.signals.values(:, 9))
    title('Altitude em função do tempo')
    ylabel('Altitude (m)')
    xlabel('Tempo (s)')
    hold on
    plot(stepSimout.time,stepSimout.signals.values)
    hold off
    legend('Resposta em Simulação', 'Referência','location', 'southeast')   
end
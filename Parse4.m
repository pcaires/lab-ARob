fitAmplitudes = zeros(5,3);
for i=1:5
    if i==1
        load 41_1rad.mat
        targetStart = 10;
        targetFinish = 33; 
        start = round(targetStart/sampleTime);
        finish = round(targetFinish/sampleTime);            
    elseif i==2
        load 41_2rad.mat
        targetStart = 10;
        targetFinish = 30; 
        start = round(targetStart/sampleTime);
        finish = round(targetFinish/sampleTime);
    elseif i==3
        load 41_4rad.mat
        targetStart = 10;
        targetFinish = 30; 
        start = round(targetStart/sampleTime);
        finish = round(targetFinish/sampleTime);
    elseif i==4
        load 41_8rad.mat
        targetStart = 10;
        targetFinish = 22; 
        start = round(targetStart/sampleTime);
        finish = round(targetFinish/sampleTime);
    elseif i==5
        load 41_16rad.mat
        targetStart = 10;
        targetFinish = 24; 
        start = round(targetStart/sampleTime);
        finish = round(targetFinish/sampleTime);
    end
    %figures with response and pitch ref
    figure(i)
    plot(time(start:finish), states.signals.values(start:finish,2))
    title('Pitch')
    ylabel('theta(rad)')
    xlabel('Tempo(s)')
    hold on 
    plot(pitchref.time(start:finish), pitchref.signals.values(start:finish,1))      
    legend('Resposta da Pitch','Referencia de Pitch','location', 'southeast')
    hold off
    %figures with sinewave fitting of the response signal
    figure(i+10)
    fiti = fit(time(start:finish),states.signals.values(start:finish,2),'sin1');
    fitBox{i} = fiti;
    fitAmplitudes(i,:) = coeffvalues(fiti); 
    plot(fiti,time(start:finish),states.signals.values(start:finish,2))
    title('Pitch')
    ylabel('theta(rad)')
    xlabel('Tempo(s)')
    legend('Resposta da Pitch','Interpolação de seno','location', 'southeast')
       
end
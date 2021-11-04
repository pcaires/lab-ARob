i=1;

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
    
    figure (i)
    plot(time(start:finish), states.signals.values(start:finish,2))
    title('Pitch')
    ylabel('theta(rad)')
    xlabel('Tempo(s)')
    hold on
    hold off
    legend('Resposta da Pitch','location', 'southeast')   
end
fitAmplitudes = zeros(5,3);
fitBox = cell(1,4);
AmplitudeRef = [0.2; 0.2; 0.5; 1; 2];
FreqRef = [1 2 4 8 16];%rad
gain=zeros(1,5);
gainDb=gain;
s=tf('s');

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
    title('Picada - Referência e resposta')
    ylabel('\theta (rad)')
    xlabel('tempo(s)')
    hold on 
    plot(pitchref.time(start:finish), pitchref.signals.values(start:finish,1))      
    legend('Resposta de picada','Referência de picada','location', 'southeast')
    hold off
    %figures with sinewave fitting of the response signal
        
    fiti = fit(time(start:finish),states.signals.values(start:finish,2),'sin1');
    fitBox{i} = fiti;
    fitAmplitudes(i,:) = coeffvalues(fiti); 
    
    figure(i+10)
    plot(fiti,time(start:finish),states.signals.values(start:finish,2))
    title('Picada - Resposta')
    ylabel('\theta (rad)')
    xlabel('tempo(s)')
    legend('Resposta de picada','Interpolação de seno','location', 'southeast')      
end

%Gain calc

for i=1:5
    gain(i) = fitAmplitudes(i,1)/AmplitudeRef(i);
    gainDb(i) = 20*log10(gain(i));
end
figure(20)
semilogx(FreqRef,gainDb);
title('Diagrama de Bode experimental')
ylabel('gain(dB)')
xlabel('\omega rad/s')
legend('dados experimentais','location', 'southeast')

%modelfun=@(b,x)((x+b(4))./(b(1)+b(2).*x+b(3).*x.*x));
modelfun = @(b,x)(b(1).*sqrt(x.^2+b(2).^2))./(sqrt((b(3)^2-x.^2).^2+(2.*b(3).*b(4).*x).^2));
beta0=[1 ; 3 ; 3 ; 0.5];
[beta,R,J,CovB,MSE,ErrorModelInfo]=nlinfit(FreqRef,gain,modelfun,beta0);
H = beta(1)*(s+beta(2))/(s^2+2*beta(4)*beta(3)*s+beta(3)^2);
H0 = beta(1)*beta(2)/(beta(3)^2);
tau =1/(beta(4)*beta(3)); 
damp(H)
hold on
bode(H)
hold off
figure(22)
rlocus(H)
figure(23)
semilogx(FreqRef,gainDb);
title('Diagrama de Bode experimental')
ylabel('gain(dB)')
xlabel('\omega rad/s')
legend('dados experimentais','location', 'southeast')

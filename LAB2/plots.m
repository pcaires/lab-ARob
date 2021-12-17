%plot out estimations
figure(4)
plot(out.thetaDeg)
hold on
plot (thetaRaw(:,1), rad2deg(thetaRaw(:,2)))
plot (GyrosESTpitch)
legend('estimated theta','raw theta','gyro theta')
hold off

figure(5)
plot(out.phiDeg)
hold on
plot(phiRaw(:,1), rad2deg(phiRaw(:,2)))
plot(GyrosESTpitch)

legend('estimated phi','raw phi','gyro phi')
hold off

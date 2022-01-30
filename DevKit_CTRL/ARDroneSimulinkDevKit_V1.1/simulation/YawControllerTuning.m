Kyaw=1;
a=1;
A_yaw=[a 0; 
   1 0];
B_yaw=[Kyaw 0]';
q1=0.5;
q2=0.5;
Q_yaw=[q1 0;
       0 q2];
R_yaw=1;

[K_yaw, P_yaw, eigen_yaw] = lqr(A_yaw,B_yaw,Q_yaw,R_yaw);
s = tf('s');
tfYaw = (K_yaw(1)*Kyaw*s+K_yaw(2))/(s^2+(K_yaw(1)*Kyaw+a)*s+K_yaw(2)*Kyaw); 
step(tfYaw*pi/2)
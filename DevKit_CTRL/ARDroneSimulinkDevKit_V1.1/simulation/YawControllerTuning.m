Kyaw=1;
a=1;
A_yaw=[a 0; 
   1 0];
B_yaw=[Kyaw 0]';
q1=1;
q2=1;
Q_yaw=[q1 0;
       0 q2];
R_yaw=0.5;

[K_yaw, P_yaw, eigen_yaw] = lqr(A_yaw,B_yaw,Q_yaw,R_yaw);
s = tf('s');
%K_yaw =[1.8; 0.4];
%K_yaw=[0.7,0.01]
tfYaw = (K_yaw(1)*Kyaw*s+K_yaw(2))/(s^2+(K_yaw(1)*Kyaw+a)*s+K_yaw(2)*Kyaw); 
step(tfYaw*pi/2)
hold on
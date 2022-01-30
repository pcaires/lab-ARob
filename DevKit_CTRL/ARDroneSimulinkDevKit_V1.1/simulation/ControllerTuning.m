rho=0.1;
q1=0.5;
q2=1;

A_cont=[zeros(3) eye(3); 
   zeros(3) zeros(3)];

B_cont=[zeros(3); 
    eye(3)];

Q_cont=[eye(3)*q1 zeros(3);
   zeros(3) eye(3)*q2];

R_cont=eye(3)*rho;

[K_cont, P_cont, eigen_cont] = lqr(A_cont,B_cont,Q_cont,R_cont);
s = tf('s');

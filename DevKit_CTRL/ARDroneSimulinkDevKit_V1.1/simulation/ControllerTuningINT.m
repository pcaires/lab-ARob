rho1=0.1;
q1=1;
q2=1;
q3=1;
rho2=rho1;
A_cont=[zeros(3) eye(3)   zeros(3); 
        zeros(3) zeros(3) zeros(3);
        zeros(3) zeros(3) zeros(3)];

B_cont=[zeros(3) zeros(3);
        zeros(3) eye(3) ; 
        eye(3) zeros(3)];

Q_cont=[eye(3)*q1 zeros(3) zeros(3);
        zeros(3) eye(3)*q2 zeros(3);
        zeros(3) zeros(3)  eye(3)*q3];

R_cont=[eye(3)*rho1 zeros(3);
        zeros(3) eye(3)*rho2];

[K_contint, P_contint, eigen_contint] = lqr(A_cont,B_cont,Q_cont,R_cont);
s = tf('s');

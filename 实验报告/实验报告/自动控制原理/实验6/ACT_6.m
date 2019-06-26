% clear;
% A=[-2 -1 1;1 0 1;-1 0 1];
% [V,D]=eig(A)

% clear;
% A = [-2 -1 1; 1 0 1; -1 0 1];
% B = [1; 1; 1];
% P = [-1; -2; -3];
% K = acker(A,B,P)

% clear;
% A= [0 1;-3 -4]; B = [0;1];
% C = [2 0]; D = [];
% sys = ss(A,B,C,D);
% t = 0:0.001:5;
% x1 = step(sys,t);
% x2 = initial(sys,[0;1],t);
% plot(t,x1+x2);
% title('Step Response');
% xlabel('Time(seconds)');
% ylabel('Amplitude');
% grid on;

clear;
A = [0 1;-3 -4]; B = [0; 1];
C = [2 0]; D = [];
A1 = A'; B1 = C'; C1 = B';
P = [-12+1i -12-1i];
K = place(A1, B1, P);
G = K';
sys = ss(A-G*C, B, C, D);
step(sys);
grid on;


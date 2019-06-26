A = [0 1 0 0;0 0 1 0;0 0 0 1;-1 -2 -3 -4];
B = [0;0;0;1];
C = [10 2 0 0];
D = [0];
Gss = ss(A,B,C,D)
Gtf = tf(Gss)
Gzpk = zpk(Gss)
pzmap(Gzpk);
grid on;
title('Áã¼«µãÍ¼');
grid on;

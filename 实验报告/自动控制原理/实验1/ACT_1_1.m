num = [2 18 40];
den = [1 5 8 6];
Gtf = tf(num,den) %系统传函
Gzpk = zpk(Gtf) %零极点增益
pzmap(Gzpk) %绘制零极点
title('零极点图')
grid on;
Gss = ss(Gtf) %空间方程模型
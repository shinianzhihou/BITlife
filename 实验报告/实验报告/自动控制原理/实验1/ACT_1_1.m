num = [2 18 40];
den = [1 5 8 6];
Gtf = tf(num,den) %ϵͳ����
Gzpk = zpk(Gtf) %�㼫������
pzmap(Gzpk) %�����㼫��
title('�㼫��ͼ')
grid on;
Gss = ss(Gtf) %�ռ䷽��ģ��
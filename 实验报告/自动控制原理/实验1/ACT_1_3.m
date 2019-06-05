a1 = [2 6 5];
b1 = [1 4 5 2];
a2 = [1 4 1];
b2 = [1 9 8];
a3 = [1 10 21]*5;
b3 = [1 11 34 24];

Gtf1 = tf(a1,b1);
Gtf2 = tf(a2,b2);
Gtf3 = tf(a3,b3);

Gtf = Gtf1*Gtf2*Gtf3
Gzpk = zpk(Gtf)


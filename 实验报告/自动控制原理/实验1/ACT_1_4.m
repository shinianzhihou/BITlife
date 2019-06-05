clear all;
a_1 = [1];
b_1 = [1 1];
a_2_4 = [1];  %2 and 4 is same
b_2_4 = [0.5 1];
a_3 = [3];
b_3 = [1 0];

Gtf1 = tf(a_1,b_1);
Gtf2 = tf(a_2_4,b_2_4);
Gtf3 = tf(a_3,b_3);
H = tf(a_2_4,b_2_4);

Gtf = (Gtf1+Gtf2)*Gtf3;
F = feedback(Gtf,H,-1) % -1 -> negative

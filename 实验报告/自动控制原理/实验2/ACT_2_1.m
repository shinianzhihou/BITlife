clear all;
a = [80];
b = [1 2 0];
G = tf(a,b);
T = feedback(G,1,-1)
step(T);
grid on;
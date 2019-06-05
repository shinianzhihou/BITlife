clear all;
wn = [1 5 10];
sn = 0.5;
t = [0:0.05:10];
for i=1:length(wn)

	a = [wn(i)^2];
	b = [1 2*wn(i)*sn wn(i)^2];
	G = tf(a,b);
	step(G,t);
	grid on;
    hold on;
    gtext(['w{n}=' num2str(wn(i))]);
end;
hold off;
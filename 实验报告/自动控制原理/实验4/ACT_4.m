clear all;
for K = [5 20]
	G = zpk([],[0 -1 -10],10*K);
	figure;
	margin(G);
    gtext(['K = ' num2str(K)]);

end
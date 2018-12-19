clc
clear all
xn1=[0,1,2,4]; %����xn1����
xn2=[1,0,1,0,1];%����xn2����
N1=length(xn1);%��xn1�ĳ���
N2=length(xn2);%��xn2�ĳ���
N=max(N1,N2);%ȷ��N
if N1>N2
    xn2=[xn2,zeros(1,N1-N2)];%�Գ��ȶ̵����в�0
elseif N2>N1
    xn1=[xn1,zeros(1,N2-N1)];
end
yn=2*xn1+3*xn2;%����yn
n=0:N-1;
k=0:N-1;
Yk1=yn*(exp(-j*2*pi/N)).^(n'*k);%��yn��N��DFT
Xk1=xn1*(exp(-j*2*pi/N)).^(n'*k);%��xn1��N��DFT
Xk2=xn2*(exp(-j*2*pi/N)).^(n'*k);%��xn2��N��DFT
Yk2=2*Xk1+3*Xk2;%��Xk1��Xk2��Yk
subplot(2,1,1);stem(n,Yk1); %����Yk1
axis([-1,N,-12,30]);
title('Yk1');
subplot(2,1,2);stem(n,Yk2); %����Yk1
axis([-1,N,-12,30]);
title('Yk');
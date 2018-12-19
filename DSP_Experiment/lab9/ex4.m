clc
clear all;
xn1=[5,4,-3,-2];%����x1(n)����
xn2=[1,2,3,0];%����x2(n)����
N=length(xn1);
n=0:N-1;
k=0:N-1;
Xk1=xn1*(exp(-j*2*pi/N)).^(n'*k)%��x1(n)��DFT��X1(k)
Xk2=xn2*(exp(-j*2*pi/N)).^(n'*k)%��x2(n)��DFT��X2(k)
Yk=Xk1.*Xk2;%Y(k)��X1(k)X2(k)
yn=Yk*(exp(j*2*pi/N)).^(n'*k)/N;%��Y(k)��IDFT��y(n)
yn=abs(yn) %ȡģֵ������DFT������΢С����Ӱ��
subplot(2,3,1);stem(n,xn1);title('xn1');
subplot(2,3,2);stem(n,xn2);title('xn2');
subplot(2,3,3);stem(n,yn);title('yn');
subplot(2,3,4);stem(n,abs(Xk1));title('Xk1');
subplot(2,3,5);stem(n,abs(Xk2));title('Xk2');
subplot(2,3,6);stem(n,abs(Yk));title('Yk');
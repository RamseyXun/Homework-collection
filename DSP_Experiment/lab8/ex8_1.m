clc
clear all
xn=[7,6,5,4,3,2];
N=length(xn);
n=0:N-1;
k=0:N-1;
Xk=xn*exp(-j*2*pi/N).^(n'*k);%��ɢ����Ҷ�任
x=(Xk*exp(j*2*pi/N).^(n'*k))/N;%��ɢ����Ҷ��任
subplot(2,2,1),stem(n,xn);%��ʾԭ�ź�����
title('x(n)');
subplot(2,2,2),stem(n,abs(x));%��ʾ��任���
title('IDFT|X(k)|');
subplot(2,2,3),stem(k,abs(Xk));%��ʾ|X(k)|
title('|X(k)|');
subplot(2,2,4),stem(k,angle(Xk));%��ʾarg|X(k)|
title('arg|X(k)|');

clc
clear all
xn=[7,6,5,4,3,2];
N=length(xn);
n=0:3*N-1;
k=0:3*N-1;
xn1=xn(mod(n,N)+1);%mod (a, m), a is dividend,and  is divisor 
%��xn1����xn��xn��xn��xn]
Xk=xn1*exp(-j*2*pi/N).^(n'*k);%��ɢ����Ҷ�任
subplot(2,2,1),stem(xn);%��ʾ������ֵ
title('ԭ��ֵ�ź�x(n)');
subplot(2,2,2),stem(n,xn1);%��ʾ��������
title('���������ź�');
subplot(2,2,3),stem(k,abs(Xk));%��ʾ���еķ�����
title('|X(k)|');
subplot(2,2,4),stem(k,angle(Xk));%��ʾ���е���λ��
title('arg|X(k)|');

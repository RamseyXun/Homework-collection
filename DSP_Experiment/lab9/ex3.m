clc
clear all
x1=[8,7,6,5,4,3];%����x(n) N��6����
N=length(x1);n=0:N-1;
y1=x1(mod(-n,N)+1);%����x(��n)��N��6����
N2=10;
x2=[x1,zeros(1,N2-N)];%����x(n) N��10����
n2=0:N2-1;
y2=x2(mod(-n2,N2)+1);%����x(��n)��N��10����
k=0:N2-1;
Xk=x2*exp(-j*2*pi/N2).^(n2'*k)%��x(n)��DFT
Yk=y2*exp(-j*2*pi/N2).^(n2'*k)%��x(��n)��DFT
subplot(1,2,1),stem(n2,x2,'k'),title('x(n)');%��x(n)��N��10
subplot(1,2,2),stem(n2,y2,'k'),title('x(-n)');%��x(-n)��N��10

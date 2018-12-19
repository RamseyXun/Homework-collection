xn=[7,6,5,4,3,2];    
N=length(xn);     
n=0:N-1;    
w=linspace(-2*pi,2*pi,500);  %���ۣ�2p��2p��Ƶ������ָ�Ϊ500��
X=xn*exp(-j*n'*w);%��ɢʱ�丵��Ҷ�任	
subplot(3,1,1),stem(n,xn,'k');	
ylabel('x(n)');
subplot(3,1,2),plot(w,abs(X),'k');%��ʾ���еķ�����
axis([-2*pi,2*pi,1.1*min(abs(X)),1.1*max(abs(X))]);
ylabel('������');
subplot(3,1,3),plot(w,angle(X),'k');%��ʾ���е���λ��
axis([-2*pi,2*pi,1.1*min(angle(X)),1.1*max(angle(X))]);
ylabel('��λ��');

figure;         
N=100;         
xn=[7,6,5,4,3,2,zeros(1,N-6)];
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






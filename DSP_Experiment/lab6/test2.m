clc
clear all
a=[1,-1,1];
b=[1,-0.5,0];
N=32;
n=0:N-1;
hn=impz(b,a,n);%��ʱ��λ�弤��Ӧ
gn=dstep(b,a,n);%��ʱ��λ��Ծ��Ӧ
subplot(1,2,1),stem(n,hn);%��ʾ�弤��Ӧ����
title('ϵͳ�ĵ�λ�弤��Ӧ');
ylabel('h(n)');xlabel('n');
axis([0,N-1,1.1*min(hn),1.1*max(hn)]);
n=0:N-2;
subplot(1,2,2),stem(n,gn);%��ʾ��Ծ��Ӧ����
title('ϵͳ�ĵ�λ��Ծ��Ӧ');
ylabel('g(n)');xlabel('n');
axis([0,N-1,1.1*min(gn),1.1*max(gn)]);

a=[1,-1,1];
b=[1,-0.5,0];
x01=0;y01=0;N=32;
xi=filtic(b,a,0);%���Ч��ʼ��������������
n=0:N-1;    %����N���ʱ������
x1=[n==0];   %�������뵥λ�弤�ź�x1(n)
hn=filter(b,a,x1,xi);%�����뵥λ�弤�źŽ����˲�����弤��Ӧ
x2=[n>=0];%�������뵥λ��Ծ�ź�x2(n)
gn=filter(b,a,x2,xi);%�����뵥λ��Ծ�źŽ����˲������Ծ��Ӧ
figure
subplot(1,2,1),stem(n,hn);
title('ϵͳ��λ�弤��Ӧ');
ylabel('h(n)');xlabel('n');
axis([0,N-1,1.1*min(hn),1.1*max(hn)]);
subplot(1,2,2),stem(n,gn);
title('ϵͳ��λ��Ծ��Ӧ');
ylabel('g(n)');xlabel('n');
axis([0,N-1,1.1*min(gn),1.1*max(gn)]);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clc
clear all
m=[0,1,0,0,0;0.5,-8,0.5,-0.5,-1]
m=mapminmax(m)   %��һ������
a=m(1:1,1:5).*(1/m(1,1))
b=m(2:2,1:5).*(1/m(1,1))
N=32;
n=0:N-1;
hn=impz(b,a,n);%��ʱ��λ�弤��Ӧ
gn=dstep(b,a,n);%��ʱ��λ��Ծ��Ӧ
figure;
subplot(1,2,1),stem(n,hn);%��ʾ�弤��Ӧ����
title('ϵͳ�ĵ�λ�弤��Ӧ');
ylabel('h(n)');xlabel('n');
axis([0,N-1,1.1*min(hn),1.1*max(hn)]);
n=0:N-2;
subplot(1,2,2),stem(n,gn);%��ʾ��Ծ��Ӧ����
title('ϵͳ�ĵ�λ��Ծ��Ӧ');
ylabel('g(n)');xlabel('n');
axis([0,N-1,1.1*min(gn),1.1*max(gn)]);

m=[0,1,0,0,0;0.5,-8,0.5,-0.5,-1]
m=mapminmax(m)     %��һ������
a=m(1:1,1:5).*(1/m(1,1))
b=m(2:2,1:5).*(1/m(1,1))
x01=0;y01=0;N=32;
xi=filtic(b,a,0);%���Ч��ʼ��������������
n=0:N-1;    %����N���ʱ������
x1=[n==0];   %�������뵥λ�弤�ź�x1(n)
hn=filter(b,a,x1,xi);%�����뵥λ�弤�źŽ����˲�����弤��Ӧ
x2=[n>=0];%�������뵥λ��Ծ�ź�x2(n)
gn=filter(b,a,x2,xi);%�����뵥λ��Ծ�źŽ����˲������Ծ��Ӧ
figure
subplot(1,2,1),stem(n,hn);
title('ϵͳ��λ�弤��Ӧ');
ylabel('h(n)');xlabel('n');
axis([0,N-1,1.1*min(hn),1.1*max(hn)]);
subplot(1,2,2),stem(n,gn);
title('ϵͳ��λ��Ծ��Ӧ');
ylabel('g(n)');xlabel('n');
axis([0,N-1,1.1*min(gn),1.1*max(gn)]);
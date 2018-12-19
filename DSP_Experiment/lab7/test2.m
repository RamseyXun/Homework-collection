clc
clear all
a=[1,-0.602012,0.495684,0.0359244]; %����ϵͳa��bϵ��
b=[0.187632,0.241242,0.241242,0.187632];
N=20;n=0:N-1;
for i=1:4
    if i==1     %���������ź�x(n)
       x=0+[n==3];  %��[n-3]
       figure('Name','x[n]=��[n-3]');
    elseif i==2
       x=0+[n==0]+[n==1]+[n==2]+[n==3]+[n==4];%R5[n]
       figure('Name','x[n]=R5[n-3]');
    elseif i==3
       x=cos(2*pi*n/3)+sin(3*pi*n/10); 
       figure('Name','x[n]=cos(2pin/3)+sin(3pin/10)');
    elseif i==4
       x=0.6.^n.*[n>=3]; %0.6^n*u(n��3)
       figure('Name','x[n]=0.6^n*u(n��3)');
    end
    x0=zeros(1,N);%�����������ź�
    y01=[5 5];%�����ʼ����
    xi=filtic(b,a,y01);%�����ʼ״̬
    y0=filter(b,a,x0,xi);%����������Ӧ
    xi0=filtic(b,a,0);%�����ʼ״̬Ϊ������
    y1=filter(b,a,x,xi0);%����״̬��Ӧ
    y=filter(b,a,x,xi);%��ϵͳ����ȫ��Ӧ
    subplot(2,2,1),stem(n,y0);
    title('ϵͳ����������Ӧ');
    subplot(2,2,2),stem(n,y1);
    title('ϵͳ����״̬��Ӧ');
    subplot(2,2,[3 4]),stem(n,y);        
    title('��filter��ϵͳ����ȫ��Ӧy(n)');
end
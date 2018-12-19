clc
clear all
a=[1,-0.5,1,-0.5]; %����ϵͳa��bϵ��
b=[1,-1,1,0];
N=20;n=0:N-1;
for i=1:4
    if i==1     %���������ź�x(n)
       x=0+[n>=3];  %u[n-3]
       figure('Name','x[n]=u[n-3]');
    elseif i==2
       x=0+[n==0]-[n==5];%��[n]-��[n-5]
       figure('Name','x[n]=��[n]-��[n-5]');
    elseif i==3
       x=exp(0.1.*n).*[n>=3];%e^0.1n*u(n��3)
       figure('Name','e0.1^n*u(n��3)');
    else
       x=0.5.^n.*[n>=0]; %0.5^n*u(n)
       figure('Name','x[n]=0.5^n*u(n)');
    end
    subplot(3,1,1);stem(n,x);title('�����ź�')
    %��dlsim��
    y=dlsim(b,a,x);
    subplot(3,1,2);stem(n,y);title('dlsim���ϵͳ��ȫ��Ӧ')
    %��filtic��filter��
    x01=0;y01=0;%�����ʼ����
    xi=filtic(b,a,y01,x01);%�����ʼ״̬
    y=filter(b,a,x,xi); % ��ϵͳ��ȫ��Ӧ
    subplot(3,1,3);stem(n,y);title('filtic��filter���ϵͳ��ȫ��Ӧ')
end
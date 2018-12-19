clc
clear all
figure;
t=linspace(-pi,pi,500); %���ۣ�pi��pi��Ƶ������ָ�Ϊ500��
f=0.5*(1+cos(t));       %f(t)ԭ�ź�
subplot(2,1,1),plot(t,f);
ylim([1.1*min(f),1.1*max(f)]);
ylabel('f(t)');grid on;
T=2*pi;wm=2*pi/T;
N=length(t),k=0:N-1;
w1=k*wm/N;dt=t(2)-t(1);
fw=f*exp(-j*t'*w1)*dt;   %f(t)����Ҷ�任
subplot(2,1,2),plot(w1/(2*pi),abs(fw)); %����f(t)Ƶ��
axis([0,4*1/T,1.1*min(abs(fw)),1.1*max(abs(fw))]);
ylabel('Ƶ��');grid on;

for i=0:2
    figure;
    if i==0           %��������
        T=1;
    elseif i==1
        T=pi/2;
    else
        T=2;
    end
    fs=1/T;           %����Ƶ��
    n=-pi:T:pi;
    f=0.5*(1+cos(n)); %���ɳ����ź�
    subplot(2,1,1);stem(n,f,'filled');
    ylabel('�����ź�');
    axis([min(n),max(n),1.1*min(f),1.1*max(f)]);
    N=length(n),k=0:N-1;
    wm=2*pi*fs;w=k*wm/N;
    fw=f*exp(-j*n'*w)*T;   %�Գ����źŽ��и���Ҷ�任
    subplot(2,1,2),plot(w/(2*pi),abs(fw)); %����f(t)Ƶ��
    ylabel('�����ź�Ƶ��');
    axis([0,4*fs,1.1*min(abs(fw)),1.1*max(abs(fw))]);
        
end

figure;
T0=2*pi;f0=1/T0;dt=0.01;
t0=-pi:dt:pi;
f0=0.5*(1+cos(t0));
for i=0:2
    if i==0           %��������
        T=1;
    elseif i==1
        T=pi/2;
    else
        T=2;
    end
    fs=1/T;           %����Ƶ��
    n=-pi:T:pi;        %����n����
    f=0.5*(1+cos(n));  %�����ź�
    t_nT=ones(length(n),1)*t0-n'*ones(1,length(t0)); %t-nT����
    fr=f*sinc(fs*t_nT); %�ؽ����ź�
    subplot(4,2,i*2+1);plot(t0,fr);
    title('�ؽ����ź�');
    axis([-4,4,1.1*min(fr),1.1*max(fr)]);
    delta=f0-fr;        %��ԭ�źŵľ������
    subplot(4,2,i*2+2);plot(t0,abs(delta));
    title('abs(f(t)-fr(t))');
    axis([-4,4,1.1*min(abs(delta)),1.1*max(abs(delta))]);
end

clc
clear all;
fp=3500;wp=2*pi*fp;        %����ʵ���˲�����ͨ����ֹƵ��
fs=6000;ws=2*pi*fs;        %����ʵ���˲����������ֹƵ��
Rp=1;As=40;                %�����˲�����ͨ���˥��ָ��
%cheb2ord ���������б�ѩ����������˲����Ľ���n�ͽ�ֹƵ��wc
[n,wc]=cheb2ord(wp,ws,Rp,As,'s')

%����n��ģ���ͨԭ�ͣ��õ����ƽ���㼫��
[z0,p0,k0]=cheb2ap(n,As)
b0=k0*real(poly(z0));       %���һ�����˲���ϵ��b0
a0=real(poly(p0));          %���һ�����˲���ϵ��a0
[H,w0]=freqs(b0,a0);        %���һ�����˲���Ƶ������
dbH=20*log10(abs(H)+eps/max(abs(H)));%����Ϊ�ֱ�ֵ

%�任Ϊʵ��ģ���ͨ�˲���
[b1,a1]=lp2lp(b0,a0,wc);    %�ӹ�һ����ͨ�任��ʵ�ʵ�ͨ
[Ha,wa]=freqs(b1,a1);       %��ʵ�ʵ�ͨ�˲�����Ƶ������
dbHa=20*log10(abs(Ha)+eps/max(abs(Ha)));%���Ȼ�Ϊ�ֱ�ֵ

%Ϊ��ͼ׼������
wp0=fp/wc;                  %ͨ����ֹƵ�ʹ�һ��
wc0=wc/2/pi/wc;             %��ֹƵ�ʹ�һ��
ws0=fs/wc;                  %�����ֹƵ�ʹ�һ��
fc=floor(wc/2/pi);          %��ֹƵ��

%��һ��ģ���ͨԭ��Ƶ��������ͼ
subplot(2,1,1),plot(w0/(2*pi),dbH);
title('��һ��ģ��ԭ�ͷ���');ylabel('dB');
axis([0,0.5,-100,1]);grid;
set(gca,'Xtick',[0,wp0,wc0,ws0,1]);
set(gca,'Ytick',[-100,-40,-20,-1]);
subplot(2,1,2),plot(w0/(2*pi),angle(H)/(pi*180));
title('��һ��ģ��ԭ����λ');ylabel('\phi');
axis([0,0.5,-0.01,0.01]);grid;
set(gca,'Xtick',[0,wp0,wc0,ws0,1]);
set(gca,'Ytick',[-0.01,-0.005,0,0.005,0.01]);

%ʵ��ģ���ͨƵ��������ͼ
figure;
subplot(2,1,1),plot(wa/(2*pi),dbHa);grid
title('ʵ��ģ���ͨ����');ylabel('dB');xlabel('Ƶ��(Hz)');
set(gca,'Xtick',[0,fp,fc,fs,2*fs]);
set(gca,'Ytick',[-100,-40,-20,-1]);
axis([0,2*fs,-100,1]);
subplot(2,1,2),plot(wa/(2*pi),angle(Ha)/(pi*180));grid
title('ʵ��ģ���ͨ��λ');ylabel('\phi');xlabel('Ƶ��(Hz)');
set(gca,'Xtick',[0,fp,fc,fs,2*fs]);
set(gca,'Ytick',[-0.01,-0.005,-0.001,0,0.001,0.005,0.01]);
axis([0,2*fs,-0.01,0.01]);
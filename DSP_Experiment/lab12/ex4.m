clc
clear all;
fp1=3500;wp1=2*pi*fp1;%�����ͨ�˲�����ͨ����ֹƵ��
fp2=5500;wp2=2*pi*fp2;
wp=[wp1,wp2];
fs1=3000;ws1=2*pi*fs1;%�����ͨ�˲����������ֹƵ��
fs2=6000;ws2=2*pi*fs2;
ws=[ws1,ws2]
As=40;Rp=1           ;%�����˲�����ͨ���˥��ָ��
bw=wp2-wp1;w=sqrt(wp1*wp2);%��ͨ����Ⱥ�����Ƶ��
%�����˲����Ľ����ͽ�ֹƵ��
[n,wn]=ellipord(wp,ws,Rp,As,'s')
%����n��ģ���ͨԭ�ͣ��õ����ƽ���㼫��
[z0,p0,k0]=ellipap(n,Rp,As)
b0=k0*real(poly(z0));  %���һ�����˲���ϵ��b0
a0=real(poly(p0));     %���һ�����˲���ϵ��a0
[H,w0]=freqs(b0,a0);   %���һ�����˲���Ƶ������
dbH=20*log10(abs(H)+eps/max(abs(H)));%���Ȼ�Ϊ�ֱ�ֵ
%�任Ϊʵ��ģ���ͨ�˲���
[b1,a1]=lp2bp(b0,a0,w,bw);%�ӹ�һ����ͨ�任��ģ���ͨ
[Ha,wa]=freqs(b1,a1);     %��ʵ�ʴ�ͨ�˲�����Ƶ������
dbHa=20*log10(abs(Ha)+eps/max(abs(Ha)));%���Ȼ�Ϊ�ֱ�ֵ

%��һ��ģ���ͨԭ��Ƶ��������ͼ
subplot(2,2,1),plot(w0/(2*pi),dbH);grid
title('��һ��ģ��ԭ�ͷ���');ylabel('dB');
subplot(2,2,2),plot(w0/(2*pi),angle(H)/(pi*180));grid;
title('��һ��ģ��ԭ����λ');ylabel('\phi');

%ʵ��ģ���ͨƵ��������ͼ
subplot(2,2,3),plot(wa/(2*pi),dbHa);grid
title('ʵ��ģ���ͨ����');ylabel('dB');xlabel('Ƶ��(Hz)');
axis([0,15000,-150,0]);
set(gca,'Xtick',[0,fs1,fp1,fp2,fs2,2*fp1]);
set(gca,'Ytick',[-150,-100,-80,-40,-20,-1]);
subplot(2,2,4),plot(wa/(2*pi),angle(Ha)/(pi*180));grid
title('ʵ��ģ���ͨ��λ');ylabel('\phi');xlabel('Ƶ��(Hz)');

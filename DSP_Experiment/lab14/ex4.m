clc
clear all;
Fs = 10;
fp1=1;fp2=4.5;   %�˲���ͨ����ֹƵ��
wp1=2*fp1/Fs;wp2=2*fp2/Fs;
wp=[wp1,wp2];
fs1=2;fs2=3.5;   %�˲��������ֹƵ��
ws1=2*fs1/Fs;ws2=2*fs2/Fs;
ws=[ws1,ws2];
Rp=1;As=20;        %�����˲���ͨ���˥��ָ��

[n,wc]=cheb1ord(wp,ws,Rp,As)%�������n�ͽ�ֹƵ��

[b,a]=cheby1(n,Rp,wc,'stop') %ֱ�������ִ�ͨ�˲���ϵ��

[H,w]=freqz(b,a);%������ϵͳ��Ƶ������
dbH=20*log10((abs(H)+eps)/max(abs(H))); %��Ϊ�ֱ�ֵ

subplot(2,2,1),plot(w/pi,abs(H)); 
title('������Ӧ');grid;
xlabel('w(��)');ylabel('|H|');
set(gca,'Xtick',[0,wp1,ws1,ws2,wp2,1]);
subplot(2,2,2),plot(w/pi,angle(H));
title('��λ��Ӧ');grid;
xlabel('w(��)');ylabel('��');
subplot(2,2,3),plot(w/pi,dbH);
title('������Ӧ');grid;
xlabel('w(��)');ylabel('dB');
axis([0,1,-40,0]);
set(gca,'Xtick',[0,wp1,ws1,ws2,wp2,1]);
set(gca,'Ytick',[-40,-20,-1,0]);
subplot(2,2,4),zplane(b,a);grid;
title('�㼫��ͼ');grid;
xlabel('Real Part');ylabel('Imaginary Part');
��






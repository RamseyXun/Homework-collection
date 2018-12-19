clc
clear all;
Fs = 20;
fp1=3.5;fp2=6.5;   %�˲���ͨ����ֹƵ��
wp1=2*fp1/Fs;wp2=2*fp2/Fs;
wp=[wp1,wp2];
fs1=2.5;fs2=7.5;   %�˲��������ֹƵ��
ws1=2*fs1/Fs;ws2=2*fs2/Fs;
ws=[ws1,ws2];
Rp=3;As=15;        %�����˲���ͨ���˥��ָ��

[n,wc]=buttord(wp,ws,Rp,As)%�������n�ͽ�ֹƵ��

[b,a]=butter(n,wc) %ֱ�������ִ�ͨ�˲���ϵ��

[H,w]=freqz(b,a);%������ϵͳ��Ƶ������
dbH=20*log10((abs(H)+eps)/max(abs(H))); %��Ϊ�ֱ�ֵ

subplot(2,2,1),plot(w/pi,abs(H)); 
title('������Ӧ');grid;
xlabel('w(��)');ylabel('|H|');
set(gca,'Xtick',[0,ws1,wp1,wp2,ws2,1]);
subplot(2,2,2),plot(w/pi,angle(H));
title('��λ��Ӧ');grid;
xlabel('w(��)');ylabel('��');
subplot(2,2,3),plot(w/pi,dbH);
title('������Ӧ');grid;
xlabel('w(��)');ylabel('dB');
axis([0,1,-40,0]);
set(gca,'Xtick',[0,ws1,wp1,wp2,ws2,1]);
set(gca,'Ytick',[-40,-15,-3,0]);
subplot(2,2,4),zplane(b,a);grid;
title('�㼫��ͼ');grid;
xlabel('Real Part');ylabel('Imaginary Part');







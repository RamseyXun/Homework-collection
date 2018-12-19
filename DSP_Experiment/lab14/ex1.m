clc
clear all;
wp=0.2;  %�˲���ͨ����ֹƵ��
ws=0.3;   %�˲��������ֹƵ��
Rp=1;As=20; %�����˲���ͨ���˥��ָ��

[n,wc]=cheb2ord(wp,ws,Rp,As)%�������n�ͽ�ֹƵ��

[b,a]=cheby2(n,As,wc)%ֱ�������ֵ�ͨ�˲���ϵ��

[H,w]=freqz(b,a);%������ϵͳ��Ƶ������
dbH=20*log10((abs(H)+eps)/max(abs(H))); %��Ϊ�ֱ�ֵ

subplot(2,2,1),plot(w/pi,abs(H)); 
title('������Ӧ');grid;
xlabel('w(��)');ylabel('|H|');
set(gca,'Xtick',[0,wp,ws,1]);
subplot(2,2,2),plot(w/pi,angle(H));
title('��λ��Ӧ');grid;
xlabel('w(��)');ylabel('��');
subplot(2,2,3),plot(w/pi,dbH);
title('������Ӧ');grid;
xlabel('w(��)');ylabel('dB');
axis([0,1,-40,0]);
set(gca,'Xtick',[0,wp,ws,1]);
set(gca,'Ytick',[-40,-20,-1,0]);
subplot(2,2,4),zplane(b,a);grid;
title('�㼫��ͼ');grid;
xlabel('Real Part');ylabel('Imaginary Part');







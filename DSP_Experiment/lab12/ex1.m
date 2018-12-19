clc 
clear all;
fp=2000;Omgp=2*pi*fp;  %����ʵ���˲�����ͨ����ֹƵ��
fs=5000;Omgs=2*pi*fs;  %����ʵ���˲����������ֹƵ��
Rp=1;As=20;            %�����˲�����ͨ���˥��ָ��
%buttord �������������˹�����˲����Ľ���n��3 dB��ֹƵ��Omgc
[n,Omgc]=buttord(Omgp,Omgs,Rp,As,'s')

%����n��ģ���ͨԭ�ͣ��õ����ƽ���㼫��
% buttap���ڼ���N�װ�����˹��һ����3dB��ֹƵ�ʦ�c=1��
% ģ���ͨԭ���˲���ϵͳ�������㡢������������ӡ�
[z0,p0,k0] = buttap(n);
b0 = k0*real(poly(z0))  %���һ�����˲���ϵ��b0
a0 = real(poly(p0))     %���һ�����˲���ϵ��a0
[H,Omg0]=freqs(b0,a0);  %���һ�����˲���Ƶ������
dbH = 20*log10((abs(H)+eps)/max(abs(H))); %���Ȼ�Ϊ�ֱ�ֵ

%�任Ϊʵ��ģ���ͨ�˲���
[ba,aa]=lp2lp(b0,a0,Omgc);%�ӹ�һ����ͨ�任��ʵ�ʵ�ͨ
[Ha,Omga]=freqs(ba,aa);%��ʵ��ϵͳ��Ƶ������
dbHa=20*log10((abs(Ha)+eps)/max(abs(Ha))); %���Ȼ�Ϊ�ֱ�ֵ

%Ϊ��ͼ׼������
Omg0p=fp/Omgc;%ͨ����ֹƵ�ʹ�һ��
Omg0c=Omgc/2/pi/Omgc;%3 dB��ֹƵ�ʹ�һ��
Omg0s=fs/Omgc;%�����ֹƵ�ʹ�һ��
fc=floor(Omgc/2/pi);%3 dB��ֹƵ��

%��һ��ģ���ͨԭ��Ƶ��������ͼ
subplot(2,1,1),plot(Omg0/2/pi,dbH);
axis([0,1,-50,1]);title('��һ��ģ���ͨԭ�ͷ���');
ylabel('dB');
set(gca,'Xtick',[0,Omg0p,Omg0c,Omg0s,1]);
set(gca,'Ytick',[-50,-20,-3,-1]);grid
subplot(2,1,2),plot(Omg0/2/pi,angle(H)/pi*180);
axis([0,1,-200,200]);title('��һ��ģ���ͨԭ����λ');
ylabel('��phi');
set(gca,'Xtick',[0,Omg0p,Omg0c,Omg0s,1]);
set(gca,'Ytick',[-180,-120,0,90,180]);grid 

%ʵ��ģ���ͨƵ��������ͼ
figure;
subplot(2,1,1),plot(Omga/2/pi,dbHa);
axis([0,2*fs,-50,1]);title('ʵ��ģ���ͨ����');
ylabel(' dB');xlabel('Ƶ��(Hz)');
set(gca,'Xtick',[0,fp,fc,fs,2*fs]);
set(gca,'Ytick',[-50,-20,-3,-1]);grid
subplot(2,1,2),plot(Omga/2/pi,angle(Ha)/pi*180);
axis([0,2*fs,-200,200]);title('ʵ��ģ���ͨ��λ');
set(gca,'Xtick',[0,fp,fc,fs,2*fs]);
set(gca,'Ytick',[-180,-120,0,90,180]);grid 
ylabel('��phi');xlabel('Ƶ��(Hz)');
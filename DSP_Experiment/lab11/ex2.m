clc
clear;
num=[2,3,0];%����ϵ������
den=[1,0.4,1];%��ĸϵ������
[z,p,k] = tf2zp(num, den)%ʹ��tf2zp����-��������ģ��
[sos,g] = tf2sos(num, den)%ʹ��tf2sos����η�ʽģ��
[r,p,k] = residuez(num, den)%ʹ��residuez�󼫵�����(rpk)ģ��
[A,B,C,D] = tf2ss(num,den)%ʹ��tf2ss(num,den)��״̬����ģ��
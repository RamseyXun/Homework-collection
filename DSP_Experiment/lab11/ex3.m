clc
clear all;
%�ȸ�����-����ģ�͵�ϵͳ����д��z,p,k
z=[1,-3,5]';  
p=[2,4,-6]';
k=3;
[num,den]=zp2tf(z,p,k)%ʹ��zp2tf��tfģ��
[sos,g]=zp2sos(z,p,k)%ʹ��zp2sos��sosģ��
[r,p,k] = residuez(num,den)%��ͨ��֮ǰ�����tfģ��ʹ��residuez�󼫵�����(rpk)ģ��
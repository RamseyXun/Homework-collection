#ifndef BIGNUM_H_
#define BIGNUM_H_
#include"myheader.h"
class Bignum{
    public:
        Bignum();
		Bignum(int n);//����ת�� 
    	Bignum(string str);//�ַ���ת�� 
    	friend string transform(const Bignum &y); 
    	bool operator <= (const Bignum & y);//�Ƚ��Ƿ��yС 
    	bool operator == (const Bignum & y);//�Ƚ��Ƿ��y��� 
    	Bignum operator + (const Bignum & y);//�߾���+ 
    	Bignum operator - (const Bignum & y);//�߾���- 
    	Bignum operator / (const int & y);//�߾�/����
    	Bignum operator * (const Bignum & y);//�߾�*�߾� 
    	Bignum operator / (Bignum & y);//�߾�/�߾�
    	friend Bignum calc(Bignum r1,char ch,Bignum r2);//������������ch���� 
    	void Print();//��������� 	
    private:
        const static int Maxn=1100,exp=10,remain=5;//expΪ����10λ��remain�Ǳ���5λС�� 
   	    int v[Maxn],flag;//flag=0,������flag=1���� 
};
#endif 
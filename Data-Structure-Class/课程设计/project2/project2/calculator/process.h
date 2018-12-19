#ifndef PROCESS_H_
#define PROCESS_H_
#include"bignum.h"
#include"mystack.cpp"
#include"myheader.h"
class process{
	public:
		void Introduce();//���� 
		void start();//��ʼ���� 
		int check();//�����ʽ�Ƿ�Ϸ� 
		void work();//��ʼ���� 
		void deletenum();
		void printstack(int step);
	private:
		char s[1010];
		int len,st;
		Bignum zero;
		Mystack<Bignum>q1;//����ջ 
		Mystack<char>q2;//������ջ
		string  operators;//������ջ������
		string  operand;//����ջ������ 
		map<char,int>f;
};
#endif
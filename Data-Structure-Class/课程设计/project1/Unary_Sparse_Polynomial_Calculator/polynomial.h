#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
class polynomial{
	public:	
		polynomial();
		friend polynomial* creatpolyn(int n);// ��������ʽ 
		friend void del(polynomial *p);//ɾ������ʽ 
		friend void insert(polynomial *p,polynomial *head); //����һ���㵽һ������ʽ��  
		friend int compare(polynomial *a,polynomial *b); //�Ƚ�ĳ���� 
		friend polynomial* add(polynomial *a,polynomial *b);//�ӷ� 
		friend polynomial* sub(polynomial *a,polynomial *b);//���� 
		friend polynomial* mul(polynomial *a,polynomial *b);//�˷� 
		friend polynomial* derivative(polynomial *p);//�� 
		friend float value(polynomial *head,float x);//��ֵ 
		friend void print(polynomial *p);//��� 
	private:
		float coef;//ϵ��
 		int exp;//ָ��	
	    polynomial *next;
};
#endif
#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_
class polynomial {
public:
	polynomial();
	friend void del(polynomial *p);//ɾ������ʽ 
	friend void insert(polynomial *p, polynomial *head); //����һ���㵽һ������ʽ��  
	friend polynomial* derivative(polynomial *p);//�� 
	friend void print(polynomial *p);//��� 
	float coef;//ϵ��
	int exp;//ָ��	
	char v;
	polynomial *next;
};
#endif
#include"poly.h"
#include<cstdio>
#include<iostream> 
using namespace std;
polynomial::polynomial() {
	next = NULL;
	coef = 0.0;
	exp = 0;
}
void del(polynomial *p) {//ɾ������ʽ 
	polynomial *p1, *p2;
	p1 = p->next; p2 = p1->next;
	while (p1->next) {
		delete p1;
		p1 = p2;
		p2 = p2->next;
	}
	p = NULL;
}
void insert(polynomial *p, polynomial *head) {  //����һ���㵽һ������ʽ��   
	if (p->coef == 0) delete p;   //ϵ��Ϊ0��ɾ���˽�� 
	else {
		polynomial *last = head, *now = head->next;
		//nowָ��ǰ��㣬lastָ����һ����� 
		while (now&&p->exp<now->exp) {//����ָ���Ӵ�С��˳����Ҳ���λ��   
			last = now;
			now = now->next;
		}
		if (now&&p->exp == now->exp) {//�ϲ�ָ����ͬ�� 
			now->coef += p->coef;
			delete p;
			if (!now->coef) {//ϵ��Ϊ0ɾ���˽��             
				last->next = now->next;
				delete now;
			}
		}
		else {  //��һ�γ��ֵ�ָ���Ľ�� 
			p->next = now;
			last->next = p;
		}
	}
}
polynomial* derivative(polynomial *p) {//�� 
	polynomial *h = p->next, *node, *ans_head;
	ans_head = new polynomial;
	ans_head->next = NULL;
	for (; h; h = h->next) {
		node = new polynomial;
		node->coef = (h->coef)*(h->exp);
		node->exp = (h->exp) - 1;
		node->v = h->v;
		insert(node, ans_head);
	}
	return ans_head;
}
void print(polynomial* p) { //�������ʽ 
	polynomial* head = p->next;
	int cnt = 1;
	if (!head) {//������ʽΪ�գ����0
		cout << "0" << "\n";
		return;
	}
	while (head) {
		if (head->coef>0 && cnt != 1) putchar('+'); //�����������ϵ����ǰ��+�� 
		if (head->coef != 1 && head->coef != -1) {//ϵ����1��-1
			cout << head->coef;
			if (head->exp)cout << head->v; //ָ����Ϊ0�����x 
			if (head->exp != 0 && head->exp != 1)cout << "^" << head->exp;//ָ����Ϊ0�Ҳ�Ϊ1�����ָ�� 
		}
		else {
			if (head->coef == 1 || head->coef == -1) {
				if (!head->exp)cout << 1 * head->coef;//ָ��Ϊ0 
				else {
					if (head->coef == -1)cout << "-";//ϵ��Ϊ-1ֻ���- 
					if (head->exp)cout <<head->v; //ָ����Ϊ0�����x 
					if (head->exp != 0 && head->exp != 1)cout << "^" << head->exp;//ָ����Ϊ0�Ҳ�Ϊ1�����ָ�� 
				}
			}
		}
		head = head->next;
		cnt++;
	}
}
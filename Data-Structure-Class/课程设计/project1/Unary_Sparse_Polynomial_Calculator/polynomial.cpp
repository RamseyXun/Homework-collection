#include"polynomial.h"
#include<cstdio>
#include<iostream> 
using namespace std;
polynomial::polynomial(){
	next=NULL;
	coef=0.0;
	exp=0;
}
polynomial* creatpolyn(int	n){// ��������ʽ 
	polynomial *p,*head;
	head=new polynomial;
	head->next=NULL;
	if(n)cout<<"������ÿһ���ϵ����ָ��������֮���ÿո����(��3x+4x^2 �� ���� 3 1 4 2)��"<<endl; 
	for(int i=1;i<=n;i++){
		p=new polynomial;
		cin>>p->coef>>p->exp;
		insert(p,head);//������p 
	}
	return head;
}
void del(polynomial *p){//ɾ������ʽ 
	polynomial *p1,*p2;
	p1=p->next;p2=p1->next;
	while(p1->next){
		delete p1; 
		p1=p2;
		p2=p2->next;
	}
	p=NULL;
}
void insert(polynomial *p,polynomial *head){  //����һ���㵽һ������ʽ��   
	if(p->coef==0) delete p;   //ϵ��Ϊ0��ɾ���˽�� 
	else{
		polynomial *last=head,*now=head->next;
		//nowָ��ǰ��㣬lastָ����һ����� 
		while(now&&p->exp<now->exp){//����ָ���Ӵ�С��˳����Ҳ���λ��   
			last=now;
			now=now->next;
		}
		if(now&&p->exp==now->exp){//�ϲ�ָ����ͬ�� 
			now->coef+=p->coef;
			delete p;
			if(!now->coef){//ϵ��Ϊ0ɾ���˽��             
				last->next=now->next;
				delete now;
			}
		}
		else{  //��һ�γ��ֵ�ָ���Ľ�� 
			p->next=now;
			last->next=p;
		}
	}
}
int compare(polynomial *a,polynomial *b){//�Ƚ������� 
	if(a&&b){
		if(a->exp>b->exp)return 1;//a>b
		else if(a->exp<b->exp) return -1;//a<b 
		else return 0;//a=b
	}
	else if(!a&&b) return -1;//a�գ�b�ǿ�
	else return 1;//b�գ�a�ǿ�
}
polynomial* add(polynomial *a,polynomial *b){//�����ʽa+b 
	polynomial *p1=a->next,*p2=b->next;
	polynomial *ans_head,*h,*node;
	ans_head=new polynomial;
	ans_head->next=NULL;
	h=ans_head;
	while(p1||p2){
		node=new polynomial;
		int result_=compare(p1,p2);
		if(result_==-1){//��ǰp2��ָ������ 
			node->coef=p2->coef;
			node->exp=p2->exp;
			p2=p2->next;
		}
		else if (!result_){//p1��p2ָ��һ�� 
			node->coef=p1->coef+p2->coef;
			node->exp=p1->exp;
			p1=p1->next;
			p2=p2->next;
		
		}
		else if (result_==1){//��ǰp1��ָ������ 
			node->coef=p1->coef;
			node->exp=p1->exp;
			p1=p1->next;
		
		}
		if(node->coef!=0){
			node->next=node->next;
			h->next=node;
			h=node;
		}
		else delete node;//�����ϵ��Ϊ0ʱ��ɾ����� 
	}
	return ans_head;
}
polynomial* sub(polynomial *a,polynomial *b){//�����ʽa-b 
	polynomial* h=b,*p=b->next,*ans_head;
	for(;p;p=p->next)p->coef*=-1; //������ת���ɼӷ�ִ�� 
	ans_head=add(a,h);
	for(p=h->next;p;p=p->next)p->coef*=-1;    //�ָ�pb��ϵ��
	return ans_head;
}
polynomial* mul(polynomial *a,polynomial *b){//�����ʽa*b 
	polynomial *p1=a->next,*p2=b->next;
	polynomial *ans_head,*node,*h;
	ans_head=new polynomial;
	ans_head->next=NULL;
	for (;p1;p1=p1->next){//������� 
		h=p2;
		for (;h;h=h->next){
			node=new polynomial;
			node->coef=p1->coef*h->coef;
			node->exp=p1->exp+h->exp;
			insert(node,ans_head);
		}
	}
	return ans_head;
	 
}
polynomial* derivative(polynomial *p){//�� 
	polynomial *h=p->next,*node,*ans_head;
	ans_head=new polynomial;
	ans_head->next=NULL;
	for (;h;h=h->next){
		node=new polynomial;
		node->coef=(h->coef)*(h->exp);
		node->exp=(h->exp)-1;
		insert(node,ans_head);
	}
	return ans_head;
}
float value(polynomial *head,float x){//����ʽ��x����ֵ 
	polynomial *p;
	float sum=0,t;
	for(p=head->next;p;p=p->next){
		t=1;
		for(int i=p->exp;i!=0;){
			if(i<0){//ָ��С��0�����г���
				t/=x;
				i++;
			}
			else{//ָ������0�����г˷�
				t*=x;
				i--;
			}
		}
		sum+=p->coef*t;
	}
	return sum;
}
void print(polynomial* p){ //�������ʽ 
	polynomial* head=p->next; 
	int cnt=1;
	if(!head){//������ʽΪ�գ����0
		cout<<"0"<<"\n";
		return;
	}   
	while (head){
		if(head->coef>0&&cnt!=1) putchar('+'); //�����������ϵ����ǰ��+�� 
		if(head->coef!=1&&head->coef!=-1){//ϵ����1��-1
			cout<<head->coef;
			if (head->exp)cout<<"X"; //ָ����Ϊ0�����x 
			if(head->exp!=0&&head->exp!=1)cout<<"^"<<head->exp;//ָ����Ϊ0�Ҳ�Ϊ1�����ָ�� 
		}
		else{
			if(head->coef==1||head->coef==-1){
				if(!head->exp)cout<<1*head->coef;//ָ��Ϊ0 
				else {
					if (head->coef==-1)cout<<"-";//ϵ��Ϊ-1ֻ���- 
					if(head->exp)cout<<"X"; //ָ����Ϊ0�����x 
					if(head->exp!=0&&head->exp!=1)cout<<"^"<<head->exp;//ָ����Ϊ0�Ҳ�Ϊ1�����ָ�� 
				}
			}
		}
		head=head->next; 
		cnt++;
	}
}
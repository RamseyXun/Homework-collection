#include<iostream>
#include<cmath>
#include"Expression.h"
#include"poly.h"
using namespace std;
//----------------------���ڵ����Ա����
TreeNode::TreeNode(char _data,TreeNode* _left,TreeNode* _right){
         Data=_data;
         left=_left;
         right=_right;
}
TreeNode::~TreeNode(){}
void TreeNode::SetData(char _data){Data=_data;}//���øý���ֵ
char TreeNode::GetData(){return Data;}//��ȡ�ý���ֵ 
void TreeNode::SetLeft(TreeNode* _left){left=_left;}//�������� 
void TreeNode::SetRight(TreeNode* _right){right=_right;}//�����Һ��� 
TreeNode*TreeNode::GetLeft(){return left;}//��ȡ���� 
TreeNode*TreeNode::GetRight(){return right;}//��ȡ�к��� 

//---------------------------- �������������ʽ���Ա����

Tree::Tree(){
	root=NULL;
	Expr_i=len=0;
}

Tree::~Tree(){}

void Tree::Release(){
	if(root!=NULL){
 		DeleteTree(root);  //ɾ��һ�������ͷŸ����ĵĿռ� 
   		delete(root);
     	root=NULL;
   	}
}

void Tree::DeleteTree(TreeNode* &p){//ɾ����PΪ���ڵ���� 
	if(p->GetLeft()!=NULL){//ɾ�������� 
 		TreeNode* p1;
		p1=p->GetLeft();
		DeleteTree(p1);
		delete(p1);
	}
	else if(p->GetRight()!=NULL){//ɾ�������� 
		TreeNode*p2;
		p2=p->GetRight();
		DeleteTree(p2);
		delete(p2);
	}
	p=NULL;
}

TreeNode*  Tree::GetRoot(){return root;}

void Tree::ReadExpr(char* E){//�ñ��ʽE���� 
	if(root!=NULL) {Release();root=NULL;}
	Expr_i=0;
	len=strlen(E);
  	if(len==0) return ;
    ReadExprRecursion(root,E);//���õݹ麯������ 
}

void Tree::ReadExprRecursion(TreeNode* &p,char* E){//�ݹ齨�� 
	if(Expr_i==len)return ;
 	p=(TreeNode*)new TreeNode(E[Expr_i++],NULL,NULL);
  	char temp=p->GetData();
   	if(!IsOperator(temp)){
	   
	   return ;//����������򷵻أ���ΪҶ�ӽ��һ�������ֻ��߱��� 	
    }
	else{
    	TreeNode* q1,* q2;//������ҽ��� 
     	ReadExprRecursion(q1,E); 
      	p->SetLeft(q1);
		ReadExprRecursion(q2,E);
		p->SetRight(q2);
	}
}

void Tree::WriteExpr(char* E){//�õ���׺���ʽ 
         if(root==NULL) {E[0]='\0';return ;}
         WriteExprRecursion(root,E);//�õݹ麯��������������׺���ʽ�浽E�� 
}

void Tree::WriteExprRecursion(TreeNode* p,char* E){//�õݹ麯��������������׺���ʽ�浽E�� 
	char c1,c2,c3[100],c4[100];
	int i;
 	if(p->GetLeft()==NULL ||p->GetRight()==NULL){//Ҷ�ӽ�㣬��ǰ�����ֻ���δ֪�� 
		E[0]=p->GetData();
		E[1]='\0';
 		return ;
   	}
    c1=p->GetLeft()->GetData();
	c2=p->GetRight()->GetData();
	if(!IsOperator(c1) &&!IsOperator(c2)){//���Ӻ��Һ��Ӷ���Ҷ��� 
		E[0]=c1;
		E[1]=p->GetData();
		E[2]=c2;
		E[3]='\0';
  	}
   	else if(IsOperator(c1) &&!IsOperator(c2)){//��������������Һ��������� 
    	WriteExprRecursion(p->GetLeft(),c3);//�������Ҫ�õ����������ʽ 
		if(Priority(p->GetData(),p->GetLeft()->GetData())>0){
		/*��ǰ������������ȼ������������һ���������������ȼ��ߣ�ǰ���ʽ��Ҫ������ 
		        *                         (3+4)*2
		      |    |
			  +    2
			 | | 
			 3 4           */
  			E[0]='(';
			for(i=0;i<(int)strlen(c3);i++) E[i+1]=c3[i];
			E[i+1]=')';
			E[i+2]=p->GetData();
			E[i+3]=p->GetRight()->GetData();
			E[i+4]='\0';
		}
		else{
			/*���ȼ�С�ڵ�����ǰ�治�ü�����*/ 
			for(i=0;i<(int)strlen(c3);i++) E[i]=c3[i];
			E[i]=p->GetData();
			E[i+1]=p->GetRight()->GetData();
			E[i+2]='\0';
		}
	}
	else if(!IsOperator(c1) &&IsOperator(c2)){//�����������Һ���������� 
		WriteExprRecursion(p->GetRight(),c3);
		if( Priority(p->GetData(),p->GetRight()->GetData())>0 || p->GetData()=='-'&& (p->GetRight()->GetData()=='+'|| p->GetRight()->GetData() == '-')){
			/*��ǰ������������ȼ������������һ���������������ȼ��ߣ������ʽ��Ҫ������,����Ҫ���� 
		        *                         2*(3+4)
		      |    |
			  2    +    
			      | | 
			      3 4           */
			E[0]=p->GetLeft()->GetData();
			E[1]=p->GetData();
			E[2]='(';
			for(i=0;i<(int)strlen(c3);i++) E[i+3]=c3[i];
			E[i+3]=')';
			E[i+4]='\0';
		}
		else {
			/*���ȼ�С�ڵ�������治�ü�����*/ 
			E[0]=p->GetLeft()->GetData();
			E[1]=p->GetData();
			for(i=0;i<(int)strlen(c3);i++) E[i+2]=c3[i];
			E[i+2]='\0';
		}
	}
	else{//���Ӻ��Һ��Ӷ�����������ֱ�ݹ鴦�����������ٺϲ� �ϲ�������ǰ������ 
			WriteExprRecursion(p->GetLeft(),c3);
			WriteExprRecursion(p->GetRight(),c4);
			if (Priority(p->GetData(), p->GetLeft()->GetData())>0) {
				E[0]='(';
				for(i=0;i<(int)strlen(c3);i++) E[i+1]=c3[i];
				E[i+1]=')';
				E[i+2]='\0';
			}
			else {
				for(i=0;i<(int)strlen(c3);i++) E[i]=c3[i];
				E[i]='\0';
			}
			int j=strlen(E);
			E[j]=p->GetData();
			if (Priority(p->GetData(), p->GetRight()->GetData())>0 || p->GetData() == '-' && (p->GetRight()->GetData() == '+' || p->GetRight()->GetData() == '-')) {
				E[j+1]='(';
				for(i=0;i<(int)strlen(c4);i++)E[j+2+i]=c4[i];
				E[j+2+i]=')';
				E[j+3+i]='\0';
			}
			else{
				for(i=0;i<(int)strlen(c4);i++) E[j+1+i]=c4[i];
				E[j+1+i]='\0';
			}
	}
}
int Tree::Priority(char c1,char c2){
//���ȼ��жϺ���
	switch(c1){
		case '+':
		case '-':
			return -1;
		case '*':
			switch(c2){
				case '+':
    			case '-':
					return 1;
			}
			return -1;
   		case '/':
			switch(c2){
   				case '+':
       			case '-':
  				return 1;
			}
			return -1;
		case '^':
			return 1;
	}
	return 0;
}

bool Tree::IsOperator(char c){//�ж��Ƿ�������� 
	return !(c>=97 && c<=122|| c>=48 && c<=57);
}
bool Tree::IsNumber(char c){//�ж��Ƿ������� 
	return (c>=48 && c<=57);
}
void Tree::Assign(char v,int c){//��c��ֵ��V 
	AssignRecursion(root,v,c);//�ݹ鸳ֵ 
}

void Tree::AssignRecursion(TreeNode* p,char v,int c){//�ݹ鸳ֵ���� 
	if(p!=NULL){
		if(p->GetData()==v)p->SetData(c+48);
		AssignRecursion(p->GetLeft(),v,c);
		AssignRecursion(p->GetRight(),v,c);
	}
}

Tree* Tree::CompoundExpr(char p,char* E1,char* E2){//���츴�ϱ��ʽ
	Tree BTAE1,BTAE2,*BTAE3;
	BTAE1.ReadExpr(E1);
	BTAE2.ReadExpr(E2);
	TreeNode* q=(TreeNode*)new TreeNode(p,NULL,NULL);//pΪ���ڵ㣬������ΪE1��������ΪE2 
	q->SetLeft(BTAE1.GetRoot());
	q->SetRight(BTAE2.GetRoot());
	BTAE3=(Tree*)new Tree;
	BTAE3->SetRoot(q);
	return BTAE3;
}
void Tree::MergeConst(char* E){//�ϲ�������
	  int i,j,k;
	  int flag=1;
	  while (flag){
	  	flag=0;
	  	for (i=0;i<(int)strlen(E);i++)
	  		if (E[i]=='^')Conbination(E,i);	   
		for (i = 0; i<(int)strlen(E); i++)
	  		if (E[i]=='*'||E[i]=='/')Conbination(E,i);
		for (i = 0; i<(int)strlen(E); i++)
	  		if (E[i]=='-')Conbination(E,i);
		for (i = 0; i<(int)strlen(E); i++)
			if (E[i] == '+')Conbination(E, i);
		for (i = 0; i<(int)strlen(E); i++)
  			if (E[i]=='('){
  				j=i+1;
  				while (j<(int)strlen(E)&&E[j]>='0'&&E[j]<='9')j++;
  				if (j<(int)strlen(E)&&E[j]==')'){
				  	  flag=1;
				  	  for (k=i;k<j;k++)
						E[k]=E[k+1];
				  	  for (k=j-1;k+1<(int)strlen(E);k++)
						E[k]=E[k+2];
				  	  k=(int)strlen(E);
				  	  E[k]='\0';
				  }
  			}
	  }
}
void Tree::Conbination(char *E,int idx){
	if (!IsNumber(E[idx-1]) || !IsNumber(E[idx+1]))return;
	int i=idx-1,j=idx+1,k,len=(int)strlen(E);
	while (i-1>=0&& IsNumber(E[i-1]))i--;
	while (j+1<len&& IsNumber(E[j+1]))j++;
	if (i - 1 >= 0 && IsOperator(E[i - 1]) && Priority(E[i - 1], E[idx]) > 0)return;
	if (j + 1 <strlen(E) && IsOperator(E[j + 1]) && Priority(E[j + 1], E[idx]) > 0)return;
	int num1=0,num2=0,num3,num4=0;
	for (k=i;k<idx;k++)num1=num1*10+(E[k]-'0');
	for (k=idx+1;k<=j;k++)num2=num2*10+(E[k]-'0');
	if (i-1>=0&&E[i-1]=='-'){
		if (E[idx]=='+')E[idx]='-';
		else if (E[idx]=='-')E[idx]='+';
	}
	num3=Calculate(num1,E[idx],num2);
	while (num3){
		num4=num4*10+num3%10;
		num3/=10; 
	}
	k=i;
	while (num4){
		int x=num4%10;
		num4/=10;
		E[k++]=char (x+48);
	}
	for (i=j+1;i<len;i++)E[k++]=E[i];
	E[k]='\0';
}
void Tree::Diff(char * E, char V){
	MergeConst(E);
	int flag = 1;
	polynomial *head,*p;
	head = new polynomial;
	head->next = NULL;
	head->v = V;
	for (int idx = 0; idx < (int)strlen(E); idx++)
		if (E[idx] == V) {
			p = new polynomial;
			p->v = V;
			p-> coef = 1.0;
			p->exp = 1;
			int i = idx - 1;
			int j;
			if (i >= 0) {
				if (E[i] == '-')p->coef = -1.0;
				else if (E[i]=='*'&&i-1>=0&&IsNumber(E[i-1])){
					i--;
					p->coef = 0.0;
					p->coef = p->coef * 10.0 + (float)(E[i] - '0');
					while (i - 1 >= 0 && IsNumber(E[i - 1])) {
						i--;
						p->coef = p->coef * 10.0 + (float)(E[i]-'0');
						
					}
					if (i - 1 >= 0 && E[i-1] == '-')p->coef *= -1.0;
				}
			}
			i = idx + 1;
			if (E[i] != '^')p->exp = 1;
			else {
				p->exp = 0;
				for (j = i; j + 1 < (int)strlen(E) && IsNumber(E[j + 1]); j++);
				for (i = idx + 2; i <= j; i++) p->exp = p->exp * 10 + (int)(E[i] - '0');
			}
			insert(p, head);
		}
	head = derivative(head);
	cout << "��ƫ����"; print(head); cout << endl;
	del(head);
}


void Tree::SetRoot(TreeNode* _root){//���ø��ڵ� 
	root=_root;
}

int Tree::Value(char* E){//���ʽ��ֵ
	Tree tree;
 	tree.ReadExpr(E);
  	return tree.ValueRecursion(tree.GetRoot());//���õݹ麯����ֵ 
}

int Tree::ValueRecursion(TreeNode* p){//�ݹ���ֵ���� 
    char c1,c2;
    int temp1,temp2;
    if(p->GetLeft()==NULL ||p->GetRight()==NULL){//��ǰΪҶ�ӽ�� 
		c1=p->GetData();
		return (c1>=97 &&c1<=122)?0:c1-48;
  	}
	c1=p->GetLeft()->GetData();
	c2=p->GetRight()->GetData();
	if(!IsOperator(c1) &&!IsOperator(c2)){//���Һ�����Ҷ�ӽڵ� 
		if(c1>=97 &&c1<=122) temp1=0;
		else temp1=c1-48;
		if(c2>=97 &&c2<=122) temp2=0;
		else temp2=c2-48;
		return Calculate(temp1,p->GetData(),temp2);
  	}
	else if(IsOperator(c1) &&!IsOperator(c2)){//���������Ҷ�� 
 		temp1=ValueRecursion(p->GetLeft());
		if(c2>=97 &&c2<=122) temp2=0;
		else temp2=c2-48;
		return Calculate(temp1,p->GetData(),temp2);
	}
	else if(!IsOperator(c1) &&IsOperator(c2)){//��Ҷ��������� 
		temp2=ValueRecursion(p->GetRight());
		if(c1>=97 &&c1<=122) temp1=0;
		else temp1=c1-48;
		return Calculate(temp1,p->GetData(),temp2);
  	}
	else{//���Ҷ�������� 
		temp1=ValueRecursion(p->GetLeft());
		temp2=ValueRecursion(p->GetRight());
		return Calculate(temp1,p->GetData(),temp2);
	}
}
int Tree::Calculate(int a,char op,int b){//������֮��ļ��� 
         switch(op){
         case '+':
                   return a+b;
                   break;
         case '-':
                   return a-b;
                   break;

         case '*':
                   return a*b;
                   break;

         case '/':
                   return a/b;
                   break;
         case '^':
                   return (int)pow((double)a,(double)b);
                   break;
         }
         return 0;
}

#include"AdjMultiListGraph.h"
#include<iostream>
#include<queue> 
#include<stack>
#include<cstring>
using std::queue;
using std::stack;
using std::cout;
using std::cin;
using std::endl;
///////////////////////////////////������˵����.h�ļ� 
///////////////////////////////////�ڽӶ��ر�ͼ����
AdjMultiListGraph::AdjMultiListGraph(){
	n=m=st=ncount=mcount=0;
	startpoint="";
	f.clear();
	name.clear();
	f[""]=0;
	name[0]="";
	head=new PrintTree2;
	head->next=NULL;
	head->name="";
	head->dep=-1; 
}
AdjMultiListGraph::~AdjMultiListGraph(){
	while (head->next!=NULL){
		PrintTree2 *p=head->next;
		delete head;
		head=p;
	}
	delete head;
}
void AdjMultiListGraph::insert(int x,int y,int d){//���� 
	edgenode *e=new edgenode;
	e->x=x;e->y=y;e->d=d;
	e->xnext=firstedge[x];
	e->ynext=firstedge[y];
	firstedge[x]=e;
	firstedge[y]=e;
}
void AdjMultiListGraph::ReadGraph(){//��ͼ 
	freopen("input.txt","r",stdin);
	cout<<"����������ͱ���n m:"<<endl;
	cin>>n>>m;
	string s,t;
	int d;
	for (int i=1;i<=n;i++){
		firstedge[i]=NULL;
		visit[i]=0;
	}
	cout<<"������m���ߵ���Ϣ(�˵�x���� �˵�y���� ����d):"<<endl; 
	for (int i=1;i<=m;i++){
		cin>>s>>t>>d;
		int &ret1=f[s];
		int &ret2=f[t];
		if (!ret1)ret1=++ncount,name[ncount]=s;
		if (!ret2)ret2=++ncount,name[ncount]=t; 
		insert(ret1,ret2,d);
	}
	cout<<"��������������:"<<endl;
	cin>>startpoint;
	st=f[startpoint];
	freopen("CON","r",stdin);
	if (!st){
		cout<<"�޴���㣬�������޸�����"<<endl; 
		exit(0);
	}
	
}
void AdjMultiListGraph::dfs(){//�ݹ������ 
	cout<<endl;
	for (int i=1;i<=n;i++){
		visit[i]=0;
		tree[i].clear();
	}
	visitorder.clear();
	if (head->next!=NULL)DeletePrintTree(head->next);
	head->next=NULL; 
	cout<<"�߼�"<<endl; 
	DfsRecursion(st,0,0,0); 
	cout<<endl;
	cout<<"�����˳��"<<endl;
	for (int i=0;i<visitorder.size();i++)cout<<name[visitorder[i]]<<" "; 
	cout<<endl<<endl;
	print_tree();
	cout<<endl;
	printvisitvec();
}
void AdjMultiListGraph::DfsRecursion(int x,int dep,int d,int fa){//�ݹ�����ѹ��� 
	visit[x]=1;
	visitorder.push_back(x);
	insertPrintTree(x,dep,d,name[fa]);
	for (edge k=firstedge[x];k!=NULL;k=(x==k->x?k->xnext:k->ynext)){
		if (k->x==x){
			if (!visit[k->y]){
				tree[k->x].push_back(k);
				cout<<name[k->x]<<" "<<name[k->y]<<" "<<k->d<<endl;
				DfsRecursion(k->y,dep+1,k->d,k->x);
			}
		}
		else {
			if (!visit[k->x]){
				tree[k->y].push_back(k);
				cout<<name[k->y]<<" "<<name[k->x]<<" "<<k->d<<endl;
				DfsRecursion(k->x,dep+1,k->d,k->y);
			}
		}
	}
}
void AdjMultiListGraph::non_recursive_dfs(){//�ǵݹ������ 
	cout<<endl;
	for (int i=1;i<=n;i++){
		visit[i]=0;
		tree[i].clear();
	}
	if (head->next!=NULL)DeletePrintTree(head->next);
	head->next=NULL; 
	visitorder.clear();
	stack<node>Q;
	Q.push(node(st,0));
	visit[st]=1;
	visitorder.push_back(st);
	insertPrintTree(st,0,0,"");
	cout<<"�߼�:"<<endl; 
	while (!Q.empty()){
		node no=Q.top();
		int flag=0;
		for (edge k=firstedge[no.x];k!=NULL;k=(no.x==k->x?k->xnext:k->ynext))
			if (k->x==no.x&& !visit[k->y]){
				visit[k->y]=1;
				tree[k->x].push_back(k);
				visitorder.push_back(k->y);
				insertPrintTree(k->y,no.dep+1,k->d,name[no.x]);
				cout<<name[k->x]<<" "<<name[k->y]<<" "<<k->d<<endl;
				Q.push(node(k->y,no.dep+1));
				flag=1;
				break;
			}
			else if (k->y==no.x&& !visit[k->x]){
				visit[k->x]=1;
				tree[k->y].push_back(k);
				visitorder.push_back(k->x);
				insertPrintTree(k->x,no.dep+1,k->d,name[no.x]);
				cout<<name[k->y]<<" "<<name[k->x]<<" "<<k->d<<endl;
				Q.push(node(k->x,no.dep+1));
				flag=1;
				break;
			}
		if (!flag)Q.pop();	
	}
	cout<<endl;
	cout<<"�����˳��"<<endl;
	for (int i=0;i<visitorder.size();i++)cout<<name[visitorder[i]]<<" "; 
	cout<<endl<<endl;
	print_tree();
	cout<<endl;
	printvisitvec();
}
void AdjMultiListGraph::bfs(){//���� 
	cout<<endl;
	for (int i=1;i<=n;i++){
		visit[i]=0;
		tree[i].clear();
	}
	visitorder.clear();
	if (head->next!=NULL)DeletePrintTree(head->next);
	head->next=NULL; 
	queue<node>Q;
	Q.push(node(st,0));
	visit[st]=1;
	visitorder.push_back(st);
	insertPrintTree(st,0,0,"");
	cout<<"�߼�:"<<endl; 
	while (!Q.empty()){
		node  no=Q.front();
		Q.pop();
		for (edge k=firstedge[no.x];k!=NULL;k=(no.x==k->x?k->xnext:k->ynext))
			if (k->x==no.x && !visit[k->y]){
				visit[k->y]=1;
				visitorder.push_back(k->y);
				tree[k->x].push_back(k);
				insertPrintTree(k->y,no.dep+1,k->d,name[no.x]);
				cout<<name[k->x]<<" "<<name[k->y]<<" "<<k->d<<endl;
				Q.push(node(k->y,no.dep+1));
			}
			else if (k->y==no.x&& !visit[k->x]){
				visit[k->x]=1;
				visitorder.push_back(k->x);
				tree[k->y].push_back(k);
				insertPrintTree(k->x,no.dep+1,k->d,name[no.x]);
				cout<<name[k->y]<<" "<<name[k->x]<<" "<<k->d<<endl;
				Q.push(node(k->x,no.dep+1));
			}
	}
	cout<<endl;
	cout<<"�����˳��"<<endl;
	for (int i=0;i<visitorder.size();i++)cout<<name[visitorder[i]]<<" "; 
	cout<<endl<<endl;
	print_tree();
	cout<<endl;
	printvisitvec();
} 
void AdjMultiListGraph::insertPrintTree(int x,int dep,int d,string fa){//�������ı� 
	PrintTree2 *p=new PrintTree2;
	p->name=name[x];
	p->blank="";
	for (int i=1;i<=dep;i++){
		if (i<dep)p->blank+="|     ";
		else p->blank+="|-----";	
	}
	p->dep=dep; 
	p->d=d;
	PrintTree2 *q=head;
	while (q->name!=fa)q=q->next;
	p->next=q->next;
	q->next=p;
}
void AdjMultiListGraph::DeletePrintTree(PrintTree2 *p){//ɾ���� 
	if (p==NULL)return;
	DeletePrintTree(p->next);
	delete p;
} 
void AdjMultiListGraph::print_tree(){//����� 
	PrintTree2 *p=head->next;
	while (p){
		cout<<p->blank<<p->name<<"("<<p->d<<")"<<endl;
		p=p->next;
	}
}
void AdjMultiListGraph::printvisitvec(){
	cout<<"�ȸ�����: ";preorder(st);cout<<endl; 
	cout<<"���������";postorder(st);cout<<endl;
}
void AdjMultiListGraph::preorder(int x){//�ȸ����� 
	cout<<name[x]<<" ";
	vector<edge>::iterator it;
	for (it=tree[x].begin();it!=tree[x].end();it++){
		edge k=*it;
		if (k->x==x)preorder(k->y);
		else preorder(k->x);
	}
}
void AdjMultiListGraph::postorder(int x){//������� 
	vector<edge>::iterator it;
	for (it=tree[x].begin();it!=tree[x].end();it++){
		edge k=*it;
		if (k->x==x)postorder(k->y);
		else postorder(k->x);
	}
	cout<<name[x]<<" ";
}
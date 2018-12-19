#include"AdjListGraph.h"
#include<iostream>
#include<queue> 
#include<stack>
#include<cstring>
using std::queue;
using std::stack;
using std::cout;
using std::cin;
using std::endl;
///////////////////////////////////�ڽӱ�ͼ���� 
AdjListGraph::AdjListGraph(){
	n=m=st=ncount=mcount=0;
	startpoint="";
	f.clear();
	name.clear();
	f[""]=0;
	name[0]="";
	head=new PrintTree;
	head->next=NULL;
	head->name="";
	head->dep=-1; 
}
AdjListGraph::~AdjListGraph(){
	while (head->next!=NULL){
		PrintTree *p=head->next;
		delete head;
		head=p;
	}
	delete head;
}
void AdjListGraph::ReadGraph(){//��ͼ 
	freopen("input.txt","r",stdin);
	cout<<"����������ͱ���n m:"<<endl;
	cin>>n>>m;
	string s,t;
	int d;
	for (int i=1;i<=n;i++){
		firstedge[i]=-1;
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
void AdjListGraph::insert(int x,int y,int d){//���� 
	int len1=++mcount,len2=++mcount;
	e[len1].y=y;e[len1].d=d;
	e[len1].next=firstedge[x];firstedge[x]=len1;
	
	e[len2].y=x;e[len2].d=d;
	e[len2].next=firstedge[y];firstedge[y]=len2;
} 
void AdjListGraph::dfs(){//�ݹ������ 
	for (int i=1;i<=n;i++)visit[i]=0;
	if (head->next!=NULL)DeletePrintTree(head->next);
	head->next=NULL; 
	DfsRecursion(st,0,0,0); 
} 
void AdjListGraph::DfsRecursion(int x,int dep,int d,int fa){//�ݹ������ ���� 
	visit[x]=1;
	insertPrintTree(x,dep,d,name[fa]);
	for (int k=firstedge[x];k!=-1;k=e[k].next)
		if (!visit[e[k].y])
			DfsRecursion(e[k].y,dep+1,e[k].d,x);
}
void AdjListGraph::non_recursive_dfs(){//�ǵݹ������ 
	for (int i=1;i<=n;i++)visit[i]=0;
	if (head->next!=NULL)DeletePrintTree(head->next);
	head->next=NULL; 
	stack<node>Q;
	Q.push(node(st,0));
	visit[st]=0;
	insertPrintTree(st,0,0,"");
	while (!Q.empty()){
		node no=Q.top();
		int flag=0;
		for (int k=firstedge[no.x];k!=-1;k=e[k].next)
			if (!visit[e[k].y]){
				visit[e[k].y]=1;
				insertPrintTree(e[k].y,no.dep+1,e[k].d,name[no.x]);
				Q.push(node(e[k].y,no.dep+1));
				flag=1;
				break;
			}
		if (!flag)Q.pop();	
	}
}
void AdjListGraph::bfs(){//���� 
	for (int i=1;i<=n;i++)visit[i]=0;
	if (head->next!=NULL)DeletePrintTree(head->next);
	head->next=NULL; 
	queue<node>Q;
	Q.push(node(st,0));
	visit[st]=1;
	insertPrintTree(st,0,0,"");
	while (!Q.empty()){
		node  no=Q.front();
		Q.pop();
		for (int k=firstedge[no.x];k!=-1;k=e[k].next)
			if (!visit[e[k].y]){
				visit[e[k].y]=1;
				insertPrintTree(e[k].y,no.dep+1,e[k].d,name[no.x]);
				Q.push(node(e[k].y,no.dep+1));
			}
	}
} 
void AdjListGraph::insertPrintTree(int x,int dep,int d,string fa){//�������ı� 
	PrintTree *p=new PrintTree;
	p->name=name[x];
	p->blank="";
	for (int i=1;i<=dep;i++)
		if (i<dep)p->blank+="|    ";
		else p->blank+="|-----";
	p->dep=dep; 
	p->d=d;
	PrintTree *q=head;
	while (q->name!=fa)q=q->next;
	p->next=q->next;
	q->next=p;
}
void AdjListGraph::DeletePrintTree(PrintTree *p){//�������ı� 
	if (p==NULL)return;
	DeletePrintTree(p->next);
	delete p;
} 
void AdjListGraph::print_tree(){//����� 
	PrintTree *p=head->next;
	while (p){
		cout<<p->blank<<p->name<<"("<<p->d<<")"<<endl;
		p=p->next;
	}
}

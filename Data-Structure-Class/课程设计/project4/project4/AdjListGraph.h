#ifndef _ADJLISTGRAPH_H_
#define _ADJLISTGRAPH_H_
#include<string>
#include<map> 
using std::map;
using std::string;
class PrintTree{//��������� 
	public:
		string name,blank;
		int d,dep; 
		PrintTree *next;
}; 
class AdjListGraph{//�ڽӱ�ͼ���� 
	public:
		AdjListGraph();
		~AdjListGraph();
		void ReadGraph();//��ͼ 
		void dfs();//�ݹ������ 
		void bfs();//���� 
		void non_recursive_dfs();//�ǵݹ������ 
		void print_tree();//����� 
	private:
		void DfsRecursion(int x,int dep,int d,int fa);//�ݹ������ ���� 
		void insert(int x,int y,int d);//���� 
		void insertPrintTree(int x,int dep,int d,string fa);//�������ı� 
		void DeletePrintTree(PrintTree *p);//ɾ���� 
		int n,m,st,ncount,mcount;//n���㣬m���� 
		string startpoint;//��� 
		struct edgenode{//����Ϣ��� 
			int y,d,next;
		}e[2000];
		struct node{//bfs�����кͷǵݹ�stack�е���Ϣ�ṹ 
			int x,dep;
			node(){}
			node(int _x,int _dep){
				x=_x;dep=_dep;
			}
		};
		int visit[50],firstedge[2000];//�жϵ��Ƿ���� ��ÿ�����һ����  
		PrintTree *head;//�������ͷ��� 
		map<string,int> f;//hash�� 
		map<int,string> name; //��hash 
};
#endif

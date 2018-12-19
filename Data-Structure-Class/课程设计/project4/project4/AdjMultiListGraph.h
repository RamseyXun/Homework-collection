#ifndef _ADJMULTILISTGRAPH_H_
#define _ADJMULTILISTGRAPH_H_
#include<string>
#include<map> 
#include<vector>
using std::map;
using std::vector;
using std::string;
class PrintTree2{//��������� 
	public:
		string name,blank;
		int d,dep; 
		PrintTree2 *next;
}; 
class AdjMultiListGraph{//�ڽӶ��ر�ͼ���� 
	public:
		AdjMultiListGraph();
		~AdjMultiListGraph();
		void ReadGraph();//��ͼ 
		void dfs();//�ݹ������ 
		void non_recursive_dfs();//�ǵݹ������ 
		void bfs();//���� 
	private:
		void insert(int x,int y,int d);//���� 
		void DfsRecursion(int x,int dep,int d,int fa);//���ѹ��� 
		void insertPrintTree(int x,int dep,int d,string fa);//�����������һ���� 
		void DeletePrintTree(PrintTree2 *p);//ɾ���� 
		void print_tree();//����� 
		void printvisitvec(); //����ȸ������ͺ������ 
		void preorder(int x);//�ȸ�����  
		void postorder(int x);//������� 
		vector<int> visitorder;//����ʱ���ʵĵ�˳�� 
		int n,m,st,ncount,mcount;//n���㣬m���� 
		string startpoint;//��ʼ�� 
		typedef struct edgenode{//�洢�ߵĽṹ�� 
			int x,y,d;
			edgenode *xnext;
			edgenode *ynext;
		}*edge;
		struct node{//bfs�����кͷǵݹ�stack�е���Ϣ�ṹ 
			int x,dep;
			node(){}
			node(int _x,int _dep){
				x=_x;dep=_dep;
			}
		};
		vector<edge>tree[50];//�洢����� 
		int visit[50];//�жϵ��Ƿ���� 
		edge firstedge[50];//ÿ�����һ���� 
		PrintTree2 *head;//�������ͷ��� 
		map<string,int> f;//hash�� 
		map<int,string> name; //��hash 
};
#endif

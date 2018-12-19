#ifndef _EXPRESSION_H_
#define _EXPRESSION_H_
//--------------------    �������
class TreeNode{
	public:
        TreeNode(char _data,TreeNode* _left,TreeNode* _right);
        ~TreeNode();
        char GetData();//��ȡ�ý���ֵ 
        void SetData(char _data);//���øý���ֵ 
        void SetLeft(TreeNode* _left);//�������� 
        void SetRight(TreeNode* _right);//�����Һ��� 
        TreeNode* GetLeft();//��ȡ���� 
        TreeNode* GetRight();//��ȡ�Һ��� 
	private:
        char Data; 
        TreeNode*left,*right;
};

//--------------------��������  
class Tree{ 
	public:
        Tree();
        ~Tree();
        TreeNode*GetRoot();//��ȡ���ڵ� 
        void SetRoot(TreeNode* _root);//���ø��ڵ� 
        void ReadExpr(char* E);//��ǰ׺���ʽE���� 
        void WriteExpr(char* E);//�õ���׺���ʽ������E 
        void MergeConst(char *E);//�ϲ���������׺���ʽ������E 
		void Diff(char *E, char V);//��E��V��ƫ����
        void Assign(char v,int c);//������V��ֵ��C 
        static int Value(char* E);//��E��ֵ 
        static Tree* CompoundExpr(char p,char* E1,char* E2);//���츴�ϱ��ʽ(E1)P(E2) 
        void Release();//ɾ������ 

	private:
        void DeleteTree(TreeNode* &p);//ɾ��pΪ���������� 
        void ReadExprRecursion(TreeNode* &p,char* E);
        void WriteExprRecursion(TreeNode* p,char* E);
        void AssignRecursion(TreeNode* p,char v,int c);
        int ValueRecursion(TreeNode* p);
        void Conbination(char *E,int i);//�ϲ����� 
        int Priority(char c1,char c2);
        bool IsOperator(char c);
        bool IsNumber(char c);//�ж��Ƿ������� 
        int Calculate(int a,char op,int b);
        TreeNode *root;//����� 
        int Expr_i,len;
};

#endif

#include<iostream>
#include<cstdio>
#include<conio.h>
#include"Expression.h"
using namespace std;
int main(){
	Tree tree,*tree1;
 	char E1[100],E2[100],P,V;
  	int switchs,c,switchs2;
   	bool run=true,run2=true;
    while(run){
		system("cls"); 
		cout<<"��ѡ��Ҫִ�еĹ���:"<<endl;
		cout<<"   1.����ǰ׺���ʽ�������׺���ʽ."<<endl;
		cout<<"   2.���츴�ϱ��ʽ."<<endl;
		cout<<"   3.��ǰ׺���ʽ��ֵ."<<endl;
		cout<<"   4.��ǰ׺���ʽ��ƫ��." << endl;
		cout<<"   5.�˳�."<<endl;
		cin>>switchs;
		switch(switchs){
  			case 5:
				run=false;
				break;
			case 1:
				cout<<"������ǰ׺���ʽ�����س���������:"<<endl;
				cin>>E1;
				tree.ReadExpr(E1);
				while(run2){
					cout<<"���б���Ҫ��ֵ������1����������2"<<endl;
					cin>>switchs2;
					if(switchs2==1){
						cout<<"�������������,��x��ֵΪ1������ x 1 :"<<endl;
						getchar();
						scanf("%c%d",&V,&c);
						tree.Assign(V,c);
					}
					else run2=false;
				}
				tree.WriteExpr(E2);
				cout<<"��׺���ʽ: "<<E2<<endl;
				cout<<"�Ƿ�ϲ�����:1��2��"<<endl;
				cin>>switchs2;
				if (switchs2==1){
					tree.MergeConst(E2);	
					cout<<"�ϲ�������: "<<E2<<endl;	
				}
				run2=true;
				break;
    		case 2:
				cout<<"������ǰ׺���ʽ1 �м������ ǰ׺���ʽ2:"<<endl;
				getchar();
				scanf("%s %c %s",E1,&P,E2);
				tree1=Tree::CompoundExpr(P,E1,E2);
    			while(run2){
					cout<<"���б���Ҫ��ֵ������1����������2"<<endl;
					cin>>switchs2;
					if(switchs2==1){
						cout<<"�������������,��x��ֵΪ1������ x 1 :"<<endl;
						getchar();
						scanf("%c%d",&V,&c);
						tree1->Assign(V,c);
					}
					else run2=false;
				}
				tree1->WriteExpr(E1);
				cout<<"��׺���ʽ:"<<E1<<endl;
				tree1->Release();
				delete(tree1);
				run2=true;
				break;
			
			case 3:
				cout<<"�������������.ǰ׺���ʽ"<<endl;
				cin>>E1;
				tree.ReadExpr(E1);
				tree.WriteExpr(E2);
				cout<<"��׺���ʽΪ:";
				cout<<E2<<endl;
				cout<<"������Ϊ:";
				cout<<Tree::Value(E1)<<endl;
				break;
			case 4:
				cout << "������ǰ׺���ʽ�����س���������:" << endl;
				cin >> E1;
				tree.ReadExpr(E1);
				tree.WriteExpr(E2);
				cout << "��������ĸ�������ƫ��:" << endl;
				getchar();
				cin >> V;
				cout << "��ƫ��ǰ��" << E2 << endl;
				tree.Diff(E2,V);
				break;
			default:
				cout<<"���������Ч!����������."<<endl;
				break;
		}
		tree.Release();
		if(run) cout<<endl;
		cout<<"please input any key to continue"<<endl;
		getch();
	}
	return 0;
}

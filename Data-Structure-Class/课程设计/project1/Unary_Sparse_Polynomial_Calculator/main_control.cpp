#include"main_control.h"
#include"polynomial.h"
#include<iostream>
using namespace std;
void MainControl::How_to_use(){
	cout<<"                ��ӭʹ�øü��һԪ����ʽ������               "<<endl;
	cout<<"          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<<endl;
	cout<<"           ����˵����                                        "<<endl;
	cout<<"                   1.��������ʽa��b.                         "<<endl;
	cout<<"                   2.�������ʽa+b.                          "<<endl;
	cout<<"                   3.�������ʽa-b.                          "<<endl;
	cout<<"                   4.�������ʽa*b.                          "<<endl;
	cout<<"                   5.�Զ���ʽa��.                          "<<endl;
	cout<<"                   6.�Զ���ʽb��.                          "<<endl;
	cout<<"                   7.���������ʽ��x����ֵ.                  "<<endl;
	cout<<"                   8.�˳�.                                   "<<endl;
	cout<<"          ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<<endl;
}
void MainControl::start_work(){
	How_to_use();
	polynomial* ret[7];
	for (int i=0;i<5;i++)
		ret[i]=NULL;
	int n,x;
	for (int type=0;;type=0){
        cin>>type;		
		if (ret[0]||ret[1]){
			system("cls");
			How_to_use();
			cout<<"����ʽa��";print(ret[0]);cout<<endl;
			cout<<"����ʽb��";print(ret[1]);cout<<endl;
			cout<<endl;
		}
		if (type==1){//��������ʽa��b 
			for (int i=0;i<7;i++)
				if (ret[i])del(ret[i]);	
			cout<<"���������ʽa������:"<<endl;
	        cin>>n;	        
	        ret[0]=creatpolyn(n);//��������ʽa
	        
	        cout<<"���������ʽb������:"<<endl;
	        cin>>n;
	        ret[1]=creatpolyn(n);//��������ʽb
	        
	        system("cls");
			How_to_use();
			cout<<"����ʽa��";print(ret[0]);cout<<endl;
			cout<<"����ʽb��";print(ret[1]);cout<<endl;
			cout<<endl;
		}
		else if (type==2){//�ӷ� 
			if(!ret[2])ret[2]=add(ret[0],ret[1]);
			cout<<"����ʽa+b:\n(";print(ret[0]);cout<<")+(";print(ret[1]);cout<<")=(";print(ret[2]);cout<<")"<<endl;
		}
		else if (type==3){//���� 
			if(!ret[3])ret[3]=sub(ret[0],ret[1]);
			cout<<"����ʽa-b:\n(";print(ret[0]);cout<<")-(";print(ret[1]);cout<<")=(";print(ret[3]);cout<<")"<<endl;
		}
		else if (type==4){//�˷� 
			if(!ret[4])ret[4]=mul(ret[0],ret[1]);
			cout<<"����ʽa*b:\n(";print(ret[0]);cout<<")*(";print(ret[1]);cout<<")=(";print(ret[4]);cout<<")"<<endl;
		}
		else if (type==5){//a�� 
			if(!ret[5])ret[5]=derivative(ret[0]);
			cout<<"�Զ���ʽa�󵼵�a��= (";print(ret[5]);cout<<")"<<endl; 
		} 
		else if (type==6){//b�� 
			if(!ret[6])ret[6]=derivative(ret[1]);
			cout<<"�Զ���ʽb�󵼵�b��= (";print(ret[6]);cout<<")"<<endl; 
		}
		else if (type==7){//��ֵ 
			cout<<"������x��ֵ"<<endl;
			cin>>x;
			if (ret[0]!=NULL){
				cout<<"a: (";print(ret[0]);cout<<")="<<value(ret[0],x)<<endl;
			}
			if (ret[1]!=NULL){
				cout<<"b: (";print(ret[1]);cout<<")="<<value(ret[1],x)<<endl;
			}
			if (ret[2]!=NULL){
				cout<<"����ʽa+b��ֵ:\n(";print(ret[0]);cout<<")+(";print(ret[1]);cout<<")="<<value(ret[2],x)<<endl;
			}
			if (ret[3]!=NULL){
				cout<<"����ʽa-b��ֵ:\n(";print(ret[0]);cout<<")-(";print(ret[1]);cout<<")="<<value(ret[3],x)<<endl;
			}
			if (ret[4]!=NULL){
				cout<<"����ʽa*b��ֵ:\n(";print(ret[0]);cout<<")*(";print(ret[1]);cout<<")="<<value(ret[4],x)<<endl;
			}
		    if (ret[5]!=NULL){
				cout<<"����ʽa�󵼵�ֵ  a':\n(";print(ret[5]);cout<<")="<<value(ret[5],x)<<endl;
		    }
			if (ret[6]!=NULL){
				cout<<"����ʽb�󵼵�ֵ  b':\n(";print(ret[6]);cout<<")="<<value(ret[6],x)<<endl;
			}
		}
		else if (type==8)break;
		else cout<<"����Ƿ�������������:"<<endl; 
	}
	for (int i=0;i<7;i++)
		if (ret[i])del(ret[i]);
	system("cls");
	cout<<"ллʹ��"<<endl; 
}

#include<iostream>
#include<sstream>
using namespace std;
int main(){
	string s="",ss;
	char ch;
	int Letternum=0,Wordnum=0;
	//Letternumͳ���ַ�����Wordnumͳ�Ƶ����� 
	while (cin.get(ch)){
		if (ch!='\n'){//���ǻ��з����ַ��ӽ�s
			s+=ch;
			Letternum++;
		}
		else s+=" ";
		//���ǻ��з����ÿո���棬��һ������Ҫ�����������뵥�� 
	}
	istringstream str(s);
	while (str>>ss)Wordnum++;//���뵥�ʲ�ͳ�� 
	cout<<"Letters: "<<Letternum<<endl;
	cout<<"Words: "<<Wordnum<<endl;
	return 0;
}

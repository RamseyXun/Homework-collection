#include<iostream>
#include<cstring>
using namespace std;
#define rep(i,u,v) for (int i=(u);i<=(v);i++) 
int main(){
	int r,c,len;
    string str;
    while(cin>>c&&c){
        char a[201][201];
        cin>>str;
        len=str.length();
        r=len/c;
        int x=0,y=0;//x��y��ʾ��ǰ�x��y�� 
        rep(i,0,len-1){
        	if (x%2==0){//��������
				a[x][y]=str[i];
				if (++y==c){
					x++;y=c-1;
				}
        	}
        	else {//���ҵ�����
				a[x][y]=str[i];
				if (--y==-1){
					x++;y=0;
				}
        	}
		}
 		rep(j,0,c-1)
 			rep(i,0,r-1)
 				cout<<a[i][j];
		cout<<endl;
    }
    return 0;
}                    
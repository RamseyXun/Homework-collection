#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define rep(i,u,v) for (int i=(u);i<=(v);i++)
int f[4*30][16];
void solve(int T,int n,int m) {
	memset(f,0,sizeof(f));
	f[0][(1<<m)-2]=1;//������������滹��һ�����Ѿ����� 
	for (int i=1;i<n*m;i++)//ö�ٸ��� 
		for (int k=0;k<(1<<m);k++)//ö�ٶ�����״̬ 
			if (k&1) {//�����i�񱻸��� 
				if (i/m>0)f[i][k]=f[i-1][k>>1];//�������һ�У��Ϳ������ŷ�һ�� 
				if (i%m>0&&(k&2))f[i][k]+=f[i-1][((k>>1)^1)|(1<<m>>1)];
				//������һ����ţ��Ϳ��Ժ��ŷ�һ�� 
			} 
			else f[i][k]=f[i-1][(k>>1)|(1<<m>>1)];
			//�����i��û�б����ǣ����i-m������һ����1����������״̬��ͬ 
	cout<<T<<" "<<f[n*m-1][(1<<m)-1]<<endl;
}
int main() {
	int T,n,m;
	cin>>T; 
	rep(t,1,T){
		cin>>n;
		solve(t,n,4);
	}
	return 0;
}

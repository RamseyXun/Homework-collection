#include<iostream>
#include<cstdio>
using namespace std;
#define rep(i,u,v) for (int i=(u);i<=(v);i++)
#define N 1010
#define INF 2000000000
int n;
int a[N],f[N][N];
void dfs(int l,int r){
	int len=r-l+1;
	if (f[l][r]!=-INF)return;
	if (l==r){
		f[l][r]=-a[l];
		return;
	}
	if (len%2==1){//�ڶ�����ȡ����ֻȡ�ϴ��� 
		if (a[l]>=a[r]){
			dfs(l+1,r);
			f[l][r]=f[l+1][r]-a[l];	
		}
		else {	
			dfs(l,r-1);
			f[l][r]=f[l][r-1]-a[r];
		}
	} 
	else {//��һ����ȡ��������ѡ�� 
		dfs(l+1,r);
		dfs(l,r-1);
		f[l][r]=max(f[l+1][r]+a[l],f[l][r-1]+a[r]);
	} 
}
int main(){
	int T=0;
	while(cin>>n,n>0){
		rep(i,1,n)cin>>a[i];
		rep(i,1,n)
			rep(j,1,n)
				f[i][j]=-INF;
	    //f[i][j]Ϊ[i,j]�Ĵ𰸣��ȳ�ʼ��Ϊ����С 
		dfs(1,n);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++T,f[1][n]);
	} 
	return 0; 
} 

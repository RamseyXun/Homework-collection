#include<iostream>
#include<cstring>
using namespace std;
#define rep(i,u,v) for (int i=(u);i<=(v);i++)
int a[21][3],f[21][31][31];
int n,m,k,ans,T;
inline void dfs(int sta,int times,int score,int cnt){
	if (ans>=k-times+cnt)return;//��ǰ״̬���󲻿����ٱȵ�ǰ����ֵ���� 
	if (f[sta][times][score]>=cnt)return;//֮ǰ�ѵ����״̬ʱ�����ڸ��� 
	f[sta][times][score]=cnt;
	if (times==k){
		if (score==m&&ans<cnt)ans=cnt;
		return;
	}
	dfs(a[sta][0],times+1,score+(a[sta][2]==0),cnt+1);
	dfs(a[sta][1],times+1,score+(a[sta][2]==1),cnt);
}
int main(){
	while (scanf("%d",&T)!=EOF){
		if (!T)break;
		scanf("%d%d%d",&n,&k,&m);
	 	rep(i,0,n-1)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	 	ans=0;
	 	memset(f,-1,sizeof(f));
	 	dfs(0,0,0,0);
	 	printf("%d %d\n",T,ans); 
	}
	return 0;
}
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define rep(i,u,v) for (int i=(u);i<=(v);i++)
#define INF 100000000.0
struct node{
	double x,y;
}a[110];
int n;
double dp[110][110];
bool cmp(const node &n1,const node &n2){
	return n1.x<n2.x;
}
double dist(node &n1,node &n2){
	double x=n1.x-n2.x;
	double y=n1.y-n2.y;
	return sqrt(x*x+y*y);
}
int main(){
	while(cin>>n){
		rep(i,1,n)
			cin>>a[i].x>>a[i].y;
		sort(a+1,a+1+n,cmp);
		rep(i,0,n)
			rep(j,0,n)
				if (!i || !j)dp[i][j]=0;
				else dp[i][j]=INF;
		dp[1][1]=0;//��㵽�Լ���0
		rep(i,2,n)dp[1][i]=dp[i][1]=dp[i-1][1]+dist(a[i],a[i-1]);
		//�����ⲽ�����ñ߽磬��һ��������ȫ�� 
		rep(i,1,n)//ö�ٵ�һ�����ߵĵ�
			rep(j,1,i){//ö�ٵڶ������ߵĵ�
				if(i>j+1)dp[i][j]=dp[j][i]=dp[i-1][j]+dist(a[i],a[i-1]);
				else if (i==j+1){
					rep(k,1,j-1)//ö�ٵ�һ�����Ǵ�k���ߵ�i��� 
						dp[i][j]=dp[j][i]=min(dp[i][j],dp[k][j]+dist(a[i],a[k]));
				} 
				else{//i==j
					rep(k,1,j-1)
						dp[i][j]=dp[j][i]=min(dp[i][j],
						dp[i-1][k]+dist(a[i],a[i-1])+dist(a[k],a[j]));	
				}
			} 
		printf("%.2lf\n",dp[n][n]);	
	} 
	return 0;
}
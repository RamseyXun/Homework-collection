#include<iostream>
using namespace std;
#define rep(i,u,v) for (int i=(u);i<=(v);i++)
#define N 102 
double dp[N],t[10010];
int a[N];
double b,e,v,f;
int r;
double calc(int x){
	if (x>=r)
		return (double)1.0/(v - e * (x - r));
	else  
		return (double)1.0/(v - f * (r - x));
}
int main(){
	int n;
	while (cin>>n&&n){
		rep(i,1,n)cin>>a[i];
		cin>>b>>r>>v>>e>>f;
		dp[0]=0;//��㵽�Լ�ʱ��Ϊ0
		rep(i,1,a[n])t[i]=t[i-1]+calc(i-1);
		rep(i,1,n){
			dp[i]=t[a[i]];//����ʱ��ʼ��Ϊȫ�̲���̥��ʱ�� 
			rep(j,1,i-1)//ö�ٻ�̥�ص㣬��ʱ�俪����Сֵ��
				dp[i]=min(dp[i],dp[j]+t[a[i]-a[j]]+b); 
		}
		printf("%.4lf\n",dp[n]);
	}
	return 0;
}
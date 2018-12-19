#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
#define rep(i,u,v) for (int i=(u);i<=(v);i++)
class Josephus{
    public:
        int n,s,m;
        int next[5002];
    Josephus(int n,int s,int m){ 
        this->n=n;
        this->s=s;
        this->m=m;
    }
    void pre(){
	   //׼��������next[i]��ʾ��i���� ����һ������˭����next������ģ������ 
        rep(i,1,n-1)next[i]=i+1;
        next[n]=1;
    }
    void getans(){
        int count=0,fa=s-1;
        if (!fa)fa=n;
        while (1){
            int cnt=0;
            while (++cnt<m){//ÿ��ѭ��m���˵õ����ӵ��ˣ�fa��¼��ǰ�����һ���� 
                fa=s;
                s=next[s];
            }
            cout<<s<<endl;
            count++;    
            if (count==n)return;
            next[fa]=next[s];//ɾ�������ˣ�next[fa]��ֵ��Ϊs����һ���˼�next[s] 
            s=next[s];//��һ�ֱ�����s����һ���˿�ʼ 
        }
    }
};
int main(){
    int n,s,m;
    cin>>n>>s>>m;
    Josephus text(n,s,m);
    text.pre();
    text.getans();
    return 0;
}                           
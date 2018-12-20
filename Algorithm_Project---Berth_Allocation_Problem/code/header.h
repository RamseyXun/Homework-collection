#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<string>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<utility>
using namespace std;
#define rep(i,u,v) for (int i=(u);i<=(v);++i)
#define dto(i,u,v) for (int i=(u);i<=(v);++i)
#define w1 100
#define w2 2
#define w3 1
#ifdef   GLOBALS  
#define  EXTERN 
#else  
#define  EXTERN  extern  
#endif  
struct vessel{
	int a,t,b;
	/*
	�����ʾ���Ľṹ��
	a: arrive time
	t: service time
	b: it need to occupiy b berths
	*/
};
struct sol{
	int position_to_start_docking[30];//
	int time_to_start_service[30];
	int total_waiting_time;
	int last_departure_time;
	int fx;
	/*�����ʾͣ�������Ľṹ��
	�����漰���Ĵ���˳���ǰ�������ʱ��˳�� 
	
	position_to_start_docking[i] ��i�Ҵ����ĸ�berths��ʼͣ
    time_to_start_service[i]     ��i�Ҵ����ĸ�ʱ�俪ʼͣ 
    total_waiting_time           �ܵȴ�ʱ�� 
    ast_departure_time           ����뿪�Ĵ����뿪ʱ�� 
    fx                           �÷���������ֵ������Ŀ 
	*/ 
};
struct permutation{
	int array[30];
	int sta[13][31];
	sol ans;
	/*
	array: ���У�ָ��ͣ��˳��array[i]��ʾ��i��ͣ�Ĵ��Ƕ�����ʱ�ĵ�array[i]�Ҵ� 
	sta: �ۿ�״̬����һά��λ�ã��ڶ�ά��ʱ�䣬ֵΪ0��ʾ��ͣ��Ϊ1��ʾ����ͣ 
	ans���洢�����е�̰�ĵó��Ľ�� 
	*/ 
};
EXTERN int T,n,L;
EXTERN vessel boat[30];
EXTERN sol ANS;
EXTERN permutation p[7];                  
EXTERN char datanum[50];
EXTERN bool OpenDataFile();             //�����ݶ�ȡ�ļ��ͽ��д���ļ�
EXTERN void Print_Ans();                //����� 
EXTERN void Evaluate(permutation &n1); //����fx,����뿪ʱ�䣬�ܵȴ�ʱ�� 
EXTERN void update(sol &n1, sol n2);   //�������Ž⣬����n1�� 


////////////////////̰�Ĳ���
EXTERN bool check(permutation &n1, int stb, int edb, int stt, int edt);//����ܷ�ͣ 
EXTERN void find_location(permutation &n1, int idx);//���������еĵ�idxλָʾ�Ĵ���λ��ͣ
EXTERN void Greedy(permutation &n1); //��permutaion����ָ����ͣ��˳����̰��Ѱ��ͣ��λ��
							 //����ڴ���n1�� 
//////////////////////////// 

///////////////////////////���Ѳ���
EXTERN int v[30];
EXTERN void dfs(int x);//��ȫ���� 
EXTERN void violence_search();// ���ѷ�����ں��� 
////////////////////////////////// 

////////////////////////ģ���˻𲿷�
EXTERN double random();
EXTERN void Simulate_Anneal();
/////////////////////////////////// 


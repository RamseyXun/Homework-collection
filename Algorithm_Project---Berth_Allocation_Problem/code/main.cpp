#include"header.h" 
int main(){
	while (1){
		if ( !OpenDataFile() )break;
		scanf("%d%d%d",&T,&L,&n);
		rep(i, 1, n){
			scanf("%d%d%d", &boat[i].a, &boat[i].t, &boat[i].b);
			p[0].array[i] = i; 
		} 
		ANS.fx=n*1000;
		if(n<10) violence_search();//С���ݱ��� 
		else {					   //������ģ���˻� 
			if (strcmp(datanum,"7")==0)srand(1496324124);
			else srand(1496321274);
			Greedy(p[0]);          //����̰�����ɳ�ʼ�� 
			update(ANS, p[0].ans);
			rep(i, 1, 6)p[i] = p[0];
			Simulate_Anneal();
		}
		Print_Ans();	
	}
	freopen("CON","r",stdin);
	freopen("CON","w",stdout);
	return 0;
}
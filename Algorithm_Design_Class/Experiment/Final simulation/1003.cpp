#include<iostream>
using namespace std;
int main(){
    int times;
    cin >> times;
    while(times--){
        int pointCount;     //���еĸ���
        int delPointNum = 0;    //�Ѿ�����Ժõĳ��и���
        cin >> pointCount;
        int edgeArray[pointCount][2];   //������������������
        int pointLigature[pointCount];  //����ÿ�����еĶ�
        for(int i = 0; i < pointCount; i++)pointLigature[i] = 0;
        for(int i = 0; i < pointCount - 1; i++){
            int startPoint, endPoint;
            cin >> startPoint >> endPoint;
            edgeArray[i][0] = startPoint;
            edgeArray[i][1] = endPoint;
            pointLigature[startPoint - 1]++;
            pointLigature[endPoint - 1]++;
        }
        if(pointCount % 2 == 1) {cout << "No" << endl;continue;}    //������еĸ�����������ֱ���жϲ������
        int maxDelTime = pointCount;
        while(maxDelTime--){     //��������Ŷ�Ϊ1�Ķ��㣨���У���ÿ��ѭ��������ԣ�ɾ����һ��
            int delPoint = 0;   //�ҳ���Ϊ1�Ķ���
            for(; delPoint< pointCount; delPoint++){
                if(pointLigature[delPoint] == 1){
                    delPointNum += 2;
                    break;
                }
            }
            for(int i = 0; i < pointCount - 1; i++){     //�ҳ����Ϊ1�Ķ��������Ķ���   
                if(edgeArray[i][0] == delPoint + 1) {delPoint = edgeArray[i][1]; break;}
                if(edgeArray[i][1] == delPoint + 1) {delPoint = edgeArray[i][0]; break;}
            }
            for(int i = 0; i < pointCount - 1; i++){     //�����Ϊ1�Ķ��������Ķ���Ϊ���ģ�ɾ������������·��           
                if(edgeArray[i][0] == delPoint || edgeArray[i][1] == delPoint){   
                    int point;
                    point = edgeArray[i][0] - 1;
                    pointLigature[point]--;
                    point = edgeArray[i][1] - 1;
                    pointLigature[point]--;
                    edgeArray[i][0] = 0;
                    edgeArray[i][1] = 0;
                }
            }
        }
        if(delPointNum >= pointCount) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
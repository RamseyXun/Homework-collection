#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std; 
char keys[11];
char flag[11];//��ʾ��һ���Ƿ��Ѿ��������
char line[101];//����
char plaintext[101];//����
void Decrypt(){//���� 
    int i,index,column, count,keysLength, lineLength;
    char c;
    memset(flag, 0, sizeof(flag));
    lineLength=strlen(line);//�������ַ���
    keysLength=strlen(keys);//����
    count=lineLength/keysLength;
    plaintext[lineLength]=0;
    
    //�ҳ���С��ĸ 
    for(column=0;column<keysLength;column++){
        c='Z'+1;
        for(i=0;i<keysLength;i++)
            if(flag[i]==0 && keys[i]<c)
                c=keys[i],index=i;
        flag[index]=1;
        for(i=0;i<count;i++){
            //���ĵĵ�index��
            plaintext[keysLength*i + index]=line[count*column+i];
        }
    }    
}
int main(){
    while(1){
        gets(keys);
        if(strcmp(keys,"THEEND")==0) break;
        gets(line);
        Decrypt();
        printf("%s\n", plaintext);
    }
}               
#include"process.h"
void process::Introduce(){
	system("color 2");
	cout<<"Welcome to use this easy calculator maked by zjw."<<endl;
	cout<<"This calculator is  support '+'��'-'��'*'��'/' ��'(' and ')'."<<endl; 
	cout<<"You can input a expression less than 1000 character."<<endl;
	cout<<"Your input can include decimal whose  decimal digits aren't more than 16."<<endl;
	cout<<"The result can be 1000 digits."<<endl<<endl;
	cout<<"Please input \"ON\" to start the calculator or input \"OFF\" to quit the program."<<endl;
	string str;
	while (1){
		cin>>str;
		if (str=="OFF"||str=="off")exit(0);
		if (str=="ON"||str=="on")return;
		cout<<"Your input is  illegal,please input a correct expression."<<endl;
	}
}
int process::check(){//�жϱ��ʽ�Ƿ�Ϸ� 
    int m=0;
    int label=1,point_count;//0Ϊ���� 1Ϊ+-*/,2Ϊ(��3Ϊ) 
    int kuo=0; 
    char ss[1010];
    memset(ss,0,sizeof(ss));
    while (s[st]==' ')st++; 
    if(s[st]=='-')s[--st]='0'; 
    rep(i,st,len){
        int j; 
        if(s[i]!=' '){
            if (s[i]>='0'&&s[i]<='9'){ 
                if (!label)return 0;//��������֮���������,�Ƿ� 
                if (label==3)return 0;//�����ź���ֱ�Ӹ����� 
                j=i-1;point_count=0; 
                while (j+1<=len&&((s[j+1]>='0'&&s[j+1]<='9')||s[j+1]=='.')){
                    ss[++m]=s[++j];//ȡ���ǿո��ַ� 
                	if (s[j]=='.')point_count++;
                	if (point_count>1)return 0;//һ���������һ���� 
				}
                label=0;i=j;
            }
            else if (s[i]=='+'||s[i]=='*'||s[i]=='/'){
                if(label==1||label==2)return 0;//����������������ߣ������������Ƿ� 
                ss[++m]=s[i];
                label=1;
            }
            else if (s[i]=='-'){
            	if (label==1)return 0;
            	if (label==2)ss[++m]='0';
				ss[++m]=s[i];
				label=1; 
			}
            else if (s[i]=='('){
			    kuo++;
				if (ss[m]=='('){
					ss[++m]='0';ss[++m]='+';
					label=1;
				}
				if (label!=1)return 0;
				ss[++m]=s[i];
				label=2; 
            }
            else if (s[i]==')'){
            	kuo--;
            	if (kuo<0)return 0;
            	if (label==1)return 0;// )ǰ����Ϊ����� 
            	if (label==2){
            		ss[++m]='0';ss[++m]='+';
            		ss[++m]='0';label=3;
				}
				ss[++m]=s[i];
			}
			else return 0;//�Ƿ��ַ� 
		}
    } 
    if (label==1)return 0;//������ַ����Ƿ� 
    if (kuo!=0)return 0;
    len=m;
    memcpy(s,ss,sizeof(ss));
    return 1;
}
void process::printstack(int step){
	cout<<"Step"<<step<<":"<<endl;
	cout<<"operator stack: "<<operators<<endl;
	cout<<"operand stack: "<<operand<<endl;
	
}
void process::deletenum(){
	if (operand=="")return;
	int len=operand.length();
	for (int i=len-1;i>=0;i--)
		if (s[i]==' '){
			operand.erase(i,len-i);
			return;
		}
	operand="";
}
void process::work(){//������ʽ��ֵ����׺���ʽת��׺���ʽ���� 
    while (!q1.empty())q1.pop();
    while (!q2.empty())q2.pop();	
	int cnt=0;
    operators=operand=""; 
    cout<<"process:"<<endl;
    operators+="#";
    q2.push('#');
    string str;
    rep(i,1,len){
        if(s[i]>='0'&&s[i]<='9'){
            int j=i-1;str="";
            while (j+1<=len&&((s[j+1]>='0'&&s[j+1]<='9')||s[j+1]=='.')){
                str+=s[++j];
            }
            q1.push(Bignum(str));//ȡ������ֱ�ӽ�ջ 
            printstack(++cnt);
            cout<<"input character: "<<str<<endl;
            cout<<"operation: push "<<str<<endl;
            operand=operand+" "+str;
            i=j;
        }
        else {
            if (f[s[i]]>f[q2.top()]){
				q2.push(s[i]);//��ǰ��������ȼ�����ջ����������ȼ�ֱ�ӽ�ջ 
			    printstack(++cnt);
			    cout<<"input character: "<<s[i]<<endl;
            	cout<<"operation: push "<<s[i]<<endl;
            	operators+=s[i];
            }
            else {//���򲻶ϳ�ջ����֪��ջ����������ȼ�С�ڵ�ǰ��������ȼ� 
            	if (s[i]=='('){
					q2.push(s[i]);
					printstack(++cnt);
					cout<<"input character: "<<s[i]<<endl;
					cout<<"operation: push "<<s[i]<<endl;
					operators+=s[i];
            	}
            	else if (s[i]==')'){
            		if (q2.top()=='('){
            			q2.pop();
            			printstack(++cnt);
            			cout<<"input character: "<<s[i]<<endl;
						cout<<"operation: pop "<<s[i]<<endl;
						operators.erase((operators.length())-1,1);
            			continue;
					}
            		do{
            			
                    	Bignum ret1=q1.top();q1.pop();
                    	Bignum ret2=q1.top();q1.pop();
                    	Bignum ret3=calc(ret2,q2.top(),ret1);
                    	q1.push(ret3);
						printstack(++cnt);
						cout<<"input character: "<<s[i]<<endl;
						cout<<"operation: pop "<<q2.top()<<" and push "
							<<transform(ret2)<<q2.top()<<transform(ret1)<<endl;
                    	if (q2.top()=='/'&&ret1==zero){//��������Ϊ 0
            				cout<<"The divisor can not be zero"<<endl; 
            				return;
						}
                    	q2.pop();
                    	operators.erase((operators.length())-1,1);
                    	deletenum();
						deletenum();
						operand+=" ";operand+=transform(ret3);
                	}while(q2.top()!='(');
                	printstack(++cnt);
                	cout<<"operation: pop "<<q2.top()<<endl;
                	operators.erase((operators.length())-1,1);
					q2.pop();
            	}
            	else {
                	do{
                    	Bignum ret1=q1.top();q1.pop();
                    	Bignum ret2=q1.top();q1.pop();
                    	Bignum ret3=calc(ret2,q2.top(),ret1);
                   		q1.push(ret3);
						printstack(++cnt);
						cout<<"input character: "<<s[i]<<endl;
						cout<<"operation: pop "<<q2.top()<<"and push "
							<<transform(ret2)<<q2.top()<<transform(ret1)<<endl;
                    	if (q2.top()=='/'&&ret1==zero){//��������Ϊ 0
            				cout<<"The divisor can not be zero"<<endl; 
            				return;
						}
                    	q2.pop();
                    	operators.erase((operators.length())-1,1);
                    	deletenum();
						deletenum();
						operand+=" ";operand+=transform(ret3); 
                	}while(f[q2.top()]>=f[s[i]]);
                	printstack(++cnt);
                	cout<<"operation: push "<<s[i]<<endl;
                	operators+=s[i];
                	q2.push(s[i]);
            	}
			}
        }
    }
    while (q2.top()!='#'){//ʣ�µļ��� 
            Bignum ret1=q1.top();q1.pop();
           	Bignum ret2=q1.top();q1.pop();
           	Bignum ret3=calc(ret2,q2.top(),ret1);
           	q1.push(ret3);
			printstack(++cnt);
			cout<<"input character: "<<endl;
			cout<<"operation: pop "<<q2.top()<<" and push "
			<<transform(ret2)<<q2.top()<<transform(ret1)<<endl;
  			if (q2.top()=='/'&&ret1==zero){//��������Ϊ 0
 				cout<<"The divisor can not be zero"<<endl; 
 				return;
			}
  			q2.pop();
    		operators.erase((operators.length())-1,1);
     		deletenum();
			deletenum();
			operand+=" ";operand+=transform(ret3); 
    }
    printstack(++cnt);
    cout<<"input character: "<<endl;
    cout<<"The operator stack is empty,the calculation is finished."<<endl;
    cout<<"The result of your expression is:"<<endl;
    q1.top().Print();
}
void process::start(){
	f['#']=-1;
	f['(']=1;f[')']=0;
    f['+']=2;f['-']=2;
    f['*']=3;f['/']=3; f['%']=3;//��������������ȼ��������д���� 
    Introduce();
	getchar();	
	system("cls");
	system("color 3");
    while (1){  
    	cout<<"Please input your expression or input \"OFF\" to quit the program:"<<endl;
        gets(s+1);
        len=strlen(s+1);st=1;
        if (len==3&&(s[1]=='O'||s[1]=='o')&&(s[2]=='F'||s[2]=='f')
			&&(s[3]=='F'||s[3]=='f'))break;
        if (!check())
			cout<<"Your input is  illegal,please input a correct expression."<<endl;
        else {
        	system("cls");
        	printf("The expression you input:\n%s\n\n",s+1);
			work();
        }
        cout<<endl;
    }
}
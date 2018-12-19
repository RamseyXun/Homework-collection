#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
class MyString{

	public:
    	MyString(const char*);
   	 	MyString(int = 0, char = '\0');  //initialize size_t number of char, terminated with '\0'
   	 	MyString(const MyString&);  //copy constructor
    	~MyString();  //destructor
    	const char* c_str(); //return private char*
    	static int getNumberOfObjects();
	private:
    	char *str;
    	static int numberOfObjects;//count the number of MyString objects

};
MyString::MyString(const char *s){//���캯������str��ʼ��Ϊs
    str=new char[strlen(s)+1];//ע�ⳤ�Ȳ�û�н�������\0�����ڣ����Ҫ+1����ͬ 
    strcpy(str,s);
    ++numberOfObjects;
}
MyString::MyString(int n, char ch){//���캯������str��ʼ������Ϊn���ַ�����ch 
    str=new char[n+1];
    for(int i=0;i<n;i++)str[i]=ch;
    str[n]='\0';
    ++numberOfObjects;
}
MyString::MyString(const MyString &s){//�������캯��������ǰ�����ʼ���������sһ�� 
    str=new char[strlen(s.str)+1];
    strcpy(str,s.str);
    ++numberOfObjects;
}
MyString::~MyString() {//�����������ͷſռ䣬ͬʱ����ǰ������-1 
    delete [] str;
    --numberOfObjects;
}
const char *MyString::c_str() {//����˽�г�Աstr 
    return str;
}
int MyString::getNumberOfObjects() {//����Ŀǰ�ж��ٸ�MyString���� 
    return numberOfObjects;
}
int MyString::numberOfObjects=0;//��̬���ݳ�Ա��ʼ�� 
int main(){
       MyString ms1(5, 'c');
       cout << ms1.c_str() << endl;
       MyString *ptr_ms2 = new MyString("Hello!");
       {
       		MyString ms3(ms1);
       }
       cout << ptr_ms2->c_str() << endl;
       delete ptr_ms2;
       cout << MyString::getNumberOfObjects() << endl;
       
       MyString ms4(30, 'd');
       cout << ms4.c_str() << endl;
       MyString *ptr_ms5 = new MyString("Accept!");
       {
       		MyString ms6(ms4);
       		cout<<ms6.c_str()<<endl; 
       }
       cout << ptr_ms5->c_str() << endl;
       delete ptr_ms5;
       cout << MyString::getNumberOfObjects() << endl;
       
	   return 0;
}
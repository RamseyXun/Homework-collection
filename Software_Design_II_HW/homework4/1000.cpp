#include<string>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class MyInteger
{
  private:
    int value;
  public:
    MyInteger(int);
    int getValue()const;
    bool isEven()const;
    bool isOdd()const;
    bool isPrime()const;
    static bool isEven(int);
    static bool isOdd(int);
    static bool isPrime(int);
    static bool isEven(const MyInteger&);
    static bool isOdd(const MyInteger&);
    static bool isPrime(const MyInteger&);
    bool equals(int)const;
    bool equals(const MyInteger&)const;
    static int parseInt(const string&);
};
MyInteger::MyInteger(int value){//���캯������ʼ��value��ֵ 
    this->value=value;
}
int MyInteger::getValue()const{//�õ�value��ֵ 
    return value;
}

bool MyInteger::isEven(int value){//�ж��Ƿ���ż�� 
    if (value%2==0)return true;
    else return false;
}
bool MyInteger::isEven()const{
    return isEven(value);
}
bool MyInteger::isEven(const MyInteger & myInteger){
    return myInteger.isEven();
}

bool MyInteger::isOdd(int value){//�ж��Ƿ������� 
    //ͨ�������ж�ż���ķ����ж�������ʡȴ�˷��������жϵ��鷳 
	return !isEven(value);
}
bool MyInteger::isOdd()const{
    return isOdd(value);
}

bool MyInteger::isOdd(const MyInteger & myInteger){
    return myInteger.isOdd();
}
bool MyInteger::isPrime(int value){
    if (value<2) return false;//С��2�Ķ��������� 
    if (value==2) return true;;//ע����������2 
    for (int i=2;i<=sqrt(value);i++){
        if (value%i==0){
            return false;
        }
    }
    return true;
}
bool MyInteger::isPrime()const{//�ж����� 
    return isPrime(value);
}

bool MyInteger::isPrime(const MyInteger & myInteger){
    return myInteger.isPrime();
}

bool MyInteger::equals(int value)const{//�ж���� 
    if (this->value==value)return true;
    else return false;
}
bool MyInteger::equals(const MyInteger & myInteger)const{
    if (value==myInteger.value)return true;
    else return false;
}

int MyInteger::parseInt(const string& str){//���ַ���ת����value 
    return atoi(str.c_str());
}           
int main(){
	MyInteger myint(10);
	cout<<myint.getValue()<<endl;
	cout<<myint.isEven()<<endl;
	cout<<myint.isOdd()<<endl;
	cout<<myint.isPrime()<<endl;
	cout<<endl;
	cout<<myint.isEven(-5)<<endl;
	cout<<myint.isOdd(-5)<<endl;
	cout<<myint.isPrime(-5)<<endl;
	cout<<myint.isPrime(97)<<endl;
	cout<<endl;
	MyInteger others(13);
	cout<<myint.equals(10)<<endl;
	cout<<myint.equals(others)<<endl;
	cout<<myint.parseInt("1234")<<endl;
}    
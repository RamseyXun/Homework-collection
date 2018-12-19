#include<iostream>
using namespace std;
class Complex //������
{
	public:
		Complex(double real = 0, double imag = 0);
		Complex operator+(Complex& com); 
		Complex operator-(Complex& com);
		Complex operator*(Complex& com);
		Complex operator/(Complex& com);
		double& operator[](int i); 
		double operator[](int i) const;
		friend ostream& operator<<(ostream& os, Complex& com);//��Ԫ����������ȡ�����"<<"
		friend istream& operator>>(istream& is, Complex& com);//��Ԫ�������ز��������">>"
	private:
		double real;//ʵ��
		double imag;//����
};
Complex::Complex(double real,double imag){//���캯������ʼ����ǰ�����real��imag 
	this->real=real;
	this->imag=imag;
}
Complex Complex::operator+(Complex &com){//���������+ 
	Complex tmp;
	tmp.real=real+com.real;
	tmp.imag=imag+com.imag;
	return tmp;
}
Complex Complex::operator-(Complex &com){//���������- 
	Complex tmp;
	tmp.real=real-com.real;
	tmp.imag=imag-com.imag;
	return tmp;
}
Complex Complex::operator*(Complex &com){//���������* 
	Complex tmp;
	//(a+bi)*(c+di)=(ac-bd)+(ad+bc)i;
	tmp.real=real*com.real-imag*com.imag;
	tmp.imag=real*com.imag+imag*com.real;;
	return tmp;
}
Complex Complex::operator/(Complex& com){//���������/ 
    //(a+bi)/(c+di)=[(ac+bd)+(bc-ad)i]/(c^2+d^2) 
    Complex tmp;
	double div = (com.real*com.real)+(com.imag*com.imag);
    tmp.real = ((real*com.real)+(imag*com.imag))/div;
    tmp.imag = ((imag*com.real)-(real*com.imag))/div;
    return tmp;
}
double& Complex:: operator[](int i){//���������ţ�����ֵ������ֵ 
    if (!i)return real;
    else return imag;
}
double Complex:: operator[](int i) const{//���������ţ�����ֵ��������ֵ 
    if (!i)return real;
    else return imag;
}
ostream& operator<<(ostream& os, Complex& com){//��Ԫ����������ȡ�����"<<" 
    if (com.real==0&&com.imag==0)os<<0;//ʵ�����鲿��Ϊ0 
    else {//ʵ�����鲿����Ϊ0 
    	if (com.real!=0)os<<com.real;//
    	if (com.real!=0&&com.imag>0)os<<'+';//�鲿Ϊ����ʱҪ��+�� 
    	if (com.imag!=0&&com.imag!=1&&com.imag!=-1)os<<com.imag;//ע���鲿����ֵΪ1ʱ�������1 
    	if (com.imag!=0){
    		if (com.imag==-1)os<<'-';//�鲿Ϊ-1������ǰ��û���-1�����Բ�һ��-�� 
    		os<<'i';
		}
	}
    return os;
}
istream& operator>>(istream& is, Complex& com){//��Ԫ�������ز��������">>" 
    is >> com.real>> com.imag;
    return is;
}
int main(){
	int T;
	cin >> T;
	while (T--) {
		Complex com1, com2;
		cin >> com1;
		cout << com1 << endl;
		cout << com1[0] << " " << com1[1] << endl;
 
		cin >> com2;
		cout << com2 << endl;
		cout << com2[0] << " " << com2[1] << endl;
 
		Complex c1 = com1 + com2;
		cout << "(" << com1 << ")+(" << com2 << ")=" << c1 << endl;
 
		Complex c2 = com1 - com2;
		cout << "(" << com1 << ")-(" << com2 << ")=" << c2 << endl;
 
		Complex c3 = com1 * com2;
		cout << "(" << com1 << ")*(" << com2 << ")=" << c3 << endl;
 
		Complex c4 = com1 / com2;
		cout << "(" << com1 << ")/(" << com2 << ")=" << c4 << endl;
	}
    return 0;
}
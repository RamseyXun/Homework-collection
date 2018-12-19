#include <iostream>
using namespace std;
class Point{
	public:
    	Point();
    	Point(double xv, double yv);
    	Point(Point& pt);
    	double getx();
    	double gety();
	private:
    	double x,y;
};
Point::Point(){//�޲ι��캯�� 
	x=y=0;
}
Point::Point(double xv,double yv){//�вι��캯�� 
	x=xv;
	y=yv;
}
Point::Point(Point& pt){//�������캯�� 
	x=pt.x;
	y=pt.y;
}
double Point::getx() {//��ȡx���� 
    return x;
}
double Point::gety() {//��ȡy���� 
    return y;
}
class Circle:public Point {
	public:
    	Circle();
    	Circle(double xv, double yv, double rv);
    	Circle(Circle& c);
    	int position(Point &pt);
    private:
    	double r;
};
 
Circle::Circle():Point(){//�޲ι��� 
	r=0;
}
Circle::Circle(double xv,double yv,double rv):Point(xv,yv){//�вι��캯�� 
	r=rv;
}
 
Circle::Circle(Circle& c):Point(c.getx(),c.gety()){//�������캯�� 
	r=c.r;
}
int Circle::position(Point& pt) {//�жϵ��Ƿ���Բ�� 
    double dx=pt.getx()-getx();
    double dy=pt.gety()-gety();
    double diff=dx*dx+dy*dy-r*r;
    if (diff>0)return 1;//��Բ�� 
    else if (diff < 0)return -1;//԰�� 
    else return 0;//Բ�� 
} 
class Rectangle:public Point {
	public:
    	Rectangle();
    	Rectangle(double xv, double yv, double wv, double hv);
    	Rectangle(Rectangle& r);
    	int position(Point& pt);
	private:
        double w,h;
};
Rectangle::Rectangle():Point(){//�޲ι��� 
	w=h=0;
}
Rectangle::Rectangle(double xv, double yv, double wv, double hv):Point(xv,yv){
	w=wv;//�вι��� 
	h=hv;
}
Rectangle::Rectangle(Rectangle& r):Point(r.getx(),r.gety()){
	w=r.w;//�������� 
	h=r.h;
}
int Rectangle::position(Point& pt) {
    double dx=pt.getx()-getx();//�Ƚ�������任 ���Ծ������½�Ϊԭ�� 
    double dy=pt.gety()-gety();
    if (dx>0&&dx<w&&dy>0&&dy<h)return -1;//������ 
    else if ((dx==0||dx==w)&&dy>=0&&dy<=h)return 0;//������ 
    else if ((dy==0||dy==h)&&dx>=0&&dx<=w)return 0;//������ 
    else return 1;//������ 
}
int main()
{
    Circle cc1(23, 45, 6);
    Rectangle rt1(-88, -21,123,144);
    Point p1(0, 0);
    cout << "point p1:";
    switch (rt1.position(p1))
    {
    case 0:cout << "on-rectangle" << endl; break;
    case -1:cout << "inside-rectangle" << endl; break;
    case 1:cout << "outside-rectangle" << endl; break;
    }
    switch (cc1.position(p1))
    {
    case 0:cout << "on-circle" << endl; break;
    case -1:cout << "inside-circle" << endl; break;
    case 1:cout << "outside-circle" << endl; break;
    }
    return 0;
}
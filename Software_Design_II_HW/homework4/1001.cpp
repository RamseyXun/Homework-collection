#include <iostream>
#include <map>
using namespace std;
class Position {
 public:
         int x;
         int y;
};
class Robot {
public:
         Robot(); /* default constructor, initialize at (0,0) */
         Robot(Position pos);/* initialize at pos */
         void Move(char Dir); 
		 /* Dir could be 'N', 'E', 'S', 'W', 
		 for other characters, the robot don��t move */
         Position GetPosition();/* return current position */
private:
         Position currentPos;
};
Robot::Robot(){
    currentPos.x=currentPos.y=0;//������λ�ó�ʼ��Ϊ(0,0) 
}
Robot::Robot(Position pos){
    currentPos=pos;//������λ�ó�ʼ��Ϊpos 
}
void Robot::Move(char Dir){
    if (Dir=='N')currentPos.y++;//N�������߼�������+1 
    else if (Dir=='E')currentPos.x++;//E�������߼�������+1 
    else if (Dir=='W')currentPos.x--;//W�������߼�������-1 
    else if (Dir=='S')currentPos.y--;//S�������߼�������-1 
}
Position Robot::GetPosition(){
    return currentPos;//���ص�ǰ���� 
}            
int main() {
    Position c;
    c.x = 0;
    c.y = 1;
    Robot a;
    cout << a.GetPosition().x << ' ' << a.GetPosition().y << endl;
    Robot b( c );
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    b.Move('E');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    b.Move('N');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    b.Move('W');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    b.Move('S');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;

    b.Move('s');
    cout << b.GetPosition().x << ' ' << b.GetPosition().y << endl;
    return 0;
}    
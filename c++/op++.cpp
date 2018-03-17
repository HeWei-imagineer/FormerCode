#include <iostream>
#include <cmath>
using namespace std;
class Point
{
   public:
       Point( int a= 0, int b = 0 ):x(a),y(b) {  }
       friend ostream& operator<<(ostream&out,const Point&p);
       double operator-(Point&p);
  private:
        int x, y;	// 平面坐标
};
ostream& operator<<(ostream&out,const Point&p)
{
    out<<"["<<p.x<<","<<p.y<<"]";
    return out;
}
double Point::operator-(Point&p)
{
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}
int main()
{
  Point p1(2,1),p2;
double d = p1-p2;   //计算两点距离
cout<<p1<<"；"<< p2<< " = "<<d<<endl;  // 输出 [2,1] → [0,0] = 2.23
  return 0;
}

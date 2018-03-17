#include <iostream>
#include<math.h>
using namespace std;

class circle;
class point
    {
    private:
        double x,y;
    public:
        point(double xx=0,double yy=0):x(xx),y(yy){}
       //friend bool circle::judge(point p1);
        double distance(point p1)
        {
            return sqrt(p1.x*p1.x+p1.y*p1.y);
        }
        void print()
        {
            cout<<"("<<x<<","<<y<<")"<<",";
        }
    };
class circle
{
private:
    point center;double radium;static float pi;
public:
     bool judge(point p1);
    circle( double ra=1.0);
    circle(double xx,double yy,double ra);

    double area()
    {
        return pi*radium*radium;
    }
    void print()
    {
        center.print();
        cout<<"r="<<radium<<endl;
    }
};

float circle:: pi=3.14159;
circle::circle(double ra):center(){radium=ra;}
circle::circle(double xx,double yy,double ra):center(xx,yy){radium=ra;}


bool circle::judge(point p1)
{
    if(p1.distance(p1) <= radium )
        return true;
    else
        return false;

}

 int main()
{
    circle cc[3]={circle(1,2,3.3),circle(3)};
    for(int i=0;i<3;i++)
    {
        cout<<"cc["<<i<<"]"<<":";
        cc[i].print();

    }
  cout <<cc[0].area()<<endl;
  point p1(1,2);
  if(cc[0].judge(p1))
  {
      cout<<"p1 on cc[0]"<<endl;
  }
   else
   {
       cout<<"p1 not on cc[0]"<<endl;
   }

    return 0;
}

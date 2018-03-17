#include <iostream>
#include<cstring>
using namespace std;
class shape
{
public:
    shape(){cout<<"construct shape"<<endl;}
    void show(){cout<<"м╪пн"<<endl;}

};
class point2D
{
private:
    double x,y;
public:
    point(double m,double n):x(m),y(n){}
    void print()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};
class point3D:public point2D
{
private:
    double z;
public:
    point(double m,double n,double r):point2D(m,n)x(m),y(n){}
    void print()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};
class Towshape:public shape
{
private:
    char*name;

public:
    point d1;
    void show()
    {
        cout<<name<<endl;
        d1.print();
    }
    Towshape(const char* n=0,int xx=0,int yy=0):d1(xx,yy)
    {
        if(n)
        {
            name=new char[strlen(n+1)];
            strcpy(name,n);
        }
        else
        {
            name=new char[5];
            strcpy(name,"null");
        }
        cout<<"construct 2"<<endl;
    }
  virtual  double getArea();
  virtual  double getC();
};
class Threeshape:public shape
{
private:

    char*name;
public:
    point d1;
    void show()
    {
        cout<<name<<endl;
        d1.print();
    }
    Threeshape(const char *n=0,int x=0,int y=0):d1(x,y)
    {
        if(n)
        {
            name=new char[strlen(n+1)];
            strcpy(name,n);
        }
        else
        {
            name=new char[5];
            strcpy(name,"null");
        }
        cout<<"construct 3"<<endl;
    }
  virtual  double getS();
  virtual  double getV();
};

class circle:public Towshape
{
private:
    char *name;
    double radium;
public:
    static double Pi;
    void show()
    {
        cout<<name<<":"<<"边长"<<radium;
        d1.print();
    }
    circle(const char *n,double a,int xx,int yy):Towshape(n,xx,yy),radium(a)
    {if(n)
        {
            name=new char[strlen(n+1)];
            strcpy(name,n);
        }
        else
        {
            name=new char[5];
            strcpy(name,"null");
        }cout<<"construct circle"<<endl;
    }
double getArea();
double getC();
};
double circle::Pi=3.14;
double circle::getC()
{
    return 2*Pi*radium;
}
double circle::getArea()
{
    return Pi*radium*radium;
}

class cube:public Threeshape
{
private:
    char*name;
    double a;
public:
    void show()
    {
        cout<<name<<":"<<"边长"<<a;
        d1.print();
    }
    cube(char*n,double s,int xx,int yy):Threeshape(n,xx,yy),a(s)
    {
        if(n)
        {
            name=new char[strlen(n+1)];
            strcpy(name,n);
        }
        else
        {
            name=new char[5];
            strcpy(name,"null");
        }cout<<"construct cube"<<endl;

    }

double getS();
double getV();
};
double cube::getS()
{
    return 6*a*a;
}
double cube::getV()
{
    return a*a*a;
}
int main()
{
    shape * a[2];
    circle c1("圆",2.0,1,1);
    cube c2("正方体",2.0,2,2);
    a[0]=&c1;
    a[1]=&c2;

    for(int i=0;i<2;i++)
    {
       cout<<a[i].show()<<endl;
    }
    return 0;
}

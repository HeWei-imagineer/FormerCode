#include <iostream>
#include<cstring>
using namespace std;
class person
{
protected:
    char*name;
    int number;
public:
   ~person(){delete []name;}
   person(const char*n,int m):number(m)
   {
      if(n)
      {
        name=new char[strlen(n)+1];
        strcpy(name,n);
      }
      else
      {
        name=new char[5];
        strcpy(name,"null");
      }
    }
    virtual void show(){cout<<name<<"__"<<"number:"<<number<<endl;}
};

class manager:public person
{
    static int money;
public:
    manager(const char*n,int m):person(n,m){}
    void show(){cout<<name<<"__"<<"number:"<<number<<"__money:"<<money<<endl;}
};
int manager::money=800;

class technic:public person
{
    int hour;
public:
    technic(const char*n,int m,int h):person(n,m),hour(h){}
    void show(){cout<<name<<"__"<<"number:"<<number<<"__money:"<<get_salary()<<endl;}
    int get_salary(){return hour*100;}
};

class saleman:public person
{
    int total;
public:
    saleman(const char*n,int m,int t):person(n,m),total(t){}
    int get_salary(){return(total*0.04);}
    void show(){cout<<name<<"__"<<"number:"<<number<<"__money:"<<get_salary()<<endl;}
};

class sm:public person
{
int total;
public:
    sm(const char*n,int m,int t):person(n,m),total(t){}
    int get_salary()
    {
        return (5000+total*0.05);
    }
    void show(){cout<<name<<"__"<<"number:"<<number<<"__money:"<<get_salary()<<endl;}
};
int main()
{
person*p[4];
manager m1("Q",001);technic t1("W",002,3);saleman s1("T",003,1000);sm sm1("K",004,5000);
p[0]=&m1;
p[1]=&t1;
p[2]=&s1;
p[3]=&sm1;
for(int i=0;i<4;i++)
{
    p[i]->show();
}
return 0;
}

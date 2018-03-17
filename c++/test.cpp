#include <iostream>
#include<cstring>
using namespace std;
class  B
{
public : int  b ;
    B ()const;
    virtual void print(){cout<<"this is b"<<endl;}
} ;
B::B(){b=0;}
class  B1 : virtual public  B
{

public:

      void print(){cout<<"this is b1"<<endl;}
} ;
class  B2 : virtual public  B
{
public:
       void print(){cout<<"this is b2"<<endl;}
} ;
class D: public  B1 , public  B2
{
    public:int d ;
    int get(){return d;}
    void print(){cout<<"this is d"<<endl;}
} ;
class E:virtual public D
{
    int e;
    int get(){return e;}
    void print(){cout<<"this is e"<<endl;}
};


int main()
{

    E e;D d;
    B*p1=&d;
    B*p2=&e;
    p1->print();
    p2->print();
   cout<<sizeof(d)<<endl;
   cout<<sizeof(e)<<endl;

    return 0;
}

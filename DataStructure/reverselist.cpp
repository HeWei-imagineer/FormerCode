#include <iostream>
#include "linelist.h"
#include "doublelist.h"
//using namespace std;

int main()
{
    int A[6]={3,1,5,0,8,6},B[6]={1,1,2,3,5,6};
    sequence<int> s(6,A);
    int k1=8,k2=4,k3=6;
    std::cout<<s.delsmall()<<std::endl;
    s.del(k1);
    s.delAtoB(k2,k3);
    for(int i=0;i<6;i++)
    {
        std::cout<<s.getarr(i)<<" ";
    }

    Note a(1);Note b(4);Note c(5);Note d(8);
    alist s1;int sum=0;float avg;Note*p;
    s1.addtail(d);
    s1.addtail(c);
    s1.addtail(b);
    s1.addtail(a);
    alist s2(s1);
    s2.sot();
    p=s2.head;
    while(p->next)
    {
        p=p->next;
        sum+=p->a;
    }
    //cout<<sum<<endl;
 /*   avg=(float)sum/s2.n;
    cout <<"最大值："<<p->a<<endl<<"节点个数: "<<s1.n<<endl<<"平均值："<<avg;


//链表倒序

     cout<<"s1:"<<endl;
     s1.show();
     invertedOrder(s1);
     cout<<"inverted order s1:"<<endl;
     s1.show();*/

    //链表有序合并
    alist s3,s4;
    Note e(0);Note f(2);Note g(6);Note h(9);
    s3.addtail(h);
    s3.addtail(g);
    s3.addtail(f);
    s3.addtail(e);
    s4=s3.ordermerge(s1);
    s4.sot();
    s4.show();
    return 0;
}

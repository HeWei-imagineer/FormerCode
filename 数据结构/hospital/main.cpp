#include <iostream>
#include"treeToForest.h"
using namespace std;


int main()
{
    char*p1="hospital";
    char*p2="floor";
    char*p3="room";
    char*p4="bed";
    HosNode h1(1,p1);
    HosNode h2(2,p2);
    HosNode h3(5,p3);
    HosNode h4(2,p4);
    Tree t1;
    t1.Insert(p1,&h2);
    t1.Insert(p2,&h3);
    t1.Insert(p3,&h4);
    t1.WithTraverse(t1.getroot());
    cout<<t1.icount(p1,p4)<<endl;
    t1.Parent(&h4)->print()<<endl;
    t1.Find(p2)->print();

    return 0;
}

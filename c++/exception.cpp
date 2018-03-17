//ch8_7.cpp
#include <iostream>
#include<cstring>
using namespace std;
// 数组越界类
class A
{
public:
    const int b;
    A():b(3){}
    int getA(int a);
};
int A::getA(int a){return a;}
int main()
{

    A s;
    cout<<s.getA(2);
    return 0;
}


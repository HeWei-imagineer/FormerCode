#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class String { // 注：为方便大家理解，类实现并非按照STL中string实现
private:
	char *str;
public:
	String(char*pn);// 构造函数
	int length(); // 返回字符串长度
	void display(); // 打印字符串以及长度，例如 hello 5
	void pop_back(); // 删除字符串末尾一个字符
	void push_back(char c); // 向字符串末尾添加一个字符
	String substr(int m, int n); // 返回当前字符串的子字符串，从下标start开始，长度为length
	~String() {delete[] str;}
	String(String&pn);
};
    String::String( char*pn)
{
     if(pn)
    {
    str=new char[strlen(pn)+1];
    strcpy(str,pn);
    }
    else
    str=new char[5];
    strcpy(str,"空字符串");
}
    String::String( String&p)
{
    if(p)
    {
    str=new char[5];
    strcpy(str,"空字符串");
    }

    else
    {
    str=new char[strlen(p)+1];
    strcpy(str,p);
    }
}
    int String::length(){return strlen(str);}
    void String::display()
{
    cout<<str<<";"<<strlen(str)<<endl;
}
    void String::pop_back()
{
    char *p;int i;
    p=str;
    for(i=0;i<strlen(str);++i,p++)
    {
        if(*p='/0')
        *(p--)='/0';
    }

}
    void String::push_back(char c)
{
    char *p;int i;
    p=new char[strlen(str)+2];
    strcpy(p,str);
    delete[]str;
    for(i=0;i<strlen(str)+1;++i,p++)
    {
        if(*p='/0')
        *p=c;
    }
        *p='/0';
    for(i=0;i<strlen(str)+1;++i,p--)
    str=p;
}
    String String::substr(int m,int n)
{
    String a;
    int i;char *star,*p;
    if(n>m)
    {
    p=str;
    for(i=0;i<m;i++,p++);
    star=new char[n-m+2];strcpy(star,p);
    for(i=m;i<n+1;i++,p++);
    *p='/0';
    strcpy(a.str,star);
    return a;
    }

}
int main() {
	String s1("hello");
	String s2 = s1;
	s1.display();// 构造测试，结果 hello 5（换行），以下类比
	s2.display();// 构造测试
	s1.push_back('w');
	s1.display();// push_back()函数功能测试
	s2.pop_back();
	s2.display();// pop_back()函数功能测试
	s1.substr(1, 2).display();// substr()函数功能测试
	String s3 = s2.substr(1, 4).substr(2, 1);
    s3.display();// 鲁棒性测试
	s3.pop_back();
	s3.display();// 鲁棒性测试
	system("pause");
	return 0;
}

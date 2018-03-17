#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class String { // ע��Ϊ��������⣬��ʵ�ֲ��ǰ���STL��stringʵ��
private:
	char *str;
public:
	String(char*pn);// ���캯��
	int length(); // �����ַ�������
	void display(); // ��ӡ�ַ����Լ����ȣ����� hello 5
	void pop_back(); // ɾ���ַ���ĩβһ���ַ�
	void push_back(char c); // ���ַ���ĩβ���һ���ַ�
	String substr(int m, int n); // ���ص�ǰ�ַ��������ַ��������±�start��ʼ������Ϊlength
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
    strcpy(str,"���ַ���");
}
    String::String( String&p)
{
    if(p)
    {
    str=new char[5];
    strcpy(str,"���ַ���");
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
	s1.display();// ������ԣ���� hello 5�����У����������
	s2.display();// �������
	s1.push_back('w');
	s1.display();// push_back()�������ܲ���
	s2.pop_back();
	s2.display();// pop_back()�������ܲ���
	s1.substr(1, 2).display();// substr()�������ܲ���
	String s3 = s2.substr(1, 4).substr(2, 1);
    s3.display();// ³���Բ���
	s3.pop_back();
	s3.display();// ³���Բ���
	system("pause");
	return 0;
}

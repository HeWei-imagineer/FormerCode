#include <iostream>
#include<cstring>
using namespace std;
class date
{
private:
    int year,month,day;
public:
    date(int y,int m,int d):year(y),month(m),day(d){}
    void show(){cout<<year<<"/"<<month<<"/"<<day;}
};

class Publication
{
public:
    char* name;
    ~Publication(){delete [] name;}
     Publication(const char*n);
     virtual void show(){cout<<"publication"<<endl;}
};
Publication::Publication(const char*n)
{
    if(n)
       {name=new char[strlen(n)+1];
        strcpy(name,n);}
    else
        {name=new char[5];
         strcpy(name,"null");}
}
class newspaper:public Publication
{
private:
    date d;
public:
    newspaper(const char* n,int y,int m,int d):d(y,m,d),Publication(n){}
    void show()
    {
        d.show();
        cout<<name<<endl;
    }
};


class book:public Publication
{
private:
    char*writer;
public:
    ~book(){delete [] writer;}
    book(const char* n,const char* w);
    void show(){cout<<name<<":"<<writer<<endl;}
};

book::book(const char* n,const char* w):Publication(n)
{
  if(w)
  {
    writer=new char[strlen(w)+1];
    strcpy(writer,w);
   }
  else
    {
      writer=new char[5];
      strcpy(writer,"null");
    }
}

class magzine:public Publication
{
private:
    date c;
    int number;
public:
    magzine (const char* n,int y,int m,int d,int i):c(y,m,d),Publication(n),number(i){}
    void show()
    {
        c.show();
        cout<<name<<":"<<"��"<<number<<"��"<<endl;
    }

};
class Library
{
public:
     int total;                //ʵ�ʹݲ���
private:
    Publication * publications[100];  //���йݲأ�����ݲ�����Ϊ100

    public:
   // Library(){publications=new Publication strlen(Publication); }
    void add(Publication & p);      //����¹ݲأ��˺�������ɣ�
    void show()
      {                 //������йݲص���Ӧ��Ϣ
        for(int i=0;i<total;i++)
        {
             publications[i]->show();
        }

      }
};
	 //�˺���������������йݲص���Ӧ��Ϣ
     // �磺    C++   zhengli
     //         Thames     2010/1/1
     //         DuZhe      2011/5/1  ��10��
     //ע�ⲻͬ���������������ͬ�������Ϣ��
//int Library::total=0;

void Library::add(Publication&p)
{
    total=0;
    publications[total]=&p;
    total++;
}



int main()
{
    book b1("c++","Zhengli");newspaper m1("Thames",2010,1,1); magzine n1("DuZhe",2011,5,1,10);
    Publication* p[3]={&b1,&m1,&n1};
    Library l1;


    for(int i=0;i<3;i++)
    {
        l1.add(*p[i]);
        l1.show();
    }

    return 0;
}

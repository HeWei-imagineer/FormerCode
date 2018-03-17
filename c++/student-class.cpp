#include <iostream>
#include<cstring>
using namespace std;
class date
{
    private:
        int year,month,day;
    public:
        date(int m=8,int d=3,int y=2013);

        void print()
        {
            cout<<month<<"/"<<day<<"/"<<year<<endl;
        }
    };
date::date(int m,int d,int y):month(m),day(d),year(y){}
class Stu
{
private:
    int id; date roll; char* name;
public:
    static int number;
    Stu( char*pn,date roll1);
    Stu( char *pn,int m=8,int d=3,int y=2013);
    int getnum(){return number;}
    void show()
    {
        cout<<name<<":"<<id<<","<<endl;
        roll.print();
    }
};
int Stu::number=0;

Stu::Stu(char *pn,date roll1):roll(roll1)
{
   ++number;
   id=number;
   if(name)
   {
      name=new char(strlen(pn)+1);
      strcpy(name,pn);
   }

   else
   {
      name=new char[6];
      strcpy(name,"ssdut");
   }

}
Stu::Stu(char *pn,int m,int d,int y):roll(m,d,y)
{
   ++number;
   id=number;
   if(name)
    {
        name=new char(strlen(pn)+1);
        strcpy(name,pn);
    }

   else
   {
         name=new char[6];
        strcpy(name,"ssdut");
   }

}


int main()
{
    date d1,d2;
    Stu s0("S1", 8,3,1);
    Stu s1("S2", d1);
    Stu s2("S3");
    Stu s[3]={s0, s1, s2};
    Stu("S1", 8,3,1);

    s[1].show();
    cout<<Stu::number;
    return 0;
}
//http://pan.baidu.com/s/1i3XV9yt

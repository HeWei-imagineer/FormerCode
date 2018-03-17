#include <iostream>
#include<cstring>
using namespace std;


class teacher;
class student
{
private :
    char*name;char*major;char* number;
    teacher* t;
public:
    student(char*na,char*ma,char* n);
    teacher* get(){return t};
    void print()
    {
        cout<<name<<"/"<<major<<"/"<<number<<endl;
    }
    ~student()
    {
        delete []name;delete []major;delete []number;
    }

};
student::student(char*na,char*ma,char* n,teacher*t)
{
    (t.i)++;
    if(na)
    {
        na=new char[strlen(na+1)];
        strcpy(name,na);
    }
    else
    {
         na=new char[5];
        strcpy(name,"null")
    }
     if(ma)
    {
        na=new char[strlen(ma+1)];
        strcpy(major,ma);
    }
    else
    {
         na=new char[5];
        strcpy(major,"null")
     }
     if(n)
    {
        n=new char[strlen(n+1)];
        strcpy(number,n);
    }
    else
    {
         na=new char[5];
        strcpy(name,"null")
}
    };

class teacher
   {
      private:
          char*Name;char*direction;
          int i;

      public:
           teacher(char*na,char*dir,int i1=0 );
           ~teacher()
           {
               delete[]Name;delete[]direction;
           }
           void show()
           {
               cout<<Name<<":"<<direction<<i<<endl;
           }

};
teacher::teacher(char*na,char*dir,int i1):i(i1)
{
    if(na)
    {
        na=new char[strlen(na+1)];
        strcpy(Name,na);
    }
    else
    {
         na=new char[5];
        strcpy(Name,"null");
    }
    if(dir)
    {
        dir=new char[strlen(dir+1)];
        strcpy(direction,dir);
    }
    else
    {
         dir=new char[5];
        strcpy(direction,"null");
   }

}
int main()
{
    teacher tea[3]={teacher("li","math",1),teacher("xi","En",1),teacher("han","Ch",1)};
    student stu[3]={student("hh","math","201",&tea[1]),student("qq","en","202",&tea[0]),student("aa","ch","203",&tea[2])};
   for(int k=0;k<3;k++)
   {
       for(int j=0;j<3;j++)
    {
        if((stu[j].get)==&tea[k])
        stu[j].print;
    }
    tea[k].show();
   }
return 0;
    }


}

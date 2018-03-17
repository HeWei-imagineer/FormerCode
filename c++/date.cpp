#include <iostream>

using namespace std;

class date
{
    private:
       int year,month,day;
    public:
        int static i;

      date(int y=0,int m=0,int d=0)
      {
          year=y;month=m;day=d;
      }

      void boolset(int y,int m,int d);//并对该时间的有效性进行检测

      void charge();//判断该日期是一年的第几天
};
int date::i=1;
void date::boolset(int y,int m,int d)
{

    int c[7]={4,6,9,11,0,0,0}, f[7]={1,3,5,7,8,10,12};
    year=(y>=1&&y<=9999)?y:0;
    month=(m>=1&&m<=12)?m:0;
if(month==0||year==0)
{
        i=0;
    cout<<"wrong date"<<endl;
}

else
{
    if((year%4==0&&year%100!=0)||(year%400==0))
    {
        if(month==2){day=(d>=1&&d<=29)?d:0;}

        else
        {
            for(int j=0;j<7;j++)
            {
            if(month==c[j]){day=(d>=1&&d<=30)?d:0;}
            if(month==f[j]){day=(d>=1&&d<=31)?d:0;}
            }
        }
    }
    else
     {
         if(month==2){day=(d>=1&&d<=28)?d:0;}

         else
            {
             for(int j=0;j<7;j++)
             {
             if(month==c[j]){day=(d>=1&&d<=30)?d:0;}
             if(month==f[j]){day=(d>=1&&d<=31)?d:0;}
             }

            }

     }

}


if(day==0)
{
    i=0;
    cout<<"wrong date"<<endl;
}

else{cout<<month<<"/"<<day<<"/"<<year<<endl;}


}

void date::charge()
{
        int j=0,k;
        int a[12]={30,28,31,30,31,30,31,31,30,31,30,31};
        int b[12]={30,29,31,30,31,30,31,31,30,31,30,31};

        if((year%4==0&&year%100!=0)||(year%400==0))
        {
            for(k=0;k<month;k++)
            j+=b[k];
        }
        else
        {
             for(k=0;k<month;k++)
              j+=a[k];
        }
        j=j+day;
        cout<<"该日期是"<<j<<endl;

    }

int main()
{
date date1(2015,6,31);
date1.boolset(2015,6,31);

  if(date1.i)
    {
        date1.charge();
    }



    return 0;
}


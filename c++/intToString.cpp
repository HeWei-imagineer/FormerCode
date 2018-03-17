#include <iostream>
#include<cstring>
using namespace std;

    /*整数转化成字符串*/
void intToString( long num, char str[], int n)
{
    char temp[20];
    int i,j;
    for(i=0;i<n;i++)
    {
        temp[i]=(num%10)+'0';
        num=num/10;
    }
    i--;
    for(j=0;j<n;j++,i--)
    {
        str[j]=temp[i];
    }
    str[j]=0;
}

long strToInt( char str[], int n)
{
   int i;
   long k=0;
   char temp[20];
    for(i=0;i<n;i++)
    {
        switch(str[i])
        {
        case '一':
            temp[i]=1;break;
        case '二':
            temp[i]=2;break;
        case '三':
            temp[i]=3;break;
        case '四':
            temp[i]=4;break;
        case '五':
            temp[i]=5;break;
        case '六':
            temp[i]=6;break;
        case '七':
            temp[i]=7;break;
        case '八':
            temp[i]=8;break;
        case '九':
            temp[i]=9;break;
      default :break;
        }
        temp[i]=0;

    }
    cout<<temp<<endl;
   for(i=0;i<n;i++)
   {
       k=k*10+(temp[i]-'0');

   }
   return k;
}
int main()
{
    char str[20];
    intToString(12345,str,5);
    cout<<str<<endl;
    char s[]="一万两千三百四十五";
    cout<<strToInt( s, 6)<<endl;
    cout<<s;
    return 0;
}

#include <iostream>
#include<cstring>
using namespace std;

    /*����ת�����ַ���*/
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
        case 'һ':
            temp[i]=1;break;
        case '��':
            temp[i]=2;break;
        case '��':
            temp[i]=3;break;
        case '��':
            temp[i]=4;break;
        case '��':
            temp[i]=5;break;
        case '��':
            temp[i]=6;break;
        case '��':
            temp[i]=7;break;
        case '��':
            temp[i]=8;break;
        case '��':
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
    char s[]="һ����ǧ������ʮ��";
    cout<<strToInt( s, 6)<<endl;
    cout<<s;
    return 0;
}

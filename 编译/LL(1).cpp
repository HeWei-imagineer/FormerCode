#include <iostream>
#include<cstring>
using namespace std;

void First(char*p[],int n)
{
    char*ss[n];//每条记录的第一个非终结符
    char*first[n];//记录下每条记录的第一个字母，
    int flag[n];//是否可生成空字符串
    int k1=0,k2=0;

    //记录下每条记录的第一个字母，以及第一个非终结符
    for(int i=0;i<n;++i)
    {
        int length=strlen(p[i]);
        ss[i]=new char[length];//记录每条记录右部可能的第一个字母
        for(int j=0;j<length;j++)
        {   //记录终结符
            if((33<=p[i][j]&&p[i][j]<=64)||(91<=p[i][j]&&p[i][j]<=126))
               {
                   ss[i][k1++]=p[i][j];
               }
            else if('ε'==p[i][j])
            {
              flag[i]=1;
            }
            else
            {

            }
        }
        k1=0;
    }

    for(int i=0;i<n;++i)
    {
      int length=strlen(p[i]);
     for(int j=0;j<length;j++)
     {
         switch(p[i][j])
            {
            case'->': case'|':
                first[i][k2++]=p[i][j+1];
                if(65<=p[i][j+1]&&p[i][j+1]<=90)//默认只有大写字母为非终结符
                {
                 while((65<=p[i][j+1]&&p[i][j+1]<=90)||('|'!=p[i][j++])||('\0'!=p[i][j]))//找出所有开头非终结符
                {
                    for(int k=0;k<n;k++)
                    {
                        if(p[i][j]==p[k][0]&&flag[k]==1)
                        {
                           first[i][k2++]=p[i][j];
                        }
                    }
                }
                if(flag[i]!=1&&(p[i][j]=='|')||(p[i][j]=='\0'))
                {
                   first[i][k2++]='ε';
                }

                }

                break;


            default:
                cout<<"输入有误"<<endl;

            }

     }
        k2=0;


    }

   for(int i=0;i<n;i++)
   {
       k1=0;
       while(first[i][k1]!=0)
      {
          for(int j=0;j<n;j++)
          {
              if(p[i][0]==first[i][k1])
              {
                  cout<<"First:"<<p[i][0]<<":"<<ss[i]<<endl;
              }
          }

      }

   }

}
int main()
{
    char*p[7]={
       "A->BCDE",
       "B->aBA|ε",
       "C->F|ε",
       "D->b|c|ε",
       "E->e|ε",
       "F->d|ε"
    };
    First(p,7);



    cout << "Hello world!" << endl;
    return 0;
}

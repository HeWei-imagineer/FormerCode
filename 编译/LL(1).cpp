#include <iostream>
#include<cstring>
using namespace std;

void First(char*p[],int n)
{
    char*ss[n];//ÿ����¼�ĵ�һ�����ս��
    char*first[n];//��¼��ÿ����¼�ĵ�һ����ĸ��
    int flag[n];//�Ƿ�����ɿ��ַ���
    int k1=0,k2=0;

    //��¼��ÿ����¼�ĵ�һ����ĸ���Լ���һ�����ս��
    for(int i=0;i<n;++i)
    {
        int length=strlen(p[i]);
        ss[i]=new char[length];//��¼ÿ����¼�Ҳ����ܵĵ�һ����ĸ
        for(int j=0;j<length;j++)
        {   //��¼�ս��
            if((33<=p[i][j]&&p[i][j]<=64)||(91<=p[i][j]&&p[i][j]<=126))
               {
                   ss[i][k1++]=p[i][j];
               }
            else if('��'==p[i][j])
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
                if(65<=p[i][j+1]&&p[i][j+1]<=90)//Ĭ��ֻ�д�д��ĸΪ���ս��
                {
                 while((65<=p[i][j+1]&&p[i][j+1]<=90)||('|'!=p[i][j++])||('\0'!=p[i][j]))//�ҳ����п�ͷ���ս��
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
                   first[i][k2++]='��';
                }

                }

                break;


            default:
                cout<<"��������"<<endl;

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
       "B->aBA|��",
       "C->F|��",
       "D->b|c|��",
       "E->e|��",
       "F->d|��"
    };
    First(p,7);



    cout << "Hello world!" << endl;
    return 0;
}

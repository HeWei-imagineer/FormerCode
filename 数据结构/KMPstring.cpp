#include <iostream>
#include<cstring>
using namespace std;

//�����ַ�������������,���ģʽ���ƶ���λ��
int* Next(char*p)
{
    int m=strlen(p);
    int k;//kΪ��ǰѰ��λǰһλ���ǰ׺λ��
    int* N=new int[m];
    N[0]=0;
    for(int i=1;i<m;i++)//��������Ѱ�ң���jλǰ���ǰ׺k&&p[j]==p[k]
    {
        k=N[i-1];
        if(k==0&&p[i]==p[0])
        {
           N[i]=1;
        }

        else if(k==0&&p[i]!=p[0])
        {
            N[i]=0;
        }

        else
        {
            while(k>0)
         {
           if(p[i]==p[k]){N[i]=k+1;break;}
           else{k=N[k-1];}
         }
         if(k==0&&p[i]==p[0])
         {
            N[i]=1;
         }
         if(k==0&&p[i]!=p[0]){ N[i]=0;}


        }



    }
return N;
}
//�ַ���KMP�㷨
int KMPStrMatching(char*p,char*t,int*N)
{
    int i=0,j=0;//iΪĿ�괮�±꣬jΪģʽ���±�
    while(t[i]!='\0'&&p[j]!='\0')
    {
        if(p[j]==t[i])
        {
           ++j;++i;
        }
        else
        {
            if(j==0){++i;//��λ��û���ǰ׺�Ӵ�}
            else
            {
                j=N[j-1];//����������������������ַ����ƶ���
            }
        }
    }
    if(p[j]=='\0'){return 0;}
    else{return -1;}
}

//��ģʽ������λ�õ��㷨
int kKMPStrMatching(char*p,char*t,int*N,int*M)
{
    int m=-1,i=0,j=0;
    int k=strlen(p);
    while(t[i]!='\0')
    {
        if(p[j]=='\0')
        {
            ++i;j=0;
            M[++m]=i-k;
        }
        if(p[j]==t[i])
        {
           ++j;++i;
        }
        else
        {
            if(j==0){++i;}
            else
            {
                j=N[j-1];
            }
        }
    }
    if(p[j]=='\0'){M[++m]=i-k+1;return 0;}
    else{return -1;}
}

int NativeStrMatching(const char*t,const char*p)
{
    int i=0,j=0;
    for(int k=0;k<strlen(t)-strlen(p);k++)
    {
        i=k;
         while(p[j]!='\0')
    {
        if(t[i]==p[j])
        {
            ++i;++j;
        }
        else{j=0;break;}
    }
    if(p[j]=='\0')
    {
        return 1;
    }
    }
    return -1;

}

int strcomp(char*s1,char*s2)
{
    int i=-1;
    while(s1[++i]!='\0'&&s2[++i]!='\0')
    {
        if(s1[i]>s2[i])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    if(s1[i]!='\0'&&s2[i]=='\0')
    {
        return 1;
    }
    if(s1[i]=='\0'&&s2[i]!='\0')
    {
        return -1;
    }
     return 0;
}
int main()
{
    char *t="substrsestr";
    char *p="str";
    cout<<"�Ƚ��ַ�����"<<endl;
    cout<<strcomp(p,t)<<endl;
    int *n;
    int m[10];
    n=Next(p);
    cout<<"���ģʽ��������������"<<endl;
    for(int i=0;i<strlen(p);i++)
    {
        cout<<n[i]<<" ";
    }
    cout<<endl;
   kKMPStrMatching(p,t,n,m);
   cout<<"ģʽ����Ŀ�괮�е�λ�ã�"<<endl;
   for(int i=0;i<3;i++)
    {
        cout<<m[i]<<" ";
    }
     cout<<endl;
    cout<<"�򵥵��ַ���ƥ���㷨��"<<endl;
    cout<<NativeStrMatching(t,p)<<endl;
    return 0;
}

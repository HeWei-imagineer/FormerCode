#include <iostream>
#include<cstring>
using namespace std;

//计算字符串的特征向量,标记模式串移动的位置
int* Next(char*p)
{
    int m=strlen(p);
    int k;//k为当前寻找位前一位的最长前缀位数
    int* N=new int[m];
    N[0]=0;
    for(int i=1;i<m;i++)//分两部分寻找，第j位前的最长前缀k&&p[j]==p[k]
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
//字符串KMP算法
int KMPStrMatching(char*p,char*t,int*N)
{
    int i=0,j=0;//i为目标串下标，j为模式串下标
    while(t[i]!='\0'&&p[j]!='\0')
    {
        if(p[j]==t[i])
        {
           ++j;++i;
        }
        else
        {
            if(j==0){++i;//该位置没有最长前缀子串}
            else
            {
                j=N[j-1];//这里很厉害，体现了灵活的字符串移动。
            }
        }
    }
    if(p[j]=='\0'){return 0;}
    else{return -1;}
}

//带模式串出现位置的算法
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
    cout<<"比较字符串："<<endl;
    cout<<strcomp(p,t)<<endl;
    int *n;
    int m[10];
    n=Next(p);
    cout<<"输出模式串的特征向量："<<endl;
    for(int i=0;i<strlen(p);i++)
    {
        cout<<n[i]<<" ";
    }
    cout<<endl;
   kKMPStrMatching(p,t,n,m);
   cout<<"模式船在目标串中的位置："<<endl;
   for(int i=0;i<3;i++)
    {
        cout<<m[i]<<" ";
    }
     cout<<endl;
    cout<<"简单的字符串匹配算法："<<endl;
    cout<<NativeStrMatching(t,p)<<endl;
    return 0;
}

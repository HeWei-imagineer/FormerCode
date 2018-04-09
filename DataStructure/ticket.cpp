#include <iostream>
using namespace std;
//最大波动
void maxNum()
{
    int *p;
    int n,k1=0,k2=0;
    cin>>n;
    p=new int[n];
    cin>>p[0];
    for(int i=1;i<n;++i)
    {
        cin>>p[i];
        k1=(p[i]-p[i-1])<0?0-(p[i]-p[i-1]):(p[i]-p[i-1]);
        k2=k2>k1?k2:k1;
    }
    cout<<k2;
    delete[]p;
}

//火车购票
void print(int i,int n,int j)//i为记录每排剩余座位数组的下表，j为购买的票数
{
    int m=(i*5+(5-n+1));
    for(int k=0;k<j;++k)
    {
        cout<<m<<" ";
        ++m;
    }
    cout<<endl;

}

void setMan()
{
    int p[20];//标记每排剩余座位数
     for(int i=0;i<20;++i)
    {
       p[i]=5;
    }
    int k;
    int*s;//记录输入指令
    cin>>k;
    s=new int[k];
    for(int i=0;i<k;++i)
    {
       cin>>s[i];
    }
    int n=0;//记录当前排数

    for(int i=0;i<k;++i)
    {
        int j;
        for(j=0;j<n;++j)
        {
            if(p[j]>s[i]||p[j]==s[i])
         {
            print(j,p[j],s[i]);
            p[j]-=s[i];
            break;
         }

        }
        if(n==j)
        {
            if(p[n]>s[i]||p[n]==s[i])
          {
              print(n,p[n],s[i]);
              p[n]-=s[i];
           }
        else
        {
            ++n;
            print(n,p[n],s[i]);
            p[n]-=s[i];
        }

        }

    }
}


int main()
{
    //maxNum();
    setMan();
    return 0;
}

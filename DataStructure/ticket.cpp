#include <iostream>
using namespace std;
//��󲨶�
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

//�𳵹�Ʊ
void print(int i,int n,int j)//iΪ��¼ÿ��ʣ����λ������±�jΪ�����Ʊ��
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
    int p[20];//���ÿ��ʣ����λ��
     for(int i=0;i<20;++i)
    {
       p[i]=5;
    }
    int k;
    int*s;//��¼����ָ��
    cin>>k;
    s=new int[k];
    for(int i=0;i<k;++i)
    {
       cin>>s[i];
    }
    int n=0;//��¼��ǰ����

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

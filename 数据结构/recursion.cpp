#include <iostream>

using namespace std;
int fibonacci(int n)
{
    if(n==1||n==2){
        return 1;
    }
    else if(n>2){
        return fibonacci(n-1)+fibonacci(n-2);
    }
}


void comb(int n,int k,int a[],int m)//mΪ���ÿһ��ѡ��������
{
    //��k����ѡ��֮���������
    if(k==0)
    {
        for(int j=0;j<m;++j)
            cout<<a[j];
        cout<<"  ";
    }
    else
    {
        //ÿһ��ѭ�������δӸò�ѡ������������ѡ�����ܳ��ֵ���
        for(int i=n;i>=k;--i)
        {
            a[m]=i;
            comb(i-1,k-1,a,m+1);
        }

    }
}
//24����Ϸ
void recursion(int n,int k,int a[],int m,int n)
{

    if(m==k)
    {
        int b[m];
        for(int i=0;i<m;i++)
        {
            b[i]=a[i];
        }
        for(int j=0;j<4;j++)
        {
            switch(j)
            {
            case 0:
                b[n-2]=b[n-1]+b[n-2];break;
            case 1:
                b[m-3]=b[m-2]-b[m-1];break;
            case 2:
                b[m-3]=b[m-2]*b[m-1];break;
            case 3:
                b[m-3]=b[m-2]/b[m-1];break;
            }
        }

    }
    else
    {
        for(int i=0;i<k;i++)
            a[m]=i;
        recursion(n,k,a,++m)
    }
}

int main()
{
    int n,k,m=0;
    int a[200];
    recursion(8,4,a,m);
    return 0;
}

#include <iostream>

using namespace std;

bool FindValue(int*A,int n,int x)
{
    for(int i=0;i<n;i++)
    {
         if(A[n]==x)
        return true;
    else
        return false;
    }

}

void BubbleSort(int* A,int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
       for(j=0;j<n-i-1;j++)
       {
          if(A[j]>A[j+1])
          {
              k=A[j];
              A[j]=A[j+1];
              A[j+1]=k;
          }

       }
    }
}

int Count(int* A,int n)
{
    int i,k=1;
    int arr[n];
    for(i=0;i<n;i++)
    {
       arr[i]=A[i];
    }
    BubbleSort(arr,n);
    for(i=0;i<n-1;i++)
    {
       if(arr[i]!=arr[i+1])
        k++;
    }
    return k;
}

void Merge(int *A,int m1,int *B,int m2,int*C)
{
    int i,j;
    for(i=0;i<m1;i++)
    {
        C[i]=A[i];
    }
    for(i=m1,j=0;i<m1+m2;j++,i++)
    {
        C[i]=B[j];
    }
    BubbleSort(C,m1+m2);
}
double compute(double a,double b,char c)
{
    int i=c+1;
    switch(i){
        case 44:
        return (a+b);break;
        case 46:
        return (a-b);break;
        case 43 :
        return(a*b);break;
        case 48 :
            if(b==0){
                cout<<"´íÎó£º³ýÊýÎªÁã"<<endl;
                return 0;
            }
            else{
                 return (a/b);
            }
            break;
        default:
            cout<<"³¬³öÔËËã·¶Î§"<<endl;
          return 0;break;

    }
}
int main()
{
   int A[6]={4,8,1,9,3,0},B[6]={0,0,4,9,9,10},C[6]={1,5,8,9,9,22},D[12];
   BubbleSort(A,6);
   for(int i=0;i<6;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<Count(B,6)<<endl;
    cout<<endl;
    Merge(B,6,C,6,D);
    for(int i=0;i<12;i++)
    {
        cout<<D[i]<<" ";
    }

    cout<<endl;
    cout<<compute(2.1,0,'/');


    FindValue(A,6,9);
    return 0;
}

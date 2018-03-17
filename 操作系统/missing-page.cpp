#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

int arr[]={3,4,3,2,6,3,5,6,4,3,4,2};
int flag[10];
int n;
int num=0;//缺页次数

void breakOff(int m)
{
    cout<<"---------------发生缺页----------"<<endl;
    cout<<"缺页数："<<m<<endl;
}


void FIFO()
{
    queue<int> q;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(j<3)
        {
            if(flag[arr[i]]==0)
            {
                breakOff(arr[i]);
                q.push(arr[i]);
                j++;
                flag[arr[i]]=1;
                num++;
            }

        }
        else
        {
            if(flag[arr[i]]==0)
            {
               breakOff(arr[i]);
               int num2=q.front();
               flag[num2]=0;
               q.pop();
               q.push(arr[i]);
               flag[arr[i]]=1;
               num++;
            }

        }

    }

    cout<<"缺页率："<<(float)(num)/n;

}
int maxFlag(int*arr)
{
    int m=0;
    int k;
    for(int i=0;i<3;i++)
    {
        if(flag[arr[i]]>m)
        {
            m=flag[arr[i]];
            k=i;
        }

    }
    return k;
}
int findMax(int*arr)
{
    int m=0;
    int k;
    for(int i=0;i<3;i++)
    {
        if(arr[i]>m)
        {
            m=arr[i];
            k=i;
        }

    }
    return k;

}
//向前看
void LRU()
{
   int alist[3]={-1,-1,-1};
   int icount=0;
   for(int i=0;i<n;i++)
   {
       if(icount<3)
       {
           if(flag[arr[i]]==0)
           {
               breakOff(arr[i]);
               alist[icount++]=arr[i];
               flag[arr[i]]=1;
               num++;
           }
            else{
                flag[arr[i]]=1;
            }
       }
       else
       {
           if(flag[arr[i]]==0)
           {
               breakOff(arr[i]);
               int rm=maxFlag(alist);
               flag[alist[rm]]=0;
               alist[rm]=arr[i];
               flag[arr[i]]=1;
               num++;
           }
            else{
                flag[arr[i]]=1;
            }

       }
       for(int i=0;i<3;i++)
       {
           if(alist[i]!=-1)
           flag[alist[i]]++;
       }
   }
   cout<<"缺页率："<<(float)(num)/n;
}
void OPT()
{
   int alist[3]={-1,-1,-1};
   int icount=0;
   for(int i=0;i<n;i++)
   {
       if(icount<3)
       {
           if(flag[arr[i]]==0)
           {
               breakOff(arr[i]);

               alist[icount++]=arr[i];
               flag[arr[i]]=1;
               num++;
           }
       }
       else
       {
           if(flag[arr[i]]==0)
           {
               breakOff(arr[i]);
               int record[3]={-1,-1,-1};
               int k=1;
               for(int j=i;j<n;j++)
               {
                   if(alist[0]==arr[j]&&record[0]==-1)
                   {
                       record[0]=k++;
                   }
                   if(alist[1]==arr[j]&&record[1]==-1)
                   {
                       record[1]=k++;
                   }
                   if(alist[2]==arr[j]&&record[2]==-1)
                   {
                       record[2]=k++;
                   }
                   if(k==4)
                   {
                       break;
                   }

               }
               k=-1;
               for(int i=0;i<3;i++)
               {
                   if(record[i]==-1){
                    k=i;break;
                   }
               }
               if(k!=-1){
                flag[alist[k]]=0;
                alist[k]=arr[i];
                flag[arr[i]]=1;

               }
               else{
                k=findMax(record);
                flag[alist[k]]=0;
                alist[k]=arr[i];
                flag[arr[i]]=1;
               }
               num++;

           }

       }

   }
   cout<<"缺页率："<<(float)(num)/n;
}
int main()
{
    n=12;

    for(int i=0;i<10;i++)
    {
        flag[i]=0;
    }
   /* cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }*/
    //FIFO();
    //LRU();
   OPT();
    cout << "Hello world!" << endl;
    return 0;
}

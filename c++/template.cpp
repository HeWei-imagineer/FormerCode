#include <iostream>
#include<cstring>

using namespace std;
template<typename T>

T mini(T* arr,int n)
{
    int i=0;
   T m=arr[i];
    for(i=0;i<n;i++)
    {
        if(arr[i]<m)
            m=arr[i];
    }
    return m;
}
template<>const char* mini(const char*arr[],int n)
{
    int i=0;
    const char *a=arr[i];
    for(i=0;i<n;i++)
    {
        if(strcmp(arr[i],a)<0)
        a=arr[i];
    }
    return a;

}
int main()
{
int a[ 10 ] = { 1,3,5,7,9};
double d[3] = {-1.1, -2.2, -3.3};
const char* name[]= {"linda","lelele","linlin"};
cout<<mini(a,5)<<endl;
cout<<mini(d,3)<<endl;
cout<<mini(name,3)<<endl;
}



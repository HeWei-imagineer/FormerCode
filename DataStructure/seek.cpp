#include <iostream>
#include"dichotomy_find.h"
using namespace std;

int main()
{
    int a[6]={4,2,7,4,6,9};
    //fold_insert(a,6);
    //order_insert(a,6);
    //int b[6];
    //mergeSort(a,0,5,b);
    //ShellSort(a,6);
    int **p;
    p=buid_link(a,6);

    for(int i=0;i<6;++i)
    {
        for(int j=0;j<6;++j)
        {
             cout<<p[i][j]<<" ";
        }
       cout<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}

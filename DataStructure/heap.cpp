#include <iostream>
#include "Heap.h"
using namespace std;

int main()
{
	const int n=10;
	int a[11]={0,20,12,35,15,10,80,30,17,2,1};
	int b[5]={5,2,6,3,4};
    Heap<int> h(100);

	//通过插入建立堆
	h.Insert(14);
	h.Insert(15);
	h.Insert(2);
	h.Insert(10);
	h.Insert(20);
	int i,len,x;
	len=h.Size();

	for(i=1;i<=len;i++)
	{
	    h.DeleteTop(x);
	    cout<<x<<' ';
	}
	cout<<endl;
	h.Initialize(a,10); //初始化堆
	len=h.Size();

	for(i=1;i<=len;i++)
	{
	    h.DeleteTop(x);
	    cout<<x<<' ';
	}

    h.print();
	return 0;
}

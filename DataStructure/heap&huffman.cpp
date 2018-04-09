#include <iostream>
#include"miniHeap.h"

using namespace std;

int main()
{
    int arr[10]={20,12,35,15,10,80,30,17,2,1};
    minHeap<int>heap(arr,9,9);
    heap.buildheap();
    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
}

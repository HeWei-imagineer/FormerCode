#include<iostream>
using namespace std;

//声明类模板
template< typename T >
class  Array
{
 public :
    void BubbleSort(T* arr, int n);
    Array ( int s=0 ) ;
	virtual ~ Array () ;
    T& get( int index );
    void set( int index, const T & value ) ;
    T& isearch(int i);
    T& operator==(T&a);
    T& operator<(T&a);
	T& operator[](int i);
	friend ostream& operator<<(ostream& out, Array<T>& a );
    T * element;
 protected :
    int size ;
} ;

//类模板成员函数
template<typename T>
Array<T>::Array(int s)
{
    if(s <0)
    {
		cout << "argument error" << endl;
		s=0;
	}
	size = s;
	if(s)
	   element = new T[size];
	else
		element = 0;
}

template < typename T >
Array < T > :: ~Array()
{
	if(element)
		delete [] element ;
}

template < typename T >
T& Array < T > :: get ( int index )
{
	return  element [ index ] ;
}

template < typename T >
void Array < T > :: set(int index, const T& value)
{
	element [ index ] = value ;
}

template <typename T>
void Array<T>::BubbleSort(T* arr, int n){ // 对arr数组中的n个数据排序
	T temp;
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=n-1;j>i;j--){
			if(arr[j]<arr[j-1]){
				//交换arr[j],arr[j-1]
				temp =arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
			}
		}
}



//类模板的实例化
int main()
{
   Array <int> IntAry1( 5 ), IntAry2( 5 ) ;
   cout << "Integer Array : \n" ;
  for ( int i = 0; i < 5; i ++ )
  {
	  IntAry1.set ( i, i ) ;
	  cout << IntAry1.get(i) << '\t' ;
  }
  IntAry1.BubbleSort(IntAry1.element,5);

   Array <double> dAry( 3 ) ;
   cout << "\nDouble Array : \n" ;
   for (int i = 0; i < 5; i ++ )
   {
	   dAry[i] = (i+1)*0.5  ;
	   cout<<dAry[i]<<endl;
   }


int a[10]={8,1,6,4,2,7,9,3};
   return 0;

}

template < typename T >
T& Array < T > ::operator[](int i)
{
   if(i<0 || i>=size)
   {  i = 0;
	  cout<<"Out of range!";
   }
    return element[i];
}

template < typename T >
 ostream& operator<<(ostream& out, Array<T>& a )
{
   out<<a.size<<" element: ";
   for ( int i = 0; i < a.size; i ++ )
	   out<< *(a.element+i)<<"\t";
   out<<endl;
   return out;
}

template<typename T>
T& Array<T>::operator==(T&a)
{

}

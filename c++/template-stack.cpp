#include <iostream>

using namespace std;
template<typename T>
class istack
{
private:
    T*s;
    int top;
    int imax;
public:
    int gettop(){return top;}
    istack(int n);
    T& push(T a);
    T& pop();
    bool stackempty()
    {
        if(top<imax)
            return true;
        else
            return false;
    }
    ~istack(){if(s)delete[]s;}
};
template<typename T>
istack<T>::istack(int n)
{
    top=0;
    s=new T[imax];
}
template<typename T>
T& istack<T>::push(T a)
{
  if(stackempty())
  {
      s[top]=a;
      top++;
  }
  else
    cout<<"overflow"<<endl;
}
template<typename T>
T&istack<T>::pop()
{
    if(top>0)
    {
        s[top]=0;
        top--;
        return s[top];
    }
    else
    {
      cout<<"reach bottom"<<endl;
    }


}
int main()
{

    istack<int>istack1(10);
    for(int i=0;i<10;i++)
    {
        istack1.push(i);
    }
    cout<<istack1.gettop()<<endl;
    istack1.pop();
    cout<<istack1.gettop()<<endl;
return 0;
}

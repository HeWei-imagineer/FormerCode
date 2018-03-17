#include <iostream>
#include<cstring>
using namespace std;


//ջ��˳��ʵ��
template<typename T>
class arrayStack
{
private:
    int maxSize;
    int top;
    T*st;
public:
    arrayStack(int asize);
    arrayStack();
    ~arrayStack();
    void Clear();
    bool push(const T item);
    bool pop(T& item);
    bool Top(T& item);
    bool isempty();
    bool isfull();
    int gettop()
    {
        return top;
    }
};
template<typename T>
arrayStack<T>::arrayStack(int asize)
{
    maxSize=asize;
    top=-1;
    st=new T[maxSize];
}
template<typename T>
arrayStack<T>::arrayStack()
{
    top=-1;
}
template<typename T>
arrayStack<T>::~arrayStack()
{
   delete [] st;
}

template<typename T>
void arrayStack<T>::Clear()
{
   top=-1;
}
template<typename T>
bool arrayStack<T>::push(const T item)
{
  if(top==maxSize-1){
     cout<<"ջ�����"<<endl;
     return false;
  }

  else{
     st[++top]=item;
     return true;
  }
}
template<typename T>
bool arrayStack<T>::pop(T& item)
{
  if(top==-1){
     cout<<"ջ��"<<endl;
     return false;
  }

  else{
     item=st[top--];
     return true;
  }
}
template<typename T>
bool arrayStack<T>::Top(T& item)
{
  if(top==-1){
     cout<<"ջ��"<<endl;
     return false;
  }

  else{
     item=st[top];
     return true;
  }
}
template<typename T>
bool arrayStack<T>::isempty()
{
  if(top==-1){
     cout<<"ջ��"<<endl;
     return true;
  }

  else{
     return false;
  }
}
template<typename T>
bool arrayStack<T>::isfull()
{
  if(top==maxSize){
     cout<<"ջ��"<<endl;
     return true;
  }

  else{
     return false;
  }
}
//ջ����ʽʵ��
template<typename T>
struct LinkNote
{
public:
    T data;
    LinkNote<T>* link;
    LinkNote(const T& el,LinkNote<T>*ptr=0)
    {
        data=el;
        link=ptr;
    }
};
template<typename T>
class listStack
{
private:
    LinkNote<T>* top;
    int lsize;
public:
    listStack();
    ~listStack();
    void Clear();
    bool push(const T item);
    bool pop(T& item);
    bool Top(T& item);
    bool isempty();
   // bool isfull();
};
template<typename T>
listStack<T>::listStack()
{
    top=NULL;
    lsize=0;
}

template<typename T>
listStack<T>::~listStack()
{
   Clear();
}

template<typename T>
void listStack<T>::Clear()
{
   while(top)
   {
       LinkNote<T>*p=top;
       top=top->link;
       delete p;
   }
   lsize=0;
}
template<typename T>
bool listStack<T>::push(const T item)
{
  LinkNote<T>*p=new LinkNote<T>(item,top);
  top=p;
  lsize++;
}
template<typename T>
bool listStack<T>::pop(T& item)
{
  if(top==NULL){
     cout<<"ջ��"<<endl;
     return false;
  }

  else{
     LinkNote<T>*p=top;
     top=top->link;
     item=top->data;
     delete p;
     return true;
  }
}
template<typename T>
bool listStack<T>::Top(T& item)
{
  if(top==NULL){
     cout<<"ջ��"<<endl;
     return false;
  }

  else{
     item=top->data;
     return true;
  }
}
template<typename T>
bool listStack<T>::isempty()
{
  if(top==NULL){
     cout<<"ջ��"<<endl;
     return true;
  }

  else{
     return false;
  }
}
/*template<typename T>
bool arrayStack<T>::isfull()
{
  if(top==maxSize){
     cout<<"ջ��"<<endl;
     return true;
  }

  else{
     return false;
  }
}
*/
//ʮ������ת��Ϊ��~�Ž���֮�����
int InttransformTwoToNine(int num,int n,int arr[])
{
    arrayStack<int>A(50);
    int k=0,j;//KΪת��������λ��
    if(n>=2&&n<=9)
    {
       while(num/n)
       {
         A.push(num%n);
         num=num/n;
       }
        A.push(num);
    }
      j=A.gettop();
    for(int i=0;i<=j;i++)
    {
        A.pop(arr[i]);
        k++;
    }
    return k;
}
//�ж�(),[],{},�Ƿ����
bool P80_13()
{
    char st[100];
    char c;
    cin>>st;
    arrayStack<char> s1(50);
    for(int i=0;i<strlen(st);i++)
    {
        switch(st[i])
        {
        case '/':
             if(st[i+1]=='*')
             {
                 int k=i+1;
                 while(st[++k]!='\0')
                 {
                     if(st[k]=='*'&&st[k+1]=='/')
                     {
                          i=k+1;break;
                     }

                 }
             }break;
        case '(':
            s1.push('(');break;
        case '[':
            s1.push('[');break;
        case '{':
            s1.push('{');break;
        case ')':
            s1.Top(c);
            if(c=='('){
                s1.pop(c);
               }
            else{
             cout<<"()������Բ���ȷ"<<endl;return false;
              }
            break;
        case ']':
            s1.Top(c);
            if(c=='['){
                s1.pop(c);
               }
            else{
              cout<<"[]������Բ���ȷ"<<endl;return false;
              }
            break;
        case '}':
            s1.Top(c);
           if(c=='{'){
                s1.pop(c);
               }
            else{
              cout<<"{}������Բ���ȷ"<<endl;return false;
              }
            break;
        default:
            break;
        }

    }
    if(s1.isempty()){
        cout<<"���������ȷ"<<endl;return true;
    }

    else{
            s1.Top(c);
           cout<<c<<"  ";
         cout<<"������Բ���ȷ"<<endl;return false;
    }
}


bool judge_palindrome(char*str)
{
   int i=strlen(str);
   int j;
   arrayStack<int>arr(strlen(str)/2);
   for(j=0;j<i/2;j++)
    {
           arr.push(str[j]);
    }
   if((i%2)!=0)
   {
       ++j;
   }

    while(!arr.isempty())
       {
           arr.pop(i);
           if(i!=str[j++])
           {
               cout<<"���ǻ���"<<endl;
               return false;
           }
       }
    cout<<"�ǻ���"<<endl;
               return true;

}


int main()
{
    int arr[10];
    int n;
    n=InttransformTwoToNine(8,3,arr);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

    P80_13();
    judge_palindrome("hahah");
    return 0;
}

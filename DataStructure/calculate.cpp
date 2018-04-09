#include <iostream>
#include<cstring>
using namespace std;
//栈的顺序实现


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
    st=new T(maxSize);
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
     cout<<"栈满溢出"<<endl;
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
     cout<<"栈空"<<endl;
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
     cout<<"栈空"<<endl;
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
     cout<<"栈空"<<endl;
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
     cout<<"栈满"<<endl;
     return true;
  }

  else{
     return false;
  }
}




int string_to_int(char* str)
{
    int i=strlen(str);
    int num=0;
    int n=-1;
    while(str[++n]!=' ')
    {
        num=num*10+(str[n]-'0');
    }
    return num;
}

//字符到数字的转换（利用空格标记），后缀表达式长度不太合理，需要设置“\0”标记字符串结束
//输入字符串有问题
class calculate
{
private:
    char*postfixExp;
    int a[100];
public:
   calculate();
   char* getpostfixExp(){return postfixExp;}
   bool infix_to_suffix();
   double cal_suffix();
   //double cal(double num1,double num2,char op);
};
calculate::calculate()
{
    a['+']=a['-']=2;
    a['*']=a['/']=4;

}
bool calculate::infix_to_suffix()
{
    char InfixExp[100];
    cout<<"输入一个合法的表达式："<<endl;
    cin>>InfixExp;
    postfixExp=new char(strlen(InfixExp));
    int n,m;
    m=-1;n=-1;
    char c;
    arrayStack<char>st(strlen(InfixExp));
    while(InfixExp[++n]!='\0')
    {
        if(InfixExp[n]>=48&&InfixExp[n]<=57)
        {
            postfixExp[++m]=InfixExp[n];
        }
        else
        {
            postfixExp[++m]=' ';
            switch(InfixExp[n])
            {
            case '+':
                st.Top(c);
                while(!st.isempty()&&c!='('&&(a[c]+1)>a['+'])
                {
                    st.pop(c);
                    postfixExp[++m]=c;
                    st.Top(c);
                }
                st.push('+');break;
            case '-':
                st.Top(c);
                while(!st.isempty()&&c!='('&&(a[c]+1)>a['-'])
                {
                    st.pop(c);
                    postfixExp[++m]=c;
                    st.Top(c);
                }
                st.push('-');break;
            case '*':
                st.Top(c);
                while(!st.isempty()&&c!='('&&(a[c]+1)>a['*'])
                {
                    st.pop(c);
                    postfixExp[++m]=c;
                    st.Top(c);
                }
                st.push('*');break;
            case '/':
                st.Top(c);
                while(!st.isempty()&&c!='('&&(a[c]+1)>a['/'])
                {
                    st.pop(c);
                    postfixExp[++m]=c;
                    st.Top(c);
                }
                st.push('/');break;
            case '(':
                st.push('(');break;
            case ')':
                st.pop(c);
                while(c!='(')
                {
                     postfixExp[++m]=c;
                     if(st.isempty()){
                        st.Clear();
                        return false;
                     }
                     st.pop(c);
                }break;
            default:
                return false;
           }
        }

    }
    postfixExp[++m]=' ';
    while(!st.isempty())
    {
       st.pop(c);
        postfixExp[++m]=c;
    }
    postfixExp[++m]='\0';//标记字符串结束
    delete[]InfixExp;
   return true;

}
double calculate::cal_suffix()
{
    int m=-1;
    int n=-1;
    double num1,num2;
    arrayStack<double>arr(strlen(postfixExp));
    char str[strlen(postfixExp)];
    while(postfixExp[++m]!='\0')
    {
        if(postfixExp[m]>=48&&postfixExp[m]<=57)
        {
            str[++n]=postfixExp[m];
        }
        else
        {
            switch(postfixExp[m])
            {
            case ' ':
                str[++n]=' ';
                if(str[0]!=' '){
                    arr.push(string_to_int(str));
                    n=-1;//将字符串清空
                }
                else{
                    n=-1;//将字符串清空，处理表达式中两个符号接连出现的情况
                }
                break;
            case '+':
                arr.Top(num2);
                arr.pop(num2);arr.pop(num1);
                arr.push(num1+num2);break;
            case '-':
                arr.pop(num2);arr.pop(num1);
                arr.push(num1-num2);break;
            case '*':
                arr.pop(num2);arr.pop(num1);
                arr.push(num1*num2);break;
            case '/':
                arr.pop(num2);arr.pop(num1);
                arr.push(num1/num2);break;
            }
        }
    }
    arr.pop(num1);cout<<num1<<" ";
    if(arr.isempty()){
        return num1;
    }
    else{
        cout<<"程序出错"<<endl;
        return 0;
    }
}

int main()
{

    calculate a;
    a.infix_to_suffix();
    int i=-1;
    cout<<"输出相应后缀表达式："<<endl;
    while(a.getpostfixExp()[++i]!='\0')
    {
        cout<<a.getpostfixExp()[i];
    }
    cout<<endl;
    cout<<"输出计算结果："<<endl;
    a.cal_suffix();

    return 0;
}

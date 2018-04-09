#include <iostream>

using namespace std;

//顺序表
template<typename T>
class sequence
{
private:
    T arr[100];
    int n;
public:
    sequence(sequence& s)
    {
        n=s.getn();
        for(int i=0;i<n;i++)
    {
        arr[i]=s.getarr(i);
    }

    }
    sequence(int m,T a[])
    {
        n=m;
        for(int i=0;i<n;i++)
    {
        arr[i]=a[i];
    }

    }
    T& getarr(int i){
        return arr[i];
    }
    int getn(){return n;}
    void sot();
    bool add(int i,T& a);
    //bool del(int i);
    T& delsmall();
    void del(T& a);
    void delAtoB(T& a,T& b);
    T& inser(int i);
    //void alter(int i,T a);
    void alter(T& a,T& b);
    };
template<typename T>
bool sequence<T>::add(int i,T& a)
{
    int j;

    for(j=n;j>=i;j--)
    {
        arr[j]=arr[j-1];
    }
    arr[j]=a;
}
/*template<typename T>
bool sequence<T>::del(int i)
{
    int j;
    for(j=i-1;j<n-1;j++)
    {
        arr[j]=arr[j+1];
    }
}*/
template<typename T>
T& sequence<T>::delsmall()
{
    int i;
    sequence<T> s(*this);
    s.sot();
    this->del(s.getarr(0));
    this->alter(arr[n-1],s.getarr(1));
    return s.getarr(0);
}
template<typename T>
void sequence<T>::del(T& a)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(arr[j]==a)
        arr[j]=0;
    }
}
template<typename T>
void sequence<T>::delAtoB(T& a,T& b)
{
    int j;
    for(j=0;j<n;j++)
    {
        if((arr[j]>=a)&&(arr[j]<=b))
        arr[j]=0;
    }
}
template<typename T>
T& sequence<T>::inser(int i)
{
    if(i>=0&&i<=n)
    {
        return arr[i-1];
    }
    else{
        cout<<"超出线性表范围"<<endl;
        return 0;
    }

}
/*template<typename T>
void sequence<T>::alter(int i,T a)
{
    if(i>=0&&i<=n)
    {
        arr[i-1]=a;
    }
    else{
        cout<<"超出线性表范围"<<endl;
    }
}*/
template<typename T>
void sequence<T>::alter(T& a,T& b)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==b){
             arr[i]=a;
        }

    }

}
template<typename T>
void sequence<T>::sot()
{
        T m;
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    m=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=m;
                }
            }

        }
    }
//单链表

class Note
{
public:
    int a;
    Note* next;
public:
    Note(int b)
    {
        a=b;
        next=NULL;
    }
    Note()
    {
        a=0;
        next=NULL;
    }
};


class alist
{
public:
    Note* head;

public:
    static int n;
    alist()
    {
        head=new Note;
    }
    alist(alist& s)
    {
        head=s.head;
    }
    void addtail(Note& a);
    void add(int i,Note& a);
    void delet(int i);
    Note* inser(int i);
    void alter(int i,Note& a);
    void sot();
    void show();
    alist& ordermerge(alist&a);//原链表递增排序
};
int alist::n=0;
void alist::addtail(Note& a)
{
    ++n;
    Note*p=head;
    while(p->next)
    {
        p=p->next;
    }
    p->next=&a;
    a.next=NULL;
}
void alist::add(int i,Note&a)
{
    ++n;
    int j;
    Note*p=head; Note*q;
    for(j=1;j<i;j++)
    {
        p=p->next;
    }
    q=p->next;
    p->next=&a;
    a.next=q;

}
void alist::delet(int i)
{
    --n;
    Note*p=head;Note*q;
    for(int j=1;j<i;j++)
    {
        p=p->next;
    }
    q=p->next;
    p->next=p->next->next;
    delete q;
}
Note* alist::inser(int i)
{
    int j;
    Note*p=head;
    for(j=0;j<i;j++,p++);
    return p;

}
void alist::alter(int i,Note& a)
{
    Note*p=head;Note*q;
    for(int j=1;j<i;j++,p=p->next);
    q=p->next;
    p->next=&a;
    a.next=q->next;
    delete q;
}
void alist::sot()
{
   Note*p=head;Note*q1=new Note;Note*q2=new Note;
   //冒泡排序
   for(int i=1;i<n;i++)
        {
           for(int j=0;j<n-i;j++)
            {
                 if((p->next->a)>(p->next->next->a))
                {
                    q1=p->next;//记住头指针后一位节点
                    q2=p->next->next->next;//记住要交换的两位指针后一位节点
                    p->next=p->next->next;//交换
                    p->next->next=q1;
                    q1->next=q2;
                }
              p=p->next;
            }
              p=head;
        }
}
alist& alist::ordermerge(alist&a)
{
   Note*p1,*p2,*p3;
   alist b;
   p1=head->next;p2=a.head->next;p3=b.head;
   while((p1->next)&&(p2->next))
   {
       if((p1->a)>(p2->a)){
            p3->next=p1;
            p3=p1;
            p1=p1->next;

       }
       else{
            p3->next=p2;
            p3=p2;
            p2=p2->next;

       }

   }
   if(p1->next)
   {
        p3->next=p1;
   }
   else
   {
       p3->next=p2;
   }
   return b;
}
void alist::show()
{
    Note*p=head;
    while(p->next)
    {
        p=p->next;
        cout<<p->a<<" ";
    }
}
alist& invertedOrder(alist& a)
{
    int k=1;
    Note*head=a.head->next;Note*p=head;Note*q1=head;Note*q2;
    while(p->next)
    {
        p=p->next;
        k++;
    }
    head=p;//头结点指向尾
    q2=p;//记录下新头结点，一会做++操作
    p=q1;//p指向旧头节点
   for(int j=0;j<k-1;j++)
    {
        for(int i=k-2;i>j;i--)
        {
            q1=q1->next;
        }

        //cout<<q1->a<<" ";
        q2->next=q1;//第一个节点
        q1->next=NULL;
        q2=q1;//新链表从头开始移动
        q1=p;//重新指回旧头结点
    }
    a.head=head;
     return a;
}

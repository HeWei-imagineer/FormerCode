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
    sequence(){  n=0; }
    T& getarr(int i){  return arr[i]; }
    int getn(){return n;}
    void sot();
    bool add(int i,T& a);
    //bool del(int i);
    T& delsmall();//删除最小元素，并由最后一个元素补齐
    void del(T& a);
    void delAtoB(T& a,T& b);//删除A~B间元素
    bool inser(T&a);
    //void alter(int i,T a);
    void alter(T& a,T& b);//把a改为b
    void show();
    };
template<typename T>
bool sequence<T>::add(int i,T& a)
{
    n++;
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
   --n;
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
    this->alter(s.getarr(0),arr[n-1]);
    return s.getarr(0);
}
template<typename T>
void sequence<T>::del(T& a)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(arr[j]==a)
        {
            for(int i=j;i<n;i++)
            {
                arr[j]=arr[j+1];
            }
           --n;
        }

    }
}
template<typename T>
void sequence<T>::delAtoB(T& a,T& b)
{
    int j;
    for(j=0;j<n;j++)
    {
        if((arr[j]>=a)&&(arr[j]<=b))
        {
            for(int i=j;i<n-1;i++)
            {
                arr[i]=arr[i+1];
            }
            --n;--j;
        }

    }
}
template<typename T>
bool sequence<T>::inser(T&a)
{
        for(int i=0;i<n;i++)
        {
            if(arr[i]==a)
                return true;
        }

        return false;
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
        if(arr[i]==a){
             arr[i]=b;
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
template<typename T>
void sequence<T>::show()
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
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
    int n;
    alist()
    {
        n=0;
        head=new Note;
    }
    void addtail(Note& a);
    void add(int i,Note& a);
    void delet(int i);
    Note* inser(int i);
    void alter(int i,Note& a);
    void sot();
    void show();
    void revers();
    alist& ordermerge(alist&a);//原链表递减排序
};

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
   while(p1&&p2)
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
   if(p1)
   {
        p3->next=p2;
   }
   else
   {
       p3->next=p1;
   }
   return b;
}
void alist::revers()
{
   Note*p,*q1,*q2;
    p=head->next;
    q1=p;
    //链表倒序算法
    int k=1;
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
     p=head;
     cout<<"链表倒序：";
     while(p->next)
    {
        cout<<p->a<<" ";
        p=p->next;
    }
    cout<<p->a<<endl;
}
void alist::show()
{
    Note*p=head;
    while(p->next)
    {
        p=p->next;
        cout<<p->a<<" ";
    }
    cout<<endl;
}

 //递归算最大值
    int maxnum(Note*head)
    {
       if(head==NULL)
       {
          return 0;
       }
       else
       {
           int maxn=maxnum(head->next);
           return maxn=(head->a)>maxn?(head->a):maxn;
       }
    }
int Findsum(Note*head)
{
   if(head==NULL)
   {
       return 0;
   }
   else
   {
       return (head->a)+Findsum(head->next);
   }
}
int Findcount(int count_num,Note*head)
{
    if(head==NULL)
    {
        return count_num;
    }
    else
    {
        count_num++;
        Findcount(count_num,head->next);
    }
}
int main()
{
    int arr[10]={1,5,4,2,6,8,9,6,8,10};
    int a1,a2=1,a3=4,a4=9;
    sequence<int> A(10,arr);
    A.show();
    a1=A.delsmall();
    cout<<a1<<endl;
    A.show();
    A.del(a2);
    A.show();
    A.delAtoB(a3,a4);
    A.show();


    Note a(3),b(1),c(8),d(0),e(5),f(10);
    Note g(1);Note h(5);Note i(7);Note j(18);
    alist s1;
    s1.addtail(g);
    s1.addtail(h);
    s1.addtail(i);
    s1.addtail(j);
    alist s2;
    s2.addtail(a);
    s2.addtail(b);
    s2.addtail(c);
    s2.addtail(d);
    s2.addtail(e);
    cout<<"输出s2："<<endl;
    s2.show();
    s2.sot();
    cout<<"输出排序后s2："<<endl;
    s2.show();
    s2.alter(3,f);
    s2.delet(2);
    s2.show();

    Note*p=s2.head->next;
    int count_num=0,sum=0;
    cout<<"最大值："<<maxnum(p)<<endl;
    cout<<"总数："<<Findsum(p)<<endl;
    cout<<"个数："<<Findcount(count_num,p)<<endl;

    cout<<"输出s1："<<endl;
    s1.show();
    s1.ordermerge(s2);
    s1.show();
    s1.revers();
    s1.show();
}

#include <iostream>

using namespace std;

//队列的顺序实现
template<typename T>
class arrQueue
{
private:
    int maxSize;
    int ifront;
    int irear;
    T* iqueue;
public:
    arrQueue(int isize);
    ~arrQueue();
    void Clear();
    bool enQueue(const T item);
    bool deQueue(T& item);
    bool isEmpty();
    bool isFull();
    bool getFront(T& item);
};
template<typename T>
arrQueue<T>::arrQueue(int isize)
{
    maxSize=isize+1;//多出一个空间，区分满，空。有
    ifront=irear=0;
    iqueue=new T[maxSize];
}
template<typename T>
arrQueue<T>::~arrQueue()
{
   delete []iqueue;
}
template<typename T>
void arrQueue<T>::Clear()
{
   ifront=irear;
}
template<typename T>
bool arrQueue<T>::enQueue(const T item)
{
   if((irear+1)%maxSize==ifront){
    cout<<"队列已满，溢出"<<endl;
    return false;
   }
   else{
    iqueue[irear]=item;
    irear=(irear+1)%maxSize;
    return true;
   }
}
template<typename T>
bool arrQueue<T>::deQueue(T& item)
{
   if(ifront==irear){
    cout<<"队列为空"<<endl;
    return false;
    }
   else{
        item=iqueue[ifront];
        ifront=(ifront+1)%maxSize;
        return true;
    }

}
template<typename T>
bool arrQueue<T>::getFront(T& item)
{
   if(ifront==irear){
    cout<<"队列为空"<<endl;
    return false;
    }
   else{
        item=iqueue[ifront];
        return true;
    }
}
template<typename T>
bool arrQueue<T>::isEmpty()
{
   if(irear==ifront){
    return true;
   }
   else{
    return false;
   }
}
template<typename T>
bool arrQueue<T>::isFull()
{
   if((irear+1)%maxSize==ifront){
    return true;
   }
   else{
    return false;
   }
}

//队的链式实现
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
class listQueue
{

private:
    int Size;
    LinkNote<T>* ifront;
    LinkNote<T>* irear;
public:
    listQueue();
    ~listQueue();
    void Clear();
    bool enQueue(const T item);
    bool deQueue(T& item);
    bool isEmpty();
    bool getFront(T& item);
    LinkNote<T>* getirear(){return irear;}
    LinkNote<T>* getifront(){return ifront;}
};
template<typename T>
listQueue<T>::listQueue()
{
    Size=0;
    ifront=irear=NULL;
}

template<typename T>
void listQueue<T>::Clear()
{
   while(ifront)
   {
       irear=ifront;
       ifront=ifront->link;
       delete irear;
   }
   irear=NULL;

}
template<typename T>
listQueue<T>::~listQueue()
{
   Clear();
}
template<typename T>
bool listQueue<T>::enQueue(const T item)
{
   if(irear==NULL){
    ifront=irear=new LinkNote<T>(item,NULL);
   }
   else{
    irear->link=new LinkNote<T>(item,NULL);
    irear=irear->link;
    }
    Size++;
    return true;

}
template<typename T>
bool listQueue<T>::deQueue(T& item)
{
   if(ifront==irear&&ifront==NULL){
    cout<<"队列为空"<<endl;
    return false;
    }
   else{
        LinkNote<T>*p;
        item=ifront->data;
        p=ifront;
        ifront=ifront->link;
        delete p;
        Size--;
        return true;
    }


}
template<typename T>
bool listQueue<T>::getFront(T& item)
{
   if(ifront==irear&&ifront==NULL){
    cout<<"队列为空"<<endl;
    return false;
    }
   else{
        item=ifront->data;
        return true;
    }
}
template<typename T>
bool listQueue<T>::isEmpty()
{
   if(irear==ifront&&ifront==NULL){
    return true;
   }
   else{
    return false;
   }
}

void P80_14()
{
    int num;
    int k;
    cout<<"输入各队列中的数字，一会顺序输出："<<endl;
    cin>>num;
    listQueue<int> ss[10];
    LinkNote<int>* head;
    LinkNote<int>*p1;
    while(num>=0&&num<=9)
    {
        switch(num)
        {
        case 0:
            ss[0].enQueue(0);break;
        case 1:
            ss[1].enQueue(1);break;
        case 2:
            ss[2].enQueue(2);break;
        case 3:
            ss[3].enQueue(3);break;
        case 4:
            ss[4].enQueue(4);break;
        case 5:
            ss[5].enQueue(5);break;
        case 6:
            ss[6].enQueue(6);break;
        case 7:
            ss[7].enQueue(7);break;
        case 8:
            ss[8].enQueue(8);break;
        case 9:
            ss[9].enQueue(9);break;
        default:
            break;
        }
        cin>>num;
    }
//找到第一个非空队列
    for(int i=0;i<10;i++)
    {
        if(!ss[i].isEmpty())
        {
           head=ss[i].getifront();
           p1=ss[i].getirear();
           k=i;
           break;
        }
    }

    for(int i=0;i<10;i++)
    {
        if(!ss[i].isEmpty()&&i!=k)
        {
           p1->link=ss[i].getifront();
           p1=ss[i].getirear();

        }
    }
    p1=head;
    while(p1)
    {
        cout<<p1->data<<"   ";
        p1=p1->link;
    }
}

void Pascal_triangle()
{
    int i,num1,num2,k=1;
    cout<<"输入要计算的幂数："<<endl;
    cin>>i;
    arrQueue<int>aq(100);
    aq.enQueue(0);
    aq.enQueue(1);
    aq.enQueue(1);
    aq.enQueue(0);
    if(i<=0)
    {
        cout<<"输入错误"<<endl;
    }
    else if(i==1)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<1<<endl;
        for(k;k<i;)
    {
        aq.deQueue(num1); aq.getFront(num2);
        aq.enQueue(num1+num2);
        cout<<num1+num2<<" ";
        if(num2==0)
        {
            aq.enQueue(0);
            ++k;
            cout<<endl;
        }
    }
    }

}
int main()
{
    Pascal_triangle();
    //P80_14();
    return 0;
}

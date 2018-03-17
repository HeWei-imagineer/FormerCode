#ifndef LINER_LIST_H_INCLUDED
#define LINER_LIST_H_INCLUDED
using namespace std;
//���е�˳��ʵ��
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
    maxSize=isize+1;//���һ���ռ䣬���������ա���
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
    cout<<"�������������"<<endl;
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
    cout<<"����Ϊ��"<<endl;
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
    cout<<"����Ϊ��"<<endl;
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
     //cout<<"ջ��"<<endl;
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
     //cout<<"ջ��"<<endl;
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



#endif // LINER_LIST_H_INCLUDED

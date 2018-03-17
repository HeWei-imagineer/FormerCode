#include <iostream>

using namespace std;

class dllNote
{
public:
    int a;
    dllNote* next;
    dllNote* prev;
public:
    dllNote(int b)
    {
        a=b;
        next=NULL;
        prev=NULL;
    }
    dllNote()
    {
        a=0;
        next=NULL;
        prev=NULL;
    }
};

class doubleList
{
public:
    dllNote *head;
public:
    //int n=0;
    doubleList()
    {
        head=new dllNote;
    }
    doubleList(doubleList& s)
    {
        head=s.head;
    }
    void addtail(dllNote& a);
    void add(int i,dllNote& a);
    void delet(dllNote&a);//可以直接删除尾节点哟~
    dllNote* inser(int i);
    void alter(int i,dllNote& a);
    void sot();
    void show();
    doubleList& ordermerge(doubleList&a,doubleList&b);//有序链表合并（原链表递增排序）
    //将L（a1,a2,a3,a5...）转换为L（a1,a3,...,a4,a2）未考虑节点为一的情况
    void select();

};

void doubleList::add(int i,dllNote& a)
{
    //++n;
    dllNote* p=head,*q;
    for(int j=1;j<i;j++)
    {
        p=p->next;
    }
    q=p->next;
    p->next=&a;
    a.prev=p;
    a.next=q;
    q->prev=&a;
}
void doubleList::addtail(dllNote&a)
{
   // ++n;
    dllNote* p=head;
    while(p->next)
    {
        p=p->next;
    }
    p->next=&a;
    a.prev=p;
    a.next=NULL;

}

void doubleList::delet(dllNote&a)
{
    //--n;
    dllNote*p=head,*q;
    while(p->next->next)
    {
        if((p->next->a)==a.a)
        {
            if(p->next->next)
            {
               q=p->next;
               p->next=p->next->next;
               p->next->next->prev=p;
               delete q;
            }


        }
         p=p->next;
    }
         if(p->next->a==a.a)
            {
               q=p->next;
               p->next=NULL;
               delete q;
            }


}
dllNote* doubleList::inser(int i)
{
    int j;
    dllNote*p=head;
    for(j=0;j<i;j++,p=p->next);
    return p;

}
void doubleList::alter(int i,dllNote& a)
{
    dllNote*p=head;dllNote*q;
    for(int j=1;j<i;j++,p=p->next);
    p->next->a=a.a;
}
void doubleList::sot()
{
   dllNote*p=head;dllNote*q1=new dllNote;dllNote*q2=new dllNote;
   int n=0;
   //冒泡排序
   while(p->next)
   {
       ++n;
       p=p->next;

   }
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
            if(int j=0){p->next->next=NULL;}
              p=head;
        }
        while(p->next)
        {
            p->next->prev=p;
            p=p->next;
        }
}
doubleList& doubleList::ordermerge(doubleList&a,doubleList&b)
{
   dllNote*p1,*p2,*p3;
   p1=head->next;p2=a.head->next;p3=b.head;
   while(p1&&p2)
   {
       if((p1->a)<(p2->a)){
            p3->next=p1;
            p1->prev=p3;
            p3=p1;
            p1=p1->next;

       }
       else{
            p3->next=p2;
            p2->prev=p3;
            p3=p2;
            p2=p2->next;

       }

   }
   if(p1==NULL)
   {
        p3->next=p2;
        p2->prev=p3;
   }
   else
   {
       p3->next=p1;
       p1->prev=p3;
   }
   return b;
}
void doubleList::select()
{
    dllNote*p,*p1,*q,*q1;
    p1=p=head->next;
    int n=0;

   while(p)
   {
       n++;
       p=p->next;
   }
   if(n>3)
   {
       while((p->next)&&(p->next->next))
    {
        q=p->next;
        if(p==head->next)
        {
            q1=q;//记下新链表中尾节点
        }
        p->next=p->next->next;
        p=p->next;
        q->prev=p->next;
    }
    if(p->next)
    {
        q=p->next;
        q1->next=NULL;//尾节点置为空
        while(p1!=p)
        {
            p1->next->prev=p1;
            p1=p1->next;
        }
       // cout<<q1->a<<"   "<<q->a<<endl;
        while(q1!=q)
        {
           q1->prev->next=q1;
//cout<<q1->a;
           q1=q1->prev;
        }
    }


    else
    {
        p->next=q;
        q->prev=p;
        q1->next=NULL;//尾节点置为空
        while(p1!=p)
        {
            p1->next->prev=p1;
            p1=p1->next;
        }
        while(q1!=q)
        {
           q1->prev->next=q1;
           q1=q1->prev;
        }


    }
   }
   else
   {
       if(n==2)
    {
        p=head;
        p->next=p->next->next;
        p->next->next=p->next->prev;
        p->next->prev=p;
        p->next->next->prev=p->next;
        p->next->next->next=NULL;
    }
    if(n==3)
    {
        p=head->next;
        q=p->next;
        p->next=p->next->next;
        p->next->prev=p;
        p->next->next=q;
        q->next=NULL;

   }
   }


}
void doubleList::show()
{
    dllNote*p=head;
    while(p->next)
    {
        p=p->next;
        cout<<p->a<<" ";
    }
    cout<<endl;
}

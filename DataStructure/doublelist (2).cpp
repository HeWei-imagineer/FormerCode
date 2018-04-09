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
    int n;
    doubleList()
    {
        n=0;
        head=new dllNote;
    }
    doubleList(doubleList& s)
    {
        n=s.n;
        head=s.head;
    }
    void addtail(dllNote& a);
    void add(int i,dllNote& a);
    void delet(dllNote&a);//可以直接删除尾节点哟~
    dllNote* inser(int i);
    void alter(int i,dllNote& a);
    void sot();
    void show();
    doubleList& ordermerge(doubleList&a);//有序链表合并（原链表递增排序）
    void select();//将L（a1,a2,a3,a5...）转换为L（a1,a3,...,a4,a2）未考虑节点为一的情况

};

void doubleList::add(int i,dllNote& a)
{
    ++n;
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
    ++n;
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
    --n;
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
            if(int j=0){p->next->next=NULL;}
              p=head;
        }
        while(p->next)
        {
            p->next->prev=p;
            p=p->next;
        }
}
doubleList& doubleList::ordermerge(doubleList&a)
{
   dllNote*p1,*p2,*p3=head;
   p1=head->next;
   p2=a.head->next;
   //delete a.head;//删除传入链表头指针
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
   a.head->next=NULL;//将传入链表制空
   return *this;
}
void doubleList::select()
{
    dllNote*p,*p1,*q,*q1;
    p1=p=head->next;

   if(n>3)
   {
       while((p->next)&&(p->next->next))
    {
        q=p->next;
        if(q==head->next->next)
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


int main()
{
 dllNote a(0);dllNote b(4);dllNote c(9);dllNote d(10);dllNote e(8);dllNote* f;
 dllNote a1(1);dllNote b1(5);dllNote c1(7);dllNote d1(18);
    doubleList s1;
    s1.addtail(a);
    s1.addtail(b);
    s1.addtail(c);
    s1.addtail(d);
    cout<<"输出s1："<<endl;
    s1.show();
    doubleList s2;
    s2.addtail(a1);
    s2.addtail(b1);
    s2.addtail(c1);
    s2.addtail(d1);
    cout<<"输出s2："<<endl;
    s2.show();
    s1.ordermerge(s2);
    cout<<"输出s1于s2有序合并后链表："<<endl;
    s1.show();
    s2.show();
    cout<<"输出s1："<<endl;
    s1.show();
    s1.select();
    cout<<"将L（a1,a2,a3,a5...）转换为L（a1,a3,...,a4,a2）的情况:"<<endl;
    s1.show();

    //循环链表删除第一个节点

    return 0;
}

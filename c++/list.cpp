#include <iostream>

using namespace std;

class note
{
 public:
     int a;
     note* next;

    note()
    {
        a=0;
        next=NULL;
    }
    note(int b)
    {
        a=b;
        next=NULL;
    }
};

class alist
{
private:
    note* head;
public:
    void print();
    void add(note&);
    void asort();
    void removecom();
    void createlist();
    int getsize();
    ~alist()
    {
       delete []head;
    }
};
int alist::getsize()
{
    note*p;int i=0;
    p=head;
    while(p->next)
    {
        i++;
        p=p->next;

    }
    return i;
}

void alist::createlist()
{
    note*p,*q;
    head=new note();
    p=head;
    q=new note();
    while(cin>>p->a)
    {
        p->next=q;
        p=q;
        q=new note();
    }
        p->next=NULL;
        delete q;

}

void alist::print()
{
    note*p;
    p=head;
    while(p->next)
    {
       cout<<p->a<<endl;
        p=p->next;
    }

}
void alist::asort()
{
    note*p,*q;
    q=head;
    p=head;
    while(q->next)
    {
        int i=0;
        i++;
        for(int j=getsize();j>i;j--)
        {

             if((p->a)>(p->next->a))
         {
             int temp;
             temp=p->a;
            p->a=p->next->a;
            p->next->a=temp;
         }
         p=p->next;
        }
        p=head;
        q=q->next;

    }

}
void alist::removecom()
{
    note*p;
    p=head;
    while(p->next)
    {
        if(p->a==p->next->a)
        {
            p->next=p->next->next;
        }
        p=p->next;
    }
}
int main()
{

    alist a;
    a.createlist();
    cout<<a.getsize()<<endl;
    a.asort();
    a.removecom();
    a.print();

    return 0;
}

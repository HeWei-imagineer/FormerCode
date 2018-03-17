#include <iostream>
#include <cstring>
using namespace std;
class book
{
public:
    char*name;
    char*writer;
    float price;
    char*state;
    book*next;
    int num;
    book( char*n,char*w,float pr,int m)
   {
       name=new char[strlen(n)];
       strcpy(name,n);
       writer=new char[strlen(w)];
       strcpy(writer,w);
       price=pr;
       num=m;
       state=new char[11];
       strcpy(state,"can borrow");
       next=NULL;
   }
   book(book& b)
   {
       name=new char[strlen(b.name)];
       strcpy(name,b.name);
       writer=new char[strlen(b.writer)];
       strcpy(writer,b.writer);
       price=b.price;
       num=b.num;
       state=new char[11];
       strcpy(state,"can borrow");
       next=NULL;

   }
   book()
   {
       name=new char[5];
       strcpy(name,"NULL");
       writer=new char[5];
       strcpy(writer,"NULL");
       state=new char[5];
       strcpy(state,"NULL");
       next=NULL;
       price=0;
       num=0;


   }
   ~book()
   {
       if(name)delete[]name;
       if(writer)delete[]writer;
       if(state)delete[]state;
    }
   bool operator==(book& b)
   {
      if(num==b.num)
      {
          return true;
      }
      else
        return false;
   }
   void print()
   {
       cout<<"<<"<<name<<">>"<<'\n'<<"writer:"<<writer
       <<'\n'<<"state:"<<state<<'\n'<<"number:"<<num
       <<'\n'<<"price:"<<price<<endl;
   }

} ;
class alist
{
public:
    book* head;
    alist()
    {
      head=new book;
    }
    void create();
    void create(book& b);
    void insertlast();
    void insertlast(book& b);
    void deletfirst();
    void deletelast();
    int getdesk(book& b);//返回节点位置
    book& getbook(book& b);//返回节点
    int getlong(); //返回链表长度
    void display();
    void deletecasual(book& b);
};
void alist::create()
{
   book*p,*q;
   p=head;
   q=new book();
   cout<<"input book's name,writer,price,number:"<<endl;
   while(cin>>q->name>>q->writer>>q->price>>q->num)
   {
       p->next=q;
       p=q;
       q=new book();
   }
   p->next=NULL;
   //delete q;
}
void alist::create(book&b)
{
   book*p;
   p=head;
   p->next=&b;
   b.next=NULL;
   //delete q;
}
void alist::insertlast()
{
    book*p,*q;
    p=head;
    q=new book;
    while(p->next)
    {
        p=p->next;
    }
    p->next=q;
    cout<<"input book's name,writer,price,number:"<<endl;
    cin>>q->name>>q->writer>>q->price>>q->num;
    q->next=NULL;
}
void alist::insertlast(book& b)
{
    book*p;
    p=head;
    while(p->next)
    {
        p=p->next;
    }
    p->next=&b;
    b.next=NULL;
}

void alist::display()
{
    book *p;
    p=head;
    while(p->next)
    {
        p=p->next;
        p->print();
        cout<<'\n';
    }

}
void alist::deletelast()
{
    book*p;
    p=head;
    while(p->next->next)
    {
        p=p->next;
    }
    p->next=NULL;
}
void alist::deletecasual(book& b)
{
    book*p;
    p=head;
    while(p->next)
    {
        if(p->next->num==b.num)
        {
            p->next=p->next->next;
        }
    p=p->next;
    }
}
void alist::deletfirst()
{
   head->next=head->next->next;
}
int alist::getdesk(book& b)
{
    int k=1;
    book*p;
    p=head;
    while(p->next->num!=b.num)
    {
       k++;
       p=p->next;
    }
    return k;
}
book& alist::getbook(book& b)
{
    book*p;
    p=head->next;
    while(p->num!=b.num)
    {
       p=p->next;
       if(p==NULL)
       {
           p=new book;
          return *p;
       }
    }
    return *p;
}
int alist::getlong()
{
    int i=0;
    book*p;
    p=head;
    while(p->next)
    {
        i++;
        p=p->next;
    }
    return i;
}
class library
{

public:
    //int total;
    alist* llist;
    library()
    {
        llist=new alist;
    }
    void add()
    {
        llist->create();
    }
    void add(book&b)
    {
        if(llist->getlong()==0)
        {
            llist->create(b);
        }
        else
        {
            llist->insertlast(b);
        }
    }


    void adelete(book& b)
    {
       if(llist->getdesk(b)==llist->getlong())
       {
           llist->deletelast();
       }
       if(llist->getdesk(b)==1)
       {
           llist->deletfirst();
       }
      if(llist->getdesk(b)!=llist->getlong()&&llist->getdesk(b)!=1)
       {
           llist->deletecasual(b);
       }
    }
    void show()
    {
        cout<<"```````````````````````"<<endl;
        cout<<"library's information"<<endl;
        llist->display();
        cout<<"```````````````````````"<<endl;
    }
};
class person
{
private:
    char* name;
    char* sex;
    char* state;
    int num;

public:
    alist booklist;
    library *library1;
    person(char*n,char*ssex,int m,library&a):booklist()
    {
       name=new char[strlen(n)];
       strcpy(name,n);
       sex=new char[strlen(ssex)];
       strcpy(sex,ssex);
       num=m;
       library1=&a;
    }
    void enroll(char*s)
    {

       state=new char[strlen(s)];
       strcpy(state,s);

    }
    void borrow(book&b);
    void breturn(book&b);
    void show();


};
void person::borrow(book&b)
{
    if(strcmp(state,"member")==0)
    {
      if(library1->llist->getbook(b)==b)
        {
           if(strcmp(b.state,"can borrow")==0)
              {
               strcpy(b.state,"borrowed");
                  if(booklist.getlong()==0)
                  {
                      booklist.create(b);
                  }
                  else
                  {
                      booklist.insertlast(b);
                  }
               cout<<"operation is successful"<<endl;
              }

             else
              {
                  cout<<"borrowed"<<endl;
              }

           }
       else
        {
            cout<<"There isn't the book."<<endl;
        }

    }

   else
    {
        cout<<"No permission to borrow."<<endl;
    }
}

void person::breturn(book&b)
{
     strcpy(library1->llist->getbook(b).state,"can borrow");
     if(booklist.getlong()==booklist.getdesk(b))
      {
          booklist.deletelast();
      }
      if(b.num==1)
      {
          booklist.deletfirst();
      }
      else
      {
           booklist.deletecasual(b);
      }
}

void person::show()
{
    cout<<"````````````````````````````"<<endl;
    cout<<"name:"<<name<<'\n'<<"sex:"<<sex<<'\n'<<"state:"<<state<<'\n'
    <<"number:"<<num<<endl;
    booklist.display();
}
int main()
{
   library llibrary;
   // llibrary.add();
   //alist aa;
    book book1("Happy","Linda",60.5,01);
    book book2("prince","Exupery",20.5,02);
    book book3("Sahara's desert","Echo",24.5,03);

    llibrary.add(book1);
    llibrary.add(book2);
    llibrary.add(book3);

    llibrary.show();
    //llibrary.adelete(book1);
    //llibrary.show();
  /* aa.create(book1);
   aa.insertlast(book2);
   aa.display();*/
   //llibrary.llist->getbook(book2).print();
if(llibrary.llist->getbook(book2)==book2)
{
    cout<<"yes"<<endl;
}
else
    cout<<"no";
   /* person person1("Lily","women",201,llibrary);
    person1.enroll("member");
    person1.borrow(book1);
    person1.borrow(book2);
    person1.borrow(book3);
    person1.show();
    //book1.print();
    //person1.breturn(book1);
    //book1.print();
    //person1.show();*/

    return 0;


}

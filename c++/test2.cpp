#include <iostream>
#include<cstring>
using namespace std;
class animal
{
private:
    char *name;
public:

    static int shoutnum;
    virtual~animal(){if(name)delete[]name;}
    animal(char*n=0);
    static int getShoutNum();
    virtual animal& Shout();
    friend ostream& operator<<(ostream&out,animal&a);

};
int animal::shoutnum=0;
ostream& operator<<(ostream&out,animal&a)
{
    return out;
}
animal::animal(char*n)
    {
        if(n)
        {
          name=new char[sizeof(n)];
          strcpy(name,n);
        }

        else
        {
            name=new char[5];
            strcpy(name,"null");
        }


    }
int animal::getShoutNum()
{
    return shoutnum;
}
animal& animal::Shout()
{

    cout<<"¶¯Îï½ÐÉù"<<endl;
    return *this;
}
class cat:virtual public animal
{
private:
    char*name;
    const char *p;
public:
    animal& Shout();
    cat(char*n);
    ~cat(){if(name)delete[]name;delete[]p;}
};
animal& cat::Shout()
{
    shoutnum++;
    cout<<name<<":";
    for(int i=0;i<shoutnum;i++)
    {
        cout<<p;
    }
   cout<<endl;
    return *this;
}
cat::cat(char*n):animal()
{
        if(n)
        {
          name=new char[sizeof(n)];
          strcpy(name,n);
        }

        else
        {
            name=new char[5];
            strcpy(name,"null");
        }

       p="ß÷";
    }
class dog:virtual public animal
{
private:
    char*name;
    const char *p;
public:
    animal& Shout();
    dog(char*n);
    ~dog(){if(name)delete[]name;delete[]p;}
};
animal& dog::Shout()
{
     shoutnum++;
    cout<<name<<":";
    for(int i=0;i<shoutnum;i++)
    {
        cout<<p;
    }
     cout<<endl;
    return *this;
}
dog::dog(char*n):animal()
{
        if(n)
        {
          name=new char[sizeof(n)];
          strcpy(name,n);
        }

        else
        {
            name=new char[5];
            strcpy(name,"null");
        }

     p="Íô";
    }
class sheep:virtual public animal
{
private:
    char*name;
    const char *p;
public:
    animal& Shout();
    sheep(char*n);
    ~sheep(){if(name)delete[]name;delete[]p;}
};
animal& sheep::Shout()
{
     shoutnum++;
    cout<<name<<":";
    for(int i=0;i<shoutnum;i++)
    {
        cout<<p;
    }
    cout<<endl;
    return *this;
}
sheep::sheep(char*n):animal()
{
        if(n)
        {
          name=new char[sizeof(n)];
          strcpy(name,n);
        }

        else
        {
            name=new char[5];
            strcpy(name,"null");
        }

    p="ßã";
    }
int main()
{
    animal  *pointer[3]={new cat ("°¢»¨"),new dog ("´óºÚ"),new sheep("Ð¡°×")};
	for(int i=0;i<9;i++)
    {
        cout<<pointer[i%3]->Shout()<<endl;
    }
		return 0;
}

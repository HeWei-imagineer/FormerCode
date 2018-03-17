#include<iostream>
using namespace std;
class Animal{
protected:
string name ;
public:
	Animal(string n):name(n)
	{ 	cout<< "Animal 1"<<endl; 	}
	Animal():name("ÎÞÃû")
	{ 	cout<< "Animal 0"<<endl;	}
    void show()
	{ cout<<name<<endl; 	}
};

class Cat: public Animal
{
    int year;
public:
	Cat( )
	{	   cout<<"Cat 0"<<endl; 	}
	Cat(string n, int y):Animal(n),year(y)
	{ 	   cout<<"Cat 1"<<endl; 	}
	  void show()
	{ cout<<name<<" "<<year <<" years old\n"; 	}
};

int main()
{
   Cat cat1, cat2("Garfield",3);
   cat1.show();
   cat2.show();
   return 0;
}

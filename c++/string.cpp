#include <iostream>
#include<cstring>
using namespace std;
class myString
{
public :
      myString (const char *pn = 0);
      ~ myString ( ){delete[]pStr;}
       //set(char *pn) ;
      myString( myString&p);
      void print();
      int getLen();
private:
       char *pStr ;    // Ö¸Ïò´æ´¢×Ö·û´®µÄ¿Õ¼ä
       int size ;      //°üº¬×Ö·ûµÄÊýÄ¿
} ;
void myString::print(){cout<<pStr<<endl;}
int myString::getLen()
{
    return strlen(pStr);
}
myString::myString(const char *pn)
{
  if(pn)
  {
    pStr=new char[strlen(pn)+1];
    strcpy(pStr,pn);
    size=strlen(pStr);
  }

  else
  {
      pStr=new char[5];
      strcpy(pStr,"¿Õ×Ö·û´®");
      size=0;
  }


}
 myString::myString( myString&p)
 {
  size=p.size;
  if(p.pStr)
    { pStr=new char[strlen(p.pStr)+1];
      strcpy(pStr,p.pStr);
    }
   else
    {pStr=new char[5];
     strcpy(pStr,"¿Õ×Ö·û´®");
    }

 }
int main()
{
    myString s0, s1("world");
    s0.print();   //Êä³ö¡°¿Õ×Ö·û´®¡±
     //s0.set(¡°world¡±);
    s1.print();  //Êä³ö¡°world¡±
    cout<<s1.getLen()<<endl;  //Êä³ö5
    myString s2 = s1;
    s2.print();
          return 0;

}  //Êä³ö¡°hello¡±

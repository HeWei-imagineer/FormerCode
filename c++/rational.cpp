
#include <iostream>

using namespace std;

int gcd(int n1,int n2)
{
    int temp=n2;
    while(temp!=0)
    {
         temp=n1%n2;
         n1=n2;
         n2=temp;
    }
    return n1;
}

class Rational
{
    int m;
    int n;
  public:
         Rational(int mm=1,int nn=1):n(nn)
         {
             if(mm)
             m=mm;
             else  cout<<"wrong";
         }	//构造
         Rational  R_add(Rational & A);	//加
         Rational  R_sub(Rational & A);	//减
         Rational R_mul(Rational & A);
Rational R_div(Rational & A, Rational &B);	//除
	   void simple();		//约分
	   void print(){cout<<m<<"/"<<n;}
};
Rational Rational::R_add(Rational & A)
{
   Rational a;
   int i;
    i=gcd(m,A.m);
   a.m=m*(A.m/i);
    a.n=A.n*(m/i)+n*(A.m/i);
    return a;



}
Rational Rational::R_sub(Rational & A)
{
   Rational a;
   int i;
    i=gcd(m,A.m);
    a.m=m*(A.m/i);
    a.n=n*(m/i)-A.n*(A.m/i);

    return  a;


}
Rational Rational::R_mul(Rational & A)
{
    Rational a;
    a.m=m*A.m;
    a.n=n*A.n;

    return  a;
}
Rational Rational::R_div(Rational & A, Rational &B)
{
    Rational a;
    if(B.m)
    {
    a.m=m*A.n;
    a.n=n*A.m;

    }
    else{cout<<"wrong";}

    return a;
}
 void Rational::simple( )
{
    int i;
    i=gcd(m,n);
    m=m/i;
    n=n/i;
}
int main()
{
    Rational a1(4,1), a2(4,3),a3;
    a3=a2.R_add(a1);
    a3.simple();
    a3.print();
    return 0;
}





#include <iostream>
#include<cstring>

using namespace std;

char* keyword[6]={"for","if","then","else","while","do"};
char* op[16]={"#","+","-","*","/",":",":=","<","<>","<=",">",">=","=",";","(",")"};
int tocken[1000]; //记录词法记号
int k=0,k1=0,k2=0;
char* id[1000];
int num[1000];
bool is_op(char*p)
{
    int i=0;
    if(*p==*(op[i]))
    {
      cout<<"("<<0<<","<<*p<<")"<<endl;
      tocken[k++]=i;
      id[k2++]=p;
      return true;
    }
    for(;i<16;i++)
    {
        if(*p==*(op[i]))
            break;

    }
    if(i==16)
    {
        return false;
    }
    else{
        switch(i)
    {
        case 5:
            if(*(++p)=='=')
            {
              cout<<"(18,:=)"<<endl;
              tocken[k++]=18;
              id[k2++]=":=";

            }
            else
            {
               cout<<"("<<i+12<<","<<*(--p)<<")"<<endl;
               tocken[k++]=i+12;
               id[k2++]=p;
            }
            break;
        case 7:
            if(*(++p)=='>')
            {
              cout<<"(20,<>)"<<endl;
              tocken[k++]=20;
              id[k2++]="<>";
            }
            else if(*p=='=')
            {
              cout<<"(21,<=)"<<endl;
              tocken[k++]=21;
              id[k2++]="<=";

            }
            else
            {
               cout<<"("<<i+12<<","<<*(--p)<<")"<<endl;
               tocken[k++]=i+12;
               id[k2++]=p;
            }
             break;
        case 10:
            if(*(++p)=='=')
            {
              cout<<"(23,>=)"<<endl;
              tocken[k++]=23;
              id[k2++]=">=";

            }
            else
            {
               cout<<"("<<i+12<<","<<*(--p)<<")"<<endl;
               tocken[k++]=i+12;
               id[k2++]=p;
            }
             break;
        default:
             cout<<"("<<i+12<<","<<*(--p)<<")"<<endl;
             tocken[k++]=i+12;
             id[k2++]=p;
             break;

     }
     return true;
 }

}

bool is_keyword(char*p)
{
    for(int i=0;i<6;i++)
    {
        if(strcmp(p,keyword[i])==0)
        {
            tocken[k++]=i+1;
            cout<<"("<<i+1<<","<<keyword[i]<<")"<<endl;
            return true;
        }

    }
    return false;
}


bool is_num(char*c)
{
    char*p=c;
    while(*p++!='/0')
    {
        if(*p<=0||*p>=9)
        {
            return false;
        }
    }
    num[k1++]=*c;
    tocken[k++]=11;
   cout<<num[k1-1];
    return true;
}


void lexical(char*p)
{
   char*p1=p;
   char*p2;//记录局部字符串
   while(*p1!='\0')
   {
       int i=0;//记录局部字符串长度
       bool op=is_op(p1);
       while(!op&&(*p1!=32)&&(*p1!=13)&&(*p1!=10))
       {
        p1++;i++;
        op=is_op(p1);
       }
       p2=p1;
        if(op)
       {
           if(tocken[k-1]==18||tocken[k-1]==20||tocken[k-1]==21||tocken[k-1]==23)
           {
               p1++;
           }


       }
       if(i==0)
       {
           p1++;
           continue;

       }

           p2--;//回退空格or符号之前
           char* c=new char[i+1];
           c[i]='\0';
           while((--i)>=0)
           {
            c[i]=*p2;
            p2--;
           }
           bool finish=false;
           finish=is_keyword(c);
           if(!finish)
           {
             if(is_num(c))
             {
                cout<<"("<<11<<","<<c<<")"<<endl;
             }
             else{
                cout<<"("<<10<<","<<c<<")"<<endl;
             }
           }
           delete[] c;
        p1++;
       while(*(p1)==32||*(p1)==13||*(p1)==10)
       {
           p1++;
       }
   }

}





int main()
{
    char*p=">=12.";
    int i=0;
    lexical(p);
    while(tocken[i++]!=0)
        cout<<tocken[i]<<" ";
        cout<<p;
    return 0;
}

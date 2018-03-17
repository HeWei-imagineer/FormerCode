#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
//输入文法形式 ABd|ac//第一个字母为产生式左侧
//产生式集合

int counter=0;//求follow时循环多次无法求出时跳出
int flag[100];
struct states
{
    int n;
    char c[100];
    char s[100][100];
    states()
    {
        memset(s, 0, sizeof(s));
        memset(c, 0, sizeof(c));
    }
}state;

class FIRSTS
{
public:
    char c[100];
    char s[100][100];
    FIRSTS ()
    {
        memset(s, 0, sizeof(s));
        memset(c, 0, sizeof(c));
    }
    int n;
}FIRST;

class FOLLOWS
{
public:
    char c[100];
    char s[100][100];
    FOLLOWS()
    {
        memset(s, 0, sizeof(s));
        memset(c, 0, sizeof(c));
    }
    int n;
}FOLLOW;

void printState(){
   /*cin>>state.n;
   for(int i=0;i<state.n;i++)
   {
       cin>>state.c[i]>>state.s[i];
       FOLLOW.c[i]=state.c[i];
   }*/

   state.n=6;
   state.c[0]='A';state.s[0][0]='B';state.s[0][1]='C';state.s[0][2]='D';state.s[0][3]='E';
   state.c[1]='B'; state.s[1][0]='a';state.s[1][1]='B';state.s[1][2]='A';state.s[1][3]='|';state.s[1][4]='#';
   state.c[2]='C'; state.s[2][0]='F';state.s[2][1]='|';state.s[2][2]='#';
   state.c[3]='D'; state.s[3][0]='b';state.s[3][1]='|';state.s[3][2]='c';state.s[3][3]='|';state.s[3][4]='#';
   state.c[4]='E'; state.s[4][0]='e';state.s[4][1]='|';state.s[4][2]='#';
   state.c[5]='F'; state.s[5][0]='d';state.s[5][1]='|';state.s[5][2]='#';

   FOLLOW.n=state.n;
   FOLLOW.s[0][0]='$';

   for(int i=0;i<state.n;i++)
   {
       int length=strlen(state.s[i]);
       for(int j=0;j<length;j++)
       {
           if(state.s[i][j]=='|')
           {
               state.n++;
               state.s[i][j]='\0';
               j++;
               int k=0;
               state.c[state.n-1]=state.c[i];
               while(state.s[i][j]!='|'&&state.s[i][j]!='\0')
               {
                 state.s[state.n-1][k]=state.s[i][j];
                 j++;
                 k++;
               }
               j--;//go to for(),j will ++

           }
       }
   }
   cout<<"-------------printf state-------------"<<endl;
   FIRST.n=state.n;

   for(int i=0;i<state.n;i++)
   {
       FIRST.c[i]=state.c[i];
       FOLLOW.c[i]=state.c[i];
       //cout<<"-------"<<FOLLOW.c[i]<<endl;
       cout<<state.c[i]<<"->"<<state.s[i]<<endl;
   }
}
 bool isTerminal(char c)
 {
     if(c<'A'||c>'Z')
     {
         return true;
     }
     else{
        return false;
     }
 }

 bool isnull(char c)
 {
    for(int i=0;i<state.n;i++)
    {
        if(state.c[i]==c&&(state.s[i][0]=='#'))
        {
            return true;
        }
    }
    return false;
 }

 void add(char* s,char c){
     int i=0;
     while(s[i]!=0)
     {
         if(s[i]==c)
            return;
         else
            i++;
     }
     s[i]=c;
 }

void contact(char*s1,char*s2)
{
    int i=0;
    while(s2[i]!=0)
    {
        add(s1,s2[i]);
        i++;
    }
}

void first(char c)
{
    int num1,num2;
    int j;
    for(int i=0;i<state.n;i++)
    {
      if(state.c[i]==c)
        {
           if(isTerminal(state.s[i][0])||state.s[i][0]=='#')
              {
                 add(FIRST.s[i],state.s[i][0]);
              }
            else{
                    //be attention!

                   for(j=0;j<strlen(state.s[i]);j++)
                   {
                       //递归在这里
                       first(state.s[i][j]);
                       for(int k=0;k<state.n;k++)
                        {
                            if(state.c[k]==state.s[i][j]&&state.s[k][0]!='#')
                            {
                              contact(FIRST.s[i],FIRST.s[k]);
                            }
                        }
                        if(!isnull(state.s[i][j]))
                        {
                            break;
                        }
                        //这里看了非终结符后一个是不是终结符
                        else{
                            if(state.s[i][j+1]!=0&&isTerminal(state.s[i][j+1])){
                                add(FIRST.s[i],state.s[i][j+1]);
                                break;
                            }
                        }
                   }
                   if(j==strlen(state.s[i]))
                      {
                          add(FIRST.s[i],'#');
                      }

                }

        }
    }
}




void firstFinal()
{
    for(int i=0;i<FIRST.n;i++)
    {
        for(int j=i+1;j<state.n;j++)
        {
            if(FIRST.c[i]==state.c[j]){

                contact(FIRST.s[i],FIRST.s[j]);
                FIRST.n--;
            }
        }
    }
}

void printFirst()
{
    cout<<"-------------printf first state-------------"<<endl;
    for(int i=0;i<FIRST.n;i++)
    {
            cout<<FIRST.c[i]<<"->"<<FIRST.s[i]<<endl;
    }
}


void printFollow()
{
    cout<<"-------------printf follow state-------------"<<endl;
    for(int i=0;i<FOLLOW.n;i++)
    {
            cout<<FOLLOW.c[i]<<"->"<<FOLLOW.s[i]<<endl;
    }
}

//清除加入的#
 void clearForfollow(int n)
 {
     bool flag;
    for(int i=0;i<strlen(FOLLOW.s[n]);i++){
        if(FOLLOW.s[n][i]=='#'){
                flag=true;
        }
        if(flag){
            FOLLOW.s[n][i]=FOLLOW.s[n][i+1];
        }

    }

 }

void follow(char c)
{
    int num1,num2;
    for(int i=0;i<state.n;i++){
        if(c==state.c[i]){
            num1=i;break;
        }
    }
    for(int i=0;i<state.n;i++){
        int length=strlen(state.s[i]);
        for(int j=0;j<length;j++)
        {
            if(c==state.s[i][j])
            {
                for(int k=0;k<length-j;)
                {
                    j++;
                    if(state.s[i][j]!=0&&isTerminal(state.s[i][j]))
                    {
                        add(FOLLOW.s[num1],state.s[i][j]);
                        break;
                    }
                    else{
                        for(int k1=0;k1<state.n;k1++){
                            if(state.s[i][j]==state.c[k1]){
                            contact(FOLLOW.s[num1],FIRST.s[k1]);
                            }
                        }
                        if(!isnull(state.s[i][j])){
                        break;
                        }
                        clearForfollow(num1);//删除加入的空串
                    }
                }
                if(j==length){
                    if(flag[i]==0){
                        follow(FOLLOW.c[i]);
                        flag[i]=1;
                    }
                    contact(FOLLOW.s[num1],FOLLOW.s[i]);
                }
            }

        }
    }
}

int main()
{
    memset(flag, 0, sizeof(flag));
    printState();
    first('A');
    firstFinal();
    printFirst();


    /*follow('A');
    follow('B');
    follow('C');
    follow('D');
    follow('E');
    follow('F');

    printFollow();*/

    return 0;
}

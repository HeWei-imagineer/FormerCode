#include <iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
//输入文法形式 ABd|ac//第一个字母为产生式左侧
//产生式集合
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

char temp[100];//容纳非终结符

//判断是否为终结符
bool isterminal(char c)
{
    if(c<'A'|| c>'Z')
        return true;
    else
        return false;
}

void add(char a[], char );

void inputstates()
{
    int num;
    cin>>state.n;
    num=state.n;
    for(int i=0; i<num; i++)
    {
        cin>>state.c[i]>>state.s[i];
        int len=strlen(state.s[i]);
        for(int j=0; j<len; j++)
        {
            if(isterminal(state.s[i][j]) && state.s[i][j]!='|' && state.s[i][j]!='~')
                add(temp, state.s[i][j]);
        }
       // cout<<"temp : "<<temp<<endl;
        for(int j=0; j<len; j++)
        {
            if(state.s[i][j]=='|')
            {
                state.s[i][j]='\0';
                state.n++; j++;//n为什么加加
                state.c[state.n-1]=state.c[i];
                for(int k=0; k<=len-j; k++)
                {
                    if(state.s[i][j]=='|')
                    {
                        j--;//必须的，因为循环后j++,所以两者中和指向'|'
                        break;
                    }

                    else
                        state.s[state.n-1][k]=state.s[i][j++];
                }
            }
        }
    }
    FIRST.n=state.n;
    for(int i=0; i<state.n; i++)
    {
        FIRST.c[i]=state.c[i];
    }
}
void printstates()
{
    cout<<"*****printstates******"<<endl;
    cout<<state.n<<endl;
    for(int i=0; i<state.n; i++)
    {
        cout<<state.c[i];
        cout<<"->";
        cout<<state.s[i]<<endl;
    }
}
void add(char c[] , char a)//将一个字符a加到字符串c之后,若已经存在，则不加
{
     int i, len=strlen(c);
     for(i=0; i<len; i++)
     {
         if(c[i]==a)
            break;
     }
     if(i==len)
        c[len]=a;
}
//求first集时使用
void add(char c[],char a[])//将字符串a加到字符串c之后(除去'~')//已经存在的应该不加
{
    int lena=strlen(a);
    for(int i=0; i<lena; i++)
    {
        if(a[i]!='~')
            add(c,a[i]);
    }
}

void add2(char c[], char a[])//简单的合并（无重复的字符）
{
    int lena=strlen(a);
    for(int i=0; i<lena; i++)
    {
        add(c,a[i]);
    }
}

bool isnull(char c)//若FIRST(c)中含有'~'返回true, 否则返回false//即是否含空集
{
    for(int i=0; i<FIRST.n; i++)
    {
        if(FIRST.c[i]==c)
        {
            //cout<<"* "<<i<<" *"<<endl;
            int len=strlen(FIRST.s[i]);
            for(int k=0; k<len; k++)
            {
                if(FIRST.s[i][k]=='~')//如果FIRST.s[]串中含有‘~’
                    return true;
            }
        }
    }
    return false;
}

void first(char c)
{
    //cout<<"& "<<c<<" &"<<endl;
    int num1, num2, t;
    //cin>>t;
    for(int i=0; i<state.n; i++)
    {
        if(state.c[i]==c)
        {
            num1=i;
            if(isterminal(state.s[num1][0]))
            {
                add(FIRST.s[num1], state.s[num1][0]);
                continue;//(有无都可以)
            }
            else
            {
                int len=strlen(state.s[num1]);
                for(t=0; t<len; t++)
                {
                    //if(sstate.s[num1][t]!= )
                    first(state.s[num1][t]);//递归调用
                    for(int k=0; k<FIRST.n; k++)
                    {
                        if(FIRST.c[k]==state.s[num1][t])
                        {
                            //cout<<"& "<<FIRST.s[num2]<<" &"<<endl;
                            num2=k;
                            add(FIRST.s[num1], FIRST.s[num2]);//巴菲终结符的所有first集加入
                        }
                    }
                   // cout<<isnull(state.s[num1][t])<<endl;
                    if(isnull(state.s[num1][t])==false)
                        break;
                }
                if(t==len)
                    add(FIRST.s[num1],'~');
            }
        }
    }
}
int flag[100];
void finalfirst()
{
    int i,j;
    int num=FIRST.n;
    for(i=0; i<num; i++)
    {
        for(j=i+1; j<num; j++)
        {
            if(FIRST.c[i]==FIRST.c[j]&&flag[i]==0)//j->i
            {
                flag[j]=1;
                add2(FIRST.s[i], FIRST.s[j]);
                FIRST.n--;
            }
        }
    }
}

void printfirst()
{
    cout<<"*******printfirst*******"<<endl;
    for(int i=0; i<FIRST.n; i++)//add if flag i !=1 ? //不用，因为重复的都是加在了后面
    {
            cout<<"first("<<FIRST.c[i]<<")"<<" : "<<FIRST.s[i]<<endl;
    }
    cout<<endl;
}

void printfirst(char c)//查询单个字幕的FIRST集合
{
    cout<<"first("<<c<<")"<<" : ";
    for(int i=0; i<FIRST.n; i++)
    {
        if(c==FIRST.c[i])
        {
            cout<<FIRST.s[i]<<" ";
        }
    }
    cout<<endl;
}

void initialfollow()//调用finalfirst()函数之后
{
    FOLLOW.n=FIRST.n;
    for(int i=0; i<FIRST.n; i++)
        FOLLOW.c[i]=FIRST.c[i];
}

void follow(char c)
{
   // if(isfull(c))
        //clear(c);
    int num1, num2;
    FOLLOW.s[0][0]='$';//'$'表示文件末尾
    initialfollow();
    for(int i=0; i<FOLLOW.n; i++)
    {
        if(FOLLOW.c[i]==c)
        {
            num1=i; break;
        }
    }
    for(int i=0; i<state.n; i++)
    {
        int len=strlen(state.s[i]);
        for(int j=0; j<len; j++)
        {
            if(state.s[i][j]==c)
            {
                int k=j;
                if(j==len-1)//如果c为最后一个字符
                {
                    if(state.c[i]!=state.s[i][j])
                    {
						add(FOLLOW.s[num1], state.c[i]);//
                      /*  follow(state.c[i]);
                        for(int k=0; k<FOLLOW.n; k++)
                        {
                            if(FOLLOW.c[k]==state.c[i])
                            {
                                num2=k; break;
                            }
                        }
                        add(FOLLOW.s[num1], FOLLOW.s[num2]);*/
                    }
                }
                else
                {
                    for(k=j+1; k<len; k++)
                    {
                        if(isterminal(state.s[i][k]))
                        {
                            add(FOLLOW.s[num1],state.s[i][k]); break;
                        }
                        else
                        {
                            for(int t=0; t<FOLLOW.n; t++)
                            {
                                if(FOLLOW.c[t]==state.s[i][k])//s[i][k])为c后所跟非终结符
                                {
                                    num2=t; break;
                                }
                            }
                            add(FOLLOW.s[num1], FIRST.s[num2]);
                            if(isnull(state.s[i][k])==false) break;
                        }
                    }
                    if(k==len)
                    {
                        if(state.c[i]!=state.s[i][j])
                        {
							add(FOLLOW.s[num1], state.c[i]);
                          /*  follow(state.c[i]);
                            for(int k=0; k<FOLLOW.n; k++)
                            {
                                if(FOLLOW.c[k]==state.c[i])
                                {
                                    num2=k; break;
                                }
                            }
                            add(FOLLOW.s[num1], FOLLOW.s[num2]);*/
                        }
                    }
                }
            }
        }
    }
}
bool known(char c)//follow(c)已知，看c是否在follow集中
{
	int i;
	for(i=0; i<FOLLOW.n; i++)
	{
		if(FOLLOW.c[i]==c)
			break;
	}
	int len=strlen(FOLLOW.s[i]);
	for(int j=0; j<len; j++)
		if(!isterminal(FOLLOW.s[i][j]) && FOLLOW.s[i][j]!='$')
			return false;
	return true;
}
bool isfull(char a)//判断follow(a)中是否包含全部的终结符
{
    int t=0, num, h;
    for(int k=0; k<FOLLOW.n; k++)
    {
        if(FOLLOW.c[k]==a)
        {
            num=k; break;
        }
    }
    //cout<<num<<endl;
   // cin>>h;
	int len=strlen(FOLLOW.s[num]);
	for(int k=0; k<len; k++)
		if(isterminal(FOLLOW.s[num][k]))
			t++;
    //cout<<temp<<endl;
  //  cout<<FOLLOW.s[num]<<endl;
    if(strlen(temp)==t)
        return true;
    else
        return false;

}
void clear1(int i)
{
    cout<<FOLLOW.c[i]<<" : "<<FOLLOW.s[i]<<endl;
	int len=strlen(FOLLOW.s[i]), num;
	if(isfull(FOLLOW.c[i]))
	{
		//cout<<"yes"<<endl;
		for(int k=0; k<len; k++)
		{
			if(FOLLOW.s[i][k]==FOLLOW.c[0])
				FOLLOW.s[i][k]='$';
		}
	}
	else
	{
	   // cout<<"no"<<endl;
		for(int k=0; k<len; k++)
		{
			if(!isterminal(FOLLOW.s[i][k]) && FOLLOW.s[i][k]!='$')
			{
				for(int j=0; j<FOLLOW.n; j++)
				{
					if(FOLLOW.c[j]==FOLLOW.s[i][k])
					{
						num=j; break;
					}
				}
				if(known(FOLLOW.c[num]))
                    add(FOLLOW.s[i], FOLLOW.s[num]);
			}
		}
	}
}

bool clear2()//如果可以求出follow返回true,循环多次求不出就退出
{
    bool flag=true;
    int counter=0;
    while(flag)
    {
        counter++;
        if(counter==200)
            return false;
        flag=false;
        for(int i=0; i<FOLLOW.n; i++)
        {
            if(!known(FOLLOW.c[i]))
            {
                flag=true;//如果存在未知的
                int len=strlen(FOLLOW.s[i]);
                for(int j=0; j<len; j++)
                {
                    if(!isterminal(FOLLOW.s[i][j]) && FOLLOW.s[i][j]!='$')
                    {
                        if(known(FOLLOW.s[i][j]))
                        {
                            int h, k;
                            for(h=0; h<FOLLOW.n; h++)
                            {
                                if(FOLLOW.c[h]==FOLLOW.s[i][j])
                                    break;
                            }
                            for(k=j; k<len-1; k++)
                            {
                                FOLLOW.s[i][k]=FOLLOW.s[i][k+1];
                            }
                            FOLLOW.s[i][k]='\0';//除去FOLLOW.s[i][k]中的FOLLOW.s[i][j];
                            add(FOLLOW.s[i], FOLLOW.s[h]);
                        }
                    }
                }
            }
        }
    }
    return true;
}
void printfollow()
{
    cout<<"*******printfollow*******"<<endl;
    for(int i=0; i<FOLLOW.n; i++)
    {
            cout<<"follow("<<FOLLOW.c[i]<<")"<<" : "<<FOLLOW.s[i]<<endl;
    }
    cout<<endl;
}
int main()
{
    inputstates();
    printstates();
    cout<<"*****"<<endl;
    first('A');
    cout<<"*** "<<FIRST.s[0]<<" ***"<<endl;
    for(int i=0; i<state.n; i++)
    {
        if(FIRST.s[i][0]==NULL)//避免不必要的运算
            first(state.c[i]);//到这一步有利于建立分析表
        //printfirst(state.c[i]);
    }
    printfirst();
    finalfirst();//最终得到first
    printfirst();
    for(int i=0; i<state.n; i++)
    {
        follow(state.c[i]);//到这一步有利于建立分析表
    }
	for(int i=0; i<FOLLOW.n; i++)
		clear1(i);
    if(clear2())
        printfollow();
    else
        cout<<"循环多次没有求出"<<endl;
    return 0;
}

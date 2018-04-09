/*
   本测试题目目标是巩固单链表的相关操作
   请大家完成有todo注释的成员函数的定义,相应功能已经注释
   根据main中的提示的测试步骤来完成各个成员函数的测试

    循序渐进,提升编程信心,完善设计思维
*/

#include <iostream>
using namespace std;

class Node  //定义结点类型
{
public:
	int data;  //存放数据
	Node* next; //存放后继结点地址
	Node(int val,Node* ptr = 0)  //构造函数,初始化数据成员
	{
		data = val;
		next = ptr;
	}
};
class List
{
public:
	Node* head; //记录表头结点地址

	List()
	{
		head = new Node(0,0);//构造带有表头结点的空的单向链表
	}
	void insertToHead(int x)
	{
		//向表头插入数据值为x的结点
		Node* newNode = new Node(x,0);
		newNode->next = head->next;
		head->next = newNode;
	}

	~List()
	{
	    Node*p;
		while(head!=0)//todo: 1-释放链表的所有结点
        {
            p=head;
            head=head->next;
            delete p;
        }
	}
		void print()
	{

		Node*p=head->next;// todo: 2-依次输出链表的各个结点的数据值
        while(p)
        {
          cout<<p->data<<" ";
          p=p->next;
        }
      cout<<endl;
	}
	void moveMinToEnd()
	{
		//todo:3-将链表中数据域值最小的那个链结点移到链表的最后面。
		//要求：不得额外申请新的链结点
		Node*p=head;
		Node*iend;//记录尾节点
		int num=head->next->data;
		while(p->next)
        {
            if((p->next->data)<num)
            {
                num=p->next->data;
            }
            p=p->next;

        }
        iend=p;
        p=head;
        while(p!=iend)
        {
            if((p->next->data)==num)
            {
                iend->next=p->next;
                p->next=p->next->next;
                iend->next->next=0;
            }
            p=p->next;
        }

	}
	void delItem(int val)
	{
		//todo:4-删除倒数第一个数据值为val的结点
		Node*p=head->next;
		int k=0;//记录最后一次出现val的值
		while(p)
        {
            if(p->data==val)
            {
                ++k;
            }
            p=p->next;
        }
        p=head;
        while(p->next)
        {
            if(p->next->data==val)
            {
                --k;
            }
            if(k==0)
            {
                p->next=p->next->next;break;
            }
            p=p->next;
        }

	}

};

void imove(int a[],int n)
{
    int k=0;//记录连续出现偶数的情况
    int temp;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]%2==0&&a[i+1]%2!=0)
        {
            if(k!=0)
            {
                temp=a[i-k];
                a[i-k]=a[i+1];
                a[i+1]=temp;
                --k;
            }
            else
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }

        }
        if(a[i]%2==0&&a[i+1]%2==0)
        {
            ++k;
        }
    }
}



void movek(int a[],int n,int k)
{
    int b[k];
    for(int i=0;i<k;i++)
    {
        b[i]=a[i];
    }

    for(int i=k;i<n;i++)
    {
        a[i-k]=a[i];
    }

    for(int i=0;i<k;i++)
    {
        a[n-k+i]=b[i];
    }
}

int sum(int a[],int n)
{
    if(n>0)
    {
      return a[n-1]+sum(a,--n);
    }
    else{return 0;}
}
int main()
{
	List mylist;
    // 必须补充: 循环调用insertToHead方法向mylist中添加数据
    for(int i=4;i>1;i--)
    {
        mylist.insertToHead(i);
    }


	/* 下面开始测试各个成员函数,
	可以在实现每个测试目标的时候注释掉为完成其他测试目标而添加的代码*/

    //测试目标1: 测试析构函数----不需添加任何代码


	//测试目标2:测试print方法
	cout<<"输出链表："<<endl;
	mylist.print();

	//测试目标3:测试 moveMinToFirst方法,执行 moveMinToFirst后利用print输出结果来查看
    mylist.moveMinToEnd();
    cout<<"将最小值移到链尾："<<endl;
    mylist.print();
	//测试目标4:测试delItem方法,执行 delItem后利用print输出结果来查看
   mylist.delItem(3);
   cout<<"删除3："<<endl;
   mylist.print();
    int a1[10]={0,1,2,6,7,9,4,6,8,5};
    cout<<"输出数组："<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a1[i];
    }
    cout<<endl;
    imove(a1,10);
    cout<<"输出奇数在前偶数在后的数组："<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a1[i];
    }
    cout<<endl;
    int a2[6]={0,1,2,3,4,5};
    cout<<"输出数组："<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<a2[i];
    }
    cout<<endl;
    movek(a2,6,2);
    cout<<"输出左移2的数组："<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<a2[i];
    }
    cout<<endl;
    int a3[6]={0,1,2,3,4,5};
    cout<<"递归总数："<<endl;
    cout<<sum(a3,6);
return 0;
}

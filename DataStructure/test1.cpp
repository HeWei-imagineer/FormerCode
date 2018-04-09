/*
   ��������ĿĿ���ǹ��̵��������ز���
   ���������todoע�͵ĳ�Ա�����Ķ���,��Ӧ�����Ѿ�ע��
   ����main�е���ʾ�Ĳ��Բ�������ɸ�����Ա�����Ĳ���

    ѭ�򽥽�,�����������,�������˼ά
*/

#include <iostream>
using namespace std;

class Node  //����������
{
public:
	int data;  //�������
	Node* next; //��ź�̽���ַ
	Node(int val,Node* ptr = 0)  //���캯��,��ʼ�����ݳ�Ա
	{
		data = val;
		next = ptr;
	}
};
class List
{
public:
	Node* head; //��¼��ͷ����ַ

	List()
	{
		head = new Node(0,0);//������б�ͷ���Ŀյĵ�������
	}
	void insertToHead(int x)
	{
		//���ͷ��������ֵΪx�Ľ��
		Node* newNode = new Node(x,0);
		newNode->next = head->next;
		head->next = newNode;
	}

	~List()
	{
	    Node*p;
		while(head!=0)//todo: 1-�ͷ���������н��
        {
            p=head;
            head=head->next;
            delete p;
        }
	}
		void print()
	{

		Node*p=head->next;// todo: 2-�����������ĸ�����������ֵ
        while(p)
        {
          cout<<p->data<<" ";
          p=p->next;
        }
      cout<<endl;
	}
	void moveMinToEnd()
	{
		//todo:3-��������������ֵ��С���Ǹ�������Ƶ����������档
		//Ҫ�󣺲��ö��������µ������
		Node*p=head;
		Node*iend;//��¼β�ڵ�
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
		//todo:4-ɾ��������һ������ֵΪval�Ľ��
		Node*p=head->next;
		int k=0;//��¼���һ�γ���val��ֵ
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
    int k=0;//��¼��������ż�������
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
    // ���벹��: ѭ������insertToHead������mylist���������
    for(int i=4;i>1;i--)
    {
        mylist.insertToHead(i);
    }


	/* ���濪ʼ���Ը�����Ա����,
	������ʵ��ÿ������Ŀ���ʱ��ע�͵�Ϊ�����������Ŀ�����ӵĴ���*/

    //����Ŀ��1: ������������----��������κδ���


	//����Ŀ��2:����print����
	cout<<"�������"<<endl;
	mylist.print();

	//����Ŀ��3:���� moveMinToFirst����,ִ�� moveMinToFirst������print���������鿴
    mylist.moveMinToEnd();
    cout<<"����Сֵ�Ƶ���β��"<<endl;
    mylist.print();
	//����Ŀ��4:����delItem����,ִ�� delItem������print���������鿴
   mylist.delItem(3);
   cout<<"ɾ��3��"<<endl;
   mylist.print();
    int a1[10]={0,1,2,6,7,9,4,6,8,5};
    cout<<"������飺"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a1[i];
    }
    cout<<endl;
    imove(a1,10);
    cout<<"���������ǰż���ں�����飺"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<a1[i];
    }
    cout<<endl;
    int a2[6]={0,1,2,3,4,5};
    cout<<"������飺"<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<a2[i];
    }
    cout<<endl;
    movek(a2,6,2);
    cout<<"�������2�����飺"<<endl;
    for(int i=0;i<6;i++)
    {
        cout<<a2[i];
    }
    cout<<endl;
    int a3[6]={0,1,2,3,4,5};
    cout<<"�ݹ�������"<<endl;
    cout<<sum(a3,6);
return 0;
}

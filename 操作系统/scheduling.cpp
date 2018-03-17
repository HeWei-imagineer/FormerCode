#include <iostream>
#include<cstddef>
using namespace std;

enum Tag{UNSHD,SHD};//��ǽ����Ƿ񱻱��

struct PCB
{
    int pid;//���̺�
    size_t arrtime;
    size_t sertime;
    size_t endtime;
    size_t startime;
    float weightime;
    Tag tag;
    PCB* next;
    PCB* pre;
    PCB(int a=0,size_t b=0,size_t c=0):pid(a),arrtime(b),sertime(c),startime(0),weightime(0),next(NULL),tag(UNSHD){}
};

void FRFS(PCB*pcb)
{
    int currtime=0;
    int num=sortPCB(pcb);
    PCB*cur=pcb;
    while(cur->next)
    {
        if(cur->arrtime<=currtime)
        {
            cur->startime=currtime;
            cur->endtime=currtime+cur->sertime;
            cur->weightime=(cur->endtime-cur->arrtime)cur->sertime;
            currtime+=cur->sertime;
            cur->tag=SHD;
            cur=cur->next;
        }
        else{

            currtime++;
        }


    }
}

void SFN(PCB*pcb)//����ռ
{

    sortSerPCB(pcb);
    PCB*cur=pcb;
    do
    {
        sortSerPCB(cur);
        if(cur->arrtime<=currtime)
        {
            cur->startime=currtime;
            cur->endtime=currtime+cur->sertime;
            cur->weightime=(cur->endtime-cur->arrtime)cur->sertime;
            currtime+=cur->sertime;
            cur->tag=SHD;
            cur=cur->next;
        }
        else{
            currtime++;
        }


    }while(cur->next)
}

void SFY(PCB*pcb)//��ռʽ
{
    sortSerPCB(pcb);
    PCB*cur=pcb;
    do
    {

        sortSerPCB(cur);
        if(currtime>cur->arrtime&&cur->sertime< )
        {

        }
        if(cur->arrtime<=currtime)
        {
            cur->startime=currtime;
            cur->endtime=currtime+cur->sertime;
            cur->weightime=(cur->endtime-cur->arrtime)cur->sertime;
            currtime+=cur->sertime;
            cur->tag=SHD;
            cur=cur->next;
        }
        else{
            currtime++;
        }


    }while(cur->next)

}

int sortArrPCB(PCB*head)//������ʱ�����򣬷��ص�ǰ������
{
    PCB*cur=pcb;
    PCB*p=pcb;
    PCB*pre=pcb;

    head->next=pcb;
    int num=0;
    while(cur->next)
    {
      num++;
      cur=cur->next;
    }
    for(int i=0;i<num;++i)
    {
       while(cur->next)
        {
            if(p->arrtime>cur->arrtime)
            {
                p=cur;
                pre=cur;
                cur=cur->next;
            }
        }
        head->next=p;
        p->next=p->next->next;
    }



}

int sortSerPCB(PCB*pcb)//��ִ��ʱ�����򣬷��ص�ǰ������
{

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

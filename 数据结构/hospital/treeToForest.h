#ifndef TREETOFOREST_H_INCLUDED
#define TREETOFOREST_H_INCLUDED
#include"liner_list.h"

class HosNode
{
    friend class Tree;
private:
    int num;
    char*name;
    HosNode*fchild;
    HosNode*rSibling;
public:
    HosNode(HosNode& h){num=h.num;name=h.name;fchild=h.fchild;rSibling=h.rSibling;}
    HosNode(int n=0,char*nm=0){num=n;name=nm;fchild=0;rSibling=0;}
    void inserFirst(HosNode*p);
    void inserNext(HosNode*p);
    void print();
};
void HosNode::inserFirst(HosNode*p)
{
   if(fchild==0)
   {
       fchild=p;
   }
   else
   {
       HosNode*p1,*p2;
       p1=fchild;
       fchild=p;
       p2=p;
       while(p2->rSibling)
       {
           p2=p2->rSibling;
       }
      p2->rSibling=p1;
   }
}

void HosNode::inserNext(HosNode*p)
{
    if(fchild==0)
   {
       fchild=p;
   }
   else
   {
       HosNode*p1;
       p1=fchild;
       while(p1->rSibling)
       {
           p1=p1->rSibling;
       }
       p1->rSibling=p;
   }

}

void HosNode::print()
{
    cout<<name<<" :total num  "<<num<<endl;
    if(fchild!=0)
    {
        HosNode*p;
        p=fchild;
        cout<<p->name<<" ";
        while(p->rSibling)
        {
            p=p->rSibling;
            cout<<p->name<<" ";
        }

    }

}

class Tree
{
private:
    HosNode*root;
public:
    Tree(){root=0;}
    HosNode* Parent(HosNode*current);
    HosNode* Find(char*current);
    HosNode* getroot(){return root;}
    void Insert(char*parent,HosNode*value);
    void RootFirstTraverse(HosNode*root);
    void RootLastTraverse(HosNode*root);
    void WithTraverse(HosNode*root);
    int icount(char*gparent,char*child);

};



void Tree::Insert(char*parent,HosNode*value)
{
    if(root==0)
    {
        root=new HosNode(1,parent);
        root->fchild=value;

    }
    else
    {
        HosNode*p=root;
        arrQueue<HosNode*>aq(100);
        while(p!=0||!aq.isEmpty())
        {
            if(p->name==parent)
            {
                break;
            }
            if(p->fchild!=0)
            {
                aq.enQueue(p->fchild);
            }
            p=p->rSibling;
            if(p==0)
            {
                aq.deQueue(p);
            }

        }
        if(p->name==parent)
        {
            p->inserNext(value);
        }

    }
}

void Tree::WithTraverse(HosNode*root)
{
    if(root==0)
    {
        return;
    }
    else
    {
        HosNode*p=root;
        arrQueue<HosNode*>aq(100);
        while(p!=0||!aq.isEmpty())
        {
            cout<<p->name<<" "<<p->num<<endl;
            if(p->fchild!=0)
            {
                aq.enQueue(p->fchild);
            }
            p=p->rSibling;
            if(p==0)
            {
                cout<<"next floor"<<endl;
                aq.deQueue(p);
            }

        }
}
}
/*void Tree::RootFirstTraverse(HosNode*root)
{
    arrayStack<HosNode*>s(50);
    HosNode* pre;
    pre=root;
    while(pre||!s.isempty())
    {
        if(pre!=0)
        {
            cout<<pre->data;
            if(pre->fchild!=0)
            {
                s.push(pre->getrchild());
            }
            pre=pre->getlchild();
        }
        else
        {
            s.pop(pre);
        }
    }
   cout<<endl;
}*/

int Tree::icount(char*gparent,char*child)
{
    if(gparent==0||child==0)
    {
        return -1;
    }
    HosNode*p=root;
    HosNode*pre=root;
    char*currentname=child;
    arrQueue<HosNode*>aq(100);
    int k=1;
    while(currentname!=gparent)
    {
        while(p!=0||!aq.isEmpty())
        {
            if(p->name==currentname)
            {
                break;
            }
            else
            {
             aq.enQueue(p);
             p=p->rSibling;
             if(p==0)
             {
              aq.deQueue(p);
              pre=p;
              p=p->fchild;
             }
            }

        }
        if(p->name==currentname&&pre!=0)
        {
           k=k*p->num;
        }
        currentname=pre->name;
        p=root;
    }
    return k;

}

HosNode*Tree::Parent(HosNode*current)
{
    HosNode*p=root;
    HosNode*parent=0;
    arrQueue<HosNode*>aq(100);
    while(p!=0||!aq.isEmpty())
    {
     if(p==current)
     {
        break;
     }
     else
     {
         aq.enQueue(p);
         p=p->rSibling;
         if(p==0)
       {
         aq.deQueue(p);
         parent=p;
         p=p->fchild;
       }

     }
    }
    if(p==current&&parent!=0)
    {
        return parent;
    }
    else
        return 0;
}
HosNode* Tree::Find(char* current)
{
    if(current==0)
        return 0;
    else
    {
        HosNode*p=root;
        arrQueue<HosNode*>aq(100);
        while(p!=0||!aq.isEmpty())
        {
            if(p->name==current)
            {
                return p;
            }
            if(p->fchild!=0)
            {
                aq.enQueue(p->fchild);
            }
            p=p->rSibling;
            if(p==0)
            {
                aq.deQueue(p);
            }

        }
        return 0;

    }
}
//know previous order and inorder
/*BinaryTreeNode<char>* creatBinarytree(char A[],int s1,int e1,
                                char B[],int s2,int e2)
{
    int k;
    char iroot=A[s1];
    for(k=s2;k<=e2;++k)
    {
        if(B[k]==iroot)
            break;
    }
    if(k==e2+1)
    {
        return 0;
    }
    int leftlength=k-s2;
    int rightlength=e2-k;
    BinaryTreeNode<char>* root=new BinaryTreeNode<char>(iroot);
    if(s2!=e2)
    {
       root->setlchild(creatBinarytree( A,s1+1,s1+leftlength,B,s2,s2+leftlength-1));
       root->setrchild(creatBinarytree( A, e1-rightlength+1,e1,B, e2-rightlength+1, e2));
    }
    else
        return root;
}
    if(p==current&&parent!=0)
        return parent;
    else
        return 0;

}

/*
HosNode<char>* creatTree(char A[],int s1,int e1,
                                char B[],int s2,int e2)
{
    int k;
    char iroot=A[s1];
    for(k=s2;k<=e2;++k)
    {
        if(B[k]==iroot)
            break;
    }
    if(k==e2+1)
    {
        return 0;
    }
    int leftlength=k-s2;
    int rightlength=e2-k;
    HosNode* root=new HosNode(iroot);
    if(s2!=e2)
    {
       root->fchild(creatBinarytree( A,s1+1,s1+leftlength,B,s2,s2+leftlength-1));
       root->rSibling(creatBinarytree( A, e1-rightlength+1,e1,B, e2-rightlength+1, e2));
    }
    else
        return root;
}*/
#endif // TREETOFOREST_H_INCLUDED

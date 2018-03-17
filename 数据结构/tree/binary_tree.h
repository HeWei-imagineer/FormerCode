#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

template <typename T>
class BinaryTree;

template <typename T>
class BinaryTreeNode
{
    friend class BinaryTree<T>;
private:
    T data;
    BinaryTreeNode<T>* lchild;
    BinaryTreeNode<T>* rchild;
public:
    BinaryTreeNode(T dt, BinaryTreeNode<T>*lc=0, BinaryTreeNode<T>*rc=0)
    {
        data=dt;
        lchild=lc;
        rchild=rc;
    }
    ~BinaryTreeNode(){data=0;}
    BinaryTreeNode<T>* getlchild()
    {
        return lchild;
    }
    BinaryTreeNode<T>* getrchild()
    {
        return rchild;
    }
    void setlchild( BinaryTreeNode<T>*lc)
    {
        lchild=lc;
    }
    void setrchild( BinaryTreeNode<T>*rc)
    {
        rchild=rc;
    }
    T getdata()
    {
        return data;
    }
    void setdata(T dt)
    {
        data=dt;
    }
    bool isLeaf()
    {
        if(lchild==0&&rchild==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


template<typename T>
class BinaryTree
{

public:
    BinaryTreeNode<T>* root;
    BinaryTree(BinaryTreeNode<T>* rt=0)
    {
        root=rt;
    }
    ~BinaryTree()
    {
        delete root;
    }
    bool isEmpty()
    {
        if(root==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int breathFirstOrder(BinaryTreeNode<T>*root);
    void preOrder(BinaryTreeNode<T>*root);
    void InOrder(BinaryTreeNode<T>*root);
    void postOrder(BinaryTreeNode<T>*root);
    void preOrderRecusion(BinaryTreeNode<T>*root);
};



template<typename T>
int BinaryTree<T>::breathFirstOrder(BinaryTreeNode<T>* root)
{
    cout<<"广度优先遍历："<<endl;
    arrQueue<BinaryTreeNode<T>*>que(50);
    BinaryTreeNode<T>*p;//记录当前队头数据
    int i=0;//记录层数
    que.enQueue(root);
    que.enQueue(0);
    que.deQueue(p);
    while(!que.isEmpty())
    {
        if(p==0)
        {
            ++i;
            que.enQueue(0);
        }
        else
        {
            cout<<p->getdata()<<" ";
            if(p->getlchild()!=0)
            {
            que.enQueue(p->getlchild());
            }
            if(p->getrchild()!=0)
            {
            que.enQueue(p->getrchild());
            }
        }
        que.deQueue(p);
    }
    cout<<endl;
    ++i;//最后一次deQueue时，队列空
    return i;
}
template<typename T>
void BinaryTree<T>::preOrderRecusion(BinaryTreeNode<T>*root)
{
    if(root!=0)
    {
        cout<<root->data<<" ";
        preOrderRecusion(root->getlchild());
        preOrderRecusion(root->getrchild());

    }
}
//栈中只存右孩子
template<typename T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>*root)
{
    cout<<"深度先序优先遍历："<<endl;
    arrayStack<BinaryTreeNode<T>*>s(50);
    BinaryTreeNode<T>* pre;
    pre=root;
    while(pre||!s.isempty())
    {
        if(pre!=0)
        {
            cout<<pre->data;
            if(pre->getrchild()!=0)
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
}

//栈中存非空结点，
template<typename T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T>*root)
{
    cout<<"深度中序优先遍历："<<endl;
    arrayStack<BinaryTreeNode<T>*>s(50);
    BinaryTreeNode<T>* pre;
    pre=root;
    while(pre||!s.isempty())
    {
        if(pre!=0)
        {
            s.push(pre);
            pre=pre->getlchild();

        }
        else
        {
            s.pop(pre);
            cout<<pre->data;
            pre=pre->getrchild();
        }

    }
    cout<<endl;
}


template<typename T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>*root)
{
    cout<<"深度后序优先遍历："<<endl;
    arrayStack<BinaryTreeNode<T>*>s(50);
    BinaryTreeNode<T>* pre;
    BinaryTreeNode<T>* p;
    pre=root;
    while(pre||!s.isempty())
    {
       if(pre!=0)
        {
            s.push(pre);
            pre=pre->getlchild();
        }
        else
        {
            s.Top(p);
            while(pre==p->getrchild())//如果当前节点为之前节点的右孩子，对之前节点进行访问删除操作
            {
                s.pop(pre);
                cout<<pre->data;
                s.Top(p);
            }
           pre=p->getrchild();
           if(s.isempty())
                pre=0;
        }


    }
}
//know previous order and inorder
BinaryTreeNode<char>* creatBinarytree(char A[],int s1,int e1,
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

//线索二叉树
template <typename T>
class ThreadBinaryTree;

template <typename T>
class ThreadBinaryTree_Node
{
    friend class ThreadBinaryTree<T>;
private:
    T data;
    int leftTag;
    int rightTag;
    ThreadBinaryTree_Node<T>* lchild;
    ThreadBinaryTree_Node<T>* rchild;
public:
    ThreadBinaryTree_Node(T dt, ThreadBinaryTree_Node<T>*lc=0, ThreadBinaryTree_Node<T>*rc=0)
    {
        data=dt;
        lchild=lc;
        rchild=rc;
    }
    ThreadBinaryTree_Node<T>* getlchild()const
    {
        return lchild;
    }
    ThreadBinaryTree_Node<T>* getrchild()const
    {
        return rchild;
    }
    void setlchild( ThreadBinaryTree_Node<T>*lc)
    {
        lchild=lc;
    }
    void setrchild( ThreadBinaryTree_Node<T>*rc)
    {
        rchild=rc;
    }
    T getdata()
    {
        return data;
    }
    void setdata(T dt)
    {
        data=dt;
    }
    bool isLeaf()
    {
        if(lchild==0&&rchild==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

template<typename T>
class ThreadBinaryTree
{
private:
     ThreadBinaryTree_Node<T>* root;
public:

    ThreadBinaryTree(ThreadBinaryTree_Node<T>* rt=0)
    {
        root=rt;
    }
    ~ThreadBinaryTree()
    {
        delete root;
    }
    bool isEmpty()
    {
        if(root==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ThreadBinaryTree_Node<T>* getroot(){return root;}
    //中序线索化二叉树
    void InThread(ThreadBinaryTree_Node<T>*root,ThreadBinaryTree_Node<T>*pre);
    //中序遍历
    void InOrder(ThreadBinaryTree_Node<T>*root);
};

template<typename T>
void ThreadBinaryTree<T>::InThread(ThreadBinaryTree_Node<T>*root,ThreadBinaryTree_Node<T>*pre)
{
    ThreadBinaryTree_Node<T>* current;
    current=root;
    if(current!=0)
    {
        InThread(current->getlchild(),pre);
        if(current->getlchild()==0)
        {
            current->getlchild()=pre;
            current->leftTag=1;
        }
        if((pre)&&pre->getrchild()==0)
        {
            pre->getrchild()=root;
            pre->rightTag=1;
        }
        pre=current;
        InThread(current->getrchild(),pre);
    }
}

template<typename T>
void ThreadBinaryTree<T>::InOrder(ThreadBinaryTree_Node<T>*root)
{
    ThreadBinaryTree_Node<T>* current;
    current=root;
    while(current->leftTag==0)
        current=current->getlchild();
    while(current!=0)
    {
        cout<<current->data;
        if(current->rightTag==1)
        {
            current=current->getrchild();
        }
        else
        {
            current=current->getrchild();
            while(current&&current->leftTag==0){current=current->getlchild();}
        }
    }


}


//二叉搜索树的相关操作
template <typename T>
class BinarySearchTreeNode
{
public:
    T key;
    BinarySearchTreeNode<T>* lchild;
    BinarySearchTreeNode<T>* rchild;

    BinarySearchTreeNode(T dt, BinarySearchTreeNode<T>*lc=0, BinarySearchTreeNode<T>*rc=0)
    {
        key=dt;
        lchild=lc;
        rchild=rc;
    }
    ~BinarySearchTreeNode(){key=0;}

    bool isLeaf()
    {
        if(lchild==0&&rchild==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTreeNode<T>* root;
    BinarySearchTree(){root=0;}
    BinarySearchTreeNode<T>* isearch(BinarySearchTreeNode<T>* root,T k);
    void insertNode(BinarySearchTreeNode<T>* node);
    void deleteByMerging(BinarySearchTreeNode<T>*& node);
    void deleteByCopying(BinarySearchTreeNode<T>*& node);
    void breathFirstOrder(BinarySearchTreeNode<T>* root);
};
template <typename T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::isearch(BinarySearchTreeNode<T>*root,T k)
{
    BinarySearchTreeNode<T>*p;
    p=root;
    if(root==0)
        return false;
    while(p&&(p->key)!=k)
    {
        if(p->key>k)
            p=p->lchild;
        if(p->key<k)
            p=p->rchild;
    }
   return p;
}


//未考虑插入值与原有键码相同的情况
template <typename T>
void BinarySearchTree<T>::insertNode(BinarySearchTreeNode<T>* node)
{
    if(root==0)
    {
         root=node;return;
    }
    else
    {
    BinarySearchTreeNode<T>*current;
    current=root;
    BinarySearchTreeNode<T>*pre;
    while(current!=0)
    {
        pre=current;
        current=current->key>node->key?current->lchild:current->rchild;
    }
    if(pre->lchild==current)
        pre->lchild=node;
    else
        pre->rchild=node;
    }


}


//这样的话只能传节点里的指针进来,且父节点孩子指针有问题
template <typename T>
void BinarySearchTree<T>::deleteByMerging(BinarySearchTreeNode<T>*& node)
{
    BinarySearchTreeNode<T>*temp;
    if(!node->lchild)
    {
        node=node->rchild;
    }
    else if(!node->rchild)
    {
        node=node->lchild;
    }
    else{
        temp=node->lchild;
        while(temp->rchild){temp=temp->rchild;}
        temp->rchild=node->rchild;
        node=node->lchild;
    }
    temp=node;
    delete temp;
}


template <typename T>
void BinarySearchTree<T>::deleteByCopying(BinarySearchTreeNode<T>*& node)
{
    if(!node->lchild&&!node->rchild){delete node;}
    BinarySearchTreeNode<T>*temp;
    BinarySearchTreeNode<T>*pre;
    if(!node->lchild)
    {
        node=node->rchild;
    }
    else if(!node->rchild)
    {
        node=node->lchild;
    }
    else{
        temp=node->lchild;
        while(temp->rchild){pre=temp;temp=temp->rchild;}
        node->key=temp->rchild->key;
        if(!temp->lchild)
        {
          pre->rchild=temp->lchild;
          delete temp;
        }
    }

}
template<typename T>
void BinarySearchTree<T>::breathFirstOrder(BinarySearchTreeNode<T>* root)
{
    cout<<"广度优先遍历："<<endl;
    arrQueue<BinarySearchTreeNode<T>*>que(50);
    BinarySearchTreeNode<T>*p;//记录当前队头数据
    int i=0;//记录层数
    que.enQueue(root);
    que.enQueue(0);
    que.deQueue(p);
    while(!que.isEmpty())
    {
        if(p==0)
        {
            ++i;
            que.enQueue(0);
        }
        else
        {
            cout<<p->key<<" ";
            if(p->lchild!=0)
            {
            que.enQueue(p->lchild);
            }
            if(p->rchild!=0)
            {
            que.enQueue(p->rchild);
            }
        }
        que.deQueue(p);
    }
    cout<<endl;
    ++i;//最后一次deQueue时，队列空

}
#endif // BINARY_TREE_H_INCLUDED

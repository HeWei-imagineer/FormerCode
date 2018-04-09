#ifndef HOMEWORK_H_INCLUDED
#define HOMEWORK_H_INCLUDED

#include"binary_tree.h"
#include"liner_list.h"
using namespace std;
template<typename T>
int one_node(BinaryTreeNode<T>*root)
{
    if(root==0){return 0;}
    if(root->getlchild()!=0&&root->getrchild()==0)
    {
        return 1+one_node(root->getlchild());

    }
    if(root->getlchild()==0&&root->getrchild()!=0)
    {
        return 1+one_node(root->getrchild());
    }
    if(root->getlchild()!=0&&root->getrchild()!=0)
    {
       return one_node(root->getlchild())+one_node(root->getrchild());

    }
    else
        return 0;

}

/*template<typename T>
int one_node(BinaryTreeNode<T>*root){
    if(root==0){return 0;}
    if((root->getlchild()!=0)^(root->getrchild()!=0))
    {return 1+(root->getlchild()!=0?one_node(root->getlchild()):one_node(root->getrchild()));}
    else return one_node(root->getlchild())+one_node(root->getrchild());
}*/
template<typename T>
int two_node(BinaryTreeNode<T>*root)
{

    if(root->getlchild()!=0&&root->getrchild()!=0)
    {

        return 1+two_node(root->getlchild())+two_node(root->getrchild());
    }
    else if(root->getlchild()!=0)
    {
        return two_node(root->getlchild());
    }
    if(root->getrchild()!=0)
    {
        return two_node(root->getrchild());
    }
    else
        return 0;

}
template<typename T>
int no_node(BinaryTreeNode<T>*root,int& k)
{
    if(root==0){return 0;}
    if(root->getlchild()!=0)
    {
       no_node(root->getlchild(),k);
    }
    if(root->getrchild()!=0)
    {
      no_node(root->getrchild(),k);
    }
    else
    {
        return ++k;
    }
}


template<typename T>
int tree_high(BinaryTreeNode<T>*root)
{
   if(root==0){return 0;}
   else{
       return 1+(tree_high(root->getlchild())>tree_high(root->getrchild())?tree_high(root->getlchild()):tree_high(root->getrchild()));
   }
}
//important! firstly,level and depth are 1
template<typename T>
int tree_high(BinaryTreeNode<T>*root,int level,int& depth)
{
    if(root==0)
    {
        return 0;
    }
    else
    {
        if(level>depth){depth=level;}
        tree_breadth(root->getlchild(),++level,depth);
        tree_breadth(root->getrchild(),++level,depth);
    }

}
//important!
/*template<typename T>
int tree_high(BinaryTreeNode<T>*root)
{
    if(root==0)
    {
        return 0;
    }
    else
    {
        int h1=tree_breadth(root->getlchild());
        int h2=tree_breadth(root->getrchild());
        return 1+h1>h2?h1:h2;
    }
}*/
template<typename T>
int tree_breadth(BinaryTreeNode<T>*root,int n)
{
    // int i=0;//记录层数
        int num1=0,num2=0;
        BinaryTreeNode<T>*p=root;
        arrQueue<BinaryTreeNode<T>*>que(n);
    if(root==0){return 0;}


    else
    {
       que.enQueue(0);
       while(!que.isEmpty())
        {
        if(p==0)
        {//++i;
         num2=num1>num2?num1:num2;
         num1=0;
         que.enQueue(0);

        }
        else
        {
        if(p->getlchild()!=0)
        {
         que.enQueue(p->getlchild());
         ++num1;
        }
        if(p->getrchild()!=0)
        {
         que.enQueue(p->getrchild());
         ++num1;
        }
        }
    que.deQueue(p);
    }
    }

    return num2=num1>num2?num1:num2;
}
//firstly,level is 0
template<typename T>
int* tree_breadth(BinaryTreeNode<T>*root,int*arr,int level)
{
    if(root==0){return 0;}
    else
    {
        ++arr[level++];
        tree_breadth(root->getlchild(),arr,level);
        tree_breadth(root->getrchild(),arr,level);
    }
    return arr;
}
template<typename T>
int maxnum(BinaryTreeNode<T>*root)
{
    if(root==0){return 0;}
    if(root->getlchild()!=0&&root->getrchild()==0)
   {
     return root->getdata()>maxnum(root->getlchild())?root->getdata():maxnum(root->getlchild());
   }
   if(root->getrchild()!=0&&root->getlchild()==0)
   {
       return root->getdata()>maxnum(root->getrchild())?root->getdata():maxnum(root->getrchild());
   }
   if(root->getrchild()!=0&&root->getlchild()!=0)
   {
       if(maxnum(root->getlchild())>maxnum(root->getrchild()))
           return root->getdata()>maxnum(root->getlchild())?root->getdata():maxnum(root->getlchild());
       else
           return root->getdata()>maxnum(root->getrchild())?root->getdata():maxnum(root->getrchild());
   }
   else{return root->getdata();}

}

/*template<typename T>
void exchangeLtoR(BinaryTreeNode<T>*root)
{
    if(root==0||(root->getlchild()==0&&root->getlchild()==0)){return;}

    if(root->getrchild()==0)
    {
        exchangeLtoR(root->getlchild());
        root->setrchild(root->getlchild());
        root->setlchild(0);

    }
    if(root->getlchild()==0)
    {
         exchangeLtoR(root->getrchild());
         root->setlchild(root->getrchild());
         root->setrchild(0);

    }
    else
    {
        exchangeLtoR(root->getlchild());
        exchangeLtoR(root->getrchild());
        BinaryTreeNode<T>*p;
        p=root->getlchild();
        root->setlchild(root->getrchild());
        root->setrchild(p);

    }


}*/

template<typename T>
void exchangeLtoR(BinaryTreeNode<T>*root)
{
      BinaryTreeNode<T>*  temp;
      if (root!=0)
    { //非空
      //交换当前结点左右孩子的位置
		temp=root->getlchild();
		root->setlchild(root->getrchild());
        root->setrchild(temp);
        //递归交换
        exchangeLtoR(root->getlchild());
        exchangeLtoR(root->getrchild());
	 }
}


template<typename T>
void deletleaf(BinaryTreeNode<T>*root)
{
   if(root==0){return;}
   if(root->getlchild()!=0)
   {
       if(root->getlchild()->getlchild()==0&&root->getlchild()->getrchild()==0)
       {
           delete root->getlchild();
           root->setlchild(0);
       }
       else
       {
           deletleaf(root->getlchild());
       }

   }
    if(root->getrchild()!=0)
    {
        if(root->getrchild()->getlchild()==0&&root->getrchild()->getrchild()==0)
        {
            delete root->getrchild();
            root->setrchild(0);
        }
        else
        {
            deletleaf(root->getrchild());
        }

    }
}
//what a pity! so shallow
/*template<typename T>
bool IsCompeletTree(BinaryTreeNode<T>*root)
{
    if(root==0){return false;}
    if(root->getlchild()==0&&root->getrchild()!=0)
        return false;
    if(root->getlchild()==0&&root->getrchild()==0)
        return true;
    if(root->getlchild()!=0||root->getrchild()!=0)
    {
       IsCompeletTree(root->getlchild());
       IsCompeletTree(root->getrchild());
    }
}*/
template<typename T>
bool IsCompeletTree(BinaryTreeNode<T>*root)
{
    BinaryTreeNode<T>*p=root;
    arrQueue<BinaryTreeNode<T>*>que(20);
    if(root==0){return false;}
    else
    {
       que.enQueue(root);
       while(!que.isEmpty())
        {
          que.deQueue(p);
          if((p->getlchild()==0||p->getrchild()==0)&&!que.isEmpty())
          {
              return false;
          }
            else
            {
            if(p->getlchild()!=0)
            {
             que.enQueue(p->getlchild());
            }
            if(p->getrchild()!=0)
            {
             que.enQueue(p->getrchild());
            }
            }
        }
         return true;
      }
}
#endif // HOMEWORK_H_INCLUDED

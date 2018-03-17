#include <iostream>
#include"liner_list.h"
#include"binary_tree.h"
#include"homework.h"

using namespace std;

int main()
{
    char A[]={'a','b','e','c','d','f','g','h','i','j'};
    char B[]={'e','b','c','d','a','f','h','i','g','j'};
    char C[]={'a','b','d','f','g','i','c','e','h','k'};
    char D[]={'f','g','d','i','b','a','e','c','k','h'};
    BinaryTree<char>tree1;
    tree1.root=creatBinarytree( A,0,10,B,0,10);
    tree1.breathFirstOrder(tree1.root);

    cout<<endl;
    cout<<tree1.breathFirstOrder(tree1.root)<<endl;
    tree1.preOrder(tree1.root);
    tree1.InOrder(tree1.root);
    tree1.postOrder(tree1.root);
    int k=0;
    int arr[5]={0,0,0,0,0};
    int level=0;
    cout<<"one node:"<<endl;
    cout<<one_node(tree1.root)<<endl;
    cout<<"two node:"<<endl;
    cout<<two_node(tree1.root)<<endl;
    cout<<"no node:"<<endl;
    cout<<no_node(tree1.root,k)<<endl;
    cout<<"tree hight:"<<endl;
    cout<<tree_high(tree1.root)<<endl;
    cout<<"maxnum:"<<endl;
    cout<<maxnum(tree1.root)<<endl;
    cout<<"tree's breadth:(输出每一层结点数)"<<endl;
    tree_breadth(tree1.root,arr,level);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    tree1.breathFirstOrder(tree1.root);
    exchangeLtoR(tree1.root);
    tree1.breathFirstOrder(tree1.root);
    deletleaf(tree1.root);
    tree1.breathFirstOrder(tree1.root);
if(IsCompeletTree(tree1.root))
    cout<<"is";
else
    cout<<"no";




//二叉搜索树
/*BinarySearchTreeNode<int>P{p1(1),p2(2),p3(3),p4(4),p5(5)};
   BinarySearchTree<int>Stree;
   for(int i=0;i<5;i++)
   {
        Stree.insertNode(&P[i]);
   }*/
   /*BinarySearchTreeNode<int>p1(1);
   BinarySearchTreeNode<int>p2(2);
   BinarySearchTreeNode<int>p3(3);
   BinarySearchTreeNode<int>p4(4);
   BinarySearchTreeNode<int>p5(5);
   BinarySearchTree<int>Stree;
   Stree.insertNode(&p1);
   Stree.insertNode(&p2);
   Stree.insertNode(&p3);
   Stree.insertNode(&p4);
   Stree.insertNode(&p5);
   Stree.breathFirstOrder(Stree.root);
   Stree.breathFirstOrder(Stree.root);
   Stree.isearch(Stree.root,5);
   Stree.breathFirstOrder(Stree.root);*/


}

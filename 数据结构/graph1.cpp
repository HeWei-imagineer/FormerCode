#include <iostream>
#include"graph1.h"
using namespace std;

int main()
{
    /*Graph g1(8);
    g1.matrix[0][1]= g1.matrix[1][0]= g1.matrix[0][2]=g1.matrix[2][0]= g1.matrix[1][3]= g1.matrix[3][1]=1;
    g1.matrix[1][4]= g1.matrix[4][1]=g1.matrix[3][7]= g1.matrix[7][3]= g1.matrix[4][7]= g1.matrix[7][4]=1;
    g1.matrix[2][5]= g1.matrix[5][2]= g1.matrix[2][6]=g1.matrix[6][2]=g1.matrix[5][6]= g1.matrix[6][5]=1;
     g1.BFS();
    //g1.DFS();
    /*for(int i=0;i<8;++i)
    {
        for(int j=0;j<8;++j)
        {
            cout<<g1.matrix[i][j]<<" ";
         if((j+1)%8==0)
            cout<<endl;
        }
    }
    g1.BFS();*/

    Graph g2(6);
    g2.matrix[0][1]= g2.matrix[1][0]=6;
    g2.matrix[0][2]= g2.matrix[2][0]=1;
    g2.matrix[0][3]= g2.matrix[3][0]=5;
    g2.matrix[1][4]= g2.matrix[4][1]=3;
    g2.matrix[1][2]= g2.matrix[2][1]=5;
    g2.matrix[3][2]= g2.matrix[2][3]=5;
    g2.matrix[4][2]= g2.matrix[2][4]=6;
    g2.matrix[2][5]= g2.matrix[5][2]=4;
    g2.matrix[3][5]= g2.matrix[5][3]=2;
    g2.matrix[5][4]= g2.matrix[4][5]=6;
    //g2.Prime();
    //g2.Kruskal();
    g2.findSmalltree();
    g2.DFS();


    /*Graph g3(6);
    g3.matrix[0][1]=12;
    g3.matrix[0][2]=10;
    g3.matrix[0][4]=30;
    g3.matrix[0][5]=100;
    g3.matrix[1][2]=5;
    g3.matrix[2][3]=50;
    g3.matrix[3][5]=10;
    g3.matrix[4][3]=20;
    g3.matrix[5][4]=60;
    g3.matrix[3][0]=3;
    g3.Floyd();
    g3.matrix=g3.Floyd();
    g3.print();
    /*int *p=g3.Dijkstra(0);
    for(int i=0;i<g3.vertexNum;++i)
    {
        cout<<p[i]<<" ";
    }*/




    return 0;
}

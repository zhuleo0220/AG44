#include"Graph.h"
#include <iostream>
#include <cstdio>
#define INF 10000

using namespace std;

typedef char DATATYPE;





    void prim(int ** matrix,int N)
{
    bool flag[N]; //标记某个点是否当前生成树集合中
    int i,j;
    //初始化集合
    for(i = 0; i < N; ++i) flag[i] = false;

    flag[0] = true;
    int count = 1;
    Graph G2(N);
    while(count++ < N)
    {
        int min = 100000;
        int e1 = -1, e2 = -1;
        for(i = 0; i < N; ++i)
        {
            if(flag[i])
            {
                for(j = 0; j < N; ++j)
                {
                    if(!flag[j])
                    {
                        if((matrix[i][j] < min)&&(matrix[i][j]!=0))
                        {
                            min = matrix[i][j];
                            e1 = i;
                            e2 = j;
                        }
                    }
                }
            }
        }
        cout << e1 + 1 << "-" << e2 + 1<<" "<< matrix[e1][e2] << endl;
        G2.add_edges_int(e1+1,e2+1,matrix[e1][e2]);
        G2.add_edges_int(e2+1,e1+1,matrix[e1][e2]);
        flag[e2] = true;
    }
    G2.create_Matrix_fr_edges();
    G2.print_matrix();
}





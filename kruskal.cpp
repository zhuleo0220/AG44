#include"Graph.h"
#include <iostream>
void kruskal(Graph &G){
    int i,m,n;
    int p1,p2;
    int length=G.number_of_vertex();
    int index = 0;          // rets数组的索引
    int vends[length]={0};     // 用于保存"已有最小生成树"中每个顶点在该最小树中的终点。
    Edges rets[length-1];        // 结果数组，保存kruskal最小生成树的边

  
    G.sort_edges();

    for (i=0; i<G.number_of_edges(); i+=2)
    {
        p1 = G.get_edges()[i].get_src().iden() ;      // 获取第i条边的"起点"的序号
        p2 = G.get_edges()[i].get_dest().iden() ;      // 获取第i条边的"终点"的序号

        m =vends[p1-1];                // 获取p1在"已有的最小生成树"中的终点
        n =vends[p2-1];                 // 获取p2在"已有的最小生成树"中的终点
        // 如果m!=n，意味着"边i"与"已经添加到最小生成树中的顶点"没有形成环路
        
        if ((m==0)&&(n==0))
        {
            vends[m] = n;                       // 设置m在"已有的最小生成树"中的终点为n
            rets[index++] = G.get_edges()[i];
            cout<<rets[index-1];           // 保存结果
        }
        if (m != n)
        {
            vends[m] = n;                       // 设置m在"已有的最小生成树"中的终点为n
            rets[index++] = G.get_edges()[i];
            cout<<rets[index-1];           // 保存结果
        }
    }
}
#include<vector>
#include <iostream>
using namespace std;


void Dijkstra2( int** G,int s, int n)
{
       /*
       param
       n：           顶点个数
       s：           源点
       G：           图的邻接矩阵
       vis：         标记顶点是否已被访问
       d：           存储源点s到达其它顶点的最短距离
       */
	  vector<bool> vis(n);
	  vector<int> d(n);
	   for(int i=0;i<n;++i)  
    {  
        for(int j=0;j<n;++j)  
        {  
            if(G[i][j]==0)  
                G[i][j]=99999;
        }    
    }

	  int INF=99999;
       fill(d.begin(), d.end(), INF);                         //初始化最短距离矩阵，全部为INF
       d[s] = 0;                                              //起点s到达自身的距离为0
       for (int i = 0; i < n; ++i)
       {
              int u = -1;                                     //找到d[u]最小的u
              int MIN = INF;                                  //记录最小的d[u]
              for (int j = 0; j < n; ++j)                     //开始寻找最小的d[u]
              {
                     if (vis[j] == false && d[j] < MIN)
                     {
                           u = j;
                           MIN = d[j];
                     }
              }
              //找不到小于INF的d[u]，说明剩下的顶点和起点s不连通
              if (u == -1)
                     return;
              vis[u] = true;                                  //标记u已被访问
              for (int v = 0; v < n; ++v)
              {
                     //遍历所有顶点，如果v未被访问&&u能够到达v&&以u为中介点可以使d[v]更优
                     if (vis[v] == false && d[u] + G[u][v] < d[v])
                           d[v] = d[u] + G[u][v];             //更新d[v]
              }
       }
	   for(int i=0;i<n;++i){
		   cout<<d[i]<<"  ";
	   }
}
void Dijkstra( int** G,int n){
	for(int i=0;i<n;++i){
		Dijkstra2(G,i,n);
		cout<<endl;
	}
}


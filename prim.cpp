#include"Graph.h"
#include <iostream>
#include <cstdio>
#define INF 10000

using namespace std;

typedef char DATATYPE;


void Prim(int** MGraph, int vNum) {
    int* lowcost = new int[vNum];
    int* mst = new int[vNum];

    //初始化lowcost与mst数组
    for (int i = 0; i < vNum; i++) {
        lowcost[i] = MGraph[0][i];
        mst[i] = 0;
    }

    //寻找最小生成树
    int min;
    int minid;
    int totalWeight = 0;
    for(int i = 0; i < vNum - 1; i++) {
        //查找与顶点集S连接的代价最小的边
        min = INF;//INF
        minid = -1;
        for (int j = 1; j < vNum; j++) {
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                minid = j;
            }
        }
        //将找到的顶点加入到顶点集S中（此处为输出），并将代价设为0
        //cout << vData[mst[minid]] << "-" << vData[minid] << " = " << min << endl;
        totalWeight += min;
        lowcost[minid] = 0;
        //更新lowcost与mst
        for (int j = 1; j < vNum; j++) {
            if (MGraph[minid][j] < lowcost[j]) {
                lowcost[j] = MGraph[minid][j];
                mst[j] = minid;
            }
        }
    }

    cout << "Total Weight: " << totalWeight << endl;
}
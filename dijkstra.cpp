#include<vector>
using namespace std;
void Dijkstra(int** matrix,int start,int nodenum,int* dist,int* path)
{
	vector<int> tpath;
	int* flag=new int(nodenum);
	for(int i=0;i<=nodenum-1;i++)
	{
		flag[i]=0;
		dist[i]=9999;
		path[i]=-1;
	}
	flag[start]=1;
	path[start]=start;
	dist[start]=0;
	tpath.push_back(start);
	//initial
 
	while(tpath.size()!=0)
	{
		int tnode=tpath[0];
		tpath.erase(tpath.begin());
		for(int i=0;i<=nodenum-1;i++)
		{
			if(matrix[tnode][i]!=-1)
			{
				if(dist[tnode]+matrix[tnode][i]<dist[i])
				{
					dist[i]=dist[tnode]+matrix[tnode][i];
					path[i]=tnode;
					if(flag[i]==0)
					{
						tpath.push_back(i);
						flag[i]=1;
					}
				}
 
			}
		}
	}
}
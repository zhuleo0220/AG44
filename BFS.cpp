#include"Graph.h"
#include <iostream>
#include<list>


void BFS(Graph &G, int id) //id is the starting vertex
{
    G.setunvisited();
    list<int> q; //the queue we'll use
    G.visite_vertice(id);
    q.push_back(id);
    while(!q.empty())
    {
        id=q.front();
        cout << id << " ";
        q.pop_front();
        for(int i=0;i<G.get_Vertices()[id-1].number();++i)
        {
            if(!G.visited(G.get_Vertices()[id-1].neighbours()[i]))
            {
                G.visite_vertice(G.get_Vertices()[id-1].neighbours()[i]);
                q.push_back(G.get_Vertices()[id-1].neighbours()[i]);
            }
        }
    }
}

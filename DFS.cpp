#include"Graph.h"
#include <iostream>


void DFS_sort(Graph &G, int id)//Reminder : the vertex number x has 'id=x'
{
    G.visite_vertice(id); //mark the vertex as visited
    cout << id << " ";
    for(int i=0;i<G.get_Vertices()[id-1].number();++i)
    {
        if(!G.visited(G.get_Vertices()[id-1].neighbours()[i]))
        {
            DFS_sort(G, G.get_Vertices()[id-1].neighbours()[i]);
        }
    }
}
void DFS(Graph &G,int n)
{
    G.setunvisited();
    DFS_sort(G, n); //1 is the id of the starting vertex
}

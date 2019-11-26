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
        for(int i=0;i<#NeighborsSize#;++i)
        {
            if(!G.visited(i))
            {
                G.visite_vertice(i);
                Q.push_back(i);
            }
        }
    }
}

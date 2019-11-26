
void DFS(Graph &G)
{
    G.setunvisited();
    DFS_sort(&G, 1); //1 is the id of the starting vertex
}

void DFS_sort(Graph &G, int id)//Reminder : the vertex number x has 'id=x'
{
    G.visite_vertice(id); //mark the vertex as visited
    cout << id << " ";
    for(int i=0;i<G.get_Vertices()[id].number();++i)
    {
        if(!G.visited(id))
        {
            DFS_sort(&G, i);
        }
    }
}

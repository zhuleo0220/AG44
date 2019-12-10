// We already have the DFS_sort
// We have a function getTranspose that gives the transpose of a graph G
// getTranspose would just be another constructor of Graph that switches the src/dest values

void fillOrder(int id, Graph &G, stack<int> &Stack)
{
    Gvisite_vertice(id);
    for(int i=1;i<=G.get_Vertices()[id-1].number();++i)
    {
        if(!G.visited(G.get_Vertices()[id-1].neighbours()[i]))
        {
            fillOrder(G.get_Vertices()[id-1].neighbours()[i], G, Stack);
        }
    }
    Stack.push(id);
}

void printSCC(Graph &G)
{
    int v;
    stack<int> Stack;
    G.setunvisited();
    for(int id=0;id<G.number_of_vertex();++id)
    {
        if(!G.visited(id))
        {
            fillOrder(id,G,Stack);
        }
    }
    Graph Gr = getTranspose(); ///getTranspose may take G as an argument
    G.setunvisited();
    Gr.setunvisited();//Not sure if both need to be reset ...
    while(!Stack.empty())
    {
        v=Stack.top();
        Stack.pop();
        if(!Gr.visited(v))
        {
            Gr.DFS_sort(Gr,v);
            cout << endl;
        }
    }
}

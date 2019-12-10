void topologicalSort(Graph& G)
{
    stack(int) Stack;
    G.setunvisited();
    for(int id=0;id<#numberOfVertices#;++id)
    {
        if(!G.visited(id))
        {
            topologicalSortUtil(id,G,Stack);
        }
    }
    while (Stack.empty() == false) 
    { 
        cout << Stack.top() << " "; 
        Stack.pop(); 
    } 
}

void topologicalSortUtil(int id, Graph& G, stack<int> &Stack)
{
    G.visite_vertice(id);
    for(int i=0;i<G.get_Vertices()[id-1].number();++i)
    {
        if(!G.visited(G.get_Vertices()[id-1].neighbours()[i]))
        {
            topologicalSortUtil(G.get_Vertices()[id-1].neighbours()[i], G, Stack);
        }
    }
    Stack.push(id);
}

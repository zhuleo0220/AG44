#define INF 99999

using namespace std;

void printSolution(int dist[][G.number_of_vertex]);

void floydWarshall (int standardTab[]) //StandardTab is the table built from the file to create the graph 
{
    int V = G.number_of_vertex; //We set V so we don't have to call the function too many times
    int dist[V][V], i, j, k;
    
    for(i=0;i<V;++i)
    {
        for(j=0;j<V;++j)
        {
            dist[i][j] = standardTab[i*V+j];
        }
    }
    for(k=0;k<V;++k)  
    {  
        for(i=0;i<V;++i)  
        {  
            for(j=0;j<V;++j)  
            {  
                if(dist[i][k] + dist[k][j] < dist[i][j])  
                {
                    dist[i][j] = dist[i][k] + dist[k][j];  
                }
            }  
        }  
    }
    printSolution(dist);  
}   

void printSolution(int dist[][G.number_of_vertex])
{
    cout<<"The following matrix shows the shortest distances between every pair of vertices"<<endl;  
    for(int i=0;i<V;++i)  
    {  
        for(int j=0;j<V;++j)  
        {  
            if(dist[i][j]==INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}

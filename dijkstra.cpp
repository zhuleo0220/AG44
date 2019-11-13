#include "Graph.h"
#include <set>


extern Graph G;
friend class Graph;


bool Dijkstra(int src, int dest){
    int PathDistance=0;
    if ((G->get_Vertices()[src]->number()==0)  ||  (src==dest)) {
        return false;
    }
    G->get_Vertices()[src]->id_of_pere=-1;
    int Max = 100000;   
    set< pair<double, int> > setdest;
    set< pair<double, int> >::iterator tmp;
    vector<double> cost(G->number_of_vertex(), Max);
    cost[src] = 0;
    setdest.insert(make_pair(cost[src], src));
    while (!setdest.empty() ){
        tmp = setdest.begin();
        int u = (*tmp).second;
        setdest.erase(setdest.begin());
        if (u == dest) break;
        if (G->get_Vertices()[u]number()==0) continue;
        for (int i=0;i< G->get_Vertices()[u]->NbVoisins;i++){
            int v = G->get_Vertices()[u]->LstVoisins[i].first;// this one is vertex id v
            int idEdge = G->get_Vertices()[u]->LstVoisins[i].second;//this one is edge id u - v
            double weight= G->LstEdges[idEdge]->dist;
            if (cost[v] > cost[u] + weight ){
                if (cost[v] != Max){
                    setdest.erase(setdest.find(make_pair(cost[v], v)));
                }
                cost[v] = cost[u] + weight;
                setdest.insert(make_pair(cost[v], v));
                G->get_Vertices()[v]->Pere = u;
                G->get_Vertices()[v]->PreviousEdgeId = G->listVertex[u]->LstVoisins[i].second;
            }
        }
    }
    int curr = dest;
    cout<< curr->id<< "; ";
    while (curr != src){
        int idEdge=G->LstNoeuds[curr]->PreviousEdgeId;
        Edge* edge = G->LstEdges[idEdge];
        PathDistance += edge->dist;   
        curr = G->LstNoeuds[curr]->Pred;     
        Cout<< curr->id<< "; ";
    }
cout << endl;
cout<< << "Disatance = " << PathDistance<<endl ;
    return true;
}
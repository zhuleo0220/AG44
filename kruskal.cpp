#include"Graph.h"
#include <iostream>
void kruskal(Graph &G){
    Graph G2(G.number_of_vertex());
    G.sort_edges();
    int i=0;
    for(int i=0,j=0;(i<G.number_of_vertex()-1)&&(j<G.number_of_edges());j=j+2){
        if((G2.get_Vertices()[G.get_edges()[j].get_src().iden()-1].number()==0)||(G2.get_Vertices()[G.get_edges()[j].get_dest().iden()-1].number()==0)){
            G2.add_edges_int(G.get_edges()[j].get_src().iden(),G.get_edges()[j].get_dest().iden(),G.get_edges()[j].get_cost());
            G2.add_edges_int(G.get_edges()[j].get_dest().iden(),G.get_edges()[j].get_src().iden(),G.get_edges()[j].get_cost());
            ++i;
        }

    }
    G2.create_Matrix_fr_edges();
    G2.print_matrix();
}
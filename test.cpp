#include"Vertices.h"
#include"Edges.h"
#include"Graph.h"
#include<iostream>
int main(){
   int i[]={2,4},j[]={1,3},k[]={2,4},l[]={1,3,5},m[]={4};
    int a=1,b=2,c=3,d=4,e=5;
    Vertices x(a,i,2);
    Vertices y(b,j,2);
    Vertices z(c,k,2);
    Vertices w(d,l,3);
    Vertices t(e,m,1);
    Vertices ver[]={x,y,z,w,t};
    Edges e1(&x,&y,1),e2(&x,&z,1);
    Edges edg[]={e1,e2};
    Graph G(ver,5);
  
   // G.print_ver();
    G.create_Edges_fr_vertices();
    G.print_edge();
   



    return 0;
}


//https://blog.csdn.net/manonghouyiming/article/details/79515989
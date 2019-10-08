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
    //cout<<x;
   // Edges e1(&x,&y,1),e2(&y,&z,1),e3(&x,&w,1),e4(&z,&w,1),e5(&y,&z,1);
    //Edges edg[]={e1,e2,e3,e4,e5};
    Graph G(ver,5);
    G.print_matrix();
    G.print_ver();
    



    return 0;
}


//https://blog.csdn.net/manonghouyiming/article/details/79515989
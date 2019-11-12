#include"Vertices.h"
#include"Edges.h"
#include"Graph.h"
#include<iostream>
#include<vector>
using namespace std;
int main(){
   /*int i[]={2,4},j[]={1,3},k[]={2,4},l[]={1,3},m[]={};
    int a=1,b=2,c=3,d=4,e=5;
    Vertices x(a,i,2);
    Vertices y(b,j,2);
    Vertices z(c,k,2);
    Vertices w(d,l,2);
    Vertices t(e,m,0);
    Vertices ver[]={x,y,z,w,t};
    Graph G(ver,5);
    //cout<<x;
    //G.print_ver();
    G.create_Edges_fr_vertices();
   // G.print_edge();
   //G.add_edges(&x,&y,1);
  G.add_edges_int(2,5,8);
   cout<<G.get_edges()[6];
   G.create_Matrix_fr_edges();
   G.print_matrix();
   */
  vector<vector<pair<int,int>>> listadj(3);
  listadj[0].push_back(make_pair(2,15));
  listadj[0].push_back(make_pair(3,20));
  listadj[1].push_back(make_pair(1,15));
  listadj[1].push_back(make_pair(2,10));
  listadj[2].push_back(make_pair(1,20));
  for(int i=0;i<3;i++){
      cout<<i+1;
      for(vector<pair<int,int>>::iterator iter=listadj[i].begin();iter!=listadj[i].end();iter++)
    {
        cout<<"->"<<iter->first<<"(cost:"<<iter->second<<")";
    }
    cout<<endl;
  }
  

    



    return 0;
}


//https://blog.csdn.net/manonghouyiming/article/details/79515989
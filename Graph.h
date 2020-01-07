#ifndef AG44_GRAPH_H
#define AG44_GRAPH_H


#include"Vertices.h"
#include"Edges.h"
#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
  private:
    Vertices* listVertex;
    Edges* listEdge;
    int ** Matrix;
    vector<vector<pair<int,int>>> listadj;
    vector<vector<int>> Matrix_vector;
    int numberofv,numberofe;
public:
    friend bool Dijkstra(int src, int dest);

    
    Graph(){
        numberofv=0;
        numberofe=0;
        listEdge=new Edges[100];
    }
    ~Graph(){
       if(listEdge) delete [] listEdge;
       if(listVertex) delete [] listVertex;
       if(Matrix){
       for(int i=0;i<numberofv;i++){
           delete [] Matrix[i];
       }
       delete Matrix;
       }
       listadj.clear();
        
    }
    //this is a constructor when only have the list of vectiecs
    //it will automatically create the liste of edges 


Graph(int v):listadj(v),Matrix_vector(v,vector<int>(v)){
    numberofv=v;
    numberofe=0;
    listVertex=new Vertices[20];
       
    listEdge=new Edges[100];
    int  a[]={};
    for(int i=0;i<v;i++){
        listVertex[i]=Vertices(i+1,a,0);
    }
}



    
    const int number_of_vertex(){return numberofv;}
    const int number_of_edges(){return numberofe;}
    Edges * get_edges(){return listEdge;}
    Vertices * get_Vertices(){return listVertex;}
    int* * get_matrix(){return Matrix;}
    vector<vector<int>> get_matrixVec(){return Matrix_vector;}
    void change_num_vertex(int nu){numberofv=nu;}
    void setunvisited(){
        for(int i=0;i<=numberofv;i++)
        listVertex[i].setunvisite();
    }//to set all Vertices unvisited
    bool visited(int id){return listVertex[id-1].get_visite();}//to know wether the vertice of id have been visited
    void visite_vertice(int id){listVertex[id-1].setvisite();}//to visite the vertice of id(true)
    void devisited_vertice(int id){listVertex[id-1].setunvisite();}//to set the vertice of id unvisited(false)
    int BFS(int id) //id is the starting vertex
    {
    int nu=0;
    this->setunvisited();
    list<int> q; //the queue we'll use
    this->visite_vertice(id);
    q.push_back(id);
    while(!q.empty())
    {
        id=q.front();
        nu++;
        q.pop_front();
        for(int i=0;i<this->get_Vertices()[id-1].number();++i)
        {
            if(!this->visited(this->get_Vertices()[id-1].neighbours()[i]))
            {
                this->visite_vertice(this->get_Vertices()[id-1].neighbours()[i]);
                q.push_back(this->get_Vertices()[id-1].neighbours()[i]);
            }
        }
    }
    return nu;
    }
    bool related(){
        
    if( BFS(1)==numberofv)
    return 1;
    else return 0;
    }
    
    void sort_edges(){
    int len = numberofe;
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (listEdge[j].get_cost() > listEdge[j+1].get_cost()) {        
                Edges temp = listEdge[j+1];        
                listEdge[j+1] = listEdge[j];
                listEdge[j] = temp;
            }
        }
    }
}
    
    void add_edges(Vertices* srcs,Vertices *dests,int cos){
        if(number_of_edges()==40){
            cout<<"the number of edges is already 20 please enlarge the space"<<endl;
        }
        else{
        //    if(!listEdge){
        //        listEdge=new Edges[20];
//
         //   }
            Edges e(srcs,dests,cos);
            listEdge[numberofe]=e;
            numberofe++;
        }
    }
    void add_edges_int(int srcs,int dests,int cos){
        
            
            listVertex[srcs-1].add_nei(dests);
            Vertices v1,v2;
            search_Vertices(srcs,v1);
            search_Vertices(dests,v2);
            add_edges(&v1,&v2,cos);
        
    }
    
   

    
    
    int search_Vertices(int id,Vertices & v){
        for(int i=0;i<numberofv;i++){
            if (listVertex[i].iden()==id)
                {v=listVertex[i];
                 return 1;
                }
        }
        return 0;
    }
   
    // create the matrix from the edges lists
    void create_Matrix_fr_edges(){
        cout<<"create the matrix from edges"<<endl;
        Matrix=new int* [number_of_vertex()];
       for(int i=0;i<number_of_vertex();i++){
           Matrix[i]=new int[number_of_vertex()];
        }
        
        for(int i=0;i<number_of_edges();i++)
            {
                Matrix[listEdge[i].get_src().iden()-1][listEdge[i].get_dest().iden()-1]=listEdge[i].get_cost();
             //cout<<listEdge[i].get_cost();

            }
    }
    void create_MatrixVec_fr_edges(){
         for(int i=0;i<number_of_edges();i++)
            {
                Matrix_vector[listEdge[i].get_src().iden()-1][listEdge[i].get_dest().iden()-1]=listEdge[i].get_cost();
             //cout<<listEdge[i].get_cost();

            }
    }
    // create the matrix from the Vertices lists
    void create_List_fr_edges(){
        cout<<"create the adjlist from edges"<<endl;
        for(int i=0;i<number_of_edges();i++)
            {
               listadj[listEdge[i].get_src().iden()-1].push_back(make_pair(listEdge[i].get_dest().iden(),listEdge[i].get_cost()));
             
             cout<<listEdge[i].get_src().iden()<<" "<<listEdge[i].get_dest().iden()<<" "<<listEdge[i].get_cost()<<endl;
            }
    }
    void create_Liste(){
        cout<<"create the liste from edges"<<endl;
    }
    void print_matrix(){
        cout<<endl;
        for(int i=0;i<number_of_vertex();i++){
            for(int j=0;j<number_of_vertex();j++){
                cout<<Matrix[i][j]<<"   ";
            }
            std::cout<<std::endl;
        }

    }
    void print_list(){
        for(int i=0;i<number_of_vertex();i++){
      cout<<i+1;
      for(vector<pair<int,int>>::iterator iter=listadj[i].begin();iter!=listadj[i].end();iter++)
    {
        cout<<"->"<<iter->first<<"(cost:"<<iter->second<<")";
    }
    cout<<endl;
  }
    }
    void print_ver(){
        for(int i=0;i<number_of_vertex();i++){
            cout<<listVertex[i]<<endl;
        }
    }
    void print_edge(){
        cout<<number_of_edges();
        for(int i=0;i<number_of_edges();i++){
            cout<<listEdge[i]<<endl;
        }
    }
    void print_visite(){
        for(int i=0;i<number_of_vertex();i++){
            cout<<"id:"<<listVertex[i].iden()<<endl;
            cout<<"visite:"<<listVertex[i].get_visite()<<endl;
        }
    }


    


   
};



#endif
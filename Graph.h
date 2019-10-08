#ifndef AG44_GRAPH_H
#define AG44_GRAPH_H


#include"Vertices.h"
#include"Edges.h"
#include<iostream>
class Graph{
  private:
    Vertices* listVertex;
    Edges* listEdge;
    int ** Matrix;
    int numberofv=0,numberofe=0;
public:
    Graph(){}
    ~Graph(){    }
    Graph(Vertices* listv,int v){
        numberofv=v;
        listVertex=new Vertices[20];
        for(int i=0;i<v;i++){
            listVertex[i]=listv[i];
        }
       create_edges_from_vertices();
    
        for(int i=0;i<v;i++){
            Matrix[i]=new int[v];
            if(listVertex[i].number()!=0){
                for(int j=0;j<listVertex[i].number();j++){
                    Matrix[i][listVertex[i].neighbours()[j]-1]=1;
                }
            }
        }
    


    }
    void create_edges_from_vertices(){
        if (listEdge) delete [] listEdge;
        listEdge=new Edges[20];
        for(int i=0;i<numberofv;i++){
            if(listVertex[i].number()!=0){
                for(int j=0;j<listVertex[i].number();j++){
                    Vertices v1=listVertex[i];
                    add_edges();
                    Matrix[i][listVertex[i].neighbours()[j]-1]=1;
                }
            }
        }



    }
    int number_of_vertex(){return numberofv;}
    int number_of_edges(){return numberofe;}
    void change_num_vertex(int nu){numberofv=nu;}
    void add_edges(Vertices* srcs,Vertices *dests,int cos){
        if(number_of_edges()==20){
            cout<<"the number of edges is already 20 please enlarge the space"<<endl;
        }
        else{
            if(!listEdge){
                listEdge=new Edges[20];

            }
            Edges e(srcs,dests,cos);
            listEdge[numberofe]=e;
            numberofe++;
        }
    }
    void add_vertex(){}
    void create_Matrix_fr_edges(){
        cout<<"create the matrix from edges"<<endl;
    }
    void create_Liste(){
        cout<<"create the liste from edges"<<endl;
    }
    void print_matrix(){
        for(int i=0;i<number_of_vertex();i++){
            for(int j=0;j<number_of_vertex();j++){
                if(Matrix[i][j]!=1)
                std::cout<<"0 ";
                else
                std::cout<<"1 ";
            }
            std::cout<<std::endl;
        }

    }
    void print_ver(){
        for(int i=0;i<number_of_vertex();i++){
            cout<<listVertex[i]<<endl;
        }
    }


    


   
};



#endif
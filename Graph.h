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
    int numberofv,numberofe;
public:
    Graph(){}
    ~Graph(){
       if(listEdge) delete [] listEdge;
       if(listVertex) delete []listVertex;
       if(Matrix){
       for(int i=0;i<numberofv;i++){
           delete [] Matrix[i];
       }
       delete Matrix;
       }
        
    }
    //this is a constructor when only have the list of vectiecs
    //it will automatically create the liste of edges 
Graph(Vertices* listv,int v){
    numberofv=v;
    numberofe=0;
    listVertex=new Vertices[20];
        for(int i=0;i<v;i++){
            listVertex[i]=listv[i];
        }
}

Graph(Vertices* listv,Edges* liste,int v,int e){
        numberofv=v;
        numberofe=e;
        cout<<5;
        listVertex=new Vertices[20];
        for(int i=0;i<v;i++){
            listVertex[i]=listv[i];
        }
        listEdge=new Edges[20];
        for(int i=0;i<e;i++){
            listEdge[i]=liste[i];
        }
        cout<<5;

        for(int i=0;i<v;i++){
            Matrix[i]=new int[v];
            if(listVertex[i].number()!=0){
                for(int j=0;j<listVertex[i].number();j++){
                    Matrix[i][listVertex[i].neighbours()[j]-1]=1;
                }
            }
        }
}






    /*
    Graph(Vertices* listv,int v){
        cout<<5;
        numberofv=v;
        numberofe=0;
        cout<<5;
        if(listVertex) delete [] listVertex;
        cout<<5;
        listVertex=new Vertices[20];
        cout<<5;
        for(int i=0;i<v;i++){
            listVertex[i]=listv[i];
        }
       //create_Edges_fr_vertices();
       //create_Matrix_fr_vertices();
       print_matrix();
    }*/
    int number_of_vertex(){return numberofv;}
    int number_of_edges(){return numberofe;}
    Edges * get_edges(){return listEdge;}
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
    // this function only fit the case that the cost is 1
    //if want to create from different cost must add a list of cost in each vertices class
    
    void create_Edges_fr_vertices(){
        cout<<"create the Edges from vertices"<<endl;
        if (listEdge) delete [] listEdge;
        listEdge=new Edges[20];
        for(int i=0;i<numberofv;i++){
            if(listVertex[i].number()!=0){
                for(int j=0;j<listVertex[i].number();j++){
                    Vertices v1=listVertex[i],v2;search_Vertices(listVertex[i].neighbours()[j],v2);
                    add_edges(&v1,&v2,1);//this way to change the cost
                    
                }
            }
        }
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
    }
    // create the matrix from the Vertices lists
    void create_Matrix_fr_vertices(){
       cout<<"create the matrix from Vertices"<<endl;
       // if (Matrix) delete [] Matrix;
       cout<<numberofv;
        for(int i=0;i<numberofv;i++){
            Matrix[i]=new int[numberofv];
            if(listVertex[i].number()!=0){
                for(int j=0;j<listVertex[i].number();j++){
                    cout<<listVertex[i].iden();
                    Matrix[i][listVertex[i].neighbours()[j]-1]=1;
                }
            }
        }
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
    void print_edge(){
        cout<<number_of_edges();
        for(int i=0;i<number_of_edges();i++){
            cout<<listEdge[i]<<endl;
        }
    }


    


   
};



#endif
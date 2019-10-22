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
    int * Listadja;
    int numberofv,numberofe;
public:
    Graph(){
        numberofv=0;
        numberofe=0;
        listEdge=new Edges[40];
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
        
    }
    //this is a constructor when only have the list of vectiecs
    //it will automatically create the liste of edges 
Graph(int v,int e){
    numberofv=v;
    numberofe=e;
    listVertex=new Vertices[20];
    for(int i=0;i<v;i++){
        Vertices temp(i+1,{},0);
        listVertex[i]=temp;

    }
}
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
        listEdge=new Edges[40];
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






    
    const int number_of_vertex(){return numberofv;}
    const int number_of_edges(){return numberofe;}
    Edges * get_edges(){return listEdge;}
    Vertices * get_Vertices(){return listVertex;}
    void change_num_vertex(int nu){numberofv=nu;}
    
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
        
       
            listVertex[srcs].add_nei(dests);
            cout<<10;
            Vertices v1,v2;
            search_Vertices(srcs,v1);
            search_Vertices(dests,v2);
            add_edges(&v1,&v2,cos);
        
    }
    
    void add_vertex(){}
    // this function only fit the case that the cost is 1
    //if want to create from different cost must add a list of cost in each vertices class
    
    void create_Edges_fr_vertices(){
      
        cout<<"create the Edges from vertices"<<endl;
       //if (listEdge) delete [] listEdge;
        listEdge=new Edges[40];
        for(int i=0;i<numberofv;i++){
            if(listVertex[i].number()!=0){
                for(int j=0;j<listVertex[i].number();j++){
                    Vertices v1=listVertex[i],v2;search_Vertices(listVertex[i].neighbours()[j],v2);
                    //cout<<v1<<v2;
                    
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
        for(int i=0;i<number_of_vertex();i++){
            Matrix[i]=new int[number_of_vertex()];
        }
        
        for(int i=0;i<number_of_edges();i++)
            {
                Matrix[listEdge[i].get_src().iden()-1][listEdge[i].get_dest().iden()-1]=listEdge[i].get_cost();
             cout<<listEdge[i].get_cost();

            }
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
                cout<<Matrix[i][j]<<" ";
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
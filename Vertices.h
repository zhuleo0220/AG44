#ifndef AG44_VERTICES_H
#define AG44_VERTICES_H
#include<iostream>
using namespace std;
class Vertices{
   //friend ostream &operator<<(ostream os , Vertices v);
    private:
    int id,num_of_nei;
    int* Neighbors;
     public:
    Vertices():Neighbors(nullptr){}
    //Vertices(int iden,int* nei);
    Vertices(int iden,int* nei,int numnei):id(iden),Neighbors(nei),num_of_nei(numnei){}
    ~Vertices(){}
    int sizof(){
        return sizeof(Neighbors);
    }
    int* neighbours()const{return this->Neighbors;}
    int iden()const{return id;}
    int number()const{ return num_of_nei;}
    Vertices &operator=(Vertices const & v){
        this->id=v.id;
        this->num_of_nei=v.num_of_nei;
        //if(Neighbors) delete [] Neighbors;
        this->Neighbors=new int[this->num_of_nei] ;
        for(int i=0;i<v.number();i++){
            this->Neighbors[i]=v.Neighbors[i];
        }
        return *this;
  
    }
    void add_nei(int id){
        if(!Neighbors) 
        int * Neighbors=new int [20];
        num_of_nei=0;
        Neighbors[number()]=id;
        num_of_nei++;
    }


};
ostream &operator<<(ostream &os , const Vertices &v){                                        //this is just a test function it's inline temporally
    os<<"id is "<<v.iden()<<endl;
    if (v.number()!=0){
        os<<"Neighbors are: ";
        for(int i=0;i<v.number();i++)
            os<<v.neighbours()[i]<<" ";
        os<<endl;}
    else
        os<<"there is no neighbour";
    return os;


}

#endif
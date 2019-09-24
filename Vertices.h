#ifndef Ver
#define Ver
#include<iostream>
using namespace std;
class Vertices{
   //friend ostream &operator<<(ostream os , Vertices v);
   public:
    int id;
    int* Neighbors;
    Vertices():Neighbors(nullptr){}
    //Vertices(int iden,int* nei);
    Vertices(int iden,int* nei):id(iden),Neighbors(nei){}
    ~Vertices(){}
    int sizof(){
        return sizeof(Neighbors);
    }


};
ostream &operator<<(ostream &os , const Vertices &v){
    os<<"id is"<<v.id<<endl<<"Neighbors";
    for(int i=0;i<(sizeof(v.Neighbors)/(sizeof(v.Neighbors[0])));i++)
        os<<v.Neighbors[i];
    os<<sizeof(v.Neighbors);
    return os;


}

#endif
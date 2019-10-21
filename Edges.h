#ifndef AG44_EDGES_H
#define AG44_EDGES_H




#include <iostream>
#include "Vertices.h"

using namespace std;

class Edges
{
    public:
    //methodes
    Edges(){} //constructor
    ~Edges(){} //destructor
    Edges(Vertices* srcs,Vertices *dests,int cos):src(srcs),dest(dests),cost(cos){}
    Vertices &get_src(){return *src;}
    Vertices &get_dest(){return *dest;}
    Edges &operator=(Edges & e){
        cost=e.cost;
        src=new Vertices;
        dest=new Vertices;
        *src=*(e.src);
        *dest=*(e.dest);
        return *this;

    }
    private:
    //attributs
   // int id;
    Vertices *src;
    Vertices *dest;
    int cost;
    
};
ostream &operator<<(ostream &os , Edges &e){                                        //this is just a test function it's inline temporally
    os<<"src is "<<e.get_src().iden()<<endl;
    os<<"dest is "<<e.get_dest().iden()<<endl;
    return os;


}






#endif
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
    private:
    //attributs
   // int id;
    Vertices *src;
    Vertices *dest;
    int cost;
};






#endif
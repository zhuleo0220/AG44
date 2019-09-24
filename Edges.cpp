#include <vector>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "Edges.h"
#include "Vertex.h"

using namespace std;

class Edges
{
    public:
    //methodes
    Edges(); //constructor
    ~Edges(); //destructor
    
    private:
    //attributs
    int id;
    Vertices *src;
    Vertices *dest;
    int cost;
};
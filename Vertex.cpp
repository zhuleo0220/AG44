#include"Vertex.h"
Vertex::Vertex(int iden,int* nei){
    id=iden;
    for(int i=0; i<sizeof(nei);i++){this->Neighbors[i]=nei[i];}
}
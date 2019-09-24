#ifndef Ver
#define Ver
class Vertex{
   public:
    int id;
    int* Neighbors;
    Vertex();
    Vertex(int iden,int* nei);
    ~Vertex(){}
    int sizof(){
        return sizeof(Neighbors);
    }


};


#endif
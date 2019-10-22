#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include"Vertices.h"
#include"Edges.h"
#include"Graph.h"


using namespace std;

//adaptive function part

//function that put the cursor on the line
//number 'line' of flux
//  /!\ think about the flux.ignore();
void return_line(ifstream &flux, int line)
{
    flux.ignore();
    string stock;
    flux.seekg(0,ios::beg);
    for(int i=0;i<line;++i)
    {
        getline(flux,stock);
    }
}

void next_char(ifstream &flux, int nbr)
{
    char lettre;
    for(int i=0;i<nbr;++i)
    {
        flux.get(lettre);
        while(lettre!=';')
        {
            flux.get(lettre);
        }
    }
}

//reading function part

//function that returns the number of vertices of flux
int read_vertice(ifstream &flux)
{
    int nombre;
    return_line(flux,0);
    flux >> nombre;
    return nombre;
}

//function that returns the type of the edges of flux
char read_type(ifstream &flux)
{
    char lettre;
    return_line(flux,1);
    flux.get(lettre);
    return lettre;
}

//function that read the representation type in flux
char read_reptype(ifstream &flux)
{
    char lettre;
    return_line(flux,2);
    flux.get(lettre);
    return lettre;
}

int read_num(ifstream &flux)
{
    int nombre;
    flux >> nombre;
    return nombre;
}

//this function returns the numberth element of the matrix
int readMatrix_Num(ifstream& flux, int number)
{
    return_line(flux,(number/3) + 3);
    next_char(flux,number%3);
    return read_num(flux);
}

//checking function part

//function that checks if there is a positive
//number of vertices
bool check_vertice(int nbr)
{
    if(nbr>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function that checks if the type of the graph
//is well written
//plus it returns which letter was red
int check_type(char letter)
{
    if(letter=='o')
    {
        return 1;
    }
    else if(letter=='n')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

//function that checks if the representation
//type is well written
//plus it returns which letter was red
int check_reptype(char letter)
{
    if(letter=='m')
    {
        return 1;
    }
    else if(letter=='l')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

//global functions part

//This function, used with others checks
//checks if there is any mistake on the 3
//first lines of a file
bool firstCheck(bool vertice, int type, int reptype)
{
    if(!vertice)
    {
        cout << endl << "error : vertice";
        return false;
    }
    if(!type)
    {
        cout << endl << "error : type";
        return false;
    }
    if(!reptype)
    {
        cout << endl << "error : representation type";
        return false;
    }
    return true;
}

//This function fills a table in a matrix case
//With the graph composition given by flux
void read_matrix(ifstream &flux, int standardGraph[])
{
    int i, taille;//
    taille=read_vertice(flux);//calcul de la taille du table
    taille=taille*taille;//
    for(i=0;i<taille;++i)
    {
        standardGraph[i]=readMatrix_Num(flux,i);
        cout << standardGraph[i] << " ";
    }
}

/*//this function fills a table in a list case
//with the graph composition given by flux
void read_list(ifstream &flux, int standardGraph[])
{
    int taille;//
    taille=read_vertice(flux);//calcul de la taille de table
    taille=taille*taille;//
}*/


//graph interactive functions part

//This function requires "tableOfVertices" which should be an empty
//table of size 'sqrt(sizeof(standardGraph)/sizeof(int))'
//But this operation will cause an error so we have to create an
//int x = sizeof(standardGraph)/sizeof(int)
//and then pose sqrt(x)
void decoderFileTable(int standardGraph[], int tableOfVertices[],Graph G)
{
    int tailleS = sizeof(standardGraph)+1;//calcul de la taille de standardGraph _ fonctionnement etrange
    int tailleV = sqrt(tailleS);//size of tableOfVertices, also number of Vertices in standardGraph
    for(int i=1;i<=tailleV;++i)//creates the table of vertices and name them
    {
        tableOfVertices[i-1]=i;//the first vertice is named '1', not '0'
    }
    for(int j=0;j<tailleS;++j)
    {
        if(standardGraph[j]!=0)
        {
            //src = j/tailleV + 1;//name/number of the source Vertice
            //dest = j%tailleV + 1;//name/number of the destination Vertice
            //cost = standardGraph[j];//cost of the edge between the two Vertices
            cout<<j/tailleV + 1<<endl<<j%tailleV + 1<<endl<<standardGraph[j]<<endl;
            G.add_edges_int((j/tailleV + 1), (j%tailleV + 1), standardGraph[j]);
        }
    }
}

int main()
{
    ifstream flux("test.txt");
    if(flux)
    {
        cout << endl << "ok" << endl;
    }
    else
    {
        cout << "error : opening of file test.txt";
    }


    /*lecture fichier complet
    string line;
    flux.ignore();
    while(getline(flux,line))
    {
        cout << endl << line;
    }*/

    /*if(firstCheck(check_vertice(read_vertice(flux)),check_type(read_type(flux)),check_reptype(read_reptype(flux))))
    {
        cout << endl << "everything : ok";
    }*/

    int standardGraph[read_vertice(flux)*read_vertice(flux)];//à optimiser en calculant le ² avant de l'envoyer dans la fonction pour n'utiliser qu'une fois la fonction
    read_matrix(flux, standardGraph);
    Vertices x(1,{},0);
    Vertices y(2,{},0);
    Vertices z(3,{},0);
    Vertices ver[]={x,y,z};
    Graph G(ver,3);
    //G.create_Edges_fr_vertices();
    //Graph G(3,0);
    int  tableOfVertices[3]={1,2,3};
    decoderFileTable(standardGraph,tableOfVertices,G);
    //G.add_edges_int(1,2,9);
    G.add_edges_int(2,3,9);
    cout<<G.get_edges()[0];
    G.print_edge();
    //G.create_Matrix_fr_edges();
    //G.print_matrix();n


    cout << endl << "fini";

    return 0;
}

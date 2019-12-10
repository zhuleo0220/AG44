#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <math.h>
#include <cmath>
#include <strstream>
#include"Vertices.h"
#include"Edges.h"
#include"Graph.h"
#include"dijkstra.cpp"
#include"DFS.cpp"
#include"BFS.cpp"
#include"topologicalSort.cpp"
#include"kruskal.cpp"
#include"prim.cpp"

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
        while(lettre!=' ')
        {
            flux.get(lettre);
        }
    }
}

void past_slash(ifstream &flux, int nbr)
{
    char lettre;
    int i;
    for(i=0;i<nbr;++i)
    {
        flux.get(lettre);
        while(lettre!='/')
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

bool check_endLine(ifstream &flux)
{
    char charTest;
    flux.get(charTest);
    if(charTest=='\r' || charTest=='\n'){return true;}  //end of line test
    else{return false;}
}

int check_cost(string cost)
{
    int strSize = cost.length();
    for(int i=0;i<strSize;++i)  //int test
    {
        if(!isdigit(cost[i])){return -1;}
    }
    int icost=atoi(cost.c_str());
    if(icost<0){return -1;}
    else{return icost;}
}

int read_num(ifstream &flux)
{
    string stock;
    flux >> stock;
    int nombre = check_cost(stock);
    if(nombre!=-1)
    {
        return nombre;
    }
    else
    {
        cout << endl << "erreur ecriture nombre";
        exit(404);
    }
}

//this function returns the numberth element of the matrix
int readMatrix_Num(ifstream& flux, int number, int vertice)
{
    return_line(flux,(number/vertice) + 3);
    next_char(flux,number%vertice);
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
    int i, taille, vertice;//
    vertice=read_vertice(flux);//calcul de la taille du tableau
    taille=vertice*vertice;//
    for(i=0;i<taille;++i)
    {
        standardGraph[i]=readMatrix_Num(flux,i,vertice);
    }
}

//this function fills a table in a list case
//with the graph composition given by flux
void read_list(ifstream &flux, int standardGraph[])
{
    int nbrVertices, currentLine, dataNbr, currentVertice, currentCost;
    int taille;//
    nbrVertices=read_vertice(flux);//calcul de la taille de table
    taille=nbrVertices*nbrVertices;//
    for(int i=0;i<taille;++i)
    {
        standardGraph[i]=0;
    }
    for(int j=1;j<=nbrVertices;++j)
    {
        return_line(flux,j+2);
        currentLine = read_num(flux);
        if(currentLine!=j)
        {
            cout << "erreur d'ecriture de la liste";
            exit(403);
        }
        dataNbr = 0;
        while(!check_endLine(flux))
        {
            return_line(flux,j+2);
            next_char(flux, 3*dataNbr+1);
            /*if(check_endLine(flux))
            {
                cout << "erreur ligne incomplète";
                exit(402);
            }                  ///For a reason, this code generates an error
            else
            {
                flux.seekg(flux.tellg()-1,ios::beg);
            }*/
            currentVertice=read_num(flux);
            past_slash(flux,1);
            currentCost = read_num(flux);
            standardGraph[(currentLine-1)*nbrVertices+(currentVertice-1)] = currentCost;
            ++dataNbr;
        }
    }
}

//This function fills a standard table over the file
//To get the table write "int *tab=read_file();" and "tab" will be the table
int* read_file(ifstream &flux)
{
    if(!firstCheck(check_vertice(read_vertice(flux)),check_type(read_type(flux)),check_reptype(read_reptype(flux)))){exit(399);}
    int taille = read_vertice(flux);
    taille = taille * taille;
    int *standardGraph = new int[taille];
    if(read_reptype(flux)=='m')
        {
            read_matrix(flux,standardGraph);
        }
    else
        {
            read_list(flux,standardGraph);
        }
    return standardGraph;
}


//graph interactive functions part

//This function requires "tableOfVertices" which should be an empty
//table of size 'sqrt(sizeof(standardGraph)/sizeof(int))'
//But this operation will cause an error so we have to create an
//int x = sizeof(standardGraph)/sizeof(int)
//and then pose sqrt(x)
int * decoderFileTable(int tailleS,int standardGraph[],Graph* G)
{
    int tailleV = sqrt(tailleS);//size of tableOfVertices, also number of Vertices in standardGraph
    cout<<tailleS<<endl;
    int *tableOfVertices = new int[tailleV];
    for(int i=1;i<=tailleV;++i)//creates the table of vertices and name them
    {
        tableOfVertices[i-1]=i;//the first vertice is named '1', not '0'
    }
    for(int j=0;j<tailleS;++j)
    {
        if(standardGraph[j]!=0)
        {
            int src,dest,cost;
            src = j/tailleV + 1;//name/number of the source Vertice
            dest = j%tailleV + 1;//name/number of the destination Vertice
            cost = standardGraph[j];//cost of the edge between the two Vertices
            (*G).add_edges_int(j/tailleV + 1, j%tailleV + 1, standardGraph[j]);
            
        }
    }
    return tableOfVertices;
}


//Writing part
//For each, you need to give standardGraph
//it's size (sizeof doesn't work as we don't have a table, it's an int)
//if it's directed or not (o/n)

void write_matrix(int standardGraph[],int taille , char directed)
{
    int vertices, i, j;
    string const nomFichier("writeFile.txt");
    ofstream writeFlux(nomFichier.c_str());
    if(!writeFlux)
    {
        cout << "error at file opening";
        exit(400);
    }
    vertices = sqrt(taille);
    writeFlux << vertices << endl << directed << endl << "m" << endl;
    for(i=0;i<vertices;++i)
    {
        for(j=0;j<vertices;++j)
        {
            writeFlux << standardGraph[i*vertices+j];
            if(j!=vertices-1)
            {
                writeFlux << " ";
            }
        }
        writeFlux << endl;
    }
}

void write_list(int standardGraph[], int taille, char directed)
{
    int vertices, i, j;
    string const nomFichier("writeFile.txt");
    ofstream writeFlux(nomFichier.c_str());
    if(!writeFlux)
    {
        cout << "error at file opening";
        exit(400);
    }
    vertices = sqrt(taille);
    writeFlux << vertices << endl << directed << endl << "l" << endl;
    for(i=0;i<vertices;++i)
    {
        writeFlux << i+1;
        for(j=0;j<vertices;++j)
        {
            if(standardGraph[i*vertices+j]!=0)
            {
                writeFlux << " " << j+1 << " / " << standardGraph[i*vertices+j];
            }
        }
        writeFlux << endl;
    }
}


int main()
{
    //-----------------------------------------------------------------------------
    ifstream flux("test.txt");
    if(!flux)
    {
        cout << "error : opening of file test.txt";                     ///This part should be written in the main for the file to be used at any time.
        exit(400);
    }


   int *standardGraph=read_file(flux);

    
    Graph G(read_vertice(flux));
    int *TableOfVertices=decoderFileTable(read_vertice(flux)*read_vertice(flux),standardGraph,&G);
    cout<<endl;
   
    //G.create_List_fr_edges();
    G.create_Matrix_fr_edges();
    
    //G.print_edge();
    //G.print_list();
    
    G.print_matrix();
    //G.print_ver();
    
    
    
    //dijkstra
    /*
    int nodenum=read_vertice(flux);
    int start=0;
    int * dist=new int(nodenum);
    int * path=new int(nodenum);
    
    Dijkstra(G.get_matrix(),start,nodenum,dist,path);
    cout<<endl;
    for(int i=0;i<nodenum;i++){
        cout<<dist[i]<<" ";
    }
    */

   //DFS
  // DFS(G);

   //BFS
   //BFS(G,1);


   // topologicalSort
   //topologicalSort(G);
   //cout<<G.related();


  //kruskal(G);

  //Prim
  Prim(G.get_matrix(),G.number_of_vertex());




 



    cout << endl << "fini";
   
    
    
    write_list(standardGraph,read_vertice(flux)*read_vertice(flux),'n');
    return 0;
}

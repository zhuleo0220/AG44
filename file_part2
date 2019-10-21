#include <iostream>
#include <string>
#include <fstream>

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
            flux.seekg(flux.tellg()+1,ios::beg);
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
    return_line(flux,3);
    next_char(flux,3);
    flux >> nombre;
    return nombre;
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

//This function fills a double table
//With the graph composition given by flux
void read_matrix(ifstream &flux, int table[][read_vertice(flux)])
{

}

int main()
{
    ifstream flux("test.txt");
    if(flux)
    {
        cout << endl <<"ok";
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

    if(firstCheck(check_vertice(read_vertice(flux)),check_type(read_type(flux)),check_reptype(read_reptype(flux))))
    {
        cout << endl << "everything : ok";
    }

    int standardGraph[read_vertice(flux)][read_vertice(flux)];

    cout << endl << "fini";

    return 0;
}

//A ce stade, le package est capable de lire et vérifier le nombre de vertices, le type des edges, et si on lui donne une matrice ou une liste

//L'idée dans la continuité serait de travailler sur une fonction (2 fonctions : matrice / liste) qui lirait la composition du graph
//et la synthétiserait sous forme "canonique"

//Et le travail de vérification continuerait à partir de cette forme canonique, plus simple à traîter

//pour faire tout ça, logiquement : vectors


//update 2.0
//On cherche donc à standardier avec un tableau 2 dimensions
//Le prb actuel est d'envoyer le tableau crée à la fonction ...
//Pointeur de pointeur : solution probable

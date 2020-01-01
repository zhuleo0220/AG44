#include<iostream>
#include"Graph.h"

using namespace std;

void floydWarshall (int ** dist,int V) //StandardTab is the table built from the file to create the graph 
{
    
    int  i,j,k;
    for(int i=0;i<V;++i)  
    {  
        for(int j=0;j<V;++j)  
        {  
            if(dist[i][j]==0)  
                dist[i][j]=99999;
        }    
    }
    for(k=0;k<V;++k)  
    {  
        for(i=0;i<V;++i)  
        {  
            for(j=0;j<V;++j)  
            {  
                if(dist[i][k] + dist[k][j] < dist[i][j])  
                {
                    dist[i][j] = dist[i][k] + dist[k][j];  
                }
            }  
        }  
    }


    cout<<endl;
   cout<<"The following matrix shows the shortest distances between every pair of vertices"<<endl;  
   for(int i=0;i<V;++i){
       dist[i][i]=99999;
   }
    for(int i=0;i<V;++i)  
    {  
        for(int j=0;j<V;++j)  
        {  
            if(dist[i][j]==99999)  
                cout<<"INF"<<"   ";  
            else
                cout<<dist[i][j]<<"   ";  
        }  
        cout<<endl<<endl;  
    }  
    
}   


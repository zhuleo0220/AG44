#include"Vertices.cpp"
#include<iostream>
int main(){
    int n[]={1,2,3,4};
    int a=5;
    Vertices v(a,n);
    std::cout<<sizeof(v.Neighbors);
    std::cout<<sizeof(n);
    //std::cout<<v;



    return 0;
}


//https://blog.csdn.net/manonghouyiming/article/details/79515989
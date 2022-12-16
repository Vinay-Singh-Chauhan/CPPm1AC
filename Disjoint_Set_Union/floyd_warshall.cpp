#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
const int INF=1e9;

vector<vector<int>> graph={{0,5,INF,10},
                            {INF,0,3,INF},
                            {INF,INF,0,1},
                            {INF,INF,INF,0}};

vector<vector<int>> distanc=graph;



void floyd(int nodes){
    for (int k = 0; k < nodes; k++)
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                distanc[i][j]=min(distanc[i][j],distanc[i][k]+distanc[k][j]);
            }
            
        }
        
    }
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            if(distanc[i][j]==INF){
                cout<<"INF"<<" ";
            }else{
                cout<<distanc[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    
}
int main()
{
    
    int nodes=graph.size();

    
    floyd(nodes);
    
    cout<<endl<<"minimun distance between 1 3 is:"<<distanc[1][3];
    
    
return 0;
}
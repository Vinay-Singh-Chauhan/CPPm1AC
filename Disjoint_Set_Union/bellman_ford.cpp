#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<vector<int>> edge;
const int INF=1e9;

vector<int> distanc(N,INF);



void bellman(int source,int nodes){
    distanc[source]=0;
    
    for(int i=0;i<nodes-1;i++){
        bool change=false;

        for(auto it:edge){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(distanc[v]>w+distanc[u]) change =true;
            distanc[v]=min(distanc[v],w+distanc[u]);

        }
    }
}
int main()
{
    
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i=0;i<edges;i++){
        int w,a,d;
        cin>>a>>d>>w;
        edge.push_back({a,d,w});
        

    }
    int source;
    cin>>source;
    bellman(source,nodes);
    for (int i = 0; i < nodes; i++)
    {
        if(distanc[i]!=INF)
        cout<<distanc[i]<<" ";
        else
        cout<<-1<<" ";
    }
    

    
    
return 0;
}
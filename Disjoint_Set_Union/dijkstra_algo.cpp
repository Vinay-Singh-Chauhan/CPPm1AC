#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<vector<int>> graph[N];
const int INF=1e9;
vector<int> parent(N);
vector<int> distanc(N,INF);
vector<bool> vis(N);


void dijkstra(int source){
    set<vector<int>> s;
    distanc[source]=0;
    s.insert({0,source});
    while(!s.empty()){
        auto x=*(s.begin());
        s.erase(x);
        vis[x[1]]=true;
        int u=x[1];
        int v=parent[x[1]];
        int w=x[0];
  
        for(auto it:graph[x[1]]){
            if(vis[it[0]]) continue;
            if(distanc[it[0]]>it[1]+distanc[x[1]]){
                s.erase({distanc[it[0]],it[0]});
                distanc[it[0]]=it[1]+distanc[x[1]];
                s.insert({distanc[it[0]],it[0]});
                parent[it[0]]=x[1];
            }
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
        graph[a].push_back({d,w});
        graph[d].push_back({a,w});

    }
    int source;
    cin>>source;
    dijkstra(source);
    for (int i = 1; i <= nodes; i++)
    {
        if(distanc[i]!=INF)
        cout<<distanc[i]<<" ";
        else
        cout<<-1<<" ";
    }
    

    
    
return 0;
}
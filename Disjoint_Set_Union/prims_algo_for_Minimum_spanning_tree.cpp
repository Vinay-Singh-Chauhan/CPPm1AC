#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<vector<int>> graph[N];
int cost;
// vector<int>sz(N);
// vector<int>parent(N);

// void make_set(int a){
//     sz[a]=1;
//     parent[a]=a;
// }
// int find_set(int a){
//     if(parent[a]==a){
//         return a;
//     }
//     return parent[a]=find_set(parent[a]);
// }
// void union_sets(int a,int b){
//     a=find_set(a);
//     b=find_set(b);
//     if(a!=b){
//         if(sz[a]<sz[b]){
//             swap(a,b);
//         }
//         parent[b]=a;
//     }
    
// }
// bool detectcycle(vector<vector<int>>& edges,int n){
//     for(int i=0;i<n;i++){
//         int p1=find_set(edges[i][1]);
//         int p2=find_set(edges[i][2]);
//         if(p1==p2) return true;
//         else union_sets(edges[i][1],edges[i][2]);
//     }
//     return false;
// }
const int INF=1e9;
vector<int> parent(N);
vector<int> distanc(N,INF);
vector<bool> vis(N);


void primsMST(int source){
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
        cost+=w; 
        for(auto it:graph[x[1]]){
            if(vis[it[0]]) continue;
            if(distanc[it[0]]>it[1]){
                s.erase({distanc[it[0]],it[0]});
                distanc[it[0]]=it[1];
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
    primsMST(0);
    cout<<cost;
    
    
return 0;
}
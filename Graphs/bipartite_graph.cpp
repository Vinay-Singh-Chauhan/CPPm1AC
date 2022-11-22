/*
A graph is Bipartite graph if :

    a> vertices can be divided in two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V.
                            OR                                
    b> the graph does not conatin any odd-length cycles.
                            OR
    c> the graph is two colorable
*/
#include<bits/stdc++.h>
using namespace std;
const int n=1e5+2;
bool bipartite=true;
vector<bool> visited;
vector<int>  col;
vector<vector<int>> adjencyList;
void color(int u,int curr){
    if(col[u]!=-1 and col[u]!=curr){
        bipartite=false;
        return;
    }
    col[u]=curr;
    if(visited[u]){
        return;
    }
    visited[u]=1;
    for(auto i: adjencyList[u]){
        color(i,curr xor 1);
    }
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    adjencyList=vector<vector<int>>(n);
    visited=vector<bool>(nodes,false);
    col=vector<int>(nodes,-1);
    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        adjencyList[x].push_back(y);
        adjencyList[y].push_back(x);
    }

    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            color(i,0);
        }
    }
    //     for(int j=0;i<adjencyList[i].size();j++){
    //         if(!visited[adjencyList[i][j]]){
    //             visited[adjencyList[i][j]]=1;
    //             red!=red;
    //         }
    //     }
    // }
    if(bipartite){
        cout<<"bg";
    }
    return 0;
}

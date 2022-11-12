#include<bits/stdc++.h>
using namespace std;
bool isCycle(int src, vector<vector<int>>& adjList,vector<bool>& visited,int parent ){
    visited[src]=true;
    for(auto i:adjList[src]){
        if(i!=parent){
            if(visited[i]){
                return true;
            }
            if(!visited[i] and isCycle(i,adjList,visited,src)){
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    vector<bool>visited(nodes,false);
    vector<vector<int>> adjList(nodes);
    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    
    bool cycle=false;
    for(int i=0;i<nodes;i++){
        if(!visited[i] and isCycle(i,adjList,visited,-1)){
            cycle=true;
        }
    }
    if(cycle){
        cout<<"cycle present";
    }else cout<<" not present";
    return 0;
}
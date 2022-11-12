#include<bits/stdc++.h>
using namespace std;
bool isCycle(int src, vector<vector<int>>& adjList,vector<bool>& visited,vector<bool>& stack){
    stack[src]=true;
    if(!visited[src]){
        visited[src]=true;
        for(auto i:adjList[src]){
        
            if(visited[i]){
                return true;
            }
            if(!visited[i] and isCycle(i,adjList,visited,stack)){
                return true;
            }
        
    }
    }
    stack[src]=false;

    
    return false;
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    vector<bool>visited(nodes,false);
    vector<bool>stack(nodes,false);
    vector<vector<int>> adjList(nodes);
    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
    }
    
    bool cycle=false;
    for(int i=0;i<nodes;i++){
        if(!visited[i] and isCycle(i,adjList,visited,stack)){
            cycle=true;
        }
    }
    if(cycle){
        cout<<"cycle present";
    }else cout<<" not present";
    return 0;
}
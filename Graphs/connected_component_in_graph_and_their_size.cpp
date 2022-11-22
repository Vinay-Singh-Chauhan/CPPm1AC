#include<bits/stdc++.h>
using namespace std;

int count_components(int node,vector<vector<int>>& adjList,vector<bool>& visited){
    if(visited[node]) return 0;
    int count=0;
    if(!visited[node])
    count= 1;
    visited[node]=1;
    
    for(int i=0;i<adjList[node].size();i++){
        if(!visited[adjList[node][i]]){
            count+=1;
            visited[adjList[node][i]]=1;
        }
        // count+=count_components(adjList[node][i],adjList,visited);
    }
    return count;
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
vector<int> components;
    for(int i=0;i<nodes;i++){
        if(!visited[i]){
            components.push_back(count_components(i,adjList,visited));
        }
    }
    
    for(auto i:components){
        cout<<i<<" ";
    }
    return 0;
}
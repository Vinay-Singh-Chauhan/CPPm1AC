#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    map<int,int>degree;
    vector<int> adjList[nodes+1];
    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        degree[y]++;
    }
    


    queue<int>topological_order;
    for(int i=0;i<nodes;i++){
        if(degree[i]==0){
            topological_order.push(i);
        }
    }
    while(!topological_order.empty()){
        int n=topological_order.front();
        topological_order.pop();
        cout<<n<<" ";
        for(auto it:adjList[n]){
            degree[it]--;
            if(degree[it]==0){
                topological_order.push(it);
            } 
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int n=1e5+2;

bool visited[n];
vector<int> adjencyList[n];
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        adjencyList[x].push_back(y);
        adjencyList[y].push_back(x);
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    queue<int> bfs;
    bfs.push(1);
    visited[1]=1;
    while(!bfs.empty()){
        int node=bfs.front();
        bfs.pop();
        cout<<node<<" ";
        vector<int>::iterator it;

        for(it=adjencyList[node].begin();it!=adjencyList[node].end();it++){
            if(!visited[*it]){
                bfs.push(*it);
                visited[*it]=1;
            }
        }
    }
    return 0;
}

// 7 7
// 1 2
// 1 3
// 2 4 
// 2 6
// 2 5
// 2 7
// 7 3
#include<bits/stdc++.h>
using namespace std;
const int n=1e5+2;
bool visited[n];
vector<int> adjencyList[n];
void dfs(int i){

    //preorder
    visited[i]=1;
    // cout<<i<<" ";

    //inorder
    vector<int>::iterator it;
    for(it=adjencyList[i].begin();it!=adjencyList[i].end();it++){
        if(!visited[*it]){
            dfs(*it);
        }
    }

    //postorder
    cout<<i<<" ";

    
}


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
    dfs(1);
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
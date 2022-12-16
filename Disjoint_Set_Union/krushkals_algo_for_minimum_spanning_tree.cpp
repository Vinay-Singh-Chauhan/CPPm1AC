#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int N=1e5+2;
vector<int>sz(N);
vector<int>parent(N);

void make_set(int a){
    sz[a]=1;
    parent[a]=a;
}
int find_set(int a){
    if(parent[a]==a){
        return a;
    }
    return parent[a]=find_set(parent[a]);
}
void union_sets(int a,int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b]=a;
    }
    
}
// bool detectcycle(vector<vector<int>>& edges,int n){
//     for(int i=0;i<n;i++){
//         int p1=find_set(edges[i][1]);
//         int p2=find_set(edges[i][2]);
//         if(p1==p2) return true;
//         else union_sets(edges[i][1],edges[i][2]);
//     }
//     return false;
// }
int main()
{
    for(int i=0;i<N;i++){
        parent[i]=i;
    }
    vector<vector<int>> edges;
    int nodes;
    cin>>nodes;
    int ans=0;
    for(int i=0;i<nodes;i++){
        int w,a,d;
        cin>>a>>d>>w;
        edges.push_back({w,a,d});
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<edges.size();i++){
        int w=edges[i][0];
        int u=find_set(edges[i][1]);
        int v=find_set(edges[i][2]);
        if(u==v){
            continue;
        }else{
            ans+=w;
            union_sets(u,v);
        }
    }
    cout<<ans;
return 0;
}
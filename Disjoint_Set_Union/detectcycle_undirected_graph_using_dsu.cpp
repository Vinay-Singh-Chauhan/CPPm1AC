#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int N=1e5+2;
vector<int> parent(N);
vector<int> sz(N);
void make_set(int a){
    parent[a]=a;
    sz[a]=1;
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
        sz[a]+=sz[b];
    }
}
// bool detect_cycle(){
//     int p1=find_set(a);
//     int p2=find_set(b);
//     if(p1==p2) return true;
//     union_sets(a,b);
//     return
// }
int main()
{
    for(int i=0;i<N;i++){
        make_set(i);
    }
    cout<<"nodes and edges"<<endl;
    int i=0,edges,nodes;
    cin>>nodes>>edges;
    bool cycle=false;
    for(i=0;i<edges;i++){
        int a,b;
        cin>> a>>b;
        
        int p1=find_set(a);
        int p2=find_set(b);
        if(p1==p2) cycle=true;
        else union_sets(a,b);
    }
    if(cycle) cout<<"cycle found"<<endl;
    else cout<<"cycle not found";
    return 0;   
}
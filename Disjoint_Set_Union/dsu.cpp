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
int main()
{

    return 0;   
}
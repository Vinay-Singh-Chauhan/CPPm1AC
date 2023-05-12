#include<iostream>
using namespace std;
const int N=1e5+2;
int a[N],tree[4*N];

void build(int node,int st,int en){
    if(st==en){
        tree[node]=a[st];
        return ;
    }
    int m=(st+en)/2;
    build(2*node,st,m);
    build(2*node+1,m+1,en);
    tree[node]=tree[2*node]+tree[2*node+1];
    return ;
}
int main()
{

    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>a[i];
    }
    build(1,0,c-1);
    for(int i=1;i<15;i++){
        cout<<tree[i]<<endl; 
    }
    return 0;
}
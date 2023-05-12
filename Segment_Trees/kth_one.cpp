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
void update(int node,int st,int en,int idx){
    if(st==en){
        if(a[st]==1){
            a[st]=0;
            tree[node]=0;
        }
        else{
            a[st]=1;
            tree[node]=1;
        }
        return ;
    }
    int m=(st+en)/2;
    if(idx<=m){
        update(2*node,st,m,idx);
    }
    else{
        update(2*node+1,m+1,en,idx);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
    
}
int desc_segment_tree(int node,int st,int en,int k){
    if(st==en){
        return st;
    }
    int m=(st+en)/2;
    if(k<tree[2*node]){
         return desc_segment_tree(2*node,st,m,k);
    }
    else{
        return desc_segment_tree(2*node+1,m+1,en,k-tree[2*node]);
    }
}
int main()
{

    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>a[i];
    }
    build(1,0,c-1);
    while(true){
        int type;
        cin>>type;
        if(type==-1) break;
        if(type==1){
            int l;
            cin>>l;
            update(1,0,c-1,l);
        }
        if(type==2){
            int i;
            cin>>i;
            cout<<desc_segment_tree(1,0,c-1,i)<<endl;
        }
    }
    return 0;
}
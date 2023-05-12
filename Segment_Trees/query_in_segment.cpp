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
int query(int node,int st,int en,int l,int r){
    if(st>r||en<l){
        return 0;
    }
    if(l<=st and en<=r){
        return tree[node];
    }
    int m=(st+en)/2;
    int q1=query(2*node,st,m,l,r);
    int q2=query(2*node+1,m+1,en,l,r);
    return q1+q2;
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
            int l,r;
            cin>>l>>r;
            int ans=query(1,0,c-1,l,r);
            cout<<ans<<endl;
        }
    }
    return 0;
}
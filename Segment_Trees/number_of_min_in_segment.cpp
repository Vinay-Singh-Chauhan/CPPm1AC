#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
const int MOD=1e9+7;
int a[N];
pair<int,int> tree[4*N];

void build(int node,int st,int en){
    if(st==en){
        tree[node]={a[st],1};
        return ;
    }
    int m=(st+en)/2;
    build(2*node,st,m);
    build(2*node+1,m+1,en);
    if(tree[2*node].first>tree[2*node+1].first){
        tree[node].first=tree[2*node+1].first;
        tree[node].second=tree[2*node+1].second;
    }
    else if(tree[2*node].first<tree[2*node+1].first){
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second;
    }
    else{
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
    // tree[node]=max(tree[2*node],tree[2*node+1]);
    return ;
}
pair<int,int> query(int node,int st,int en,int l,int r){
    if(st>r||en<l){
        return {MOD,-1};
    }
    if(l<=st and en<=r){
        return tree[node];
    }
    int m=(st+en)/2;
    pair<int,int> q1=query(2*node,st,m,l,r);
    pair<int,int> q2=query(2*node+1,m+1,en,l,r);
    pair<int,int>q;
    if(q1.first<q2.first){
        q=q1;
    }else if(q1.first>q2.first){
        q=q2;
    }
    else{
        q.first=q1.first;
        q.second=q1.second+q2.second;
    }
    return q;
}

void update(int node,int st,int en,int idx,int val){
    if(st==en){
        a[st]=val;
        tree[node].first=val;
        tree[node].second=1;
        return;
    }

    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }else{
        update(2*node+1,mid+1,en,idx,val);
    }
    if(tree[2*node].first>tree[2*node+1].first){
        tree[node].first=tree[2*node+1].first;
        tree[node].second=tree[2*node+1].second;
    }
    else if(tree[2*node].first<tree[2*node+1].first){
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second;
    }
    else{
        tree[node].first=tree[2*node].first;
        tree[node].second=tree[2*node].second+tree[2*node+1].second;
    }
    // tree[node]=max(tree[2*node],tree[2*node+1]);
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
    while(true){
        int type;
        cin>>type;
        if(type==-1) break;
        if(type==1){
            int l,r;
            cin>>l>>r;
            pair<int,int> ans=query(1,0,c-1,l,r);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
        else if(type==2){
            int idx,val;
            cin>>idx>>val;
            update(1,0,c-1,idx,val);
        }
    }

    return 0;
}
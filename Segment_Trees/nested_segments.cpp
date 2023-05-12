#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int tree[4*N];
struct triplet{
    int l,r,idx;
};

bool comp(triplet t,triplet p){
    return t.r<p.r;
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

void update(int node,int st,int en,int idx,int val){
    if(st==en){
        tree[node]=val;
        return;
    }

    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }else{
        update(2*node+1,mid+1,en,idx,val);
    }
    tree[node]=tree[2*node]+tree[2*node+1];
}
int main()
{

    int c,x;
    cin>>c;
    triplet t1;
    t1.l=t1.r=-1;
    vector<triplet> t(c,t1);
    for(int i=0;i<2*c;i++){
        cin>>x;
        if(t[x-1].l==-1){
            t[x-1].l=i;
        }else{
            t[x-1].r=i;
        }
        t[x-1].idx=x;
    }
    sort(t.begin(),t.end(),comp);
    vector<int> ans(c);
    for(int i=0;i<=c;i++){
        ans[t[i].idx-1]=query(1,0,2*c-1,t[i].l,t[i].r);
        update(1,0,2*c-1,t[i].l,1);
    }

for(auto i:ans){
    cout<<i<<" ";
}

    return 0;
}
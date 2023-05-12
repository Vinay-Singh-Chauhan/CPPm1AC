#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
const int MOD=1e9+7;
class grp{
    public:
    long long sum,pref,suff,ans;
    grp(){
        this->pref=0;
        this->suff=0;
        this->sum=0;
        this->ans=0;
    }
    grp(long long pref,long long suff,long long sum,long long ans){
        this->pref=pref;
        this->suff=suff;
        this->sum=sum;
        this->ans=ans;
    }
};
int a[N];
grp tree[4*N];

void build(int node,int st,int en){
    if(st==en){
        if(a[st]<=0){
            tree[node]=grp(0,0,a[st],0);
        }
        else{
            tree[node]={a[st],a[st],a[st],a[st]};
        }
        return ;
    }
    int m=(st+en)/2;
    build(2*node,st,m);
    build(2*node+1,m+1,en);
    long long sum=tree[2*node].sum+tree[2*node+1].sum;
    long long pref=max(tree[2*node].pref,tree[2*node].sum+tree[2*node+1].pref);
    long long suff=max(tree[2*node+1].suff,tree[2*node+1].sum+tree[2*node].suff);
    long long ans=max(max(tree[2*node+1].ans,tree[2*node].ans),tree[2*node].suff+tree[2*node+1].pref);
    tree[node]=grp(pref,suff,sum,ans);
    // tree[node]=max(tree[2*node],tree[2*node+1]);
    return ;
}
void update(int node,int st,int en,int idx,int val){
    if(st==en){
        a[st]=val;
        if(a[st]<=0){
            tree[node]=grp(0,0,a[st],0);
        }
        else{
            tree[node]={a[st],a[st],a[st],a[st]};
        }
        return ;
    }

    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }else{
        update(2*node+1,mid+1,en,idx,val);
    }
    long long sum=tree[2*node].sum+tree[2*node+1].sum;
    long long pref=max(tree[2*node].pref,tree[2*node].sum+tree[2*node+1].pref);
    long long suff=max(tree[2*node+1].suff,tree[2*node+1].sum+tree[2*node+1].suff);
    long long ans=max(max(tree[2*node+1].ans,tree[2*node].ans),tree[2*node].suff+tree[2*node+1].pref);
    tree[node]=grp(pref,suff,sum,ans);
    }
int main()
{

    int c;
    cin>>c;
    for(int i=0;i<c;i++){
        cin>>a[i];
    }
    build(1,0,c-1);
    cout<<tree[1].ans<<endl;
    while(true){
        int type;
        cin>>type;
        if(type==-1) break;
        if(type==1){
            int idx,val;
            cin>>idx>>val;
            update(1,0,c-1,idx,val);
        }
        cout<<tree[1].ans<<endl;
    }

    return 0;
}
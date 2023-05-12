#include<iostream>
using namespace std;
const int N=1e5+2;
int a[N],tree[4*N];
int MOD=1e9+7;

void build(int node,int st,int en){
    if(st==en){
        tree[node]=a[st];
        return ;
    }
    int m=(st+en)/2;
    build(2*node,st,m);
    build(2*node+1,m+1,en);
    tree[node]=max(tree[2*node],tree[2*node+1]);
    return ;
}
int query(int node,int st,int en,int l,int r){
    if(st>r||en<l){
        return -MOD;
    }
    if(l<=st and en<=r){
        return tree[node];
    }
    int m=(st+en)/2;
    int q1=query(2*node,st,m,l,r);
    int q2=query(2*node+1,m+1,en,l,r);
    return max(q1,q2);
}

void update(int node,int st,int en,int idx,int val){
    if(st==en){
        a[st]=val;
        tree[node]=val;
        return;
    }

    int mid=(st+en)/2;
    if(idx<=mid){
        update(2*node,st,mid,idx,val);
    }else{
        update(2*node+1,mid+1,en,idx,val);
    }
    tree[node]=max(tree[2*node],tree[2*node+1]);
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
        if(type==-1){ break;}
        else if(type==2){
            int x;
            cin>>x;
            int ans=c,l=0,h=c-1;
            while(l<=h){
                int m=(l+h)/2;
                if(query(1,0,c-1,l,m)<x){
                    l=m+1;
                }
                else{
                    h=m-1;
                    ans=min(ans,m);
                }
            }
            cout<<ans<<endl;
        }
        else if(type==1){
            int idx,val;
            cin>>idx>>val;
            update(1,0,c-1,idx,val);
        }
    }

    return 0;
}
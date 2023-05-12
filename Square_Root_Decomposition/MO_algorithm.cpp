#include<bits/stdc++.h>
using namespace std;
int rootN;
const int N=1e5+2;
struct Q{
    int idx,l,r;
};
Q q[N];
bool comp(Q a , Q b){
    if(a.l/rootN==b.l/rootN){
        return a.r>b.r;
    }
    return a.l<b.l;
}
int main()
{
    int n ;
    cin>>n;
    vector<int>a(n);
    for(auto &i:a){
        cin>>i;
    }
    rootN=sqrtl(n);
    int qq;
    cin>>qq;
    for(int i=0;i<qq;i++){
        int l,r;
        cin>>l>>r;
        q[i].r=r;
        q[i].l=l;
        q[i].idx=i;

    }
    sort(q,q+qq,comp);
    vector<int>ans(qq);
    int cur_l=0,cur_r=-1,cur_sum=0,l,r;
    for(int i=0;i<qq;i++){
        l=q[i].l;
        r=q[i].r;
        //indexing change
        l--;
        r--;
        while(cur_r<r){
            cur_r++;
            cur_sum+=a[cur_r];
        }
        while(cur_l>l){
            cur_l--;
            cur_sum+=a[cur_l];
        }

        while(cur_l<l){
            cur_sum-=a[cur_l];
            cur_l++;
        }
        while(cur_r>r){
            cur_sum-=a[cur_r];
            cur_r--;
        }
        ans[q[i].idx]=cur_sum;
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
        return 0;
}
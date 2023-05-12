#include <bits/stdc++.h>
using namespace std;
int query(int idx,vector<int>& bit,int n){
    int ans=0;;
    while(idx>0){
        ans+=bit[idx];
        idx-= idx&(-idx);
    }
    return ans;
}
void update(int idx,int val,vector<int>& bit,int n){
    while(idx<=n){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int main()
{
    int test_case;
    cin >> test_case;
    for (int test_c = 0; test_c < test_case; test_c++)
    {
        int n;
        cin>>n;
        vector<int> bit(n+1);
        int u;cin>>u;
        while(u--){
            int l,r,inc;
            cin>>l>>r>>inc;
            l++;r++;//question has 0-based indexing and bit has 1-based indexing
            update(l,inc,bit,n);
            update(r+1,-inc,bit,n);
        }
        int q;
        cin>>q;
        while(q--){
            int w;
            cin>>w;
            w++;
            cout<<query(w,bit,n)<<endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;
int main()
{
    int n;
    cin>>n;
    int len=sqrtl(n)+1;
    vector<int>a(n),b(len,MOD);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i/len]=min(a[i],b[i/len]);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        //l--,r--;//question has 1 based indexing so changing from 1 based indexing to 0 based indexing
        int ans=MOD;
        for(int i=l;i<=r;){
            if(i%len==0 and i+len-1<=r){
                ans=min(b[i/len],ans);
                i+=len;
            }
            else{
                ans=min(a[i],ans);
                i++;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}

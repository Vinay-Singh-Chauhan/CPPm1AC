#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int len=sqrtl(n)+1;
    vector<int>a(n),b(len,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i/len]+=a[i];
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;//question has 1 based indexing so changing from 1 based indexing to 0 based indexing
        int sum=0;
        for(int i=l;i<=r;){
            if(i%len==0 and i+len-1<=r){
                sum+=b[i/len];
                i+=len;
            }
            else{
                sum+=a[i];
                i++;
            }
        }
        cout<<sum<<endl;
    }


    return 0;
}

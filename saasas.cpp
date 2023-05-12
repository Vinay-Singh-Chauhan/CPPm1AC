#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
int test_case;
cin>>test_case;
for(int test_c=0;test_c<test_case;test_c++){

    int n;
    cin>>n;
    vector<int> a(n);
    
    for(auto& i:a){
        cin>>i;
    }
    vector<int>b=a;
    sort(b.begin(),b.end());
    int m1=b[b.size()-1],m2=b[b.size()-2];
    int z=m1+m2;
    int sm=0,lg=0;
    bool f=false;
    for(int i=0;i<n/2;i++){
        if(b[i]+b[n-i-1]>=z){
            cout<<"NO"<<endl;
            f=true;
            break;
        }
        
    }
    if(!f){
        cout<<"YES"<<endl;
    }
    
    
}
return 0;
}
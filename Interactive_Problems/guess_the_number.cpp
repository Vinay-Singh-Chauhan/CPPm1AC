#include<iostream>
using namespace std;
int main()
{
    int l=0,h=1000000,ans=-1;
    string s;
    while(l<=h){
        int mid=(l+h)/2;
        cout<<mid<<endl;
        cout<<flush;
        cin>>s;
        if(s=="<"){
            h=mid-1;
        }else{
            ans=max(ans,mid);
            l=mid+1;
        }
    }
    cout<<"! "<<ans<<endl;
    return 0;
}
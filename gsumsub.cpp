#include<iostream>
using namespace std;
int main()
{
    int s;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int st=0;
    int en=0;
    int sum;
    cin>>sum;
    // cout<<sum;
    s=arr[st];
    while (s<=sum)
    {
        if(s==sum){
            cout<<st<<" "<<en;
            return 0;
        }
        else{
            en++;
            s+=arr[en];
        }
    }
    // cout<<s;
    while(s>=sum){
        if(s==sum){
            cout<<st<<" "<<en;
            return 0;
        }
        else{
            s-=arr[st];
            st++;
        }
    }
    cout<<"Not Found!";
    return 0;
    
}
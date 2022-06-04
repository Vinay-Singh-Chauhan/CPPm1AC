#include<iostream>
using namespace std;
int main(){
    int pd,curr,maxl,n,k=0;
    cin>>n;
    int arr[n];
    curr=2;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxl=INT_MIN;
    pd=arr[1]-arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]-arr[i-1]==pd){
            curr++;
            maxl=max(curr,maxl);
        }
        else{
            // k=i;
            curr=2;
        }
    }
    cout<<maxl<<endl;
    // <<k<<k+maxl;
}
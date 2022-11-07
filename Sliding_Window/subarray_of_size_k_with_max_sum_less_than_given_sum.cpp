#include<iostream>
using namespace std;
int maxSum(int arr[],int n,int k,int gsum){
    int ksum=0,i;
    int ans=0;
    for(i=0;i<k;i++){
        ksum+=arr[i];
    }
    // int j=0;
    if(ksum<gsum){
        ans=ksum;
    }
    while(i<n){
        
        // ksum-=arr[j];
        ksum-=arr[i-k];
        ksum+=arr[i];
        i++;
        // j++;
        if(ksum<gsum) ans=max(ksum,ans);
    }
    return ans;
}
int main()
{
    int arr[]={7,5,4,6,8,9};
    cout<<maxSum(arr,6,3,20);
    return 0;
}
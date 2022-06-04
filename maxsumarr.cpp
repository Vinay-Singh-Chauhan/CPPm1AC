#include<iostream>
using namespace std;
//---------------------------------Kadane Approach --------------------------------------
    int kadane(int a[],int n){
        int sum=INT_MIN;
        int currsum=0;
        for(int i=0;i<n;i++){
            currsum+=a[i];
            if(currsum<0){
                currsum=0;
            }
            sum=max(currsum,sum);
        }
        return sum;
    }
int main(){
    //-------------------------Cumulative Sum Approach------------------------------------
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    // int sarr[n+1];
    // sarr[0]=0;
    // for(int i=1;i<n+1;i++){
    //     sarr[i]=sarr[i-1]+arr[i-1];
    // }    for(int i=0;i<n+1;i++){
    //     cout<<sarr[i];
    // }
    // // cout<<sarr<<" ";
    // int maxsum=INT_MIN;
    // for(int i=0;i<n+1;i++){
    //     maxsum=max(maxsum,sarr[i]);
    //     int sum=0;
    //     for(int j=1;j<=i;j++){
    //         sum=sarr[i]-sarr[j-1];
    //         maxsum=max(maxsum,sum);
    //     }
    // }
    // cout<<maxsum;
    // return 0;
    //-----------------------------------------------------------------------------------------
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<kadane(arr,n);
    return 0;

}
#include<iostream>
#include<vector>
using namespace std;
const int N=1e3+2;
// int dp[N];
// int lis(vector<int>& arr,int n){
//     if(dp[n]!=-1) return dp[n];
//     dp[n]=1;
//     for(int i=0;i<n;i++){
//         if(arr[i]<arr[n]){
//             dp[n]=max(dp[n],1+lis(arr,i));
//         }
//     }
    
//     return dp[n];
// }
int main()
{


   
    int n,ans=0;
    cin>>n;
    vector<int> arr(n);
    vector<int>dp(n,1);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],1+dp[j]);
            }
        }
        ans=max(ans,dp[i]);
    }
    
    cout<<ans<<endl;
    
    // cout<<dp[n-1];
    return 0;
}
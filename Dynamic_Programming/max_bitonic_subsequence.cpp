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


   
    int n=8;
    vector<int> arr={1,11,2,10,4,5,2,1};

    vector<int> forward(n,1);
    vector<int> backward(n,1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[i]>arr[j]){
                forward[i]=max(forward[i],1+forward[j]);
            }
        }

    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[j]<arr[i]){
                backward[i]=max(backward[i],1+backward[j]);
            }
        }

    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,backward[i]+forward[i]-1);
    }

   cout<<ans;
    
    // cout<<dp[n-1];
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5 +2,MOD=1e7+9;
#define ll long long
//recursion
// int minSquares(ll n){
//     if(n==0||n==1||n==2||n==3) return n;
//     int ans=MOD;
//     for(int i=1;i*i<=n;i++){
//         ans=min(ans,1+minSquares(n-i*i));
//     }
//     return ans;
// }

// memoization
int dp[N];

int minSquares(ll n){
    if(n==1||n==2||n==3||n==0) return n;
    if(dp[n]!=MOD) return dp[n];
    for(int i=1;i*i<=n;i++){
        dp[n]=min(dp[n],1+minSquares(n-(i*i)));
    }
    return dp[n];
}


int main()
{
    for(int i=0;i<N;i++) dp[i]=MOD;
    cout<<minSquares(1024);
    

    //tabulation
    
    // int n;
    // cin>>n;
    // vector<int>dp (n+1,MOD);
    // dp[0]=0;
    // dp[1]=1;
    // dp[2]=2;
    // for(int i=1;i*i<=n;i++){
    //     for(int j=0;i*i +j<=n;j++){
    //         dp[i*i+j]=min(dp[i*i+j],1+dp[j]);
    //     }
    // }
    // cout<<dp[n];

    return 0;
}
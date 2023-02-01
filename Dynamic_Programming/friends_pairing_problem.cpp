#include<bits/stdc++.h>
using namespace std;
int  number_of_ways(int n,vector<int>& dp){
    if(n==1 || n==0) return dp[n];
    if(dp[n]!=0) return dp[n];
    return dp[n]=number_of_ways(n-1,dp) + (n-1)*number_of_ways(n-2,dp);


}
int main()
{
    int n=3;
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    cout<<number_of_ways(n,dp);
    return 0;
}
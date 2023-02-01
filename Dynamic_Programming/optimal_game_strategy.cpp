#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp(100,vector<int>(100,-1));
int solve(vector<int>& a,int i,int j){
    if(i==j)return a[i];
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int c1=a[i]+min(solve(a,i+2,j),solve(a,i+1,j-1));
    int c2=a[j]+min(solve(a,i+1,j-1),solve(a,i,j-2));
    return dp[i][j]=max(c2,c1);

}
int main()
{
    vector<int> a={1,2,3,4};
    int n=a.size();
    cout<<solve(a,0,n-1);
    return 0;
}
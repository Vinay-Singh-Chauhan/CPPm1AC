#include<bits/stdc++.h>
using namespace std;
const int N=2e3+2;
int dp[N][N][7];
int lcs(string&s1,string& s2,int i,int j,int k){
    if(i==0 || j==0) return dp[i][j][k]=0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    int c1=0,c2=0,c3=0;
    if(s1[i]==s2[j]){
        c1=1+lcs(s1,s2,i-1,j-1,k);  
    }
    if(k>0){
        c2=1+lcs(s1,s2,i-1,j-1,k-1);
    }
    c3=max(lcs(s1,s2,i-1,j,k),lcs(s1,s2,i,j-1,k));
    
    return dp[i][j][k]=max({c1,c2,c3});

}
int main()
{


   
    // int n=5,ans=0;
    // cin>>n;
    // vector<int> arr(n);/
    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         dp[i][j]=-1;
    //     }
    // }
    memset(dp,-1,sizeof(dp));
    // for (int i = 0; i < N; i++)
    // {
    //     dp[0][i]=-1;
    //     dp[i][0]=-1;
    // }
    string s1="12345";
    string s2="53142";
    cout<<lcs(s1,s2,4,4,1);
    return 0;
}
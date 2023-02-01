#include<iostream>
#include<vector>
using namespace std;
const int N=1e3+2,MOD=1e9+7;
int dp[N][N];
int a[N];
// int mcm(int i,int j){
//     if(i==j) return 0;

//     if(dp[i][j]!=-1) return dp[i][j];
//     dp[i][j]=MOD;
//     for(int k=i;k<j;k++){
//         dp[i][j]=min(dp[i][j],mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j]);
//     }
    
//     return dp[i][j];

// }
int main()
{


   
    int n;
    cin>>n;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j]=-1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];

    }
    for (int i = 1; i < n; i++)
    {
        dp[i][i]=0;
    }
    for(int l=2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j=i+l-1;
            dp[i][j]=MOD;
            for(int k=i;k<j;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
            }
        }
    }
    cout<<dp[1][n-1];
    return 0;
}
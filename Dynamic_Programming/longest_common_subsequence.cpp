#include<iostream>
#include<vector>
using namespace std;
const int N=1e3+2;
int dp[N][N];
int lcs(string&s1,string& s2,int i,int j){
    if(i==0 || j==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        dp[i][j]=1+lcs(s1,s2,i-1,j-1);  
    }
    else{
        dp[i][j]=max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
    }
    return dp[i][j];

}
int main()
{


   
    int n,ans=0;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j]=-1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        dp[0][i]=0;
        dp[i][0]=0;
    }
    string s1="rishabh";
    string s2="shubhi";
    cout<<lcs(s1,s2,7,6);
    return 0;
}
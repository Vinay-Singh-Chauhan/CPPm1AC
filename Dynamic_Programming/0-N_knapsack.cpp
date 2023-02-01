#include<iostream>
using namespace std;
const int N=1e3+2;
int wt[N];
int val[N];
int dp[N][N];

int main()
{

    int n=5,w=11;
    int wt[n]={3,2,4,5,1};
    int val[n]={4,3,5,6,1};

    int dp[w+1]={0};
    for(int i=0;i<=w;i++){
        for(int j=0;j<n;j++){
            if(i-wt[j]>=0){
                dp[i]=max(dp[i],val[j]+dp[i-wt[j]]);
            }
        }
    }
    cout<<dp[w];
    return 0;
}
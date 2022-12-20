#include<iostream>
#include<vector>
using namespace std;
const int N = 1e3 + 2;
long long dp[N];
long long fib(int n){
    if(n==0) return  0;
    if(n==1) return 0;
    if(n==2) return 1;
    if(dp[n]!=-1){
        return  dp[n];
    }

    dp[n]= fib(n-1)+fib(n-2);
    return dp[n];
}
// long long int fib(int n, long long * arr){
//     if(n==0||n==1){return n;}
//     for(int i=0;i<n-1;i++){long long temp=arr[0];
//     arr[0]=arr[1];
//     arr[1]=temp+arr[0];}
//     return arr[1];
// }
int main()
{
    // long long * arr=new long long[2];
    // arr[0]=0;
    // arr[1]=1;
    // cout<<fib(12,arr);
    int n;
    cin>>n;
    for(int i=0;i<N;i++){
        dp[i]=-1;
    }
    cout<<fib(n);

//tabulation
    // int n;
    // cin>>n;
    // vector<int> tb(n+1);
    // tb[0]=0;
    // tb[1]=0;
    // tb[2]=1;
    // for(int i=3;i<=n;i++){
    //     tb[i]=tb[i-1]+tb[i-2];
    // }
    // cout<<tb[n];
    return 0;
}
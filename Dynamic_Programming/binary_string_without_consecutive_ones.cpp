#include<iostream>
using namespace std;
const int N= 1e3+2;
long long int dp[N];
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
int main()
{
    int l;
    cout<<fib(l+1);
    return 0;
}
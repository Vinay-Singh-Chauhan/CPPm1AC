// (a+b)%m= a%m + b%m
// (a-b)%m= a%m - b%m //if rhs is negative return rhs+m
// (a*b)%m= a%m * b%m
// (a/b)%m= a%m * pow(b,-1)%m
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2, MOD= 1e9+7;
// iterative
long long int power( long long int a,long long int n){
    a %= MOD;
    long long int ans=1;
    while (n>0)
    {
        if(n&1){
            ans=(ans*a) % MOD;
        }
        a= (a*a) % MOD;
        n=n>>1;
    }
    return ans;
}

// recursive
long long int rpower( long long int a,long long int n){
    // a%=MOD;
    if(n==0){
        return 1;
    }
    long long int p=(rpower(a,n/2)%MOD);
    if(n&1){
        return (((p*p)%MOD)*a)%MOD;
    }
    else{
        return ((p*p)%MOD);
    }
    
}
int main()
{
    // int a=3287642832;
    // a%=MOD;
    cout<<rpower(3287642832,6);
    return 0;
}
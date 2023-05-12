#include<iostream>
using namespace std;
#define int long long

int power(int a,int n,int p ){
    int res=1;
    a=a%p;
    while(n>0){
        if(n&1){
            res=(res*a)%p;
        }
        n=n>>1;
        a=(a*a)%p;
    }
    return res;
}
int mod_inverse(int a,int p){
    return power(a,p-2,p);

}
int mod_fact(int n,int p){
    if(n>=p) return 0;
    int res=p-1;

    for(int i=n+1;i<p;i++){
        res=(res*mod_inverse(i,p))%p;
    }
    return res;
}
int32_t main()
{
    int a,b;
    cin>>a>>b;
    cout<<mod_fact(a,b);
    return 0;
}
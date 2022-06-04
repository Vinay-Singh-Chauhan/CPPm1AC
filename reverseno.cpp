#include<iostream>
using namespace std;
int main(){
    int n,s,r;
    s=0;
    cin>>n;
    while(n>0){
        r=n%10;
        // cout<<r<<endl;;
        s=s*10 + r;
        // cout<<s<<endl;
        n = n/10;
    }
    cout<<s;
}


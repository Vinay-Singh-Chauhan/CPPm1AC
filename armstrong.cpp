#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,c,r;
    c=0;
    cin>>n;
    int np=n;

    while(n>0){
        r=n%10;
        // cout<<r<<endl;;
        c=c+pow(r,3);
        // cout<<s<<endl;
        n = n/10;
    }
    if( c == np){
        cout<<"this is a armstrong no.";
    }
    cout<<np;
}


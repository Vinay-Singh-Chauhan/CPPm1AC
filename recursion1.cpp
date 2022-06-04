#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }else{
        return n*fact(n-1);
    }
}
int sum(int n){
    if(n==1){
        return 1;
    }else{
        return n+ sum(n-1);
    }
}
int power(int a,int p){
    if(p==0){
        return 1;
    }else{
        return a*power(a,p-1);
    }
}
int fib(int n){
    if(n==1||n==0){
        return n;
    }else{
        return fib(n-1)+fib(n-2);
    }
}
int main(){
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}
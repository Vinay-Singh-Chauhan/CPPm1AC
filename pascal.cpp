#include<iostream>
using namespace std;
int fact(int n){
    int fact=1;
    for(int i=1;i<=n;i++){
        fact*=i;
    }
    return fact;
}
int ncr(int i,int j){
    return fact(i)/(fact(j)*fact(i-j));
}
int main (){
    int n;
    cout<<"Enter number of rows you want in your pascal triangle:\t";
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++){
            cout<<ncr(i,j)<<" ";
        }cout<<endl;
    }
    return 0;
}
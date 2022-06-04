#include<iostream>
using namespace  std;
int main(){
    int a,b,c,x,y,z;
    cout<<"enter three integers:\t";
    cin>>x>>y>>z;
    if(max(x,max(y,z))==x){
        a=x;
        b=y;
        c=z;        
    }
    else if(max(x,max(y,z))==y){
        a=y;
        b=x;
        c=z;        
    }
    else {
        a=z;
        b=x;
        c=y;
    }
    if(a*a==b*b + c*c){
        cout<<" It's a Pytahgorian Triplet!";
    }else{
        cout<<"no it's not a pythagorian triplet";
    }
    return 0;
}
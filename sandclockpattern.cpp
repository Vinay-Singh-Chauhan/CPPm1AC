//_________________________= Sand-Clock Pattern =_______________________
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        for(int j=1;j<i;j++){
        cout<<" ";
        }
        for(int j=n;j>=i;j--){
        cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1;i>=1;i--){
        for(int j=1;j<i;j++){
        cout<<" ";
        }
        for(int j=n;j>=i;j--){
        cout<<"* ";
        }
        cout<<endl;
    }
    // for(int j=0;j<i;j++){
    //     cout<<" ";
    // }
    // for(int i=n;i>=0;i--){
    //     cout<<"*";
    // }
    // cout<<endl;
    

    return 0;
}
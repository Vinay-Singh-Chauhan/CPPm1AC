#include<iostream>
using namespace std;
int pairing(int n){
    if(n==2){return 2;
    }
    if(n==1){return 1;
    }
    if(n==0){
        return 0;
    }
    // int count =0;
    return pairing(n-2)*(n-1)+pairing(n-1);
    // return count;
}
int main(){
    cout<<pairing(4);
    return 0;
}
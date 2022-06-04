#include <iostream>
using namespace std;
int main(){
        int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
    int st=0;
    int en=n-1;
    int s;
    cin>>s;
    while(st<en){
           int sum=arr[st]+arr[en];
    if(sum==s){
        cout<<st<<' '<<en;
        return 0;
    }
    else if(sum<s){
        st++;
    }
    else if(sum>s){
        en--;
    } 
    }
    cout<<" not found!";
    return 0;
}
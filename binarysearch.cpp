#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i =0 ;i<n;i++){
        cin>>arr[i];
    }
    int mid=n/2;
    int start=0;
    int end=n;
    int key;
    cin>>key;
    while(arr[mid]!=key){
        if(arr[mid]>key){
            end=mid;
            mid=(start+end)/2;
        }
        else{
            start=mid;
            mid=(start+end)/2;
        } 
    }
    if(arr[mid]==key){
        cout<<mid;
    }else{
        cout<<-1;
    }
    return 0;
}//this is my solution ..
//solution provided by apna college is somewhat different;
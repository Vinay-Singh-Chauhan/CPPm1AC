#include<iostream>
using namespace std;
void swap(int i ,int arr[],int n){
    int temp=arr[i];
    arr[i]=arr[n-i-1];
    arr[n-1-i]=temp;
}
int main(){
    int t,n,op=0;
    cin>>t;
    for(int i=1; i<=t;i++){
        cin>>n;
        int boys[n];
        int girls[n];
        for(int i=0;i<n;i++){
            cin>>boys[i];
        }
        for(int i=0;i<n;i++){
            cin>>girls[i];
        }
        if(n%2!=0){
            if(boys[n/2]!=girls[n/2])
            cout<<"-1";
        }
        for(int i=0;i<n;i++){
            if(((boys[i]!=girls[i]&&boys[i]!=girls[n-1-i]))||((boys[n-1-i]!=girls[n-1-i]&&boys[n-1-i]!=girls[i]))){
            swap(i,girls,n);
            op++;
        }
        }
        cout<<op;
    }
}
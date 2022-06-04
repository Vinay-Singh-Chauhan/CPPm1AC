#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n+1]={0};
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(arr[j]==0){
                // cout<<"i = "<<i<<"\tj= "<<j<<endl;
                arr[j]=i;
                // cout<<"Changes at index"<<j<<"\tarr["<<j<<"]"<<arr[j]<<endl;
            }
        }
    }
    while(n!=1){
        cout<<arr[n]<<" ";
        n/=arr[n];
    }
}
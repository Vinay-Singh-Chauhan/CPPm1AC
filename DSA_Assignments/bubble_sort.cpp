#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int j=0;j<n;j++){
    for(int i=1;i<n-j;i++){
        if(arr[i-1]>arr[i]){
            int temp=arr[i-1];                                        
            arr[i-1]=arr[i];
            arr[i]=temp;
        }
    }
    }
    

        for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}
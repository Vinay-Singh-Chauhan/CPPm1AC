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
        int min=INT_MAX;
        int k;
        for(int i=j;i<n;i++){
        if(min>arr[i]){
            min=arr[i];
            k=i;                                                 
        }
        }
        arr[k]=arr[j];;
        arr[j]=min;
        int temp=arr[j];
        arr[j]=min;

    }


        for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}

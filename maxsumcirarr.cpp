#include<iostream>
using namespace std;
    int kadane(int a[],int n){
        int sum=INT_MIN;
        int currsum=0;
        for(int i=0;i<n;i++){
            currsum+=a[i];
            if(currsum<0){
                currsum=0;
            }
            sum=max(currsum,sum);
        }
        return sum;
    }
int main(){
    int n,s=0;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++){
        cin>>arr[i];
    }
        for(int i =0;i<n;i++){
        s+=arr[i];
    }
    for(int i =0;i<n;i++){
        arr[i]*=-1;
    }
    cout<<s<<endl;
    cout<<kadane(arr,n)<<endl;
    cout<<s+kadane(arr,n);
    return 0;
}
#include<iostream>
using namespace std;

int peak_elements(int arr[],int n){
    int start=0,end=n;
    while (start<=end)
    {
        int mid=(start+end)/2;
        // cout<<arr[mid]<<endl;

        if((mid==0 or arr[mid-1]<=arr[mid])and (mid==n-1 or arr[mid+1]<=arr[mid])){
            return mid;
        }
        else if(mid>0 and arr[mid-1]>arr[mid]){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return -1;
}

int main()
{
    int arr[]={0,6,8,5,7,9};
    cout<<peak_elements(arr,5);
    return 0;
}
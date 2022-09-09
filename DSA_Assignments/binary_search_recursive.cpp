#include<iostream>
using namespace std;
int binary_search(int arr[],int k,int start,int end){
    int mid=(start+end)/2;
    if(end<start){
        return -1;
    }
    if(arr[mid]==k){
        return mid;
    }
    if(arr[mid]>k){
        return binary_search(arr,k,start,mid);
    }
    if(arr[mid]<k){
        return binary_search(arr,k,mid+1,end);
    }
}
int main(){
    int arr[7]={1,2,3,4,5,6,7};
    cout<<binary_search(arr,7,0,6);
}

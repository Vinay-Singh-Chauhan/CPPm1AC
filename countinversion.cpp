#include<iostream>
using namespace std;
// int count=0;
long long merge(int arr[],int start,int mid,int end){
    long long inv=0;
    int n1=mid-start+1;
    int n2=end-mid;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[start+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+1+i];
    }
    int k=start;
    int j=0,i=0;
    while(i<n1&&j<n2){
        if(arr1[i]<arr2[j]){
        arr[k]=arr1[i];
        k++;
        i++;
    }
    else{
        inv+=n1-i;
        arr[k]=arr2[j];
        k++;j++;
    }
    }
    while(i<n1){
        arr[k]=arr1[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=arr2[j];
        k++;j++;
    }
    return inv;
}
long long mergesort(int arr[],int start,int end){
    long long inv=0;
    if(start<end){
        int mid=(start+end)/2;
        inv+=mergesort(arr,start,mid);
        inv+=mergesort(arr,mid+1,end);
        inv+=merge(arr,start,mid,end);
    }
    return inv;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int count =0;
    // for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(arr[j]<arr[i]){
    //             count++;                               ++++++ brute force ++++++++++
    //         }
    //     }
    // }
    cout<<mergesort(arr,0,n-1);
    // cout<<inv;


    
}
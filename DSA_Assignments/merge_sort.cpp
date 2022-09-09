#include<iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end){
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
}
void mergesort(int arr[],int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    cout<<endl;
    mergesort(arr,0,n);

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    return 0;


}

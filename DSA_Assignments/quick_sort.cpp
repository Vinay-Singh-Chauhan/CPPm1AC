#include<iostream>
using namespace std;
int partition(int arr[],int start,int end){
    int pivot=arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
        // i=end+1;
    }
    int temp=arr[i+1];
            arr[i+1]=arr[end];
            arr[end]=temp;
        return i+1;

}
void quicksort(int arr[],int start ,int end){
    if(start<end){
        int pivot=partition(arr,start,end);
        quicksort(arr,start,pivot-1);
        quicksort(arr,pivot+1,end);
    }
    return;
}
int main(){
    int arr[5]={1,7,5,2,6};
    quicksort(arr,0,4);//end should be the index of last element i.e. n-1;
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    // quicksort()
}
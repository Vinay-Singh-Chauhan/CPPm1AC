// #include <iostream>
// using namespace std;
// void quicksort(int arr[],int n){
//     for(int i=0;i<n;i++){
//         int count=-1;
//         for(int j=0;j<=n;j++){
//             if(arr[j]<arr[i]){
//                 // cout<<j<<"th element is "<<arr[j]<<endl;
//                 count++;
//             }
            
            
//         }
//         int temp=arr[count];
//         arr[count]=arr[i];
//         arr[i]=temp;
//     //     for(int i =0;i<n;i++){
//     //     cout<<arr[i];
//     // }cout<<endl;
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i =0;i<n;i++){
//         cin>>arr[i];
//     }
//     quicksort(arr,n);
//     for(int i =0;i<n;i++){
//         cout<<arr[i];
//     }
//     return 0;
// }

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
    int arr[]={1,7,5,2,6};
    quicksort(arr,0,4);//end should be the index of last element i.e. n-1;
    for(int i=0;i<5;i++){
        cout<<arr[i];
    }
    // quicksort()
}
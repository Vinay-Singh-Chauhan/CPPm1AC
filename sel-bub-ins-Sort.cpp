#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //-----------------------------------------------------------------------------------------
//     for(int j=0;j<n;j++){
//         int min=INT_MAX;
//         int k;
//         for(int i=j;i<n;i++){
//         if(min>arr[i]){
//             min=arr[i];
//             k=i;                                                 // My Selection Sort Algorithm
//         }
//         }
//         arr[k]=arr[j];;
//         arr[j]=min;
//         int temp=arr[j];
//         arr[j]=min;
// }
    //------------------------------------------------------------------------------------------
    // for(int j=0;j<n;j++){
    // for(int i=1;i<n-j;i++){
    //     if(arr[i-1]>arr[i]){
    //         int temp=arr[i-1];                                         // My Bubble Sort Algorithm
    //         arr[i-1]=arr[i];
    //         arr[i]=temp;
    //     }
    // }
    // }
    //------------------------------------------------------------------------------------------
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j]){
                int temp=arr[j];                                            // My Insertion Sort Algorithm
                arr[j]=arr[i];                                          
                arr[i]=temp;
            }
        }
    }
    //-------------------------------------------------------------------------------------------


        for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}
// do check out the solution provided by apna college.
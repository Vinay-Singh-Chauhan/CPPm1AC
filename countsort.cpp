// #include<iostream>
// #include<climits>
// using namespace std;
// int main(){
//     int n,m=INT_MIN;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         m=max(m,arr[i]);
//     }
//     int count[m+1]={0};
//     for(int i=0;i<n;i++){
//         count[arr[i]]++;
//     }
//     int k=0;
//     for(int i=0;i<=m;i++){
//         while(count[i]>0){
//             arr[k]=i;
//             count[i]--;
//             k++;
//         }
        
//     }
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

//     return 0;
// }
#include<iostream>
#include<climits>
using namespace std;
void countsort(int arr[],int n,int m){
    int count[m+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=m;i++){
        count[i]+=count[i-1];
    }
    int sarr[n];
    for(int i=n-1;i>=0;i--){
    if(count[arr[i]]>0){
        count[arr[i]]--;

        sarr[count[arr[i]]]=arr[i];}
    }
    for(int i=0;i<n;i++){
        arr[i]=sarr[i];
    }
    return;
}
int main(){
    int n,m=INT_MIN;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m=max(m,arr[i]);
    }
    countsort(arr,n,m);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
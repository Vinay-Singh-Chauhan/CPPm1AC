#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isFeasible(int mid, int arr[],int n,int k){
    int pos=arr[0] , elements=1;
    for(int i=1;i<n;i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            elements++;
            if(elements==k){
                return true;
            }
        }
    }
    return false;
}
int kElements(int arr[],int n,int k){
    sort(arr,arr+n);
    int result=-1;
    int left=arr[0],right = arr[n-1];
   while(left<right){ int mid =(left+right)/2;
    if(isFeasible(mid,arr,n,k)){
        result=max(mid,result);
        left=mid+1;
    }else{
        right=mid;
    }}
    return result;
}
int main()
{
    int arr[]={1,2,8,4,9};
    cout<<kElements(arr,5,3);
    return 0;
}
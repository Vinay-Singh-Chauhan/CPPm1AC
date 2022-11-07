#include<iostream>
using namespace std;
bool isPalindrome(int arr[],int start,int end){
    int size=end-start;
    for(int i=0;i<=size/2;i++){
        if(arr[start+i]!=arr[start+size-i]){
            return false;
        }
    }
    return true;
}
void palindromicSubarray(int arr[],int n,int k){
    int i=k-1,j=0;
    pair<int,int> ans={-1,0};
    while(i<=n){
        if(isPalindrome(arr,j,i)){
            ans=make_pair(j,i);
            break;
        }
        i++;
        j++;
    }
    if(ans.first!=-1){
        for(int i=ans.first;i<=ans.second;i++){
            cout<<arr[i];
        }
    }else{
        cout<<"no such subarrray";
    }
    return ;
}
int main()
{
    int arr[]={2,3,5,1,1,5};
    // cout<<isPalindrome(arr,2,4);
    palindromicSubarray(arr,6,4);
    return 0;
}
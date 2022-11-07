#include<iostream>
using namespace std;

bool isPossible(int arr[],int n,int m,int mid){
    int studentsRequired=1;
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){
            return false;
        }
        if(sum+arr[i]>mid){
            sum=arr[i];
            studentsRequired++;
            if(studentsRequired>m){
                return false;
            }
        }else{
            sum+=arr[i];
        }
    }
    return true;
}

int allocateMinimumPages(int arr[],int n,int m)
{
    int ans=INT_MAX;
    if(n<m){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    int start=0,end=sum;
    while(start<=end){
        int mid=mid=(end+start)/2;
        if(isPossible(arr,n,m,mid)){
            end=mid-1;
            ans=min(ans,mid);
        }else{
            start=mid+1;
        }
    }
    return ans;
}
int main()
{
    int arr[]={12,34,67,90};
    cout<<allocateMinimumPages(arr,4,2);
    return 0;
}
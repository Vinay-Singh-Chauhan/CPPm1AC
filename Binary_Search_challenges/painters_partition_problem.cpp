#include<iostream>
#include<algorithm>
using namespace std;

bool isPossible(int arr[],int n,int m,int mid){
    int painters=1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>mid){
            return false;
        }
        if (sum+arr[i]>mid)
        {
            painters++;
            sum=arr[i];
            if(painters>m){
                return false;
            }
        }else{
            sum+=arr[i];
        }
        
    }
    return true;
}

int minimumTimeRequired(int arr[],int n,int m,int unitforoneunitboard){
    sort(arr,arr+n);
    int ans=INT_MAX;
    if(m>n){
        return arr[n-1];
    }
    int sum=0,k=0;
    for(int i=0;i<n;i++){
        k=max(k,arr[i]);
        sum+=arr[i];
    }
    int start=k,end=sum;
    while (start<=end)
    {
        int mid=(start+end)/2;
        if(isPossible(arr,n,m,mid)){
            ans=min(ans,mid);
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    return ans*unitforoneunitboard;
    
}

int main()
{
    int arr[]={10,20,30,40};
    cout<<minimumTimeRequired(arr,4,2,1);
    return 0;
}
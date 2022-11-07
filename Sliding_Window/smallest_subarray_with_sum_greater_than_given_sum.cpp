#include<iostream>
#include<vector>
using namespace std;

int smallestSubArray(int arr[],int n,int gsum ){
    int ksum=0,i=0,minLength=n+1,j=0;
    while(i<n){
        while(i<n and ksum<=gsum){
            ksum+=arr[i];
            i++;
        }
       
        while (ksum>gsum and j<n)
        {
            if(i-j<minLength){
                minLength=i-j;
            }
            ksum-=arr[j];
            j++;
        }
       
    }
    return minLength;
}

int main()
{
    int arr[]={1,4,45,6,10,19};
    cout<<smallestSubArray(arr,6,51);
    return 0;
}
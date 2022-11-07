#include<iostream>
#include<cmath>
using namespace std;
bool isNumberPerfect(int a){
    int sum=1;
    for(int i=2;i<sqrt(a);i++){
        if(a%i==0){
            if(i==a/i){
                sum+=i;
            }else{
                sum+=i+a/i;
            }
        }
    }
    return (sum==a and a!=1);
}
int maxSum(int arr[],int n,int k){
    if(n<k){
        cout<<"invalid values";
        return -1;
    }
    int result=0;
    for(int i=0;i<k;i++){
        result+=arr[i];
    }
    int sum=result;
    for(int i=k;i<n;i++){
        sum+=(arr[i]-arr[i-k]);
        result=max(result,sum);
    }
    return result;
}
int maxNumberOfPerfects(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(isNumberPerfect(arr[i])){
            arr[i]=1;
        }else{
            arr[i]=0;
        }
    }
    return maxSum(arr,n,k);
}

int main()
{
    int arr[]={28,2,3,6,496,99,8128,24 };
    cout<<maxNumberOfPerfects(arr,8,4);
    return 0;
}
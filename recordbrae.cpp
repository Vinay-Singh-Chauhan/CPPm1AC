#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    
    int maxv;
    int ans=0;
    for(int i=0;i<n;i++){
        if(arr[i]>maxv){
            maxv=arr[i];
            if (i==n-1){
                cout<<"RBD";
            }else if( arr[i+1]<arr[i])
            {
                cout<<i+1<<"th day is RBD";
            }
            
        }
    }

}

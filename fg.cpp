#include<iostream>
using namespace std;
int main(){
    int t;
    int n;
    int c=0;
    cin>>n;
    int arr[101]={0};
    for(int i=0;i<n;i++){
        cin>>t;
        arr[t]=1;
    }
    // for(int i;i<101;i++){
    //     if(arr[i]==1) cout<<i<<" ";
    // }
    cout<<endl<<endl;
    for(int i=1;i<101;i++){
        if(arr[i]==1){
            c++;
            // cout<<i<<" ";
            for(int j=i;j<101;j+=i){
            arr[j]=0;
        }
        }
        
    }
    cout<<c<<endl;
}
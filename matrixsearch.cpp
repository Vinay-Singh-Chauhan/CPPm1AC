#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
        cin>>arr[i][j];
        }
    }
    int sum;
    cin>>sum;
    int high=n;
    int low=0;
    while(high>0&&low<n){
        if(arr[low][high]==sum){
            cout<<low<<" "<<high;
            return 0;
        }
        else if(arr[low][high]<sum){
            low++;
        }
        else if(arr[low][high]>sum){
            high--;
        }
    }
    cout<<" not found";
    return 0;
    }
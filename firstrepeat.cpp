#include <iostream>
using namespace std;
int main(){
    int n;
    int minidx=INT_MAX;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    int check[1000];
    for (int i = 0; i <1000; i++)
    {
        check[i] = -1;
    }
    for (int i = 0; i <n; i++)
    {   if(check[arr[i]]==-1){
        check[arr[i]]=i;

    }
    else{
        minidx=min(minidx,check[arr[i]]);
    }
    }
    cout<<minidx;
    return 0;
}
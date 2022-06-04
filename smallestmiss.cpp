#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
    }
    bool check[1000];
    for (int i = 0; i <1000; i++)
    {
        check[i]=false;
    }
    for (int i = 0; i <n; i++)
    {   if(arr[i]>=0){
        check[arr[i]]=true;

    }
    }
    for (int i = 01; i <1000; i++)
    {
        if(check[i]==false){
            cout<< i;
            return 0;
        }
    }
    return 0;
}
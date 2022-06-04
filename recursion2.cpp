#include<iostream>
using namespace std;
bool checksort(int arr[],int n,int i=0){
    if(i==n){
        return true;
        }
    else{
        return (arr[i+1]>arr[i])&&checksort(arr,n,i+1);
    }    
    }
void checkfoccur(int arr[],int n,int i=0){
    if(i==n){
        cout<<-1;
    }
    if(arr[i]==n){
        cout<<i<<endl;
        return;
    }
        checkfoccur(arr,n,i+1);
}
void checkloccur(int arr[],int n,int m){
    if(arr[m-1]==n){
        cout<<m-1;
        return;
    }else{
        checkloccur(arr,n,m-1);
    }
}
int main(){
    int a[7]={1,2,3,4,5,1,2};
    checkfoccur(a,1);
    checkloccur(a,1,7);
    return 0;
}
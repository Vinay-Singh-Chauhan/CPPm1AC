#include<iostream>
using namespace std;
bool isSafe( int x ,int y, int n,int** arr){
    if(x<n&&y<n&&arr[x][y]==1){
        return true;
    }
    return false;
}

bool ratinmaze(int ** arr,int x,int y,int n,int ** sarr){
    if(x==n-1&&y==n-1){
        sarr[x][y]=1;
        return true ;
    }
    if(isSafe(x,y,n, arr)){
        sarr[x][y]=1;
        if(ratinmaze(arr,x+1,y,n,sarr)){
            return true;
        }
        if(ratinmaze(arr,x,y+1,n,sarr)){
            return true;
        }
        sarr[x][y]=0;
        return false;
    }
    return false;
}
int main (){
    int n;
    cin>>n;
    int** arr=new int * [n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i]=new int [n];
        }
    }
    int** sarr=new int * [n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sarr[i]=new int [n];
        }
    }
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             cin>>arr[i][j];
         }
     }
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
             sarr[i][j]=0;
         }
     }
    int x=0,y=0;

    ratinmaze(arr,x,y,n,sarr);
     for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            cout<< sarr[i][j];
         }
         cout<<endl;
     }

}
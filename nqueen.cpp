#include<iostream>
using namespace std;

bool isSafe(int**arr,int x,int y,int n){
    for(int i=x;i>=0;i--){
        if(arr[i][y]==1){
            return false;
        }
    }
    int row=x;
    int col=y;
    while(row>=0&&col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0&&col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nqueen(int ** arr,int x,int n){
    if(x>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(isSafe(arr,x,i,n)){

            arr[x][i]=1;
            if(nqueen(arr,x+1,n)){
                return true;
            }
        arr[x][i]=0;
        }
    }
    return false;
    
}

int main(){
    int n;
    cin>>n;
    int ** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int [n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    nqueen(arr,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;

int** board(int n){
    int ** a =new int*[n];
    for(int i=0;i<n;i++){
        a[i]=new int[n];
    }
    return a;
}
bool check_row(int ** arr,int row,int n){
    for(int i=0;i<9;i++){
         if(arr[row][i]==n){
            return false;
         }
    }
    return true;
}
bool check_col(int ** arr,int col,int n){
    for(int i=0;i<9;i++){
         if(arr[i][col]==n){
            return false;
         }
    }
    return true;
}
/*
grid starting positions:
    1> starting row: (currRow/3)*3
       starting col: (currCol/3)*3 
    
    2> starting row: (currRow - currRow % 3)
       starting col: (currCol - currCol % 3)
*/

bool check_grid(int ** arr,int row,int col,int n){
    int srr=(row/3)*3;
    int src=(col/3)*3;
    for(int i=srr;i<srr+3;i++){
        for(int j=src;j<src+3;j++){
                if(arr[i][j]==n){
                    return false;
                }
            }
    }
    
    return true;
}
bool isSafe(int** arr,int row,int col,int n){
    if(check_col(arr,col,n)&&check_grid(arr,row,col,n)&&check_row(arr,row,n)){
        return true;
    }
    else{
        return false;
    }

}
bool solve(int ** arr,int row,int col){
    if(row==9){
        return true;
    }

    int ncol=0,nrow=0;

    if(col==8){
        nrow =row +1;
        ncol=0;
    }else{
        nrow=row;
        ncol=col+1;
    }

    if(arr[row][col]!=0){
        if(solve(arr,nrow,ncol)){
            return true;
        }
    }
     else{
            for(int i=1;i<10;i++){
                if(isSafe(arr,row,col,i)){
                    arr[row][col]=i;
                    if(solve(arr,nrow,ncol)){
                        return true;
                    }else{
                        arr[row][col]=0;
                    }
                }
            }
        }
        return false;
}

int main(){
    int ** a =new int*[9];
    for(int i=0;i<9;i++){
        a[i]=new int[9];
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    solve(a,0,0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }


}
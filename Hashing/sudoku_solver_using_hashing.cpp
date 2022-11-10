#include<iostream>
#include<map>
#include<vector>
using namespace std;


void helper(int row,int col,vector<vector<int>>
& arr,map<pair<int,int>,map<int,int>>&grids,vector<map<int,int>>&rows,vector<map<int,int>>&cols){
    if(row==9){
         for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
        return ;
    }
    if(col==9){
        helper(row+1,0,arr,grids,rows,cols);
        return;
    }
    if(arr[row][col]!=0){
        helper(row,col+1,arr,grids,rows,cols);
        return;
    }
    for(int i=1;i<10;i++){
        if(!grids[{row/3,col/3}][i] and !rows[row][i] and !cols[col][i]){
            grids[{row/3,col/3}][i]=1;
            rows[row][i]=1;
            cols[col][i]=1;
            arr[row][col]=i;
            helper(row,col+1,arr,grids,rows,cols);
            grids[{row/3,col/3}][i]=0;
            rows[row][i]=0;
            cols[col][i]=0;
            arr[row][col]=0;

        }
        
    }
}
void solveSudoku(vector<vector<int>>& arr){
    map<pair<int,int>,map<int,int>>grids;
    vector<map<int,int>>rows(9);
    vector<map<int,int>>cols(9);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(arr[i][j]!=0){
                grids[{i/3,j/3}][arr[i][j]]=1;
                rows[i][arr[i][j]]=1;
                cols[j][arr[i][j]]=1;
            }
        }
    }
    helper(0,0,arr,grids,rows,cols);
}
int main()
{   
    
    vector<vector<int>> arr ={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    solveSudoku(arr);
    // for(int i=0;i<9;i++){
    //     for(int j=0;j<9;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
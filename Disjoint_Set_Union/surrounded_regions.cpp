#include<bits/stdc++.h>

using namespace std;
void change(vector<vector<char>>& grid,int x,int y,int n,int m){
   
    grid[x][y]='*';
    int dx[]={0,0,-1,1};
    int dy[]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int cx=x+dx[i];
        int  cy=y+dy[i];
        
        if((cx>=0 and  cx<=n-1) and(cy>=0 and cy<=m-1) and grid[cx][cy]=='O')change(grid ,cx,cy,n,m);}
    
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||i==n-1||j==0||j==m-1){
                if(grid[i][j]=='O') change(grid,i,j,n,m);
            }
        }
    }
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='O') {grid[i][j]='X';
            count++;}
        }
    }


for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='*') {grid[i][j]='O';
            }
        }
    }
for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<count;
    return 0;
}
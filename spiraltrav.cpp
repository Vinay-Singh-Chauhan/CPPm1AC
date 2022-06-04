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
    int rs,re,cs,ce;
    rs=0;
    cs=0;
    re=n-1;
    ce=m-1;
    int c=0;
    int r=0;
    while(rs<=re&&cs<=ce){
        c=cs;
    while(c<=ce){
        cout<<arr[rs][c];
        c++;
    }
    rs++;
    r=rs;
    // r++;
    while(r<=re){
        cout<<arr[r][ce];
        r++;
    }
    ce--;
    c=ce;
    while(c>=cs){
        cout<<arr[re][c];
        c--;
    }
    re--;
    r=re;
    // rs++;
    while(r>=rs){
        cout<<arr[r][cs];
        r--;
    }
    cs++;
    // c=cs;
    }
    return 0;

}
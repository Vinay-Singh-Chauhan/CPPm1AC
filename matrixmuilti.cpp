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
    cout<<"\n 2\n";
        int q;
    cin>>q;
    int sarr[m][q];
    for(int i =0;i<m;i++){
        for(int j=0;j<q;j++){
        cin>>sarr[i][j];
        }
    }
    int marr[n][q];
        for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            
            marr[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            for(int h = 0;h<m;h++){
            marr[i][j]+=arr[i][h]*sarr[h][j];}
        }
    }
        for(int i =0;i<n;i++){
        for(int j=0;j<q;j++){
        cout<<marr[i][j];
        }cout<<endl;}
        return 0;
}
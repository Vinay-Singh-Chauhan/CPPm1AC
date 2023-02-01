#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr={1,3,5,8,9,2,6,7,6,8,2};
    int n=arr.size();
    vector<int> jump(n,INT_MAX);
    jump[0]=0;
    if(arr[0]==0){
        cout<<"inf"<<endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(j+arr[j]>=i)
            jump[i]=min(jump[i],jump[j]+1);
        }
    }
    cout<<jump[n-1];
    return 0;
}
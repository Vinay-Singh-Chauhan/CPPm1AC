#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> arr={12,-3,10,0};
    vector<int> a;
    vector<int> b;
    sort(arr.begin(),arr.end());
    int minidiff=0;
    int maxdiff=0;
    int n=arr.size();
    for(int i=0;i<n/2;i++){
        maxdiff+=abs((arr[i+n/2]-arr[i]));
        minidiff+=abs((arr[2*i+1]-arr[2*i]));
    }
    // for(int i=0;i<arr.size();i++){
    //     if(i%2==0){
    //         a.push_back(arr[i]);
    //     }else{
    //         b.push_back(arr[i]);
    //     }
    // }
    // for(int i=0;i<arr.size()/2;i++){
    //     minidiff+=abs(a[i]-b[i]);
    // }
    // vector<int>aa;
    // vector<int>bb;
    // for(int i=0;i<arr.size();i++){
    //     if(i<arr.size()/2){
    //         aa.push_back(arr[i]);
    //     }else{
    //         bb.push_back(arr[i]);
    //     }
    // }
    
    // for(int i=0;i<arr.size()/2;i++){
    //     maxdiff+=abs(aa[i]-bb[i]);
    // }
    cout<<maxdiff<<" "<<minidiff;
    return 0;
}
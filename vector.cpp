#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main(){
    int n;
    vector<int> myvector;
    cin>>n;
    myvector.push_back(n);
    cin>>n;
    myvector.push_back(n);
    cin>>n;
    myvector.push_back(n);

    for(auto elem : myvector){
        cout<< elem<<endl;
    }

    cout<<accumulate(myvector.begin(),myvector.end(),1);
    // vector<vector<int>>::iterator it;
    // // for(it=myvector.begin();it!=myvector.end();it++){
    // //     cout<< *it<<endl;
    // // }
    // int n=3,m=3;
    // vector<vector<int>> v(n,vector<int>(m,-1));
    // for(it=v.begin();it!=v.end();it++){
    //     // cout<< *it<<endl;
    //      for(auto elem : v[0]){
    //     cout<< elem<<endl;
    // }
    // }
    // v
    // sort(coins.begin(),coins.end(),greater<int>());
}
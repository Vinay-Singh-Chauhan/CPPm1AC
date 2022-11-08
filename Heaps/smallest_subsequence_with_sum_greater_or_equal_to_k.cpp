#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    vector<int>v={1,1,3,2,8};
    int k=12;
    int sum=0,count=0;
    priority_queue<int,vector<int>> maxheap;
    for(int i=0;i<v.size();i++){
        maxheap.push(v[i]);
    }
    while(!maxheap.empty()){
        sum+=maxheap.top();
        maxheap.pop();
        count++;
        if(sum>=k){
            break;
        }
    }
    if(sum<k){
        cout<<"no such subsequence";
    }else{
        cout<<count;
    }
    return 0;
}
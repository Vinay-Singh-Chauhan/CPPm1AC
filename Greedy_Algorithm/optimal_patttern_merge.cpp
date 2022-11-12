#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int arr[]={5,2,4,7};
    priority_queue<int,vector<int>,greater<int>>minHeap;
    for(int i=0;i<4;i++){
        minHeap.push(arr[i]);
    }
    int ans=0;
    while(minHeap.size()!=1){
        int temp=minHeap.top();
        minHeap.pop();
        int temp2=minHeap.top();
        minHeap.pop();
        ans+=temp+temp2;
        minHeap.push(temp+temp2);
    }
    cout<<ans;
    return 0;
}
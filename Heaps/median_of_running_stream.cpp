#include<iostream>
#include<queue>
#include<vector>
using namespace std;
priority_queue<int,vector<int>,greater<int>>minheap;
priority_queue<int,vector<int>>maxheap;

double getMedian(){
    if(minheap.size()==maxheap.size()){
        return ((minheap.top()+maxheap.top())/2.0);
    }else{
        if(minheap.size()>maxheap.size()) return minheap.top();
        return maxheap.top();
    }
}

void insert(int a){
    if(minheap.size()==maxheap.size()){
        if(minheap.size()==0){
            maxheap.push(a);
        return;
        }
        
        if(minheap.top()<a){
            minheap.push(a);
        }else{
            maxheap.push(a);
        }
    }else{
        if(maxheap.size()>minheap.size()){
            if(maxheap.top()>a){
                int temp=maxheap.top();
                maxheap.pop();
                maxheap.push(a);
                minheap.push(temp);
            }else{
                minheap.push(a);
            }
        }else{
            if(minheap.top()<a){
                int temp=minheap.top();
                minheap.pop();
                minheap.push(a);
                maxheap.push(temp);
        }else{
            maxheap.push(a);
        }
    }
}
}
int main()
{
    insert(10);
    cout<<getMedian()<<endl;
    insert(15);
    cout<<getMedian()<<endl;
    insert(21);
    cout<<getMedian()<<endl;
    insert(30);
    cout<<getMedian()<<endl;
    insert(18);
    cout<<getMedian()<<endl;
    insert(19);
    cout<<getMedian()<<endl;
    return 0;
}
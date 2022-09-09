#include<iostream>
#include<vector>
#include<deque>
using namespace std;
void swm(vector<int> a,vector<int> ans,int k,int n){
    deque<int> deq;
    for(int i=0;i<k;i++){
        while(!deq.empty() && a[deq.front()]<a[i]){
            deq.pop_back();
        }
        deq.push_back(i);
    }
    ans.push_back(a[deq.front()]);
    
    for(int i=k;i<n;i++){
        while(!deq.empty() && a[deq.front()]<a[i]){
            deq.pop_back();
        }
        deq.push_back()
    }
    // for(int )
}
int main(){
    
}
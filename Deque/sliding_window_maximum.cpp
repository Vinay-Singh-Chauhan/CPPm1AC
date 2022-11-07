#include<iostream>
#include<vector>
#include<deque>
#include<set>
using namespace std;
void swm1(vector<int>a,vector<int>ans,int k,int n){
    multiset<int,greater<int>>set;
    for(int i=0;i<k;i++){
        set.insert(a[i]);
    }
    ans.push_back(*set.begin());
    for(int i=k;i<n;i++){
        set.erase(set.lower_bound(a[i-k]));
        set.insert(a[i]);
        ans.push_back(*set.begin());
    }
}
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
        if(deq.front()==i-k){
            deq.pop_front();
        }
        while(!deq.empty() && a[deq.front()]<a[i]){
            deq.pop_back();
        }
        deq.push_back(i);
        ans.push_back(a[deq.front()]);
    }
}
int main(){
    
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int main()
{
    vector<int> ans;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>sort;

    vector<vector<int>>arrays;
    arrays={
        {1,2,3,4},
        {5,8},
        {1,4,7,9}
    };
    vector<int> idx(arrays.size(),0);
    for(int i=0;i<arrays.size();i++){
        sort.push({arrays[i][0],i});
    }
    while (!sort.empty())
    {
        pair<int,int> p=sort.top();
        sort.pop();
        ans.push_back(p.first);
        if(idx[p.second]+1<arrays[p.second].size()) sort
        .push({arrays[p.second][idx[p.second]+1],p.second});
        idx[p.second]++;
    }
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
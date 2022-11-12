#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<pair<int,int>> activities={
        {10,20},
        {12,15},
        {20,30}
    };
    int count=1;
    sort(activities.begin(),activities.end(),[&](pair<int,int> a,pair<int,int>b){return a.second<b.second; });
    int end=activities[0].second;
    for(int i=1;i<activities.size();i++){
        if(activities[i].first>=end){
            count++;
            end=activities[i].second;
        }
    }
    cout<<count;
    return 0;
}
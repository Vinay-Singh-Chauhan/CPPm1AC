#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    vector<pair<int,int>>stations={
        {10,10},{14,5},{20,2},{21,4}
    };
    int currFuel=10;
    int townDistance=25;
    for(int i=0;i<stations.size();i++){
        stations[i]={townDistance-stations[i].first,stations[i].second};
    }
    sort(stations.begin(),stations.end());
    int distanceTravelled=0;
    int count=0;
    priority_queue<int,vector<int>>maxHeap;
    for(int i=0;i<stations.size();i++){
        if(stations[i].first>currFuel){
            currFuel+=maxHeap.top();
            maxHeap.pop();
            count++;
        }
        if(i!=0)
        distanceTravelled=stations[i-1].first;
        currFuel-=(stations[i].first-distanceTravelled);
        maxHeap.push(stations[i].second);
    }
    cout<<count;
    return 0;
}
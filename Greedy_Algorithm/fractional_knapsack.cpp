#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<vector<int>>items={
        {21,7},
        {24,4},
        {12,6},
        {40,5},
        {30,6}
    };
    vector<vector<int>>valueperkg={
        {7,3},
        {4,6},
        {6,2},
        {5,8},
        {6,5}
    };
    sort(valueperkg.begin(),valueperkg.end(),[&](vector<int> a,vector<int> b){
        if(a[1]==b[1]) return a[0]>b[0];
        return a[1]>b[1] ;});
    
    int value=0,i=0,capacity=20;
    while(capacity>=0){
        // cout<<valueperkg[i][0]<<endl;
        capacity-=valueperkg[i][0];
        value+=((valueperkg[i][1])*valueperkg[i][0]);
        i++;
    }
    // cout<<valueperkg[i-1][0];
    if(capacity<0){
        capacity+=valueperkg[i-1][0];
        value-=valueperkg[i-1][1]*valueperkg[i-1][0];
    value+=capacity*valueperkg[i-1][1];

    }
    cout<<value;
    return 0;
}
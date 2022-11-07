#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> array(n);
    for(int i=0;i<n;i++) cin>>array[i];
    map<int,int>frequency;

    //unordered_map<int,int>frequency;

    
    for(auto i: array){
        frequency[i]++;
    }
    map<int,int>::iterator it;
    for(it=frequency.begin();it!=frequency.end();it++){
        cout<<it->first<<" : "<<it->second<<endl; 
    }
    return 0;
}
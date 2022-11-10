#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
static  bool compare (pair<int,int>a , pair<int,int>b){return a.second>b.second;}
int main()
{   
    int k=2;
    int arr[]={1,4,3,2,3,4};
    map<int,int>elements;
    for(int i=0;i<6;i++){
        if(elements[arr[i]]==0 and elements.size()>=k ){
            break;
        }
        elements[arr[i]]++;
    }    
    vector<pair<int,int>>ans;
    map<int,int>::iterator it;
    for(it=elements.begin();it!=elements.end();it++){
        ans.push_back({it->first,it->second});
    }
    sort(ans.begin(),ans.end(),compare);
    for(int i=0;i<k;i++){
        cout<<ans[i].first<<" ";
    }
    return 0;
}
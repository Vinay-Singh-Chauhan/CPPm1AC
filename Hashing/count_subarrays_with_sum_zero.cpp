#include<iostream>
#include<map>
using namespace std;
int main()
{
    int sum=0;
    int arr[]={1,-1,1,-1};
    map<int,int> count;
    for(int i=1;i<4;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=0;i<4;i++){
        count[arr[i]]++;
    }
    map<int,int>:: iterator it;
    for(it=count.begin();it!=count.end();it++){
        if(it->second>=2){
            sum =sum +  (it->second)*((it->second)-1)/2;
        }
        if(it->first==0){
            sum+=it->second;
        }
    }
    cout<<sum;
    return 0;
}
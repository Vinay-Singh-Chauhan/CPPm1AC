#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int sum=54;
    int count=0;
    vector<int> coins={1,2,5,10,20,50,100,200,500,2000};
    sort(coins.begin(),coins.end(),greater<int>());
    int i=0;
    while(sum!=0){
        if(i==coins.size()){
            count=-1;
            return;

        }
        if(sum/coins[i]==0){
            i++;
        }else{
            count+=sum/coins[i];  
            sum-=(coins[i]*(sum/coins[i])) ;
             
        }
    }
    cout<<count;
    return 0;
}
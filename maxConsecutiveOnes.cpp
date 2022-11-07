#include<iostream>
#include<vector>
using namespace std;
int maxConsecutiveOnes(vector<int> a,int k){
    int zeroes=0,j=0,ans=INT_MIN;
    for(int i=0;i<a.size();i++){
        if(a[i]==0){
            zeroes++;
        }
        while(zeroes>k){
            if(a[j]==0){
                zeroes--;
            }
            j++;
        }
        ans=max(ans,i-j+1);
    }
    return ans;
}
int main()
{   vector<int> a={1,1,0,0,1};
    cout<<maxConsecutiveOnes(a,2);
return 0;
}
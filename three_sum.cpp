#include<iostream>
#include<vector>
using namespace std;
bool sum(vector<int>a,int k){
    int sum=0;
    for (int i = 0; i < a.size()-1; i++)
    {   
        int itr1=i+1,itr2=a.size()-1;
        while(itr1<itr2){
            sum=(a[itr1]+a[itr2]+a[i]);
            if(sum==k){
                return true;
            }
            if(sum<k)
                itr1++;
            else
                itr2--;
        }
    }
    return false;
    
}
int main(){
    vector<int>a={1,3,6,7,9,12};
    cout<<sum(a,24);
    return 0;
}
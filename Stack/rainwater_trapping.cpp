#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int get_rain_water(vector<int>a){
    stack<int>st;
    int ans=0;
    for(int i=0;i<a.size();i++){
        while(!st.empty() and a[st.top()]<a[i] ){
            int diff=i-st.top();
            int curr=a[st.top()];
            st.pop();
            if(st.empty()){
                break;
            }
            int h=min(a[i],a[st.top()])-curr;
            ans+=(h*diff);
        }
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int>a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<get_rain_water(a)<<endl;
    return 0;
}
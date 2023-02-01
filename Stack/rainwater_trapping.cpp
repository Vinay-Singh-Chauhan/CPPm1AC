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


class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, maxH = 0;
        stack<int>stk, idx;
        for(int i = 0; i < height.size(); i++){
            int h = min(maxH, height[i]);
            if(!stk.empty()){
                int temp = 0, preIdx = i, preH = h, curH = h;
                while(!stk.empty() && stk.top() < height[i]){
                    curH = stk.top();
                    temp += (h - preH) * (preIdx - idx.top()) - (curH - preH);
                    preH = stk.top();
                    stk.pop();
                    preIdx = idx.top();
                    idx.pop();
                }
                if(!stk.empty()) temp += (h - preH) * (preIdx - 1 - idx.top());
                sum += temp;
            }
            stk.push(height[i]);
            idx.push(i);
            maxH = max(maxH, height[i]);
        }
        return sum;
    }
};

int trap(vector<int>& height) 
{
    int left = 0, right = height.size() - 1;
    int area = 0;
    
    while (left < right)
    {
        int hl = height[left];
        int hr = height[right];
        if (height[left] < height[right])
        {
            while (left < right && hl >= height[++left])
                area += hl - height[left];
        }
        else
        {
            while (right > left && hr >= height[--right])
                area += hr - height[right];
        }
    }
    
    return area;
}
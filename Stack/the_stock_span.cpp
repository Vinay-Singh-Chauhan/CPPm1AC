#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void myspan(vector<int> a){
    
    
    stack<int>st;
    int j=0;
    while(j<a.size()){
        bool flag=true;
        int count=0;
        int price=a[j];
        for(int i=j;i>=0;i--){
            if(a[i]<=price){
                count++;
            }else{
                st.push (count);
                count=0;
                flag=false;
                break;
            }
            
        }
        if(flag){st.push (count);
                count=0;}
        j++;
        }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

vector<int> span(vector<int>a){
    stack<pair<int,int>>st;
    vector<int>ans;
    for (int i = 0; i < a.size(); i++)
    {   
        int days=1;
        while(!st.empty() and st.top().first<=a[i]){
            days+=st.top().second;
            st.pop();
        }
        ans.push_back(days);
        st.push({a[i],days});
    }
    return ans;
}
int main(){
    vector<int>a={100,80,60,70,60,75,85};
    vector<int> b =span(a);
    for(auto i:b){
        cout<<i<<" ";
    }
    return 0;
}

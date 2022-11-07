#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// My Approach to the Solution  V 

int partition(int arr[],int start,int end){
    int minidx=start;
    for(int i=start;i<end;i++){
        if(arr[minidx]>=arr[i]){
            minidx=i;
        }
    }
    return minidx;
}
int area (int arr[],int start,int end,int idx){
    if(start==end){
        return arr[end-start];
    }
    int p=partition(arr,start,end);
    return max(arr[p]*(end-start),max(area(arr,p+1,end,p),area(arr,start,p,p)));
}

// Apna College Solution using stack   V

int get_max_area(vector<int> a){
    int ans=0,i=0,n=a.size();
    a.push_back(0);
    stack<int>st;
    while(i<n){
        while(!st.empty() and a[st.top()]>a[i]){
            int t=st.top();
            int h=a[t];
            st.pop();
            if(st.empty()){
                ans=max(ans,i*h);
            }else{
                ans=max(ans,h*(i-st.top()-1));
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main()
{
vector<int> arr={2,1,5,6,2,3};
cout<<get_max_area(arr);
return 0;
}
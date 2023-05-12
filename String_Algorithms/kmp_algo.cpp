#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s){
    int n=s.size();
    vector<int> prefix_indices(n,0);
    for(int i=1;i<n;i++){
        int j=prefix_indices[i-1];
        while(j>0 and s[i]!=s[j]){
            j=prefix_indices[j-1];
        }
        if(s[i]==s[j]){
            j++;
            prefix_indices[i]=j;
        }
        
    }
return prefix_indices;
}

int main()
{
    string s="na";
    string t="apna college";
    vector<int>prefixes=prefix_function(s);
    int pos=-1;
    int i(0),j(0);
    while(i<t.size()){
        if(t[i]==s[j]){
            i++;
            j++;
        }else{
            if(j!=0){
                j=prefixes[j-1];
            }else{
                i++;
            }
        }
        if(j==s.size()) {
            pos=i-s.size();
            break;
        }
    }
    cout<<pos;
    
return 0;
}
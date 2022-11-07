#include<iostream>
#include<vector>
using namespace std;
int longestSubstringWithoutReapeatingCharacters(string s){
    vector<int> dict(251,-1);
    int maxLen=0,start=-1;
    for (int i = 0; i <s.length(); i++)
    {   
        if(dict[s[i]]>start){
            start=dict[s[i]];
        }
    maxLen=max(maxLen,i-start);

            dict[s[i]]=i;
        
    }
    return maxLen;
}
int main()
{
    cout<<longestSubstringWithoutReapeatingCharacters("babad");
    return 0;
}
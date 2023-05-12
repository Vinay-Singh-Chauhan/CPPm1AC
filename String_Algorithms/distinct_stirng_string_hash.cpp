#include<bits/stdc++.h>
#include<vector>
using namespace std;
int p=31, N=1e5+3,M=1e9+7;
vector<int>powers(N);
long long calculate_hash(string s){
    long long hash=0;
    for(int i=0;i<s.size();i++){
        hash=(hash+((s[i]-'a'+1)*powers[i]))%M;
    }
    return hash;
}
int main()
{
    powers[0]=1;
    for(int i=1;i<N;i++){
        powers[i]=(powers[i-1]*p)%M;
    }
    vector<string> strings={"aa","ab","aa","b","cc","aa"};
    vector<long long> hashes;
    for(auto w: strings){
        hashes.push_back(calculate_hash(w));
    }
    int distinct=0;
    sort(hashes.begin(),hashes.end());
    for(int i=0;i<hashes.size();i++){
        if(i==0 or hashes[i]!=hashes[i-1]){
            distinct++;
        }
    }
     cout<<distinct;
    return 0;
}
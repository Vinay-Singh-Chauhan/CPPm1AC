#include<bits/stdc++.h>
using namespace std;
int p=31, N=1e5+3,M=1e9+7;
vector<long long int>powers(N);
long long calculate_hash(string s){
    long long hash=0;
    for(int i=0;i<s.size();i++){
        hash=(hash+((s[i]-'a'+1)*powers[i]))%M;
    }
    return hash;
}
int main()
{
    string s="na";
    string t="apnaacollegena";
    int T=t.size(),S=s.size();
    powers[0]=1;
    for(int i=1;i<N;i++){
        powers[i]=(powers[i-1]*p)%M;
    }
    vector<long long>h_t(T+1,0);
    long long h_s=0;
    for(int i=0;i<T;i++){
        h_t[i+1]=(h_t[i]+((t[i]-'a'+1)*powers[i]))%M;
    }
    h_s=calculate_hash(s);
    // for(int i=0;i<S;i++){
    //     h_s=(h_s+((s[i]-'a'+1)*powers[i]))%M;
    // }
    for(int i=0;i+S-1<T;i++){
        // cout<<i<<endl;
        long long cur_h=(h_t[i+S]-h_t[i]+M)%M;
        if(cur_h==((h_s*powers[i])%M)){
            cout<<i<<endl;
        }
    }
    
return 0;
}
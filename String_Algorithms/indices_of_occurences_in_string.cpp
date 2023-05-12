#include<iostream>
using namespace std;
int main()
{
    string s="na",t="apna collegena";
    int S=s.size(),T=t.size();
    for(int i=0;i<t.size()-S+1;i++){
        if(t.substr(i,S)==s){
            cout<<i<<endl;
        }
    }
    return 0;
}
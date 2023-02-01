#include<iostream>
using namespace std;
int main()
{
    int strs=1,a=0,ab=0,abc=0;
    string s="ac?b?c";
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            a+=strs;
        }
        else if(s[i]=='b'){
            ab+=a;
        }
        else if(s[i]=='c'){
            abc+=ab;
        }
        else if(s[i]=='?'){
            abc=3*abc+ab;
            ab=3*ab+a;
            a=3*a+strs;
            strs=3*strs;
        }
        cout<<abc<<endl;
    }
    return 0;
}
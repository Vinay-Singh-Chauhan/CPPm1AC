#include<iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    string ans;
    for(int i=0;i<sizeof(str);i++){
        if(str[i]!=str[i-1]){
            ans +=str[i];
        }
    }
    cout<<ans;
    return 0;
}
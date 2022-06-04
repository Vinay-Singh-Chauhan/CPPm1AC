#include <iostream>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    int arr[26];
    for(int i=0;i<26;i++){
        arr[i]=0;
    }
        for(int i=0;i<26;i++){
        cout<<arr[i];
    }
    cout<<endl;
    for(int i=0;i<sizeof(str);i++){
        arr[str[i]-'a']++;
    }
    cout<<endl;

            for(int i=0;i<26;i++){
        cout<<arr[i];
    }
    cout<<endl;

    int maxf=INT_MIN;
    for(int i=0;i<26;i++){
        maxf=max(maxf,arr[i]);
    }
    cout<<maxf;
    return 0;
}
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     string s;
//     cin>>s;
//     char ch=s[0];
//     cout<<ch;
//     for(int i=0;i<n;i++){
//         if(s[i]!=ch){
//             ch=s[i];
//             cout<<s[i];
//         }
//     }
//     return 0;
// }

#include<iostream>
using namespace std;
int main(){
    int n;
    // cin>>n;
    string s;
    cin>>s;
    n=s.length();
    cout<<n<<endl;
    char ch=s[0];
    cout<<ch;
    for(int i=0;i<n;i++){
        if(s[i]!=ch){
            ch=s[i];
            cout<<ch;
        }
    }
    return 0;
}
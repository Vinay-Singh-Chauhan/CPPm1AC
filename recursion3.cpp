#include<iostream>
using namespace std;
string keypadarr[]={"","./","abc","def","ghi","jkl","mno","tuv","wxyz"};
//------------------------reverse a string---------------------------------------------
string reverse(string str,int i=0){
    if(i==str.length()/2){
        return str;
    }
    char s=str[i];
    str[i]=str[str.length()-1-i];
    str[str.length()-1-i]=s;
    return reverse(str,i+1);
}
//---------------------------replace pi--------------------------------------------------
void replacepi(string a){
    if(a.length()==0){
        return;
    }
    if(a[0]=='p'&&a[1]=='i'){
        cout<<"3.14";
        replacepi(a.substr(2));
    }else{
        cout<<a[0];
        replacepi(a.substr(1));
    }
}
//------------------------tower of hanoi-------------------------------------------------
void toh(int n,char src,char dest ,char help){
    if(n==0){return ;}
    toh(n-1,src,help,dest);
    cout<<" move from "<<src<<" to "<<dest<<endl;
    toh(n-1,help,dest,src);
}
//-------------------remove duplicates---------------------------------------------------
void remdup(string str){
    if(str.length()==0){
        return;
    }
    if(str[0]!=str[1]){
        cout<<str[0];
        remdup(str.substr());
    }
    cout<<str[0];
    remdup(str.substr(1));
}
//------------------move all x to end-----------------------------------------------------------
void movex(string s){
    if(s.length()==0)
    return;
    char ch=s[0];
    string ans ="";
    if(ch=='x')
    ans+=ch;
    else
    cout <<ch;
    movex(s.substr(1));
    cout<<ans;
}
//-------------------all substring of string------------------------------------------------------
void sub(string s,string ans){
    // string ans="";
    if(s.length()==0){
        cout<<ans<<endl;
        return; 
    }
    else{
        char ch=s[0];
        string ros=s.substr(1);
    sub(ros,ans);
    sub(ros,ans+ch);
    // cout <<ans<<endl;
        // cout<<ans+a<<endl;
    }
}
//-------------------all substring of string with ascii number------------------------------------------------------
void subas(string s,string ans){
    // string ans="";
    if(s.length()==0){
        cout<<ans<<endl;
        return; 
    }
    else{
        char ch=s[0];
        int a=ch;
        string ros=s.substr(1);
    sub(ros,ans);
    sub(ros,ans+ch);
    sub(ros,ans+to_string(ch));
    // cout <<ans<<endl;
        // cout<<ans+a<<endl;
    }
}
//----------------------------all words with phone digits------------------------------------------
void keypad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return; 
    }
    else{
        char ch=s[0];
        string a=keypadarr[ch-'0'];
        string ros=s.substr(1);
    for(int i=0;i<a.length();i++){
        keypad(ros,ans+a[i]);
    }
    // cout <<ans<<endl;
        // cout<<ans+a<<endl;
    }
}
//------------------------------------------------------------------------------------------
int main(){
    // int n;
    // cin>>n;
    keypad("23","");
    // cout<<a;

}
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool redundant_parenthesis(string s){
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
                // bool flag=false;
                if(st.top()=='('||st.empty()){
                    return true;
                }
                while(!st.empty() and st.top()!='('){
                    st.pop();
                    
                }
                st.pop();
        }else
        st.push(s[i]);
    }
    return false;
}
int main(){
    cout<<redundant_parenthesis("(2(234(#$)))");
    return 0;
}
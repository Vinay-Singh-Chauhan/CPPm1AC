#include<iostream>
#include<stack>
using namespace std;
int precedence(char a){
    if(a=='^'){
        return 3;
    }else if (a=='*'||a=='/')
    {
        return 2;
    }
    else if (a=='+'||a=='-')
    {
        return 1;
    }else{
        return -1;
    }
    
    
}
string reverseString(string s){
    string str="";
    for(int i=s.length();i>=0;i--){
        if(s[i]=='('){
            str+=')';
            continue;
        }else if(s[i]==')'){
            str+='(';
            continue;
        }
        str+=s[i];
    }
    return str;
}
string infixToPostfix( string expression ){
    string ans="";
    stack<char>stack;
    for(int i=0;i<expression.length();i++){
        if((expression[i]>='a'&&expression[i]<='z')||(expression[i]>='A'&&expression[i]<='Z')){
            ans+=expression[i];
        }else{
            switch (expression[i])
        {
        case '(':
            stack.push(expression[i]);
            break;
        case ')':
            while(!stack.empty()&&stack.top()!='('){
                ans+=stack.top();
                stack.pop();
            }
            if(!stack.empty())
            stack.pop();
            break;
        default:
            while (!stack.empty()&&(precedence(stack.top())>precedence(expression[i])) )
            {
                ans+=stack.top();
                stack.pop();
            }
            stack.push(expression[i]);
            break;
        }
        }
        
    }
    while(!stack.empty()){
        cout<<stack.top();
        stack.pop();
    }
    return ans;
}
string infixToPrefix( string expression ){
    expression=reverseString(expression);
    string ans=reverseString(infixToPostfix(expression));

    // stack<char>stack;
    // for(int i=0;i<expression.length();i++){
    //     if((expression[i]>='a'&&expression[i]<='z')||(expression[i]>='A'&&expression[i]<='Z')){
    //         cout<<expression[i];
    //     }else{
    //         switch (expression[i])
    //     {
    //     case '(':
    //         stack.push(expression[i]);
    //         break;
    //     case ')':
    //         while(!stack.empty()&&stack.top()!='('){
    //             cout<<stack.top();
    //             stack.pop();
    //         }
    //         if(!stack.empty())
    //         stack.pop();
    //         break;
    //     default:
    //         while (!stack.empty()&&(precedence(stack.top())<precedence(expression[i])) )
    //         {
    //             cout<<stack.top();
    //             stack.pop();
    //         }
    //         // cout<<expression[i];
    //         stack.push(expression[i]);
    //         // stack.pop();
    //         break;
    //     }
    //     }
        
    // }
    // while(!stack.empty()){
    //     cout<<stack.top();
    //     stack.pop();
    // }
    return ans;
}

int main()
{   
    stack<int>stack;
    cout<<infixToPrefix("(a-b/c)*(a/k-l)");
    return 0;
}
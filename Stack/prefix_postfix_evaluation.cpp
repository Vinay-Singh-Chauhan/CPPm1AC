#include<iostream>
#include<stack>
using namespace std;
int prefixEvaluate(stack<int>* stack , string expression ){
    for(int i=expression.length()-1;i>=0;i--){
        if(expression[i]>='0'&&expression[i]<='9'){
            stack->push(expression[i]-'0');
        }else{
            int num1 =stack->top();
            stack->pop();
            int num2 =stack->top();
            stack->pop();
            switch (expression[i])
            {
            case '+':
                stack->push(num1+num2);
                break;
            case '-':
                stack->push(num1-num2);
                break;
            case '*':
                stack->push(num1*num2);
                break;
            case '/':
                stack->push(num1/num2);
                break;
            
            default:
                break;
            }
            
        }
    } 
    int ans=stack->top();
        stack->pop();
        
    if(stack->empty()){
        cout<<"all correct";
        return ans;
    }else{
        cout<<"invalid algo";
        return -1111;
    }
}

int postfixEvaluate(stack<int>* stack , string expression ){
    for(int i=0;i<=expression.length()-1;i++){
        if(expression[i]>='0'&&expression[i]<='9'){
            stack->push(expression[i]-'0');
        }else{
            int num1 =stack->top();
            stack->pop();
            int num2 =stack->top();
            stack->pop();
            switch (expression[i])
            {
            case '+':
                stack->push(num1+num2);
                break;
            case '-':
                stack->push(num2-num1);
                break;
            case '*':
                stack->push(num1*num2);
                break;
            case '/':
                stack->push(num2/num1);
                break;
            
            default:
                break;
            }
        }cout<<stack->top()<<endl;
    } 
    int ans=stack->top();
        stack->pop();
    if(stack->empty()){
        cout<<"all correct";
        return ans;
    }else{
        cout<<"invalid algo";
        return -1111;
    }
}

int main()
{   
    stack<int>stack;
    cout<< postfixEvaluate(&stack,"46+2/5*7+");
    return 0;
}
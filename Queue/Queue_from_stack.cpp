#include<iostream>
#include<stack>
using namespace std;
// using two user defined stacks
class queue{
    public:
        stack<int> stack1,stack2;
        void push(int a){
            stack1.push(a);
            return;
        }
        void pop(){
            if(stack1.empty()&&stack2.empty()){
                cout<<"Stack underflow"<<endl;
                return;
            }
            if(stack2.empty()){while (!stack1.empty())
                {
                    stack2.push(stack1.top());
                    stack1.pop();
                }}
            stack2.pop();
        }
        void top(){
            if(stack1.empty()&&stack2.empty()){
                cout<<"Queue underflow"<<endl;
                return;
            }
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
            cout<<stack2.top();
        }
        bool isEmpty(){
            if(stack1.empty()&&stack2.empty()){
                // cout<<"Stack underflow"<<endl;
                return true;
            }
            return false;
        }        
};

//using one user defined stack and function call stack as other

class que{
    public:
        stack<int> stack;
        void push(int a){
            stack.push(a);
        }
        void pop(){
            if(stack.empty()){
                cout<<"Queue Underflow"<<endl;
                return ;
            }
            int elem=stack.top();
            stack.pop();
            if(stack.empty()){
                cout<<"popped";
            }
            pop();
            push(elem);
            
        }
        void top(){
            if(stack.empty()){
                cout<<"Queue Underflow"<<endl;
                return ;
            }
            int elem=stack.top();
            stack.pop();
            if(stack.empty()){
                cout<<elem;
            }
            pop();
            push(elem);
            
        }
        bool isEmpty(){
            if(stack.empty()){
                return true;
            }
            return false;
        }
};

int main(){
    
}
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
        int pop(){
            if(stack.empty()){
                cout<<"Queue Underflow"<<endl;
                return -1;
            }
            int elem=stack.top();
            stack.pop();
            if(stack.empty()){
                // cout<<"popped"<<endl;
                return elem;
            }
            int item= pop();
            push(elem);
            return item;
            
        }
        void top(){
             if(stack.empty()){
                return;
            }
            // while(!stack.empty()){

            // }
            int elem=stack.top();
            stack.pop();
            if(stack.empty()){
                cout<< elem<<endl;
                // return;
            }
            top();
            // int item= top();
            push(elem);
            // return item;
        }
        bool isEmpty(){
            if(stack.empty()){
                return true;
            }
            return false;
        }
};

int main(){
    que a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.top();
    a.top();
    a.top();
    a.top();

    cout<<a.pop();
    cout<<a.pop();
    // cout<<a.pop();

    a.top();
    }
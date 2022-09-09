#include<iostream>
#include<queue>
using namespace std;
// using two user defined stacks
class stack1{
    public:
        queue<int> q1,q2;
        void pop(){
            if(q1.empty()){
                cout<<"queue underflow"<<endl;
                return;
            }
            q1.pop();
            return;
        }
        void push(int a){
            q2.push(a);
            while (!q1.empty())
                {
                    q2.push(q1.front());
                    q1.pop();
                }
            queue<int> temp;
            temp=q1;
            q1=q2;
            q2=temp;
        }
        void top(){
            if(q1.empty()){
                cout<<"Queue underflow"<<endl;
                return;
            }
            cout<<q1.back();
        }
        bool isEmpty(){
            if(q1.empty()){
                // cout<<"Stack underflow"<<endl;
                return true;
            }
            return false;
        }        
};

//using one user defined stack and function call stack as other

class Queue2{
    public:
        queue<int> q1,q2;
        void push(int a){
            q1.push(a);
        }
        void pop(){
            if(q1.empty()){
                cout<<"queue underflow"<<endl;
                return;
            }
            while (q1.size()!=1)
                {
                    q2.push(q1.front());
                    q1.pop();
                }
                q1.pop();
            queue<int> temp;
            temp=q1;
            q1=q2;
            q2=temp;
            return;
        }
        int top(){
            if(q1.empty()){
                cout<<"Queue Underflow"<<endl;
                return -1 ;
            }
            return q2.back();
            
        }
        bool isEmpty(){
            if(q1.empty()){
                return true;
            }
            return false;
        }
};

int main(){
    queue <int> a;
}
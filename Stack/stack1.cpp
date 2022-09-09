#include<iostream>
#include<vector>
using namespace std;
class Stack{
    private:
    int * stack;
    int top;
    public:
        Stack(){
            stack=new int[100];
            top=-1;
        }
        void Push(int element){
            if(top==99){
                cout<<"overFlow";
                return;

            }
            top++;
            stack[top]=element;
        }
        void Pop(){
            if(top==-1){
                cout<<"underFlow";
                return;

            }
            top--;
        }
        
        bool isEmpty(){
            return top==-1;
        }
        void Top(){
            if(this->isEmpty()){
                cout<<"Empty";
                return;
            }
            cout<<stack[top];
        }
};

int main(){
    Stack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    cout<<endl;
    cout<<stack.isEmpty();
    cout<<endl;
    stack.Top();
    stack.Pop();
    stack.Top();
    stack.Pop();
    stack.Pop();
    stack.Pop();
    stack.Top();
    cout<<endl;
    cout<<stack.isEmpty();

    


    return 0;
}
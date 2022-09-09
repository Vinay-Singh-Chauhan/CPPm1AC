#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int>* stack,int element){
    if(stack->empty()){
        stack->push(element);
        return;
    }
    int a =stack->top();
    stack->pop();
    insertAtBottom(stack,element);
    stack->push(a);

}

void reverseStack(stack<int>* stack){
    if(stack->empty()){
        return;
    }
    int a=stack->top();
    stack->pop();
    reverseStack(stack);
    insertAtBottom(stack,a);
}

int main()
{
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout<<stack.top();
    reverseStack(&stack);
    cout<<stack.top();
    return 0;
}
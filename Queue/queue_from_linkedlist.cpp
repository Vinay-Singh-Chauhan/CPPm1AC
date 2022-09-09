#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
        }
};
class Queue{
    public:
        // node * arr;
        node* front;
        node *rear;
        Queue(){
            front =NULL;
            rear=NULL;
        }
        void enqueue(int a){
            node* temp=new node(a);
            if(rear==NULL){
                rear=temp;
                front =temp;
                return;
            }
            rear->next=temp;
            rear=rear->next;
            return;
        }
        void dequeue(){
            if(front==NULL){
                cout<<"No Elements";
                return;
            }
            node* todelete=front;
            front=front->next;
            delete todelete;
            return;
        }
        bool isEmpty(){
            if(front==NULL){
                return true;
            }
            return false;
        }
        int peek(){
            if(front==NULL){
                cout<<"No Elements";
                return -1;
            }
            return front->data;
        }
};
int main()
{
    Queue queue;

return 0;
}
#include<iostream>
using namespace std;
class Queue{
    public:
        int * arr;
        int front;
        int rear;
        Queue(){
            arr=new int[20];
            front =-1;
            rear=-1;
        }
        void enqueue(int a){
            if(rear==19){
                cout<<"Queue Overflow";
                return;
            }
            rear ++;
            arr[rear]=a;
            if (front==-1){
                front++;
            }
            {
                /* code */
            }
            
            return;
        }
        void pop(){
            if(front==-1||rear<front){
                cout<<"No Elements";
                return;
            }
            front ++;
            return;
        }
        bool isEmpty(){
            if(front==-1||rear<front){
                return true;
            }
            return false;
        }
        int peek(){
            if(front==-1||rear<front){
                cout<<"No Elements";
                return -1;
            }
            return arr[front];
        }
};
int main()
{

return 0;
}
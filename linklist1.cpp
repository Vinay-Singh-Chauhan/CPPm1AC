#include<iostream>
using namespace std;
class node{
    public: 
    int data;
    node* next;
    node(int val){
        // node * n=new node;
        data=val;
        next=NULL; 
    }
};
void atend(node* &head,int val){
    node * n=new node(val);
    node* temp=head;
    if(head==NULL){
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    // temp=n;
    return;
}
void atbegin(node* &head,int val){
    node * n=new node(val);
    n->next=head;
    head=n; 
    return;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}
int main(){
    node* head=NULL;
    atend(head,1);
    atend(head,2);
    atend(head,3);
    display(head);
    cout<<endl;
    atbegin(head,4);
    atbegin(head,5);
    display(head);
    return 0;
}
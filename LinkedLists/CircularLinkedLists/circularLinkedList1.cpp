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

void atend(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        head->next=head;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    return;
}

void atbegin(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        head->next=head;
        return;
    }
    node* temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=n;
    n->next=head;
    head=n;
    return;
}

void display(node* &head){
    node* temp=head;
    do{
        cout<<temp->data;
        temp=temp->next;
    }while(temp!=head);
}

int main(){

    node* head=NULL;
    int arr1[]={2,3,4,5};
    for(int i=0;i<4;i++){
        atend(head,arr1[i]);
    }
    atbegin(head,1);
    display(head);


    return 0;
}
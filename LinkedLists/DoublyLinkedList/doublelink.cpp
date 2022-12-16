#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};
void atbegin(node* &head,int val){
    node * n= new node(val);
    node* temp=head;
    if(head!=NULL){
        temp->prev=n;
    }
    
    n->next=temp;
    head=n;
}
void atend(node* &head,int val){
    node * n= new node(val);
    node* temp=head;
    if(head==NULL){
        atbegin(head,val);
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void adisplay(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void deleteit(node* &head,int val){
    node* temp=head;
    if(temp==NULL||temp->next==NULL){
        if(head->data==val){
            delete head;
        }
        return;
    }
    if(head->data==val){
        node * todel= head;
        head=head->next;
        head->prev=NULL;
        delete todel;
        return;
    }
    while(temp->next->data!=val&&temp!=NULL){
        temp=temp->next;
    }
    node* todel=temp->next;
    temp->next=temp->next->next;
    if(temp->next!=NULL){
        // temp->prev=temp;
    temp->next->prev=temp;

    }
    delete todel;
}
int main(){
    node* head=NULL;
    atend(head,1);
    atend(head,2);
    atend(head,3);
    atend(head,4);
    atbegin(head,5);
    adisplay(head);
    deleteit(head,5);
    adisplay(head);
}
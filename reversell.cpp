#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node * next;
    node(int n){
            data=n;
            next=NULL;
        }
};
void deleteit(node* &head,int n){
    if(head->data==n){
        node* todel=head;
        head=head->next;
        delete todel;
        return;
    }
    
    if(head==NULL){
        cout<<"nothing to delete";
        return;}
    if(head->next==NULL){
        if(head->data==n){
            delete head;
        }
        return;
    }
    
    node * temp=head;
    while(temp->next->data!=n){
        temp=temp->next;
    }
    node* todel=temp->next;
    temp->next=temp->next->next;
    delete todel;
} 
void insertattail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
        }node* temp;
        temp=head;
    while(temp->next!=NULL){
            temp=temp->next;
            // temp++;
    }
    temp->next=n;
}
void display(node* head){
    node* temp;
    temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
            temp=temp->next;
        }            
}
void insertathead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
bool search(node* &head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        else{
            temp=temp->next;
        }
    }
    return false;
}
node* reverse(node* &head){
    node* prev =NULL;
    node* current =head;
    node* nexte ;
    while(current!=NULL){
        nexte=current->next;
        current->next=prev;
        prev=current;
        current=nexte;
        // nexte=nexte->next;
    }
    // current->next=prev;
    // prev=current;
    return prev;
}

node* recursivereverse(node* &head){
    if(head==NULL|| head->next==NULL){
        return head;
    }
    node* newhead = recursivereverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}

int main(){
    node* head=NULL;
        // node head(12);
    insertattail(head,13);
    insertattail(head,15);
    insertattail(head,16);
    insertattail(head,17);
    insertathead(head,12);
    display(head);
    // cout<<search(head,15)<<endl<<search(head,11);
    node* newhead=recursivereverse(head);
    // deleteit(head,12);
    display(newhead);
    }
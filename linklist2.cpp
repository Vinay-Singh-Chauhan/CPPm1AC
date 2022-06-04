#include<iostream>
using namespace std;
class node{
    public :
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void atend(node* &head,int val){
    node* n=new node(val);
    node * temp =head;
    if(head==NULL){
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    return;
}
void atbegin(node* &head,int val){
    node *n=new node(val);
    n->next=head;
    head=n;
    return;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    return;
}
void search(node* head,int val){
    while(head!=NULL){
        if(head->data==val){
            cout<<"Yes"<<endl;
            return;
        }
        head=head->next;
    }
    cout<<"No"<<endl;
    return;
}
void deleteit(node* &head,int val){
    node *temp=head;
    if(head==NULL){
        return;
    }
    else if(head->data==val){
        node *todel=head;
        head=head->next;
        delete todel;
        return;
    }

    while((temp->next->data!=val)&&(temp->next!=NULL)){
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout<<"Not there!"<<endl;
    }else{
        node* dtemp= temp->next;

        temp->next=temp->next->next;
        delete dtemp;
        }
    return;

}
int main(){
    node* head=NULL;
    search(head,10);//false
    atend(head,10);
    search(head,10);//true
    atend(head,20);
    atend(head,30);
    atend(head,40);
    atbegin(head,50);
    atbegin(head,60);
    search(head,122);//false
    search(head,40);//true
    search(head,30);//true
    display(head);
    deleteit(head,40);
    deleteit(head,50);
    display(head);
    return 0;
}
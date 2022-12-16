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
void intersect(node* &head1,node* &head2,int k){
    int count=1;
    node*temp1=head1;
    node* temp=head2;
    while(count<k){
        temp1=temp1->next;
        count++;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=temp1;
}
int getlength(node* &head){
    node* temp=head;
    int count=1;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}
bool checkintersect(node* &head1,node* &head2){
    node* temp;
    node* temp1;
    int k;
    int l1=getlength(head1);
    int l2=getlength(head2);
    int count=1;
    if(l1>=l2){
        k=l1-l2;
        temp=head1;
        temp1=head2;}
    else{
        k=l2-l1;
        temp=head2;
        temp1=head1;
    }
        while(count<k){
            temp=temp->next;
            count++;
        }
        while(temp!=temp1&&temp->next!=NULL){
            temp=temp->next;
            temp1=temp1->next;
            count++;
        }
        if(temp->next==NULL){
            cout<<"No Intersection Found"<<endl;
            return false;
        }
        cout<<"INTERSECTION AT POSITION : "<<count<<endl;
        return true;
    }
int main(){
    node* head1=NULL;
    atend(head1,1);
    atend(head1,2);
    atend(head1,3);
    atend(head1,4);
    atend(head1,5);
    atend(head1,6);
    display(head1);
    node* head2=NULL;
    atend(head2,9);
    atend(head2,10);
    // atend(head2,4);
    display(head2);
    intersect(head1,head2,3);
    display(head2);
    cout<<checkintersect(head1,head2);
}
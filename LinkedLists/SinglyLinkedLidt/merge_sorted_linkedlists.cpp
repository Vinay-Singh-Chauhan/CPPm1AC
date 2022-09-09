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
node* reversal(node* &head){
    node * nexte;
    node* current;
    node* prev;
    nexte=head->next;
    prev=NULL;
    current=head;
    while(current!=NULL){
        nexte=current->next;
        current->next=prev;
        prev=current;
        current=nexte;
    }
    return prev;
}
node* reversalk(int k,node* &head){
    node * nexte;
    node* current;
    node* prev;
    nexte=head->next;
    prev=NULL;
    current=head;
    int count=0;
    while(current!=NULL&&count<k){
        nexte=current->next;
        current->next=prev;
        prev=current;
        current=nexte;
        count++;
    }
    if(nexte!=NULL){
        head->next=reversalk(k,nexte);
    }
    return prev;
}
node* recrev(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node* newhead=recrev(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
void makecycle(node* &head,int pos){
    int count=1;
    node* temp=head;
    while (count<pos){
        temp=temp->next;
        count++;
    }
    node*start=temp;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=start;
}
bool checkcycle(node* head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            cout<<"CYCLE DETECTED\nREMOVING CYCLE"<<endl;
            fast=head;
            while(fast->next!=slow->next){
                slow=slow->next;
                fast=fast->next;
            }
            slow->next=NULL;
            return true ;
        }
        
    }
    cout<<"NO CYCLE DETECTED"<<endl;
    return false;
}
node* gettail(node* &head){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    return temp;

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
void applastknodes(node* &head,int k){
    node* temp=head;
    int length=getlength(head);
    k=k%length;
    int count=length-k;
    while(count>1){
        temp=temp->next;
        count--;
    }
    node*t=temp->next;    

    node * tail=gettail(head);
    temp->next=NULL;
    tail->next=head;
    head=t;
}//this was my method
node* kapp(node* &head,int k){
    node*temp=head;
    node* ntail;
    node* nhead;
    int count=1;
    int l= getlength(head)-1;
    k=k%l;
    while(temp->next!=NULL){
        temp=temp->next;
        if(count==l-k){
            ntail=temp;
        }
        if(count==l-k+1){
            nhead=temp;
        }
        count++;
    }
    temp->next=head; 
    ntail->next=NULL; 
    return nhead;

    
}
node* mergeSortedLists(node* &head1,node* &head2){
    node* ptr1=head1;
    node*ptr2=head2;
    node* newhead=new node(-1);
    node* list=newhead;
    // newhead=list;
    while(ptr1!=NULL&&ptr2!=NULL){
        if(ptr1->data>ptr2->data){
            node* temp =new node(ptr2->data);
            list->next=temp;
            list=list->next;
            ptr2=ptr2->next;
        }else{
            node *temp=new node (ptr1->data);
            list ->next=temp;
            ptr1=ptr1->next;
            list=list->next;

        }
    }
    while(ptr1!=NULL){
        node* temp=new node(ptr1->data);
        list->next=temp;
        list=list->next;
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        node* temp=new node(ptr2->data);
        list->next=temp;
        ptr2=ptr2->next;
        list=list->next;

    }
    return newhead->next;
}

node* mergeSortedListsRecursive(node* &head1,node* &head2){
    node* result;
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    if(head1->data>head2->data){
        result=new node(head2->data);
        result->next=mergeSortedLists(head1,head2->next);
    }else{
        result=new node(head1->data);
        result->next=mergeSortedLists(head1->next,head2);
    }
    return result;
}
int main(){
    // node* head=NULL;
    // search(head,10);//false
    int arr1[]={2,3,6};
    int arr2[]={1,1,3,4};
    node* head1;
    node* head2;
    for(int i=0;i<3;i++){
        atend(head1,arr1[i]);
    }
    for(int i=0;i<4;i++){
        atend(head2,arr2[i]);
    }
    display(head1);
    display(head2);
   
    node* newhead=mergeSortedListsRecursive(head1,head2);
    display(newhead);
    // atend(head,1);
    // atend(head,2);
    // atend(head,3);
    // atend(head,4);
    // atend(head,5);
    // atend(head,6);
    // node*newhead=kapp(head,3);
    // applastknodes(head,3);
    // cout<<getlength(head);
    // cout<<endl;
    // cout<<gettail(head)->data<<endl;
    // checkcycle(head);
    // makecycle(head,3);
    // checkcycle(head);

    // atend(head,10);

    // search(head,10);//true
    // atend(head,20);
    // atend(head,30);
    // atend(head,40);
    // atbegin(head,50);
    // atbegin(head,60);
    // search(head,122);//false
    // search(head,40);//true
    // search(head,30);//true
    // display(newhead);
    // reversal(head);
    // deleteit(head,40);
    // deleteit(head,50);
    // node * newhead=reversalk(5,head);
    // display(newhead);
    return 0;
}


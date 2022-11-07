#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    Node* l;
    Node* r;
    int val;
    Node(int val){
        this->val=val;
        l=NULL;
        r=NULL;
    }
};

void flatten_bt(Node *root){
    if(root==nullptr ||(root->l==nullptr and root->r!=nullptr) ){
        return;
    }
    if(root->l!=nullptr){
        flatten_bt(root->l);
        Node* temp=root->r;
        root->r=root->l;
        root->l=nullptr;
        Node *t=root->r;
        while(t->r!=nullptr){
            t=t->r;
        }
        t->r=temp;
    }
    
    flatten_bt(root->r);    
    
}
void preordertraversal(Node* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->val<<" ";
    preordertraversal(root->l);
    preordertraversal(root->r);
}

int main()
{
    Node *root=new Node(1);
    root->l=new Node(2);
    root->r=new Node(3);
    root->l->l=new Node(4);
    root->l->r=new Node(5);
    root->r->l=new Node(6);
    root->r->r=new Node(7);
    int in[]={4,2,1,5,3};
    int post[]={4,2,5,3,1};
    int h=0;
    flatten_bt(root);
    preordertraversal(root);
    return 0;
}
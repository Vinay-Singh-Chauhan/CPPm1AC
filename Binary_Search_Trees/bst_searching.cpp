#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node *l,*r;
    Node(int val){
        this->val=val;
        l=nullptr;
        r=nullptr;
    }
};

Node *insertBST(Node *root,int val){
    if(root==nullptr){
        root=new Node(val);
        return root;
    }
    if(root->val>val){
        root->l=insertBST(root->l,val);
    }
    else{
        root->r=insertBST(root->r,val);
    }
    return root;
}

Node* searchBST(Node *root,int val){
    if(root==nullptr){
        return nullptr;
    }
    if(root->val==val){
        return root;
    }
    if(root->val>val){
        return searchBST(root->l,val);
    }
    else{
        return searchBST(root->r,val);
    }
    // return root;
}
void inoreder(Node *root){
    if(root==nullptr){
        return;
    }
    inoreder(root->l);
    cout<<root->val;
    inoreder(root->r);
}
int main()
{   
    Node * root=nullptr;
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    // insertBST(root,3);
    Node * a=searchBST(root,2);
    // inoreder(root);
    cout<<a->val;
    return 0;
}  
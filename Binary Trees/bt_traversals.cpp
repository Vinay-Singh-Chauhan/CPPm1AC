#include<iostream>
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

// Inorder traversal

void inordertraversal(Node* root){
    if(root==nullptr){
        return ;
    }
    inordertraversal(root->l);
    cout<<root->val<<" ";
    inordertraversal(root->r);

}

//preorder traversal

void preordertraversal(Node* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->val<<" ";
    preordertraversal(root->l);
    preordertraversal(root->r);
}

// postorder traversal

void postordertraversal(Node* root){
    if(root==nullptr){
        return ;
    }
    
    postordertraversal(root->l);
    postordertraversal(root->r);
    cout<<root->val<<" ";
}

// implementation of main function

int main()
{

    // building a binary tree manually

    Node *root=new Node(1);
    root->l=new Node(2);
    root->r=new Node(3);
    root->l->l=new Node(4);
    root->l->r=new Node(5);
    root->r->l=new Node(6);
    root->r->r=new Node(7);

    // calling traversal functions 

    cout<<"inorder traversal"<<endl;
    inordertraversal(root);
    cout<<"preorder traversal"<<endl;
    preordertraversal(root);
    cout<<"postorder traversal"<<endl;
    postordertraversal(root);

    // return from main function 

    return 0;
}
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

int getHeight(Node *root){
    if(root==nullptr){
        return 0;
    }
    return getHeight(root->l) + getHeight(root->r) +1;
}
//my solution...................................................................
bool isBalanced(Node* root){
    if(root==nullptr){
        return true;
    }
    
    if(abs(getHeight(root->l) - getHeight(root->r))>1){
        return false;
    }

    return true;

}
// apna college solution........................................................
// bool isBalanced(Node* root){
//     if(root==nullptr){
//         return true;
//     }
//     if(isBalanced(root->l)==false){
//         return false;
//     }
//     if(isBalanced(root->r)==false){
//         return false;
//     }
    
//     if(abs(getHeight(root->l) - getHeight(root->r))>1){
//         return false;
//     }

//     return true;

// }


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
    cout<<isBalanced(root);
    preordertraversal(root);
    return 0;
}
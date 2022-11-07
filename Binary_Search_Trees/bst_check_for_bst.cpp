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

void inoreder(Node *root){
    if(root==nullptr){
        return;
    }
    inoreder(root->l);
    cout<<root->val;
    inoreder(root->r);
}
//my solution.......................
// bool check(Node* root , int min,int max){
//     if(root==nullptr){
//         return true;
//     }
    
    
//     if(root->val<max and root->val>min){

//         return check(root->r,root->val,max) and check(root->l,min,root->val);
//     }else
//     return false;
    
// }

// apna clg solution...............
bool check(Node* root , int min=NULL,int max=NULL){
    if(root==nullptr){
        return true;
    }
    if(min!=NULL and root->val<=min){
        return false;
    }
    if(max!=NULL and root->val>=max){
        return false;
    }
    bool rbool=check(root->r,root->val,max);
    bool lbool=check(root->l,min,root->val);
    return rbool and lbool;
    
    
}

int main()
{   
    Node * root=nullptr;
    // Node *root=new Node(1);
    // root->l=new Node(2);
    // root->r=new Node(3);
    // root->l->l=new Node(4);
    // root->l->r=new Node(5);
    // root->r->l=new Node(6);
    // root->r->r=new Node(7);
    root = insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,4);
    insertBST(root,2);
    insertBST(root,7);
    // insertBST(root,3);
    // inoreder(root);
    cout<<check(root,INT16_MIN,INT16_MAX);
    return 0;
}
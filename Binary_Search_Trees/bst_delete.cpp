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
Node* inorderSuccessor(Node* root){
    Node* curr= root;
    while(root and curr->l!=nullptr){
        curr=curr->l;
    }
    return curr;
}
Node* deleteBST(Node *root,int val){
    if(root->val>val){
        root->l=deleteBST(root->l,val);
    }
    else if(root->val<val){
        root->r=deleteBST(root->r,val);
    }
    else{
        if(root->l==nullptr){
            Node* temp=root->r;
            free(root);
            return temp;
        }
        else if(root->r==nullptr){
            Node*temp=root->l;
            free(root);
            return temp;
        }
        Node* temp= inorderSuccessor(root->r);
        
        root->val=temp->val;
        root->r=deleteBST(root->r,temp->val);

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
int main()
{   
    Node * root=nullptr;
    root = insertBST(root,4);
    insertBST(root,2);
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,3);
    insertBST(root,6);
    inoreder(root);
    cout<<endl;
   root= deleteBST(root,2);
    // insertBST(root,3);
    // Node * a=searchBST(root,2);
    // inoreder(root);
    // cout<<a->val;
    inoreder(root);

    return 0;
}  
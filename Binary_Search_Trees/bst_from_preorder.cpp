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
Node * fromPreorder(int preorder[],int *preorderidx,int key ,int min ,int max,int n){
    if(*preorderidx>=n){
        return nullptr;
    }
    Node*root=nullptr;
    if(key>min and key<max){
        root=new Node(key);
        *preorderidx=*preorderidx+1;
        if(*preorderidx<n){
            root->l=fromPreorder(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx<n){
            root->r=fromPreorder(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
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

void printpreorder(Node* root){
    if(root==nullptr) return ;
    cout<<root->val<<" ";
    printpreorder(root->l);
    printpreorder(root->r);
}
int main()
{   
    // Node * root=nullptr;
    // root = insertBST(root,5);
    // insertBST(root,1);
    // insertBST(root,3);
    // insertBST(root,4);
    // insertBST(root,2);
    // insertBST(root,7);
    // // insertBST(root,3);
    // inoreder(root);
    int preoder[]={10,2,1,13,11};
    int  n=5;
    int preorderidx=0;
    Node *root=fromPreorder(preoder,&preorderidx,preoder[0],INT_MIN,INT_MAX,n);
    printpreorder(root);
    return 0;
}
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

Node* fromsortedarray(int array[],int start,int end,int n){
    if(start<0 || end>n || start>end){
        return nullptr;
    }
    int mid=(start+end)/2;
    Node* node= new Node(array[mid]);
    node->l=fromsortedarray(array,start,mid-1,n);
    node->r=fromsortedarray(array,mid+1,end,n);
    return node;
}

int main()
{   
    int arr[]={1,2,3,4,5};
    Node* root=fromsortedarray(arr,0,4,5);
    // Node * root=nullptr;
    // root = insertBST(root,5);
    // insertBST(root,1);
    // insertBST(root,3);
    // insertBST(root,4);
    // insertBST(root,2);
    // insertBST(root,7);
    // // insertBST(root,3);
    inoreder(root);
    return 0;
}
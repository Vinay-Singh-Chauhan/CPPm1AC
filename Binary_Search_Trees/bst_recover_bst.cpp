#include<iostream>
using namespace std;
class Node{
    public:
    Node*left;
    Node*right;
    int val;
    Node(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void calcPointers(Node* root,Node** first,Node** mid,Node** last,Node** prev){
    if (root==nullptr)
    {
        return;
    }

    calcPointers(root->left,first,mid,last,prev);
    if(*prev and root->val<(*prev)->val){
        if(!*first){
            *first=*prev;
            *mid=root;
        }else{
            *last=root;

        }
    }
    *prev=root;
    calcPointers(root->right,first,mid,last,prev);
}
void restoreBST(Node* root){
    Node* first=nullptr;
    Node* mid=nullptr;
    Node* last=nullptr;
    Node* prev=nullptr;
    // bool condition=false;
    calcPointers(root,&first,&mid,&last,&prev);
    if(first!=nullptr and last!=nullptr)
        swap(&(first->val) , &(last->val));
    else if (first!=nullptr and mid!=nullptr)
    {
        swap(&(first->val) , &(mid->val));     
    } 

}
void inordertraversal(Node* root){
    if(root==nullptr){
        return ;
    }
    inordertraversal(root->left);
    cout<<root->val<<" ";
    inordertraversal(root->right);

}
int main()
{

    Node* root=new Node(6);
    root->right=new Node(3);
    root->left=new Node(9);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->right=new Node(13);
    inordertraversal(root);
    restoreBST(root);
    cout<<endl;
    inordertraversal(root);
    return 0;
}
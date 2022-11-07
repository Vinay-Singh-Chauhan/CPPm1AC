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

bool isIndentical(Node* root1,Node* root2){
    if(root1==nullptr and root2==nullptr){
        return true;

    }
    if((root1 and !root2)||(!root1 and root2)){
        return false;
    }
    if(root1->val==root2->val){
        return isIndentical(root1->left,root2->left) and isIndentical(root1->right, root2->right);
    }else{
        return false;
    }
    return true;
}
int main()
{
    Node*root=new Node(3);
    root->left=new Node(2);
    root->right=new Node(4);
    root->left->left=new Node(1);
    root->right->right=new Node(5);

    Node*roo=new Node(3);
    roo->left=new Node(2);
    roo->right=new Node(4);
    roo->left->left=new Node(6);
    roo->right->right=new Node(5);

    cout<<isIndentical(root,roo);
    return 0;
}
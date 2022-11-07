#include<iostream>
#include<climits>
using namespace std;
struct Node{
    public:
    Node* left;
    Node* right;
    int val;
    Node(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
Info largest_BST(Node* root){
    if(root==nullptr){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left == nullptr and root-> right== nullptr){
        return {1,root->val,root->val,1,true};
    }
    Info leftInfo=largest_BST(root->left);
    Info rightInfo=largest_BST(root->right);
    Info curr;
    curr.size=(1+leftInfo.size+rightInfo.size);
    if(leftInfo.isBST and rightInfo.isBST 
        and leftInfo.max < root->val 
        and root->val<rightInfo.min){
            curr.min=min(leftInfo.min,min(root->val,rightInfo.min));
            curr.max=max(leftInfo.max,max(root->val,rightInfo.max));

            curr.ans=curr.size;
            curr.isBST=true;
            return curr;

        }
        curr.ans=max(leftInfo.ans,rightInfo.ans);
        curr.isBST=false;
        return curr;
}
int main()
{
    Node* root=new Node(15);
    root->left=new Node(20);
    root->right =new Node(30);
    root->left->left=new Node(5);
    cout<<largest_BST(root).ans;
return 0;
}
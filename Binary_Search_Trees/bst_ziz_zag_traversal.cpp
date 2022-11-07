#include<iostream>
#include<stack>
using namespace std;
// Node Implementation
class Node
{
    public:
    Node* right;
    Node* left;
    int val;
    Node(int val)
    {
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
//zig-zag traversal implemention
void zig_zag_traversal(Node* root)
{
    bool left=false;
    stack<Node*>current_level;
    stack<Node*>next_level;

    current_level.push(root);

    while(!current_level.empty()){
        
        Node *temp=current_level.top();
        current_level.pop();
        if(temp!=nullptr){
            cout<<temp->val<<" ";
        
        if(left==true){
            if(temp->left!=nullptr)
            next_level.push(temp->left);
            if(temp->right!=nullptr)
            next_level.push(temp->right);
        }
        else{
            if(temp->right!=nullptr)
            next_level.push(temp->right);
            if(temp->left!=nullptr)
            next_level.push(temp->left);
        }
        }
        if(current_level.empty()){
            left=!left;
            swap(current_level,next_level);
        }
        
    }
}


int main()
{
    Node*root=new Node(3);
    root->left=new Node(2);
    root->right=new Node(4);
    root->left->left=new Node(1);
    root->right->right=new Node(5);
    zig_zag_traversal(root);

    return 0;
}
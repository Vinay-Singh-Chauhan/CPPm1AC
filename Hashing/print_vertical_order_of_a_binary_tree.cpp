#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<int,vector<int>>vertical_levels;
class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=nullptr;
        this->right=nullptr;
    }
};
void vertical_order(Node*root,int idx){
    if(root==nullptr) return;
    vertical_levels[idx].push_back(root->val);
    vertical_order(root->left,idx-1);
    vertical_order(root->right,idx+1);
}

int main()
{
    Node* root=new Node(10);
    root->left=new Node(7);
    root->left->left =new Node(3);
    root->left->right =new Node(11);
    root->right=new Node(4);
    root->right->right=new Node(6);
    root->right->left=new Node(14);
    vertical_order(root,0);
    map<int,vector<int>> :: iterator it;
    for(it=vertical_levels.begin();it!=vertical_levels.end();it++){
        for(int i=0;i<it->second.size();i++){
            cout<< it->second[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
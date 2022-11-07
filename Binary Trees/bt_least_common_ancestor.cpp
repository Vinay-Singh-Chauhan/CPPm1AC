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

Node* LCAoptimised(Node *root,int n1,int n2){
    if (root==nullptr)
    {
        return nullptr;
    }
    if(root->val==n1 or root->val==n2){
        return root;
    }
    Node* left=LCAoptimised(root->l,n1,n2);
    Node *right=LCAoptimised(root->r,n1,n2);

    if(left!=nullptr and right!=nullptr){
        return root;
    }
    if(left==nullptr and right ==nullptr){
        return nullptr;
    }
    if(left!=nullptr){
        return LCAoptimised(root->l,n1,n2);
    }
    return LCAoptimised(root->r,n1,n2);
    
}

bool getpath(Node *root,int key,vector<int> &path){
    if(root==nullptr){
        return false;
    }
    path.push_back(root->val);
    if(root->val==key){
        return true;
    }
    if(getpath(root->l,key,path)||getpath(root->r,key,path)){
        return true;
    }
    path.pop_back();
    return false;
}
int LCA(Node *root,int n1,int n2){
    vector<int>path1,path2;
    if(!getpath(root,n1,path1)||!getpath(root,n2,path2)){
        return -1;
    }
    int pc;
    for(pc=0;pc<path1.size() and path2.size();pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}


int main()
{
    Node *root=new Node(1);
    root->l=new Node(2);
    root->r=new Node(3);
    root->l->l=new Node(4);
    // root->l->r=new Node(5);
    root->r->l=new Node(5);
    root->r->r=new Node(6);
    root->r->l->l=new Node(7);
    int a= LCA(root,7,6);
    if(a==-1){
        cout<<"lca does not exist";
    }
    else cout<<a;
    return 0;
}
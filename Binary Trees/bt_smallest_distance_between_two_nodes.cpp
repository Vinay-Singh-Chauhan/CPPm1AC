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

Node* LCA(Node *root,int n1,int n2){
    if (root==nullptr)
    {
        return nullptr;
    }
    if(root->val==n1 or root->val==n2){
        return root;
    }
    Node* left=LCA(root->l,n1,n2);
    Node *right=LCA(root->r,n1,n2);

    if(left!=nullptr and right!=nullptr){
        return root;
    }
    if(left==nullptr and right ==nullptr){
        return nullptr;
    }
    if(left!=nullptr){
        return LCA(root->l,n1,n2);
    }
    return LCA(root->r,n1,n2);
    
}

int findDistance(Node* root, int k,int dist){
    if(root==nullptr){
        return -1;
    }
    if(root->val==k){
        return dist;
    }
    int left=findDistance(root->l,k,dist+1);
    if(left!=-1){
        return left;
    }
    return findDistance(root->r,k,dist+1);
}
int distance_between_two_nodes(Node *root, int n1,int n2){
    
    Node *ances=LCA(root,n1,n2);
    int d1=findDistance(ances,n1,0);
    int d2=findDistance(ances,n2,0);
    return d1+d2;

}

int main()
{
    Node *root=new Node(1);
    root->l=new Node(2);
    root->r=new Node(3);
    root->l->l=new Node(4);
    // root->l->r=new Node(5);
    // root->r->l=new Node(6);
    root->r->r=new Node(5);
    cout<<distance_between_two_nodes(root,4,5);
    return 0;
}
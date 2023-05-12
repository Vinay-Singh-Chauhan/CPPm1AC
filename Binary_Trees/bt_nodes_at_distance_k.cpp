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

void NADsubtree( Node *node, int distance){
    if(distance<0) return ;
    if(node==nullptr) return ;
    int k=distance;
    if(k==0){
        cout<<node->val;
        return;
    }
    NADsubtree(node->l,k-1);
    NADsubtree(node->r,k-1);
}

int nodesAtDistance(Node *root, Node *node, int distance){
    if(root==nullptr) return -1;
    if(root==node) {
        NADsubtree(root,distance);
        return 0;
    }
    int dl=nodesAtDistance(root->l,node,distance);
    if (dl!=-1)
    {
        if(dl+1==distance){
            cout<<root->val;
        }else{
            NADsubtree(root->r,distance-dl-2);
        }
        return 1+dl;
    }
    int dr=nodesAtDistance(root->r,node,distance);
    if (dr!=-1)
    {
        if(dr+1==distance){
            cout<<root->val;
        }else{
            NADsubtree(root->l,distance-dr-2);
        }
        return 1+dr;
    }
    return -1;
}




int main()
{
    Node *root=new Node(1);
    root->l=new Node(2);
    root->r=new Node(3);
    root->l->l=new Node(4);
    // root->l->r=new Node(5);
    // root->r->l=new Node(5);
    // root->r->r=new Node(6);
    // root->r->l->l=new Node(7);
    nodesAtDistance(root,root->l,1);

    // preordertraversal(root);
    return 0;
}
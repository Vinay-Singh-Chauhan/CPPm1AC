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

void rightView(Node *root){
    if(root==nullptr){
        return ;
    }
    queue<Node*>q;
    q.push(root);
    while (!q.empty())  
    {
        int n= q.size();
        for(int i=0;i<n;i++){
            Node* curr=q.front();
            q.pop();
            if(i==n-1) cout<<curr->val;
        // q.pop();
            if(curr->r!=nullptr){
                q.push(curr->r);
            }if(curr->l!=nullptr){
                q.push(curr->l);
            }
        }
        
    }
    
}


void preordertraversal(Node* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->val<<" ";
    preordertraversal(root->l);
    preordertraversal(root->r);
}

    //         1
    //      2     3
    //    4   5  6   7

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

    int in[]={4,2,1,5,3};
    int post[]={4,2,5,3,1};
    rightView(root);

    // preordertraversal(root);
    return 0;
}
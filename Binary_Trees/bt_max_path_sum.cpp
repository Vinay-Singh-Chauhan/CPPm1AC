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
int maxpathsumutil(Node *root,int &ans){
    if(root==nullptr){
        return 0;
    }
    int left = maxpathsumutil(root->l,ans);
    int right= maxpathsumutil(root->r,ans);
    int nodemax=max(max(root->val,root->val+left+right),max(root->val+left,root->val + right));
    ans=max(ans,nodemax);
    int singlemax=max(root->val,max(root->val+left,root->val + right));
    return singlemax;
}
int maxpathsum(Node *root){
    int ans=INT_MIN;
    maxpathsumutil(root,ans);
    return ans;
    // return root->val + maxpathsum(root->l)+maxpathsum(root->r);
}

int main()
{
    Node *root=new Node(1);
    root->l=new Node(2);
    root->r=new Node(3);
    root->l->l=new Node(4);
    root->l->r=new Node(5);
    root->r->l=new Node(6);
    root->r->r=new Node(7);
    int in[]={4,2,1,5,3};
    int post[]={4,2,5,3,1};
    cout<<maxpathsum(root);
    return 0;
}
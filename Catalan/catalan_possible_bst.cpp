#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node *l,*r;
    Node(int val){
        this->val=val;
        l=nullptr;
        r=nullptr;
    }
};
void preorder(Node* root){
    if(root==nullptr) return;
    cout<<root->val;
    preorder(root->l);
    preorder(root->r);
}
vector<Node*>constructBST(int start,int end){
    
    vector<Node*>trees;
    if(start>end) {
        trees.push_back(nullptr);
        return trees;
    }
    for (int  i = start; i < end+1; i++)
    {
        vector<Node*>lefttrees=constructBST(start,i-1);
        vector<Node*>righttrees=constructBST(i+1,end);
        for(int j=0;j<lefttrees.size();j++){
            Node* left=lefttrees[j];
            for (int k = 0; k < righttrees.size(); k++)
            {
                Node* right=righttrees[k];
                Node* node=new Node(i);
                node->l=left;
                node->r=right;
                trees.push_back(node);

            }
            
        }
    }
    return trees;
    
}
int main(int argc, char const *argv[])
{
   vector<Node*> totaltrees=constructBST(1,3);
   for(int i=0;i<totaltrees.size();i++){
    preorder(totaltrees[i]);
    cout<<endl;
   }
   return 0;
}
 
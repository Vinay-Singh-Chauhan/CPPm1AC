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
void inordertraversal(Node* root){
    if(root==nullptr){
        return ;
    }
    inordertraversal(root->l);
    cout<<root->val<<" ";
    inordertraversal(root->r);

}

int searchfor(int arr[],int k,int start,int end){
    int i=start;
    while(i<=end){
        if(arr[i]==k){
            return i;
        }
        i++;
    }
    return -1;
}

void level_traversal(Node *root){
    queue<Node *> a;
    a.push(root);
    a.push(NULL);
    while (!a.empty())
    {
        Node *temp=a.front();
        a.pop();
        if(temp!=nullptr)
        cout<<temp->val<<" ";
        if(temp==nullptr){
            if(a.empty()){
                return;
            }
            else{
                a.push(nullptr);
                
            }
        }else{
            if(temp->l!=nullptr)
            a.push(temp->l);
            if(temp->r!=nullptr)
            a.push(temp->r);
        }
        
    }


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
    level_traversal(root);
    return 0;
}
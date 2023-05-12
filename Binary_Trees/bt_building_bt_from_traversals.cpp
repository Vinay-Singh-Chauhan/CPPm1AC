#include<iostream>
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

Node* bt_from_preorder_and_inorder(int pre[],int in[],int start, int end){
    static int idx=0;
    if(start>end){
        return nullptr;
    }
    int curr=pre[idx];
    idx++;
    Node *root=new Node(curr);
    if(start==end){
        return root;
    }
    int rootidx=searchfor(in,curr,start,end);
    root->l= bt_from_preorder_and_inorder(pre,in,start,rootidx-1);
    root->r= bt_from_preorder_and_inorder(pre,in,rootidx+1,end);
    return root;
    
}

Node* bt_from_postorder_and_inorder(int post[],int in[],int start, int end){
    static int idx=end-start;
    if(start>end){
        return nullptr;
    }
    int curr=post[idx];
    idx--;
    Node *root=new Node(curr);
    if(start==end){
        return root;
    }
    int rootidx=searchfor(in,curr,start,end);
   
    root->r= bt_from_postorder_and_inorder(post,in,rootidx+1,end);
     root->l= bt_from_postorder_and_inorder(post,in,start,rootidx-1);
    return root;
    
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
    int pre[]={1,2,4,3,5};
    int post[]={4,2,1,5,3};
    Node* check=bt_from_preorder_and_inorder(pre,post,0,4);
    inordertraversal(check);
    return 0;
}
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


// My solution ..................................................
//int sumtraversal(Node* root){
//     if(root==nullptr){
//         return 0;
//     }
//     int sum=0;
//     sum+=sumtraversal(root->l);
//     sum+=root->val;
//     sum+=sumtraversal(root->r);
//     return sum;

// } 
// void sumrepalcement(Node *root){
//     if(root == nullptr){
//         return;
//     }
//     root->val=sumtraversal(root);
//     sumrepalcement(root->l);
//     sumrepalcement(root->r);
// }

// Apna College Solution..................
void sumreplacement(Node *root){
    if(root==nullptr){
        return;
    }
    sumreplacement(root->l);
    sumreplacement(root->r);
    if(root->l!=nullptr){
        root->val+=root->l->val;
    }
    if(root->r!=nullptr){
        root->val+=root->r->val;
    }
}

int countNodesByLevelTraversal(Node *root){
    int k=0;
    int count=0;
    queue<Node *> a;
    a.push(root);
    a.push(NULL);
    while (!a.empty())
    {   
        Node *temp=a.front();
        a.pop();
        if(temp!=nullptr)
        count++;
        if(temp==nullptr){
            k++;
            if(a.empty()){
                return count;
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

int countNodesByInorderTraversal(Node *root){
    if(root==nullptr){
        return 0;
    }
    return 1+countNodesByInorderTraversal(root->l)+countNodesByInorderTraversal(root->r);


}
void preordertraversal(Node* root){
    if(root==nullptr){
        return ;
    }
    cout<<root->val<<" ";
    preordertraversal(root->l);
    preordertraversal(root->r);
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
    sumreplacement(root);
    preordertraversal(root);
    return 0;
}
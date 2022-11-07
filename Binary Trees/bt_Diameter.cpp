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


int sumOfNodesByInorderTraversal(Node *root){
    int sum=0;
    if(root==nullptr){
        return sum;
    }
    sum+=root->val;
    sum+=sumOfNodesByInorderTraversal(root->l);
    sum+=sumOfNodesByInorderTraversal(root->r);
    return sum;

}

int heightByLevelTraversal(Node *root){
    if(root==nullptr){
        return 0;
    }
    int height=0;
    queue<Node *> a;
    a.push(root);
    a.push(NULL);
    while (!a.empty())
    {   
        Node *temp=a.front();
        a.pop();
        if(temp!=nullptr)
        ;
        if(temp==nullptr){
            height++;
            if(a.empty()){
                return height;
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

int heightOfBt(Node *root){
    if(root==nullptr){
        return 0;
    }
    return max(heightOfBt(root->l),heightOfBt(root->r)) +1;
    
}

int calcDiameter(Node *root){
    if(root==nullptr){
        return 0;
    }
    int lheight=heightOfBt(root->l);
    int rheight=heightOfBt(root->r);
    int currDia=lheight+rheight+1;

    int lDia=calcDiameter(root->l);
    int rDia=calcDiameter(root->r);
    return max(currDia,max(lDia,rDia));


}

int optimisedCalcDiameter(Node *root,int *height){
    if(root==nullptr){
        *height=0;
        return 0;
    }
    int lheight=0,rheight=0;

    int lDia=optimisedCalcDiameter(root->l,&lheight);
    int rDia=optimisedCalcDiameter(root->r,&rheight);
    *height=max(rheight,lheight)+1;
    int currDia=lheight+rheight+1;
    return max(currDia,max(lDia,rDia));


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
    int h=0;
    cout<<optimisedCalcDiameter(root,&h);
    return 0;
}
#include<iostream>
#include<vector>

#define vi vector<int>
#define rep(i,a,b) for(int i=a;i<b;i++)

using namespace std;

void heapify(vi &a,int n,int i){
    int maxIndex=i;
    int lchild=2*i+1;
    int rchild=2*i+2;

    if (lchild<n and a[lchild]>a[maxIndex])
    {
        maxIndex=lchild;

    }
    if (rchild<n and a[rchild]>a[maxIndex])
    {
        maxIndex=rchild;

    }

    if(maxIndex!=i){
        swap(a[i],a[maxIndex]);
        heapify(a,n,maxIndex);

    }
    
}

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

void heapsort(vi &a){
    int n=a.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main()
{
    vi a={4,5,3,2,6,1};
    heapsort(a);
    rep(i,0,a.size()){
        cout<<a[i]<<" ";
    }
    return 0;
}
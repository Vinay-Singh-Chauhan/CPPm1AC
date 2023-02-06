#include <bits/stdc++.h>
using namespace std;
class trie
{
public:
    trie *next[2];
    trie()
    {
        next[0] = nullptr;
        next[1] = nullptr;
    }
};

void insert(int n,trie *root)
{
    
    trie *curr = root;
    for (int s = 31; s >= 0; s--)
    {
        int bit = ((n >> s) & 1);
        if (curr->next[bit] == nullptr)
            curr->next[bit] = new trie();
            curr = curr->next[bit];
        }
}

int query(int n, trie *root)
{
    trie *it = root;
    int num = n;
    int cur_max = 0;
    for (int j = 31; j >= 0; j--)
    {
        int bit = ((num >> j) & 1) ? 0 : 1;
        if (it->next[bit])
        {
            it = it->next[bit];
            cur_max |=1<<j;
        }
        else
        {
            it = it->next[bit xor 1];
        }
    }
    return cur_max;
    
}
int main()
{
    vector<int> nums={1,2,6,8};
    trie* root=new trie();
    insert(0,root);
    vector<int>rmax(nums.size()+1,0);
    int R=0;
    for(int i=nums.size()-1;i>=0;i--){
        R=R xor nums[i];
        if(i!=nums.size()-1){
        rmax[i]=max(rmax[i],query(R,root));
        insert(R,root);
        }
        else{
            rmax[i]=query(R,root);
            insert(R,root);
        }
    }
    free(root);
    root= new trie();
    int L=0,ans=0;
    insert(0,root);
    vector<int>lmax(nums.size()+1,0);
    for(int i=0;i<nums.size();i++){
        L=L xor nums[i];
        ans=max(ans,rmax[i+1]+query(L,root));
        insert(L,root);
    }
    cout<<ans;

    }
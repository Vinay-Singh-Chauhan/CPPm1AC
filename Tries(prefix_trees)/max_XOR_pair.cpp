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

trie *bulid(vector<int> n)
{
    trie *root = new trie();
    for (auto i : n)
    {
        trie *curr = root;
        for (int s = 31; s >= 0; s--)
        {
            int bit = ((i >> s) & 1);
            if (curr->next[bit] == nullptr)
                curr->next[bit] = new trie();
            curr = curr->next[bit];
        }
    }
    return root;
}

int maxXOR(vector<int> n, trie *root)
{
    int res = INT_MIN;
    for (int i = 0; i < n.size(); i++)
    {
        trie *it = root;
        int num = n[i];
        int cur_max = 0;
        for (int j = 31; j >= 0; j--)
        {
            int bit = ((num >> j) & 1) ? 0 : 1;
            if (it->next[bit])
            {
                cur_max <<= 1;
                cur_max |= 1;
                it = it->next[bit];
            }
            else
            {
                cur_max <<= 1;
                cur_max |= 0;
                it = it->next[bit xor 1];
            }
        }
        res = max(res, cur_max);
    }
    return res;
}
int main()
{
    vector<int> a = {3, 10, 5, 15, 2};
    trie *r = bulid(a);

    int ans = maxXOR(a, r);
    cout << ans;
    return 0;
}
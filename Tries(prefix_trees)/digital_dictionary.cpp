#include<bits/stdc++.h>
using namespace std;
class trie{
    public:
    class node{
        public:
        bool end;
        node* next[26];
        node(){
            end=false;
            for(int i=0;i<26;i++){
                next[i]=nullptr;
            }
        }
    };
    node* trieHead;
    trie()  {trieHead=new node();}

    void insert(string a){
        int i=0;
        node* it=trieHead;
        while (i<a.size())
        {
            if(it->next[a[i]-'a']==nullptr){
                it->next[a[i]-'a']=new node();
            }

            it=it->next[a[i]-'a'];
            i++;
        }
        it->end=true; 
    }
    void search(string a){
        int i=0;
        node* it=trieHead;
        while (i<a.size())
        {
            if(it->next[a[i]-'a']==nullptr){
                insert(a);
                return ;
            }

            it=it->next[a[i]-'a'];
            i++;
        }
        vector<string> res;
        printall(it,a,res,"");
        for(auto c:res){
            cout<<a<<c<<endl;
        }
        // it->end=true; 
    }
    void printall(node* it,string a,vector<string>&res,string cur){
        if(it==nullptr)return;
        if(it->end){
            res.push_back(cur);
        }
        for(int i=0;i<26;i++){
            if(it->next[i]){
                printall(it->next[i],a,res,cur+char('a'+i));
            }
        }
    }

};
int main()
{
trie* mytrie=new trie();
vector<string>words={"rat","rack","bat","batman"};

for(auto i:words){
    mytrie->insert(i);
}
vector<string>w={"r","bat","quick"};
for(auto i:w){
    mytrie->search(i);
}
return 0;
}
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
    bool search(string a){
        int i=0;
        node* it=trieHead;
        while (i<a.size())
        {
            if(it->next[a[i]-'a']==nullptr){
                return false;
            }

            it=it->next[a[i]-'a'];
            i++;
        }
        
        return it->end=true; 
    }

};
int main()
{
trie* mytrie=new trie();
vector<string>words={"ayush","daasi"};
for(auto i:words) mytrie->insert(i);
if(mytrie->search("ayush")) cout<<"ayush present"<<endl;
if(mytrie->search("vaibhav")) cout <<"vaibhav present";
else cout<<"vaibhav absent";

return 0;
}
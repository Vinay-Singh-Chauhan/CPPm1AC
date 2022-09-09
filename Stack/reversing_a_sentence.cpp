#include<iostream>
#include<stack>
using namespace std;
int main(){
    string sentence;
    getline(cin,sentence);
    stack<string>revstack;
    for (int i = 0; i < sentence.length(); i++)
    {   
        string word;
        while (sentence[i]!=' '&&i<sentence.length())
        {
            
            word+=sentence[i];
            i++;
        }
        revstack.push(word);
    }
    while(!revstack.empty()){
        cout<<revstack.top()<<" ";
        revstack.pop();
    }


    return 0;
}
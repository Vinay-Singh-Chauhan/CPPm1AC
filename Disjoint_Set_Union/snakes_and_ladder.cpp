#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> visited(100,0);

int main()
{
    int snakes,ladder;
    map<int,int> s ;
    map<int,int> l ;
    
    cin>>ladder;
    for(int i=0;i<ladder;i++){
        int a,b;
        cin>>a>>b;
        l[a]=b;
    }
    cin>>snakes;
    for(int i=0;i<snakes;i++){
        int a,b;
        cin>>a>>b;
        s[a]=b;
    }
    int moves=0;
    bool found=false;
    queue<int> b;
    b.push(1);
    visited[1]=1;
    while(!b.empty() and !found){
        int sz=b.size();
        while(sz--){
            int t=b.front();
            b.pop();
            for(int poss=1;poss<=6;poss++){
                if(t+poss==100) found =true;
                if(t+poss<100){
                    //ladders
                    if(l[t+poss] and !visited[t+poss]){
                        visited[t+poss]=1;
                        if(l[t+poss]==100) found =true;
                        b.push(l[t+poss]);

                    }
                    //snakes
                    else if(s[t+poss] and !visited[t+poss]){
                        visited[t+poss]=1;
                        if(s[t+poss]==100) found =true;
                        b.push(s[t+poss]);

                    }
                    //otherwise
                    else if(!visited[t+poss] and !s[t+poss] and !l[t+poss]){
                        visited[t+poss]=1;
                        if(t+poss==100) found =true;
                        b.push(t+poss);
                        
                    }
                    
                }
            }   

        }
        moves++;
        
    }
    if(found) cout<<moves;
    else cout<<-1;
    return 0;
}
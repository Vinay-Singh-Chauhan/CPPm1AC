#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    const int N=1e5+2,MOD=1e9+7;

    vector<int> adjencyList[N];

int main()

{
    int nodes,edges;
    cin>>nodes>>edges;
    // vector<vector<int>>adjencyMatrix (nodes+1,vector<int>(nodes+1,0));

//inputing edges

    //undirected graph
    // for(int i=0;i<edges;i++){
    //     int x,y;
    //     cin>>x>>y;
    //     adjencyMatrix[x][y]=1;
    //     adjencyMatrix[y][x]=1;   

    // }

    // for(int i=1;i<nodes+1;i++){
    //     for(int j=1;j<nodes+1;j++)
    //     cout<<adjencyMatrix[i][j]<<" ";
    //     cout<<endl;
    // }

    // //checking if there is edge
    // if(adjencyMatrix[3][7]==1){
    //     cout<<"there is a edge between 3 and 7"<<endl;
    // }
cout<<"yeah";
    //adjecency List
     for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        adjencyList[x].push_back(y);
        adjencyList[y].push_back(x);
    }

    //outputting adjecencyList
    for(int i=1;i<nodes+1;i++){
        cout<<i<<"-> " ;
        for(int j=0;j<adjencyList[i].size();j++)
        cout<<adjencyList[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

// 7 7
// 1 2
// 1 3
// 2 4 
// 2 6
// 2 5
// 2 7
// 7 3
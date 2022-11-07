#include<iostream>
#include<queue>
using namespace std;
int main()
{

    //max heap:

    priority_queue<int,vector<int>>a;
    a.push(2);
    a.push(3);
    a.push(1);
    cout<<a.top()<<endl;
    a.pop();
    cout<<a.top()<<endl;


    //min heap:

    priority_queue<int,vector<int>,greater<int>> b;
    b.push(3);
    b.push(1);
    b.push(2);
    cout<<b.top()<<endl;
    b.pop();
    cout<<b.top()<<endl;

    return 0;
}
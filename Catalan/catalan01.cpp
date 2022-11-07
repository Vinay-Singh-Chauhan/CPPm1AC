#include<iostream>
using namespace std;
int catalan(int n){
    if(n<=1) return 1;
    int result=0;
    for(int i=0;i<n;i++){
        result+=catalan(i)*catalan(n-i-1);
    }
    return result;
}
int main()
{
    cout<<catalan(4);
return 0;
}
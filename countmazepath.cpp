#include<iostream>
using namespace std;
int countpath(int n,int i,int j){
    if(i==n-1&&j==n-1){
        return 1;
    }
    if(i>n-1||j>n-1){
        return 0;
    }
    int count =0;
        count +=countpath(n,i+1,j)+countpath(n,i,j+1);
    return count;

}
int main(){
    cout<<countpath(3,0,0);
    return 0;
}
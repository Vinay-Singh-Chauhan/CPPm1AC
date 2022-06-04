#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a Number :";
    cin>>n;
    for(int i=1;i<=2*n;i++){
        for(int j=1;j<= 2*n;j++){
            if(i<=n){
            if(j<=i||j>2*n-i){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }}
            else{
            if(j>=i||j<2*n+2-i){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }            
        }
            }   cout<<endl;         
        }
        
    }
    //this is my code which iterates a large for loop....
    //however the solution provided by apna college has three small for loops next by nxtt (not nested)
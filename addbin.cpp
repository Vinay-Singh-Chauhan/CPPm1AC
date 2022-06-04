#include<iostream>
using namespace  std;
int addbinary(int a,int b){
    int la,lb,sum,ans=0,x=1,prevcarry=0;
        while(a>0||b>0){
            la=a%10;
            lb=b%10;
            if((la==1&&lb==0)||(la==0&&lb==1)){
                if(prevcarry==1){
                    sum=0;
                    prevcarry=1;
                }else{
                    sum=1;
                    prevcarry=0;
                }
            }
            else if((la==0&&lb==0)){
                if(prevcarry==1){
                    sum=1;
                    prevcarry=0;
                }else{
                    sum=0;
                    prevcarry=0;
                }
            }
                else{
                if(prevcarry==1){
                    sum=1;
                    prevcarry=1;
                }else{
                    sum=0;
                    prevcarry=1;
                }
            }
        a/=10;
        b/=10;
        ans+=sum*x;
        x*=10;}
        if(prevcarry==1){
            ans+=prevcarry*x;
        }
    
    return ans;
}
int main(){
    cout<<"enter two bianry numbers:\t";
    int first,second;
    // cin>>first>>second;
    first=10;
    second=1010;
    cout<<addbinary(first,second);
    
}
#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int binarytodec(int bn){
    int r,n=0;
    float p=0.5;
    while(bn>0){
       r=bn%10;
       p= p*2;
       n= n + r*p;
       bn/=10;         
    }
    return n;
}
int octaltodec(int bn){
    int r,n=0,p=1;
    while(bn>0){
       r=bn%10;
    //    p= p*8;
       n= n + r*p;
       p*=8;
       bn/=10;         
    }
    return n;
}
int hexatodec( string hex){
    int ans=0;
    int n=hex.size();
    int x=1;
    for(int i=n-1;i>=0;i--){
        if(hex[i]>'0'&&hex[i]<='9'){
            ans+=x;
        }
        else{
            ans+=(hex[i] - 'A'+10)*x;
        }
        x*=16;
    }
    return ans;
}
//------------------------below code is mine ... soluttion provided by apna college is somewhat different ------------------------------
int dectobin(int a){
    int r,ans=0,x=1;
    while(a>0){
        r=a%2;
        ans = ans + r*x;
        x*=10;
        a/=2;
    }
    return ans;
}
//-------------------------below code is mine ... soluttion provided by apna college is somewhat different-----------------------------
int dectooctal(int a){
    int r,ans=0,x=1;
    while(a>0){
        r=a%8;
        ans = ans + r*x;
        x*=10;
        a/=8;
    }
    return ans;
}
//-----------------------------------------------------------------------------------------------------------------------------------
string dectohexa(int a){
    int r=0;
    string ans;
    while (a>0)
    {
        r=a%16;
        if(r<=9){
            ans+=to_string(r);
        }else{
            ans+=(r-10+'A');
        }
        a/=16;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
    cout<<dectohexa(90);
    return 0;
}
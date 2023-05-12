#include<iostream>
#include<vector>
using namespace std;
#define vvi vector<vector<int>>
vvi multiply(vvi &a,vvi&b){
    vvi ans;
 for(int i=0;i<a.size();i++){
    for(int j=0;j<a.size();j++){
        for(int k=0;k<a.size();k++){
            ans[i][j]+=a[i][k]*b[k][j];
        }
    }
 }
 return ans;
}

vvi matrixExponentiate(vvi& a,int n){
    if(n==0) {
        vvi i=vector(a.size(),vector(a.size(),0));
        for(int c=0;c<a.size();c++){
            i[c][c]=1;
        }
        return i;
    }
    if(n==1) return a;
    vvi ans=matrixExponentiate(a,n/2);
    ans=multiply(ans,ans);
    if(n&1) ans = multiply(ans,a);
    return ans;
    
}
int main()
{

    return 0;
}
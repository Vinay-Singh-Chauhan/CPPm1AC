// multiplicative modulo inverse for ((A*B) % m=1) exists only if (A,m) are coprime , i.e gcd(a,m)=1;
// (A*B)%m=1 ==> A*B +mQ=1 ..thus b=x in extended euclid algo
#include<iostream>
using namespace std;
struct triplet{
    int x,y,gcd;

};
triplet extendedEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    triplet smallAns=extendedEuclid(b,a%b);
    triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x -(a/b)*smallAns.y;
    return ans;
}
int multiplicativeModuloInverse(int a, int m){
    triplet t=extendedEuclid(a,m);
    return t.x;
}
int main()
{

    cout<<multiplicativeModuloInverse(19,2);
    return 0;
}
#include<iostream>
using namespace std;
//ax+by=c==> integral soltion exists only if c=gcd(a,b);
//gcd(a,b)=gcd(b,a%b)
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
int main()
{
    triplet ans=extendedEuclid(7,3);
    cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd;
    return 0;
}
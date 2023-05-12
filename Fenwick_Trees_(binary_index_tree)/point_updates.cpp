#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>bit;
int query(int idx){
    int ans=0;;
    while(idx>0){
        ans+=bit[idx];
        idx-= idx&(-idx);
    }
    return ans;
}
void update(int idx,int val){
    while(idx<=n){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int main()
{
cin>>n;
bit=vector<int>(n+1);
vector<int>a(n+1);
for(int i=1;i<=n;i++){
    cin>>a[i];
    update(i,a[i]);
}
//question has 1-based indexing and bit has 1-based indexing
while(true){
    int type;
    cin>>type;
    if(type==-1) break;
    if(type==1){
        int l,r;
        cin>>l>>r;
        cout<<query(r)-query(l-1)<<endl;
    }
    else if(type==2){
        int idx,val;
        cin>>idx>>val;
        update(idx,-a[idx]);
        update(idx,val);
    }
}

return 0;
}
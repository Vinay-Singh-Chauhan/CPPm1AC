#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int test_case;
    cin >> test_case;
// int p=0;
    for (int test_c = 0; test_c < test_case; test_c++)
    {
        long long n,m;

        cin>>n>>m;
        vector<int> arr(n);
        vector<vector<int>> para(m,vector<int>(3,0));
        
        for(auto& i:arr){
            cin>>i;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<3;j++){
                cin>>para[i][j];
            }
        }
        for(int i=0;i<m;i++){
            int a,b,c,k;
            a=para[i][0];
            b=para[i][1];
            c=para[i][2];
            bool f=false;
            for(int j=0;j<n;j++){
                k=arr[j];
                long double d=pow(b-k,2);
                d+=(-4*a*c);
                // b=sqrtl(b);
                if(d<0){
                    cout<<"YES"<<endl;
                    cout<<arr[j]<<endl;
                    f=true;
                    break;
                }

            }
            if(!f){
                cout<<"NO"<<endl;
            }
        }
            cout<<endl;
        
    }
    
    return 0;
}
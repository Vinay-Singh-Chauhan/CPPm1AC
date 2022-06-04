#include<iostream>
#include<climits>
using namespace std;
int main(){
    int city,mach;
    cin>>city>>mach;
    int city1,city2,time;
    int arr[city-1][mach];
    for(int i =0;i<city-1;i++){
        for(int j=0;j<mach;j++){
            cin>>arr[i][j];
        }
    }
    int macharr[mach];
    for(int i=0;i<mach;i++){
        cin>>macharr[i];
    }
    int mintime=INT_MAX;
    int ans=0;
    
        for(int j=0 ;j<city-1;j++){
            for(int i=0;i<mach;i++){
                           if(arr[j][0]==macharr[i]){
                for(int k=0;k<mach;k++){
                    if(arr[j][1]==macharr[k])
                    {ans+=arr[j][2];}
                }

            }
            else if(arr[j][0]!=macharr[i]||arr[j][1]!=macharr[i]){
                for(int k=0;k<mach;k++){
                if(arr[j][1]==macharr[k])
                mintime=min(mintime,arr[j][2]);}
            }

                if(arr[j][0]!=macharr[i]){
                for(int k=0;k<mach;k++){
                    if(arr[j][1]==macharr[k])
                    {mintime=min(mintime,arr[j][2]);
                    }
                    
                }
                // ans+=mintime;

                } 


            }
        }
int minidx=0;
        for(int i=0;i<city-1;i++){
            // int temp=arr[j][0];
            for(int j=0;j<city-1;j++){
                if(arr[i][1]!=arr[j][1]&&arr[i][0]==arr[j][0]){
                    minidx=min(minidx,arr[j][2]);
                }
            }
        }
        //     for(int i=1;i<mach;i++){
        //     if(macharr[i-1]==arr[j][0]&&macharr[i]==arr[j][1]){
        //         ans+=arr[i][2];
        //     }
        //     if(macharr[i]==arr[j][0]||macharr[i]==arr[j][1]){
        //         mintime=min(mintime,arr[j][2]);
        //     }
            
        // }
        // ans+=mintime;}
    // cout<<endl;
    // cout<<macharr[0];
    // cout<<endl;
    // cout<<arr[0][0]<<endl;
    // cout<<mintime;
    cout<<ans+mintime+minidx;
    return 0;
}
#include<iostream>
using namespace std;

void numberDivisibleByThree(int arr[],int n,int k){
    int i=0,sum=0;
    pair<int,int> ans;
    bool found=false;
    while (i < k)
    {
        sum += arr[i];
        i++;
    }
    if (sum % 3 == 0){
            // cout<<"got it";
            ans=make_pair(0,k-1);
            found=true;

        }
    while (i < n)
    {
        if(found) {
            break;
        }

        sum += arr[i];
        sum -= arr[i - k];
        i++;
        if (sum % 3 == 0){
            ans=make_pair(i-k,i-1);
            found =true ;

        }
 
    }
    if(!found){
        cout<<"No such subarray"<<endl;
    }else{
        for(int i=ans.first;i<=ans.second;i++){
            cout<<arr[i]<<" ";
        }
    }

    return ;
}

int main()
{
    int arr[]={8,23,45,12,56,4};
    numberDivisibleByThree(arr,6,3);
    return 0;
}
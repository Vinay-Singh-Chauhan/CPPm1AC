// _____________________________ = Z-Pattern = _________________________________
// #include<iostream>
// using namespace std;
// int main (){
//  int n;
//  cin>>n;
//  for(int i=1;i<=n;i++){
//     cout<<"* ";
//  }
//  cout<<endl;
//  for(int i=1;i<=n-2;i++){

//     for(int j=1;j<n-i;j++){
//         cout<<"  ";
//     }
    
//     cout<<"* ";

//     cout<<endl;
//  }
//     for(int i=1;i<=n;i++){
//     cout<<"* ";
//  }

//     return 0;

// }


//--------------------------------------------------------------------
#include<iostream>
using namespace std;
int main (){
   int n;
   cin>>n;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
         if(i==n||i==1){
            cout<<"* ";
         }
         else if(i+j==6){
            cout<<"* ";
         }
         else cout<<"  ";
      }

      cout<<endl;
   }

   return 0;
}
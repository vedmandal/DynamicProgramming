
/*
1. you are given a number N, which represnt the number of sides in a polygon.

2. you have to find the total number of ways in which the given polygon can be triangulated.

*/

#include<iostream>
#include<vector>
using namespace std;


void  NumberOfWaysofTriangulation(int n){
   
   
      n=n-2;


     vector<int>dp(n+1);
      
      dp[0]=1;
      dp[1]=1;

      for(int i=2;i<dp.size();i++){
       
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
        
      }
      cout<<dp[dp.size()-1];
}

int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

   
    NumberOfWaysofTriangulation(n);
}
/* 
1. you are given a number n, representing the number of upstrokes and downstrokes.
2. you are required to find the number of valleys and mountains you can  using strokes.
e.g:-
   note at no point we should go below the sea level (number of downstrokes should never be more than number of upstrokes )

*/



#include<iostream>
#include<vector>
using namespace std;


void CountValleyAndMountains(vector<int>&dp){
      
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

    vector<int>dp(n+1);
    CountValleyAndMountains(dp);
}
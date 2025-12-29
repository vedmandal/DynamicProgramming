/*
1. you are given number n, representing the number of elements.
2. you are required to find the number of binary search three yo can create using the elements.


*/

#include<iostream>
#include<vector>
using namespace std;


void CountNumberOfBstPossible(vector<int>&dp){
      
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
    CountNumberOfBstPossible(dp);
}
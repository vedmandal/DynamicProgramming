
/*
1. you are given a number n,representing the number of opening and clsoing pairs.
2. you are required to find the number of ways in which you can arrange the brackets if the closing bracket should never exceed opeing bracket. 


*/




#include<iostream>
#include<vector>
using namespace std;


void CountBrackets(vector<int>&dp){
      
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
    CountBrackets(dp);
}
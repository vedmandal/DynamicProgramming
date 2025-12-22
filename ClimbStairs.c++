/* you are given a  number represnting the number of stairs in the staircase
   you are on the 0 step and you hae to climb to top 
   in one move you are allowed to climb 1,2,3 stairs
   you are required to print the number of  different paths  via which you can climb to top

 */


#include<iostream>
#include<vector>
using namespace std;

// Normal countPath using recursion 

 int CountPath(int n){
    if(n==0){
        return 1;
    }else if (n<0){
        return 0;
    }

    return CountPath(n-1)+CountPath(n-2)+CountPath(n-3);
 }

int main(){
    cout<<CountPath(6);

}


//  Using Memorization


int CountPaths(int n ,vector<int>&dp){
    if(n==0){
        return 1;
    }else if(n<0){
        return 0;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    return dp[n]=CountPaths(n-1,dp)+CountPaths(n-2,dp)+CountPaths(n-3,dp);

}

int main(){
   int n=5;
   vector<int>dp(n+1,-1);
    cout<<CountPaths(n,dp);
}



// using Tabulation


int main(){
    int n=5;
    vector<int>dp(n+1,-1);
    dp[0]=1;

    for(int i=1;i<=n;i++){
        if(i==1){
            dp[i]=dp[i-1];
        }else if(i==2){
            dp[i]=dp[i-1]+dp[i-2];
        }else{
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }

    }

    cout<<dp[n];
}
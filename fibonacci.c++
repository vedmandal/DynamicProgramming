#include<iostream>
#include<vector>
using namespace std;



// Normal fibonacci

int fibo(int n){
    if(n==0 || n==1){
        return n;
    }
    return fibo(n-1)+fibo(n-2);
}



int main(){
    cout<<fibo(10);

}



// FibboNacci using memorization

int fibo(int n,vector<int>&dp){
    if(n==0 or n==1){
        return dp[n]=n;
    }

    if(dp[n]!=-1){
        return dp[n];
    }
    cout<<"hello"<<n<<endl;
    return dp[n]=fibo(n-1,dp)+fibo(n-2,dp);

}



int main(){
    int n=5;
    vector<int>dp(n+1,-1);
    cout<<fibo(n,dp);

}


// Fibonacii using Tabulation

  
   int main(){
    int n=10;
    vector<int>dp(n+1,-1);
    
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];

    }
    cout<<dp[n];
  }
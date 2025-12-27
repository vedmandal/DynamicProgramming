/*
1. you are given a matrix of 0's and 1's.
2. you have to find the maximum size sqaure sub-matrix with all 1's

*/




#include<iostream>
#include<vector>
using namespace std;



int LargestSqaureOf1s(vector<vector<int>>&arr,vector<vector<int>>&dp){
    int ans=0;
    for(int i=dp.size()-1;i>=0;i--){
        for(int j=dp[0].size()-1;j>=0;j--)
        {
            if(i==dp.size()-1 and j==dp[0].size()-1){
                dp[i][j]=arr[i][j];

            }else if(i==dp.size()-1 || j==dp[0].size()-1){
                dp[i][j]=arr[i][j];
                if(dp[i][j]>ans){
                        ans=dp[i][j];
                    }
            }else{
                if(arr[i][j]==0){
                    dp[i][j]=0;
                }else{
                    
                    dp[i][j]= 1+ min(dp[i][j+1],min(dp[i+1][j+1],dp[i+1][j]));
                    if(dp[i][j]>ans){
                        ans=dp[i][j];
                    }

                    

                }
            }
            
                
        
        }
    }
    
    return ans;
}


int main(){

    int n,m;
    cout<<"Enter row and column"<<endl;
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    cout<<"Enter matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
      vector<vector<int>>dp(n,vector<int>(m));

      cout<<LargestSqaureOf1s(arr,dp)<<endl;


}
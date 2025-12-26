/*
1. you are given a number n ,representing the count of items.
2. you are given n numbers,represnting the values of n items.
3. you are given n numbers, representing the weight of n items.
4. you are given a number "cap" which is the capacity of a bag.
not1-> each item can taken as 0 or 1 number of items,you are not allowed to put the same item again and again.


*/
#include<iostream>
#include<vector>
using namespace std;

int ZeroOneKnapsack(vector<int>&weight,vector<int>&value,vector<vector<int>>&dp){

    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
               if(i==0){
                dp[i][j]=0;
               }else if(j==0){
                dp[i][j]=0;
               }else  if(j>=weight[i-1]){
                if(dp[i-1][j-weight[i-1]]+value[i-1]>dp[i-1][j]){
                    dp[i][j]=dp[i-1][j-weight[i-1]]+value[i-1];
                }else{
                   dp[i][j]=dp[i-1][j]; 
                }
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[dp.size()-1][dp[0].size()-1];
}


int main(){

    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    vector<int>weight(n);
    vector<int>value(n);

    cout<<"Enter weights"<<endl;
    for(int i=0;i<weight.size();i++){
        cin>>weight[i];
    }
    cout<<"enter value"<<endl;
    for(int i=0;i<value.size();i++){
        cin>>value[i];
    }

    int cap;
    cout<<"Enter capacity"<<endl;
    cin>>cap;

    vector<vector<int>>dp(n+1,vector<int>(cap+1));

    cout<<ZeroOneKnapsack(weight,value,dp);

}
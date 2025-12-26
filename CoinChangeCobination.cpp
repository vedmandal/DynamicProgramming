/* 
1. you are given a number n ,representing the counts of coins
2. you are given n number,represnting the denonimation of  n coins 
3. you are given a number 'amt".
4.you are required to calculate and print the number of combination of the n coins  using the amount "amt" can be paid.


not1:- you have an infinite supply of each coin denomination that is same coin denomination can be used for many installments in payments of "amt".

Note2:- you are required to find the count of combination and not permuatation  that is 2+2+3=7 and 2+3+2=7 and 3+2 +=7 are different permuation of same combination.you should treat them as 1 and not 3.
*/


#include<iostream>
#include<vector>
using namespace std;


int CoinChangeCombination(vector<int>&arr,vector<int>&dp){

    dp[0]=1;

    for(int i=0;i<arr.size();i++){
        for(int j=arr[i];j<dp.size();j++){
            dp[j]+=dp[j-arr[i]];

        }

    }
    return dp[dp.size()-1];
}

int main(){

    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int amt;
    cout<<"Enter amount"<<endl;
    cin>>amt;
    vector<int>dp(amt+1,0);

    cout<<CoinChangeCombination(arr,dp);
}
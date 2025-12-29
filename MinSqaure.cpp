/*
1. you are given n;
2. you have find the minimum number of square that sum to N.
3.you can always represent a number as a sum of square of others numbers.
for eg:- in worst case N can be represnted as (1*1)*(1*1).....N times.

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

void MinSquare(vector<int>&dp){
    dp[0]=0;
    dp[1]=1;

    for(int i =2;i<dp.size();i++){
        int mini=INT_MAX;
        for(int j=1;j*j<=i;j++){
           if(dp[i-j*j]<mini){
            mini=dp[i-j*j];
           }
        }
        dp[i]=mini+1;

    }
    cout<<dp[dp.size()-1];
}


int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    vector<int>dp(n+1);
    

    MinSquare(dp);

}
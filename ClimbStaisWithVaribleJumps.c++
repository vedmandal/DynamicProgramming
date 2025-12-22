/*
1. you are given a number n, represnting the number of stairs in staircase.
2. you are on the 0th step and required to climb to the top.
3. you are given n numbers where ith number value reprents till how far you can jump  to i a single jump
4. you off course fewer no of steps in the move.
5. you are required to print hthe number of different paths by which yoy can climb to top.
*/

#include<iostream>
#include<vector>
using namespace std;


// using normal recursion 


int countPaths(int idx, int n, vector<int>& jumps) {
    // reached the top
    if (idx == n) {
        return 1;
    }

    // crossed the top
    if (idx > n) {
        return 0;
    }

    int ways = 0;

   
    for (int jump = 1; jump <= jumps[idx]; jump++) {
        ways += countPaths(idx + jump, n, jumps);
    }

    return ways;
}

int main() {
    int n = 6;
    vector<int> jumps = {3, 3, 0, 2, 2, 3};

    cout << countPaths(0, n, jumps);
}


// using memorization
int countPaths(int idx,int n,vector<int>&jumps,vector<int>&dp ){
    if(idx==n){
        return 1;//reached the top
    }
    if(idx>n){
        return 0; // crossed the top 
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    int ways=0;
    for(int jump=1;jump<=jumps[idx] and idx+jump<dp.size() ;jump++){
        ways+=countPaths(idx+jump,n,jumps,dp);
    }
    return dp[idx]=ways;

}

int main(){
    int n=6;
   vector<int> jumps;
jumps.push_back(3);
jumps.push_back(3);
jumps.push_back(0);
jumps.push_back(2);
jumps.push_back(2);
jumps.push_back(3);


    vector<int>dp(n+1,-1);
    cout<< countPaths(0,n,jumps,dp);

}


int main(){
   int n=6;
   vector<int> jumps;
jumps.push_back(3);
jumps.push_back(3);
jumps.push_back(0);
jumps.push_back(2);
jumps.push_back(2);
jumps.push_back(3);


    vector<int>dp(n+1);
    dp[n]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=jumps[i] and i+j< dp.size();j++){
            dp[i]+=dp[i+j];

        }
    }
    cout<<dp[0];


}

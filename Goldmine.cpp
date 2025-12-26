/* 1. you are given a number n ,represnting the number of rows
   2. you are given m ,representing number of colums.
   3. you are m*n 2d array represnting goldmines.
   4.you are standing on the left wall and supposed to dig to the right wall.you can start from any row from the left wall.
   5.you are allowed to move 1 cell up(d1),1 cell right(d2),1cell down(d3)
*/

#include<iostream>
#include<vector>

using namespace std;


int CollectMaxGold(vector<vector<int>>&arr,vector<vector<int>>&dp){

    for(int col=dp[0].size()-1;col>=0;col--){
        for(int row=dp.size()-1;row>=0;row--){
            if(col==dp[0].size()-1){
                dp[row][col]=arr[row][col];

            }
            else if(row==0){
                dp[row][col]=arr[row][col]+(max(dp[row][col+1],dp[row+1][col+1]));

            }
            else if(row==dp.size()-1){
                dp[row][col]=max(dp[row-1][col+1],dp[row][col+1])+arr[row][col];

            }else{
                dp[row][col]=arr[row][col]+max(dp[row-1][col+1],max(dp[row][col+1],dp[row+1][col+1]));

            }


        }
    }

    int maxigold=0;

    for(int i=0;i<dp.size();i++){
        maxigold=max(maxigold,dp[i][0]);
    }
    return maxigold;
}

int main(){
    int r,c;
    cout<<"Enter row"<<endl;
    cin>>r;
    cout<<"Enter col"<<endl;
    cin>>c;

    vector<vector<int>>arr(r,vector<int>(c));
   
    cout << "Enter gold mine matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>>dp(r,vector<int>(c));

    cout<<CollectMaxGold(arr,dp);
}
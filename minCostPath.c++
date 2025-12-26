#include<iostream>
#include<vector>
using namespace std;



/* you are given an array matrix from a cell either you can go tho horizotal or vertical you have to find minmum cost to reach last cell*/



int minCostPath(int r,int c,vector<vector<int>>&arr,vector<vector<int>>&dp){

    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
            if(i==r-1 && j==c-1){
                dp[i][j]=arr[i][j];
            }else if(i==r-1){
                dp[i][j]=dp[i][j+1]+arr[i][j];
            }else if(j==c-1){
                dp[i][j]=dp[i+1][j]+arr[i][j];
            }else{
                dp[i][j]=min(dp[i][j+1],dp[i+1][j])+arr[i][j];
            }
        }
    }
    return dp[0][0];
}
int main(){
    int r,c;
    cout<<"Enter row";
    cin>>r;
    cout<<"Enter column";
    cin>>c;

    vector<vector<int>>arr(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>dp(r,vector<int>(c));
    cout<<minCostPath(r, c,arr,dp);
}
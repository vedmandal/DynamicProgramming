/*   1. you are given a number n ,reprenting count of elements
     2.  you are given n number and target number;
     3. check true or false if there is subsets of elements of which add upto target or not"

*/

#include<iostream>
#include<vector>
using namespace std;

bool TargetSumSubset(vector<int>&arr,vector<vector<int>>&dp,int target){

    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            if(i==0 and j==0){
                dp[i][j]=true;
            }else if(i==0){
                dp[i][j]=false;
            }else if(j==0){
                dp[i][j]=true;
            }else{
                if(dp[i-1][j]==true){
                    dp[i][j]=true;
                }else{
                    int val=arr[i-1];
                    if(j>=val && dp[i-1][j-val]==true){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=false;
                    }
                }
            }
        }
    }
    return dp[dp.size()-1][dp[0].size()-1];
}

int main(){

    int n;
    cout<<"enter n"<<endl ;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter array elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;

    vector<vector<int>>dp(arr.size()+1,vector<int>(target+1));

    cout<<TargetSumSubset(arr,dp,target);

}

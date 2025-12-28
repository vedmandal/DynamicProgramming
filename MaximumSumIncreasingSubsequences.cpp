/* you are given a number n,representing the number of elements

2. you are given n nubers ,represnting the content of array of length n

3. you are required to print to print the sum of elements of the increasing subsequence of array with maximum sum for the array


*/



#include<iostream>
#include<vector>

using namespace std;


void  MaximumSumLis(vector<int>&arr,vector<int>&dp){
    int ans=arr[0];

    for(int i=0;i<dp.size();i++){
       dp[i]=arr[i];
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
               dp[i]=max(dp[i],dp[j]+arr[i]);

            }
        }
        
        if(dp[i]>ans){
            ans=dp[i];
        }
    }
    cout<<ans<<endl; 
}

int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp(n);

    MaximumSumLis(arr,dp);
}
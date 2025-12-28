
/* you are given a number n,representing the number of elements

2. you are given n nubers ,represnting the content of array of length n

3. you are required to print to print the length of longest increasing subsequence of array

*/





#include<iostream>
#include<vector>

using namespace std;

void Lis(vector<int>&arr,vector<int>&dp){

   
    int ans=0;

    for(int i=0;i<dp.size();i++){
        int maxi=0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                maxi=max(maxi,dp[j]);
            }
        }
        dp[i]=maxi+1;
        ans=max(ans,dp[i]);
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

    Lis(arr,dp);
}
/*
1. you are given an array og length n which represnets N number of ballons .
2. each ballon is painted with a minimum on it.
3. you have to collect maximum coins by bursting all the ballons.
4. if you burst a ballon with index i, you will get (arr[i-1]*arr[i]*arr[i+1]) number of coins.
5. if arr[i-1] and arr[i+1] dont exist then you may assume their value as 1.


*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;


void BurstBallons(vector<int>&arr){
    vector<vector<int>>dp(arr.size(),vector<int>(arr.size()));

    for(int g=0;g<dp.size();g++){
        for(int i=0,j=g;j<dp.size();i++,j++){
            int maxi=INT_MIN;

            for(int k=i;k<=j;k++){
                int left=k==i?0:dp[i][k-1];
                int right=k==j?0:dp[k+1][j];
                int kthval=(i==0?1:arr[i-1])*arr[k]*(j==dp.size()-1?1:arr[j+1]);
               if(left+right+kthval>maxi){
                maxi=left+right+kthval;

               }

            }
            dp[i][j]=maxi;
        }
    }
    cout<<dp[0][dp.size()-1];
}
int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter array"<<endl;
    for(int i=0;i<arr.size();i++){
        cin>>arr[i];
    }

    BurstBallons(arr);


}
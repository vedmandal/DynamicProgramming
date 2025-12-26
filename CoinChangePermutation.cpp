/*
1. you are given a number n, reprenting the count of coins.
2. you are given n number representing the denomination of n coins.
3. you are given number "amt"
4. you are required to calculate adn print hte number of permuation of n coins  which the amount "amt" can be paid.

note1:- you have infinite supply of each coin denominatination that is same coin denomination can be used for many installments in payments of amt.

note 2:- you are required to find the count of permutation and not combination  that is 2+2+3=7 and 2+3+2=7 and 3+2+2=7 are different permuations of same combination. you shoild treat them as3 and not 1.

*/

#include<iostream>
#include<vector>

using namespace std;

 int CoinChangePermutation(vector<int>&arr,vector<int>&dp){
    dp[0]=1;
    for(int i=1;i<dp.size();i++){
        for(int j=0;j<arr.size();j++){
            if(arr[j]<=i){
                dp[i]+=dp[i-arr[j]];
            }
        }
    }
    return dp[dp.size()-1];
 }

int main(){

int n;
cout<<"enter n"<<endl;
cin>>n;
vector<int>arr(n);
cout<<"Enter array"<<endl;
for(int i=0;i<arr.size();i++){
    cin>>arr[i];
}
int amt;
cout<<"Enter amt"<<endl;
cin>>amt;

vector<int>dp(amt+1,0);
cout<<CoinChangePermutation(arr,dp);

}
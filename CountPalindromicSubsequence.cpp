/*
1. you are given a string str;
2. you are required to print the count of plaindromic subsequence in the given string


*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;



void CountPalindromicSubsequence(string &str){

    vector<vector<int>>dp(str.size(),vector<int>(str.size()));

    for(int g=0;g<dp.size();g++){
        for(int i=0,j=g;j<dp.size();i++,j++){

            if(g==0){
                dp[i][j]=1;
            }else if(g==1){
                dp[i][j]=str[i]==str[j]?3:2;

            }else{
                if(str[i]==str[j]){
                    dp[i][j]=1+ dp[i][j-1]+dp[i+1][j];

                }else{
                    dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];

                }
            }
        }
    }
    cout<<dp[0][dp.size()-1];
}


int main(){

    string str;
    cout<<"Enter string"<<endl;
    cin>>str;

    CountPalindromicSubsequence(str);
}
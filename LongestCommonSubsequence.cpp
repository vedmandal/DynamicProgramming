
/*
1. you are given a string s1.
2. you are given a string s2.
3. you are rquired to print the length of longest common subsequence of two strings.

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void LongestCommonSubsequence(string &s1,string &s2){

    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));

    for(int i=dp.size()-2;i>=0;i--){
        for(int j=dp[0].size()-2;j>=0;j--){
           char c1=s1[i];
           char c2=s2[j];

           if(c1==c2){
            dp[i][j]=1+dp[i+1][j+1];
           }else{
            dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
           }


        }
    }
    cout<<dp[0][0]<<endl;
}


int main(){
    string s1,s2;
    cout<<"Enter two strings"<<endl;
    cin>>s1>>s2;

    LongestCommonSubsequence(s1,s2);
}
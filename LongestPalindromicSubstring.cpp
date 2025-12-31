/*
1. you are given an string str.
2. you are required to print the length of longest palindromic subsequence of the given str.

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;



  void  LongestPalindromicSubstring(string &str){
       int len=0;
      vector<vector<bool>>dp(str.size(),vector<bool>(str.size()));
      for(int g=0;g<dp.size();g++){
        for(int i=0,j=g;j<dp.size();i++,j++){
            if(g==0){
                dp[i][j]=true;
            }else if(g==1){
                dp[i][j]=str[i]==str[j]?true:false;
            }else{
                if(str[i]==str[j] and dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }
            }
            if(dp[i][j]==true){
                len=g+1;
            }
        }
      }
      cout<<len<<endl;
  }



int main(){
    string str;
    cout<<"Enter string"<<endl;
    cin>>str;

    LongestPalindromicSubstring(str);
}
/*
1. you are given two string s1 and s2.
2. you are required to print the length of the longest common substring of two strings.

*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

  void LongestCommonSubstring(string &s1,string &s2){

    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
    
     int len=0;
    for(int i=1;i<dp.size();i++){
        for(int j=1;j<dp[0].size();j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=dp[i-1][j-1] +1;
            }else{
                dp[i][j]=0;
            }

            if(dp[i][j]>len){
                len=dp[i][j];
            }
        }
    }
    cout<<len<<endl;
  }

int main(){
    string s1,s2;
    cout<<"Enter s1 ad s2"<<endl;
    cin>>s1>>s2;

    LongestCommonSubstring(s1,s2);
}
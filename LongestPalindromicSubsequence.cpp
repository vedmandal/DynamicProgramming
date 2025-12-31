/*
you are are given a string str.
you are required to print the longest palindromic subsequence of string.

*/


#include<iostream>
#include<string>
#include<vector>

using namespace std;

void  LongestPalindrmicSubsequence(string &str){

    vector<vector<int>>dp(str.size(),vector<int>(str.size()));


    for(int g=0;g<dp.size();g++){
        for(int i=0,j=g;j<dp.size();i++,j++){
            if(g==0){
                dp[i][j]=1;

            }else if(g==1){
                dp[i][j]=str[i]==str[j]?2:1;

            }else{
                if(str[i]==str[j]){
                    dp[i][j]=2+dp[i+1][j-1];

                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i+1][j]);

                }

            }
        }
    }
    cout<<dp[0][dp.size()-1];
}


int main(){
    string str;
    cout<<"Enter a string"<<endl;
    cin>>str;

    LongestPalindrmicSubsequence(str);

}
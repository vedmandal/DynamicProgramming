/*

you are given a string str you are required to print the count of palindromic substring from the given string.


*/


#include<iostream>
#include<vector>
#include<string>

using namespace std;



  void  CountPalindromicSubstring(string &str){
       int c=0;
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
                c++;
            }
        }
      }
      cout<<c<<endl;
  }



int main(){
    string str;
    cout<<"Enter string"<<endl;
    cin>>str;

    CountPalindromicSubstring(str);
}
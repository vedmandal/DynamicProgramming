/*

1. you are given a string.
2. you have to find the minimum number of cuts required to convert the given string into palindromic partition.
3.partinoning of the string is a palndromic partioning if every substring of the partition is a palindrome.

*/

#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

//n3 time complexcity
void  MinimumPalindromeCut(string &str){

    vector<vector<bool>>dp(str.length(),vector<bool>(str.length()));


    for(int g=0;g<dp.size();g++){
        for(int i=0,j=g;j<dp.size();i++,j++){
            if(g==0){
                dp[i][j]=true;
            }else if(g==1){
                if(str[i]==str[j]){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }
            }else{
                if(str[i]==str[j] and dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }

            }
        }
    }

     vector<vector<int>>dpstr(str.length(),vector<int>(str.length()));



    for(int g=0;g<dp.size();g++){
        for(int i=0,j=g;j<dp.size();i++,j++){
            if(g==0){
                dpstr[i][j]=0;
            }else if(g==1){
                dpstr[i][j]=str[i]==str[j]?0:1;
            }else{
               

                if(dp[i][j]==true){
                    dpstr[i][j]=0;
                }else{
                    dpstr[i][j]=INT_MAX;
                    for(int k=i;k<j;k++){
                        int l=dpstr[i][k];
                        int r=dpstr[k+1][j];
                        dpstr[i][j]=min(dpstr[i][j],l+r+1);
                    }
                }

            }
        }
    }

    cout<<dpstr[0][dp.size()-1];



}


 // n2 time complecity
 void  MinimumPalindromeCutAnother(string &str){

    vector<vector<bool>>dp(str.length(),vector<bool>(str.length()));


    for(int g=0;g<dp.size();g++){
        for(int i=0,j=g;j<dp.size();i++,j++){
            if(g==0){
                dp[i][j]=true;
            }else if(g==1){
                if(str[i]==str[j]){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }
            }else{
                if(str[i]==str[j] and dp[i+1][j-1]==true){
                    dp[i][j]=true;
                }else{
                    dp[i][j]=false;
                }

            }
        }
    }


    vector<int>dpstr(str.size());


    dpstr[0]=0;
    for(int j=1;j<str.size();j++){
        if(dp[0][j]){
            dpstr[j]=0;
        }else{
            int mini=INT_MAX;
            for(int i=j;i>=1;i--){
                if(dp[i][j]==true and dpstr[i-1]<mini){
                    mini=dpstr[i-1];
                }
            }
             dpstr[j]=mini+1;

        }
       
    }
    cout<<dpstr[dpstr.size()-1];


 }



int main(){
    string str;
    cout<<"Enter a string"<<endl;
    cin>>str;

    MinimumPalindromeCut(str);

}
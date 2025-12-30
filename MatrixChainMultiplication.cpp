/*
1. you are given an array of positive integer of length N which represnts the dimensions of N-1 matrices such that ith matrix is of dimension arr[i-1]*arr[i].
2. you have to find the minimum number of multiplication needed to multiply  the given chain  of matrices. 

*/


#include <iostream>
#include<vector>
#include<climits>
using namespace std;



void MatrixChainMultiplication(vector<int>&arr){

    vector<vector<int>>dp(arr.size()-1,vector<int>(arr.size()-1));

    for(int g=0;g<dp.size();g++){
        for(int i=0,j= g ;j<dp.size();i++,j++){
            if(g==0){
                dp[i][j]=0;
            }else if(g==1){
                dp[i][j]=arr[i]*arr[j]*arr[j+1];
            }else{
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int lc=dp[i][k];
                    int rc=dp[k+1][j];
                    int mc=arr[i]*arr[k+1]*arr[j+1];
                    if(lc+rc+mc<mini){
                        mini=lc+rc+mc;
                    }
                }
                dp[i][j]=mini;
            }

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
for(int i=0;i<n;i++){
    cin>>arr[i];
}

MatrixChainMultiplication(arr);
}


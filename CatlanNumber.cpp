/*

1. you are given a number n.
2. you are required to find the value of nth catlan number.
  c0=1;
  c1=1;
  c2->2;
  c3->5
  c4=c0*c3+c1*c2+c2*c1+c3*c0;

*/


#include<iostream>
#include<vector>
using namespace std;


void CatlanNumber(vector<int>&dp){
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<dp.size();i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    cout<<dp[dp.size()-1];
}


int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    vector<int>dp(n+1);
    CatlanNumber(dp);
}
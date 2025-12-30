/*
1. you are given an integer N ,which represents the length of a rod,and an  array of integer which represent prices of rod pieces of vaying from 1 ton.
2. you have to find the maximum value that can be obtained by selling the rod.
3. you can sell it in pieces or as a whole.

*/





#include<iostream>
#include<vector>
using namespace std;

void RodCuttinBYLeftAndRightStrategy(vector<int>&prices){


    vector<int>newprices(prices.size()+1);
    for(int i=1;i<newprices.size();i++){
        newprices[i]=prices[i-1];
    }

    vector<int>dp(prices.size()+1);
    dp[0]=0;
    dp[1]=newprices[1];

    for(int i=2;i<dp.size();i++){
        dp[i]=newprices[i];
        int l=1;
        int r=i-1;
        while(l<=r){
            dp[i]=max(dp[i],dp[l]+dp[r]);

             l++;
              r--;

        }
       
    }
    cout<<dp[dp.size()-1];
}

void RodCuttingByCutStrategy(vector<int>&prices)
{
    vector<int>newprices(prices.size()+1);
    for(int i=1;i<newprices.size();i++){
        newprices[i]=prices[i-1];
    }

    vector<int>dp(prices.size()+1);
    dp[0]=0;
    dp[1]=newprices[1];
    for(int i=2;i<dp.size();i++){
        dp[i]=newprices[i];

        for(int cut=1;cut<i;cut++){
            dp[i]=max(dp[i],newprices[cut]+dp[i-cut]);
        }
    }
    cout<<dp[dp.size()-1];
}


int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    vector<int>prices(n);
   cout<<"Enter prices array"<<endl;

   for(int i=0;i<n;i++){
    cin>>prices[i];
   }


   RodCuttinBYLeftAndRightStrategy(prices);

}
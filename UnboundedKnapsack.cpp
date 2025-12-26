/*
1. you are given a number n ,representing the count of items.
2. you are given n numbers,represnting the values of n items.
3. you are given n numbers, representing the weight of n items.
4. you are given a number "cap" which is the capacity of a bag.
5. you are required to calculate and print the maximum value that can be created in the bag without overflowing its capacity.
not1-> each item can taken any number of items,you are  allowed to put the same item again and again*/

#include<iostream>
#include<vector>
using namespace std;


int UnboundedKnapsack(vector<int>&weight,vector<int>&value,vector<int>&dp){

   dp[0]=0;

   for(int i=1;i<dp.size();i++){
    int maxi=0;
     for(int j=0;j<weight.size();j++){
        
        if(weight[j]<=i){
           
            maxi=max(maxi,dp[i-weight[j]]+value[j]);

         
        }
     }
     dp[i]=maxi;
    
   }
   return dp[dp.size()-1];



}



int main(){

    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    vector<int>weight(n);
    vector<int>value(n);

    cout<<"Enter weights"<<endl;
    for(int i=0;i<weight.size();i++){
        cin>>weight[i];
    }
    cout<<"enter value"<<endl;
    for(int i=0;i<value.size();i++){
        cin>>value[i];
    }

    int cap;
    cout<<"Enter capacity"<<endl;
    cin>>cap;

    vector<int>dp(cap+1,0);

    cout<<UnboundedKnapsack(weight,value,dp);

}



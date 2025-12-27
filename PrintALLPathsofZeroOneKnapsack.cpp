/*
1. you are given a number n ,representing the count of items.
2. you are given n numbers,represnting the values of n items.
3. you are given n numbers, representing the weight of n items.
4. you are given a number "cap" which is the capacity of a bag.
5. you have to print all index of items .
6. print all paths.
not1-> each item can taken as 0 or 1 number of items,you are not allowed to put the same item again and again.


*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class pairs{
    public:
    int i;
    int j;
    string path;
    pairs(int i,int j,string path){
        this->i=i;
        this->j=j;
        this->path=path;
    }
};


void  PrintAllPathZeroOneKnapsack(vector<int>&weight,vector<int>&value,vector<vector<int>>&dp){

    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }else{
                if(j>=weight[i-1] and dp[i-1][j-weight[i-1]]+value[i-1]>dp[i-1][j]){
                    dp[i][j]=dp[i-1][j-weight[i-1]]+value[i-1];
                }else{
                   dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    cout<<dp[dp.size()-1][dp[0].size()-1];

    queue<pairs>q;
    q.push({dp.size()-1,dp[0].size()-1,""});

    while(!q.empty()){

        pairs rem=q.front();

        q.pop();
        if (rem.i == 0 || rem.j == 0) {
       cout << rem.path << endl;
        continue;
        }


    
    if (dp[rem.i][rem.j] == dp[rem.i-1][rem.j]) {
        q.push({rem.i-1, rem.j, rem.path});
    }
        
    if (rem.j >= weight[rem.i-1] &&
        dp[rem.i][rem.j] ==
        dp[rem.i-1][rem.j-weight[rem.i-1]] + value[rem.i-1]) {

        q.push({
            rem.i-1,
            rem.j-weight[rem.i-1],
            to_string(rem.i-1) + " " + rem.path
        });
        }



    }
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

    vector<vector<int>>dp(n+1,vector<int>(cap+1));

    PrintAllPathZeroOneKnapsack(weight,value,dp);

}
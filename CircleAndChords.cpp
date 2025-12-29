/*

1.you are given an number N

2. there 2*n points on a circle. you have to draw N non intersecting chords in a circle.
3. you have to find the number of ways in which these chords can be drawn.
*/


#include<iostream>
#include<vector>
using namespace std;


void CircleAndChords(vector<int>&dp){
      
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
    CircleAndChords(dp);
}
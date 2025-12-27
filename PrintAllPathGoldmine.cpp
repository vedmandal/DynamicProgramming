/* 1. you are given a number n ,represnting the number of rows
   2. you are given m ,representing number of colums.
   3. you are m*n 2d array represnting goldmines.
   4.you are standing on the left wall and supposed to dig to the right wall.you can start from any row from the left wall.
   5.you are allowed to move 1 cell up(d1),1 cell right(d2),1cell down(d3)
   6.print all paths using d1 d2 d3
*/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

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

void  PrintAllPathCollectMaxGold(vector<vector<int>>&arr,vector<vector<int>>&dp){

    for(int j=dp[0].size()-1;j>=0;j--){
        for(int i=0;i<dp.size();i++){
            if(j==dp[0].size()-1){
                dp[i][j]=arr[i][j];

            }else if(i==0){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i+1][j+1]);

            }else if(i==dp.size()-1){
                dp[i][j]=arr[i][j]+max(dp[i][j+1],dp[i-1][j+1]);

            }else{
                dp[i][j]=arr[i][j]+max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1]));

            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0;i<dp.size();i++){
        maxi=max(maxi,dp[i][0]);
    }

    cout<<maxi<<endl;

    queue<pairs>q;

    for(int i=0;i<dp.size();i++){
        if(dp[i][0]==maxi){
            q.push({i,0,to_string(i)+"->"});
        }
    }

    while(!q.empty()){

        pairs rem =q.front();
        
        q.pop();

        if(rem.j==dp[0].size()-1){
            cout<<rem.path<<endl;
        }else if(rem.i==0){
           int maxi=max(dp[rem.i][rem.j+1],dp[rem.i+1][rem.j+1]);

           if(maxi==dp[rem.i][rem.j+1]){
            q.push({rem.i,rem.j+1,rem.path+"d2"});
           }
           if(maxi==dp[rem.i+1][rem.j+1]){
            q.push({rem.i+1,rem.j+1,rem.path+"d3"});
           }

          

        }else if(rem.i==dp.size()-1){
             int maxi=max(dp[rem.i][rem.j+1],dp[rem.i-1][rem.j+1]);
             
              if(maxi==dp[rem.i][rem.j+1]){
                   q.push({rem.i,rem.j+1,rem.path+"d2"});
               }

                if(maxi==dp[rem.i-1][rem.j+1]){
                   q.push({rem.i-1,rem.j+1,rem.path+"d1"});
                 }

        }else{
             int maxi=max(dp[rem.i][rem.j+1],max(dp[rem.i-1][rem.j+1],dp[rem.i+1][rem.j+1]));
             if(maxi==dp[rem.i][rem.j+1]){
                   q.push({rem.i,rem.j+1,rem.path+"d2"});
               }

                if(maxi==dp[rem.i-1][rem.j+1]){
                   q.push({rem.i-1,rem.j+1,rem.path+"d1"});
                 }
                 if(maxi==dp[rem.i+1][rem.j+1]){
                q.push({rem.i+1,rem.j+1,rem.path+"d3"});
                 }


        }

       


    }




}




int main(){
    int r,c;
    cout<<"Enter row"<<endl;
    cin>>r;
    cout<<"Enter col"<<endl;
    cin>>c;

    vector<vector<int>>arr(r,vector<int>(c));
   
    cout << "Enter gold mine matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>>dp(r,vector<int>(c));

    PrintAllPathCollectMaxGold(arr,dp);
}
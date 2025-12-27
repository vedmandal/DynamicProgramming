/* you are given an array matrix from a cell either you can go tho horizotal or vertical you have to find minmum cost to reach last cell  and print all paths to reach you h for horizontal and v for vertical for printing*/


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

void Print_All_Minimum_Cost_path(vector<vector<int>>&arr,vector<vector<int>>&dp){
    

    for(int i=dp.size()-1;i>=0;i--){
        for(int j=dp[0].size()-1;j>=0;j--){
            if(i==dp.size()-1 && j==dp[0].size()-1){
                dp[i][j]=arr[i][j];
            }else if(i==dp.size()-1){
                dp[i][j]=dp[i][j+1]+arr[i][j];
            }else if(j==dp[0].size()-1){
                dp[i][j]=arr[i][j]+dp[i+1][j];
            }else{
                dp[i][j]=arr[i][j]+min(dp[i][j+1],dp[i+1][j]);
            }
        }
    }
    cout<<dp[0][0]<<endl;

    queue<pairs>q;
    q.push(pairs(0,0,""));

    while(q.size()!=0){
        pairs rem=q.front();

        q.pop();

        if(rem.i==dp.size()-1 and rem.j==dp[0].size()-1){
            cout<<rem.path<<endl;
        }else if(rem.i==dp.size()-1){
              q.push({rem.i,rem.j+1,rem.path+"H"});

        }else if(rem.j==dp[0].size()-1){
             q.push({rem.i+1,rem.j,rem.path+"v"});

        }else{

            if(dp[rem.i][rem.j+1]<dp[rem.i+1][rem.j]){
                q.push({rem.i,rem.j+1,rem.path+"H"});
            }else if(dp[rem.i][rem.j+1]>dp[rem.i+1][rem.j]){
                q.push({rem.i+1,rem.j,rem.path+"v"});
            }else{
                q.push({rem.i,rem.j+1,rem.path+"H"});
                 q.push({rem.i+1,rem.j,rem.path+"v"});

            }

        }
    }

}

int main(){
    int r,c;
    cout<<"Enter row";
    cin>>r;
    cout<<"Enter column";
    cin>>c;

    vector<vector<int>>arr(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>dp(r,vector<int>(c));
     Print_All_Minimum_Cost_path(arr,dp);


}
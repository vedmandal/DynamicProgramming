 /* 1. you are given a number n ,reprenting count of elements
     2.  you are given n number and target number;
     3. check true or false if there is subsets of elements of which add upto target or not"
     4. print all path means indexes of subsets with the target sum

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

void PrintAllTargetSumSubset(vector<int>&arr,vector<vector<int>>&dp,int target){

    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            if(i==0 and j==0){
                dp[i][j]=true;
            }else if(i==0){
                dp[i][j]=false;
            }else if(j==0){
                dp[i][j]=true;
            }else{
                if(dp[i-1][j]==true){
                    dp[i][j]=true;
                }else{

                    int val=arr[i-1];
                    if(val<=j  && dp[i-1][j-val]==true){
                        dp[i][j]=true;
                        
                    }else{
                        dp[i][j]=false;
                    }
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

    if(rem.i==0 and  rem.j==0){
        cout<<rem.path<<endl;
        continue;
    }else{
        if(dp[rem.i-1][rem.j]==true){
            q.push({rem.i-1,rem.j,rem.path});
         }
      
            
            if(arr[rem.i-1]<=rem.j and dp[rem.i-1][rem.j-arr[rem.i-1]]==true){
                q.push({rem.i-1,rem.j-arr[rem.i-1],rem.path+' '+to_string(rem.i-1)});

            }
        }

    }
     

    }
   
   



int main(){

    int n;
    cout<<"enter n"<<endl ;
    cin>>n;
    vector<int>arr(n);
    cout<<"enter array elements";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter target"<<endl;
    cin>>target;

    vector<vector<int>>dp(arr.size()+1,vector<int>(target+1));

    PrintAllTargetSumSubset(arr,dp,target);

}

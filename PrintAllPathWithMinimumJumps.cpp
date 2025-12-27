/*
1)a number represinting "MINIMUM JUMPS" need from 0 step to reach (n-1)th step.
2)string representing configuration of minimum jump
*/


#include<iostream>
#include<vector>
#include<queue>
#include <climits>

using namespace std;

class pairs{
    public:
    int index;
    int size;
    int jump;
    string path;
    pairs(int i,int s,int j,string p){
        this->index=i;
        this->size=s;
        this->jump=j;
        this->path=p;
    }
};

void print_all_path_with_minimum_jumps(vector<int>&arr){
    vector<int>dp(arr.size(),INT_MAX);
    dp[dp.size()-1]=0;
    for(int i=dp.size()-2;i>=0;i--){
        int mi=INT_MAX;
        for(int j=1;j<=arr[i] and i+j<dp.size();j++){
            if(dp[i+j]!=INT_MAX && dp[i+j]<mi){
                mi=dp[i+j];
            }

        }
        if(mi!=INT_MAX){
            dp[i]=mi+1;
        }
    }
    cout<<dp[0];
    queue<pairs>q;
    q.push(pairs(0,arr[0],dp[0],to_string(0)+""));

    while(q.size()!=0){

        pairs rem=q.front();

        q.pop();

        if(rem.jump==0){
            cout<<rem.path<<endl;

        }

        for(int j=1;j<=rem.size && rem.index+j<dp.size();j++){
            int ci=rem.index+j;
            if(dp[ci]!=INT_MAX && dp[ci]==rem.jump-1){
                q.push(pairs(ci,arr[ci],dp[ci],rem.path+"->"+to_string(ci)));
            }

        }
    }


}

int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;

    vector<int>arr(n);

    cout<<"enter array elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    print_all_path_with_minimum_jumps(arr);

}
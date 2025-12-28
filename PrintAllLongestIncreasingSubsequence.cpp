
/* you are given a number n,representing the number of elements

2. you are given n nubers ,represnting the content of array of length n

3. you are required to print to print the length of longest increasing subsequence of array

4. print all path of lis.
*/



#include<iostream>
#include<vector>
#include<queue>




using namespace std;


class pairs{
    public:


    int l;
    int i;
    int v;
    string path;

    pairs(int l,int i,int v,string path){
        this->l=l;
        this->i=i;
        this->v=v;
        this->path=path;
    }
};

void Lis(vector<int>&arr,vector<int>&dp)
{
 int ans=0;
 int aidx=0;
 for(int i=0;i<dp.size();i++)
 {
    int maxi=0;
    for(int j=i-1;j>=0;j--){
        if(arr[j]<arr[i]){
         maxi=max(maxi,dp[j]);

        }

    }
    dp[i]=maxi+1;
    if(dp[i]>ans){
        ans=dp[i];
        aidx=i;
    }


 }
 cout<<ans<<endl;

    queue<pairs>q;
    q.push({ans,aidx,arr[aidx],to_string(arr[aidx])+" "});

    while(!q.empty()){

        pairs rem=q.front();
        q.pop();


        if(rem.l==1){
            cout<<rem.path<<endl;
        }

        for(int j=rem.i-1;j>=0;j--){
            if(dp[j]==rem.l-1 and arr[j]<rem.v){
                q.push({dp[j],j,arr[j],to_string(arr[j])+"->"+rem.path});
            }
        }
    }





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
    vector<int>dp(n);

    Lis(arr,dp);
}
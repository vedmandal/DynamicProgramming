/* you are given a number n,representing the number of elements

2. you are given n nubers ,represnting the content of array of length n

3.you are required to print the length of longest biotonic subsequences of array means first increase then decrease;

not:- bitonic subsequences begins with elements in increasing order ,follwed by elelments  in decresing order
*/


#include<iostream>
#include<vector>

using namespace std;

void  LongestBiotonicSubseqence(vector<int>&arr){

      vector<int>lisdp(arr.size());
     
      for(int i=0;i<lisdp.size();i++){
        int maxi=0;
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                maxi=max(maxi,lisdp[j]);

            }
        }
        lisdp[i]=maxi+1;
        
      }
    
    vector<int>ldsdp(arr.size());


      for(int i=ldsdp.size()-1;i>=0;i--){
        int maxi=0;
          for(int j=ldsdp.size()-1;j>i;j--){
            if(arr[j]<arr[i]){
                maxi=max(maxi,ldsdp[j]);
            }
          }
          ldsdp[i]=maxi+1;
      }

      int ans=0;

      for(int i=0;i<arr.size();i++){
        if(ldsdp[i]+lisdp[i]-1>ans){
            ans=ldsdp[i]+lisdp[i]-1;
        }
      }

      cout<<ans<<endl;
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
   

    LongestBiotonicSubseqence(arr);
}

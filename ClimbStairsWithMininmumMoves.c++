/*
1. you are given a number n ,representing no of stairs in a staircase.
2.you are on the ith step ,and required to climb to top.
3. you are given n number , where ith value representh till how far from the you can jump in a single move.
4. you are required to print the number of minimum moves in which you can reach to top of staircase.
5. if there are no path from the staircase print null

*/

#include<iostream>
#include<vector>
#include <climits>
using namespace std;


// using normal recursion

int minMoves(int idx, int n, vector<int>& jumps) {
    // reached the top
    if (idx == n) {
        return 0;
    }

    // crossed the top
    if (idx > n) {
        return INT_MAX;
    }

    int ans = INT_MAX;

    // try all possible jumps from this stair
    for (int jump = 1; jump <= jumps[idx] && idx + jump <= n; jump++) {
        int next = minMoves(idx + jump, n, jumps);

        if (next != INT_MAX) {
            ans = min(ans, next + 1);
        }
    }

    return ans;
}

int main() {
    int n = 10;

    vector<int> jumps;
    jumps.push_back(3);
    jumps.push_back(2);
    jumps.push_back(4);
    jumps.push_back(2);
    jumps.push_back(INT_MAX);
    jumps.push_back(2);
    jumps.push_back(3);
    jumps.push_back(1);
    jumps.push_back(2);
    jumps.push_back(2);

    int result = minMoves(0, n, jumps);

    if (result == INT_MAX) {
        cout << "null";
    } else {
        cout << result;
    }
}


// using memorization



int minMoves(int idx, int n, vector<int>& jumps, vector<int>& dp) {
    // reached top
    if (idx == n) {
        return 0;
    }

    // crossed top
    if (idx > n) {
        return INT_MAX;
    }

    // already computed
    if (dp[idx] != INT_MAX) {
        return dp[idx];
    }

    int ans = INT_MAX;

    for (int jump = 1; jump <= jumps[idx] && idx + jump <= n; jump++) {
        int next = minMoves(idx + jump, n, jumps, dp);

        if (next != INT_MAX) {
            ans = min(ans, next + 1);
        }
    }

    dp[idx] = ans;
    return ans;
}

int main() {
    int n = 10;

    vector<int> jumps;
    jumps.push_back(3);
    jumps.push_back(2);
    jumps.push_back(4);
    jumps.push_back(2);
    jumps.push_back(INT_MAX);
    jumps.push_back(2);
    jumps.push_back(3);
    jumps.push_back(1);
    jumps.push_back(2);
    jumps.push_back(2);

    vector<int> dp(n + 1, INT_MAX);

    int result = minMoves(0, n, jumps, dp);

    if (result == INT_MAX) {
        cout << "null";
    } else {
        cout << result;
    }
}


// using tabulation

int main(){
    int n=10;

    vector<int>jumps;
    jumps.push_back(3);
    jumps.push_back(2);
    jumps.push_back(4);
    jumps.push_back(2);
    jumps.push_back(INT_MAX);
    jumps.push_back(2);
    jumps.push_back(3);
    jumps.push_back(1);
    jumps.push_back(2);
    jumps.push_back(2);

    vector<int>dp(n+1,INT_MAX);
    dp[n]=0;

    for(int i=n-1;i>=0;i--){
        for(int jump=1;jump<=jumps[i] and i+jump<=n;jump++){
            if(dp[i+jump]!=INT_MAX){
                 dp[i]=min(dp[i],dp[i+jump]+1);

            }
           
        }
    }
    if(dp[0]==INT_MAX){
        cout<<"null";
    }else{
        cout<<dp[0];

    }
  


}
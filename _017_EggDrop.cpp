/*
https://leetcode.com/problems/super-egg-drop/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[105][10005];
    int solve(int k,int n){
        if (n == 0 || n == 1 || k == 1) {
            return n;
        }
        
        if (dp[k][n] != -1){
            return dp[k][n];
        }
        
        int ans = INT_MAX;
        for (int i=1;i<=n;i++){
            ans = min(ans, max(solve(k-1, i-1), solve(k, n-i)) + 1);
        }
        return dp[k][n] = ans;
    }
    
    int solvedp(int k,int n){
        vector<vector<int>> dp(105,vector<int>(10005,1e9));
        for (int i=1;i<=k;i++){
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        for (int i=1;i<=n;i++){
            dp[1][i] = i;
        }
        for (int i=2;i<=k;i++){
            for (int j=2;j<=n;j++){
                for (int x=1;x<=j;x++){
                    dp[i][j] = min(dp[i][j], max(dp[i][j-x], dp[i-1][x-1]) + 1);
                }
            }
        }
        return dp[k][n];
    }
    
    // O(K*N^2)
    int superEggDrop(int K, int N) {
        memset(dp,-1,sizeof(dp));
        return solvedp(K,N);
    }
};

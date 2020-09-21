/*
https://leetcode.com/problems/min-cost-climbing-stairs/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
public:
    int dp[1001];
    int go (int pos, vector<int> &cost) {
        if (pos >= n) {
            return 0;
        }
        if (dp[pos] != -1) {
            return dp[pos];
        }
        int ans = INT_MAX;
        int op1 = go (pos+1, cost) + cost[pos];
        int op2 = go (pos+2, cost) + cost[pos];
        
        ans = min(ans, op1);
        ans = min(ans, op2);
        return dp[pos] = ans;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        this->n = (int)cost.size();
        memset(dp,-1,sizeof dp);
        int ans1 = go (0, cost);
        memset(dp,-1,sizeof dp);
        int ans2 = go (1, cost);
        return (min(ans1,ans2));
    }
};

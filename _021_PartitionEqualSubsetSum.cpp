/*
https://leetcode.com/problems/partition-equal-subset-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int idx, int cs , int total, vector<int> &nums, vector<vector<int>> &dp){
        if (cs*2 == total){
            return true;
        }
        
        if (dp[idx][cs] != -1){
            return dp[idx][cs];
        }
        
        if (cs > total/2 || idx >= nums.size()){
            return false;
        }
        
        return dp[idx][cs] = solve(idx+1, cs, total, nums, dp) || solve(idx+1, cs+nums[idx], total, nums, dp);
    }
    
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 0) return false;
        vector<vector<int>> dp(205,vector<int>(20005,-1));
        int total = 0;
        for (auto num:nums) total += num;
        if (total&1){
            return false;
        }
        return solve(0,0,total,nums,dp);
    }
};

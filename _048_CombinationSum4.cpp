/*
https://leetcode.com/problems/combination-sum-iv/
*/


class Solution {
    int n;
public:
    unordered_map<int,int> dp;
    int go (int target, vector<int> &nums) {
        if (target == 0) {
            return 1;
        }
        if (target < 0) {
            return 0;
        }
        
        if (dp.find(target) != dp.end()) {
            return dp[target];
        }
        int ans = 0;
        for (int i=0;i<n;i++) {
            ans += go (target-nums[i], nums);
        }
        return dp[target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        this->n = nums.size();
        int ans = go (target, nums);
        return ans;
    }
};

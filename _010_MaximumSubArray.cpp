/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

https://leetcode.com/problems/maximum-subarray/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // space optimized
    int maxSubArraySO(vector<int> &nums){
        int csum = 0;
        int mxSoFar = INT_MIN;
        for (int i=0;i<nums.size();i++){
            csum += nums[i];
            if (csum > mxSoFar) mxSoFar = csum;
            if (csum < 0) csum = 0;
        }
        return mxSoFar;
    }
    
    // O(n)
    int maxSubArrayDP(vector<int> &nums){
        int n = (int)nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int maxSoFar = dp[0];
        for (int i=1;i<n;i++){
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            if (dp[i] > maxSoFar) maxSoFar = dp[i];
        }
        return maxSoFar;
    }
    
    int maxSubArray(vector<int>& nums) {
        int res1 = maxSubArraySO(nums);
        //int res2 = maxSubArrayDP(nums);
        return res1;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    int res = s.maxSubArray(nums);
    cout << res << "\n";
}

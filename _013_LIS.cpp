/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence 
such that all elements of the subsequence are sorted in increasing order. 
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.


https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) return 0;
        vector<int> dp(n,1);
        int mx = 1;
        for (int j=1;j<n;j++){
            for (int i=0;i<j;i++){
                if (nums[i] < nums[j]){
                    dp[j] = max(dp[j], dp[i]+1);
                    mx = max(mx, dp[j]);
                }
            }
        }
        return mx;
    }
};

int main(){
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    Solution s;
    int ans = s.lengthOfLIS(nums);
    cout << ans << "\n";
}

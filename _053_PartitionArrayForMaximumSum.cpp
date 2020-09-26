/*
https://leetcode.com/problems/partition-array-for-maximum-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n,k;
public:
    vector<int> tree;
    
    int rangeQ(int start,int end,int i,int j,int index) {
        if (start >= i and end <= j) {
            return tree[index];
        }
        if (start > j or end < i) {
            return -1;
        }
        int mid = start + (end - start)/2;
        int left = rangeQ(start,mid,i,j,2*index);
        int right = rangeQ(mid+1,end,i,j,2*index+1);
        return max(left,right);
    }
    
    int dp[501];
    int go (int pos, vector<int> &nums) {
        if (pos >= n ) {
            return 0;
        }
        if (dp[pos] != -1) {
            return dp[pos];
        }
        int ans = INT_MIN;
        for (int x = 0;x<=k;x++) {
            if (pos + x - 1 < n) {
                int nextPos = pos + x;
                if (x == 0) nextPos = pos + 1;
                ans = max(ans, go (nextPos, nums) + (x * rangeQ(0,n-1,pos,pos+x-1,1)));
            }
        }
        return dp[pos] = ans;
    }
    
    int buildTree(int start,int end,int index,vector<int> &nums) {
        if (start == end) {
            tree[index] = nums[start];
            return tree[index];
        }
        
        int mid = start + (end - start)/2;
        int left = buildTree(start, mid, 2*index, nums);
        int right = buildTree(mid+1, end, 2*index+1, nums);
        return tree[index] = max(left,right);
    }
    
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        this->n = (int)A.size();
        this->k = K;
        tree.resize(4*n);
        buildTree(0,n-1,1,A);
        memset(dp, -1, sizeof dp);
        int ans = go (0,A);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> A = {1,15,7,9,2,5,10};
    int K = 3;
    cout << s.maxSumAfterPartitioning(A, K) << "\n";
}

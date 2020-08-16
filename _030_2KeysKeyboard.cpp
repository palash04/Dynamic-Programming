/*
https://leetcode.com/problems/2-keys-keyboard/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1002][1002];
    int go(int curr,int copiedSoFar,int n){
        if (curr == n){
            return 0;
        }
        
        if (curr > n){
            return INT_MAX;
        }
        
        if (dp[curr][copiedSoFar] != -1){
            return dp[curr][copiedSoFar];
        }
        
        int op1 = INT_MAX;
        int op2 = INT_MAX;
        if (curr != copiedSoFar){
            // copy
            op1 = go(curr, curr, n);
        }
        // paste
        if (copiedSoFar != 0){
            op2 = go(curr+copiedSoFar, copiedSoFar,n);
        }
        
        int ans = INT_MAX;
        if (op1 != INT_MAX && op2 != INT_MAX){
            ans = min(op1,op2)+1;
        }else if (op1 != INT_MAX){
            ans = op1+1;
        }else if (op2 != INT_MAX){
            ans = op2+1;
        }
        
        return dp[curr][copiedSoFar] = ans;
    }
    
    int minSteps(int n) {
        if (n == 1) return 0;
        if (n == 2) return 2;
        memset(dp,-1,sizeof dp);
        int ans = go(1,0,n);
        return ans;
    }
};

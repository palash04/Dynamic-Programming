/*
https://leetcode.com/problems/decode-ways-ii/
*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

class Solution {
public:
    // O(N), O(N)
    int go (int pos, string s, vector<int> &dp) {
        if (pos < 0) {
            return 1;
        }
        
        if (dp[pos] != -1) {
            return dp[pos];
        }
        
        if (s[pos] == '*') {
            ll res = 9 * go (pos-1, s, dp);
            if (pos > 0 and s[pos-1] == '1') {
                res = ( res + 9 * go (pos-2, s, dp) ) % mod;
            }else if (pos > 0 and s[pos-1] == '2') {
                res = ( res + 6 * go (pos-2, s, dp) ) % mod;
            }else if (pos > 0 and s[pos-1] == '*') {
                res = ( res + 15 * go (pos-2, s, dp) ) % mod;
            }
            dp[pos] = (int)res;
            return dp[pos];
        }
        
        ll res = s[pos] != '0' ? go (pos-1, s, dp) : 0;
        if (pos > 0 and s[pos-1] == '1') {
            res = ( res + go (pos-2, s, dp) ) % mod;
        }else if (pos > 0 and s[pos-1] == '2' and s[pos] <= '6') {
            res = ( res + go (pos-2, s, dp) ) % mod;
        }else if (pos > 0 and s[pos-1] == '*') {
            res = ( res + (s[pos] <= '6' ? 2 : 1) * go (pos-2, s, dp) ) % mod;
        }
        return dp[pos] = (int)res;
    }
    
    int numDecodings(string s) {
        int n = (int)s.size();
        vector<int> dp(n,-1);
        int ans = go (n-1,s,dp);
        return ans;
    }
};

int main() {
    Solution s;
    int ans = s.numDecodings("2839");
    cout << ans << "\n";
}

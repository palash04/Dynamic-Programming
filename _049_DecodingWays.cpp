/*
https://leetcode.com/problems/decode-ways/
/*

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
public:
    unordered_map<string,int> dp;
    int go(int pos,string s) {
        string key = to_string(pos);
        if (pos >= n) {
            return 1;
        }
        
        if (s[pos] == '0') {
            return 0;
        }
        
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        
        int ans = 0;
        int op1=0, op2=0;
        op1 = go (pos+1, s);
        if (pos+1 < n) {
            if ((s[pos] == '1' and (s[pos+1] >= '0' and s[pos+1] <= '9') ) or
                (s[pos] == '2' and (s[pos+1] >= '0' and s[pos+1] <= '6'))) {
                op2 = go(pos+2, s);
            }
        }
        
        ans = op1 + op2;
        
        return dp[key] = ans;
    }
    
    int numDecodings(string s) {
        this->n = (int)s.size();
        int ans = go(0,s);
        return ans;
    }
};

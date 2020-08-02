/*

https://leetcode.com/problems/word-break/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<string> st;
    unordered_map<string, int> dp;
public:
    int solveTD(string s){
        
        if (s == ""){
            return 1;
        }
        
        if (dp.find(s) != dp.end()){
            return dp[s];
        }
        
        for (int i=1;i<=s.size();i++){
            string ss = s.substr(0,i);
            if (st.find(ss) != st.end()){
                dp[s] += solveTD(s.substr(i,s.size()-i));
            }
        }
        return dp[s];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto word:wordDict){
            st.insert(word);
        }
        int tot = solveTD(s);
        return tot>=1;
    }
};

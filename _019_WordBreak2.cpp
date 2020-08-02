/*
https://leetcode.com/problems/word-break-ii/

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> dp;
    vector<string> help(string s,vector<string> &wordDict){
        if (s == ""){
            return {""};
        }
        
        if (dp.find(s) != dp.end()){
            return dp[s];
        }
        
        vector<string> subpart,wholepart;
        for (string word:wordDict){
            string ss = s.substr(0,word.size());
            
            if (ss != word){
                continue;
            }else{
                subpart = help(s.substr(word.size()), wordDict);
            }
            
            for (auto ans : subpart){
                string space = (ans.size() == 0)? "" : " ";
                wholepart.push_back(word+space+ans);
            }
        }
        
        return dp[s] = wholepart;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return help(s,wordDict);
    }
};

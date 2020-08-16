/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int go(int index,int buy, vector<int> &prices, int k,vector<vector<vector<int>>> &dp){
        string key = to_string(index) + "" + to_string(buy) + "" + to_string(k);
        if (index >= prices.size() || k == 0){
            return 0;
        }
        
        if (dp[index][buy][k] != -1){
            return dp[index][buy][k];
        }
        
        int x = 0;
        if (buy == 0){
            int B = go(index+1, 1, prices, k,dp) - prices[index];
            int NB = go(index+1, 0, prices, k,dp);
            x = max(B,NB);
        }else{
            int S = go(index+1, 0, prices, k-1,dp) + prices[index];
            int NS = go(index+1, 1, prices, k,dp);
            x = max(S,NS);
        }
        return dp[index][buy][k] = x;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        int ans = go(0,0,prices,2,dp);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << s.maxProfit(prices) << "\n";
}

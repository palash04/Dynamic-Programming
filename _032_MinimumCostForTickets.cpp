/*
https://leetcode.com/problems/minimum-cost-for-tickets/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> costs;
public:
    unordered_set<int> st;
    int dp[366];
    int go(int i){
        if (i>365){
            return 0;
        }
        if (dp[i] != -1){
            return dp[i];
        }
        int ans = INT_MAX;
        if (st.find(i) != st.end()){
            ans = min(ans, go(i+1) + costs[0]);
            ans = min(ans, go(i+7) + costs[1]);
            ans = min(ans, go(i+30) + costs[2]);
        }else{
            ans = go(i+1);
        }
        return dp[i] = ans;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof dp);
        this->costs = costs;
        for (int day:days) st.insert(day);
        
        int ans = go(1);
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};
    int ans = s.mincostTickets(days, costs);
    cout << ans << "\n";
}

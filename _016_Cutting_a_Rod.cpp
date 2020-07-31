/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces. 
For example, if length of the rod is 8 and the values of different pieces are given as following, 
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

length   | 1   2   3   4   5   6   7   8  
-----------------------------------------
price    | 1   5   8   9  10  17  17  20


*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> dp(10000,-1);

// O(n^2)
int helper(int n,vector<int> &nums){
    if (n == 0){
        return 0;
    }
    if (dp[n] != -1){
        return dp[n];
    }
    int ans = INT_MIN;
    for (int i=1;i<=n;i++){
        ans = max(ans, nums[i] + helper(n-i,nums));
    }
    return dp[n] = ans;
}

void solve(){
    dp.clear();
    int n = 8;
    vector<int> nums(n+1);
    nums = {0,3,5,8,9,10,17,17,20};
    
    int ans = helper(n,nums);
    cout << ans << "\n";
}

signed main(){
    solve();
}

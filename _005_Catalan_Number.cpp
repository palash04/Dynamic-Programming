#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long


class Solution {
public:
    int dpTD(int n,vector<int> &dp){
        if (n == 0){
            return 1;
        }
        
        if (dp[n] != -1){
            return dp[n];
        }
        
        int ans = 0;
        for (int i=1;i<=n;i++){
            ans += (dpTD(i-1,dp) * dpTD(n-i,dp));
        }
        return dp[n] = ans;
    }
    
    int dpBU(int n){
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=i;j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    
    
    int catalan(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        int ans = dpBU(n);
        return ans;
    }
};

int32_t main(){
    Solution s;
    // printing first 20 catalan numbers
    for (int i=0;i<=20;i++){
        cout << "Catalan of " << i << " : " << s.catalan(i) << "\n";
    }
}

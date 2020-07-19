#include <bits/stdc++.h>
using namespace std;

map<string,int> dp;
int recTD(vector<int> &coins, int n){
    string key = to_string(n);
    if (n == 0){
        return 0;
    }
    if (dp.find(key) != dp.end()){
        return dp[key];
    }
    int ans = 1e9;
    for (int i=0;i<coins.size();i++){
        if (coins[i] <= n){
            ans = min(ans, recTD(coins, n-coins[i])+1);
        }
    }
    return dp[key] = ans;
}

int ccBU(vector<int> &coins,int n){
    vector<int> dp(n+1,1e9);
    dp[0] = 0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<coins.size();j++){
            if (coins[j] <= i){
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
    }
    return dp[n];
}


int coinChange(vector<int> &coins, int amount){
    int ans = recTD(coins,amount);
    return ans == 1e9 ? -1 : ans;
}

int main(){
    vector<int> coins = {1,2,4,5,6,7};
    int amount = 15;
    int ans = coinChange(coins, amount);
    cout << ans << "\n";
}

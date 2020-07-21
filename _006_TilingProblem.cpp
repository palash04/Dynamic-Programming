/*

Given a floor of size n x m and tiles of size 1 x m. The problem is to count the number of ways to tile the given floor using 1 x m tiles. 
A tile can either be placed horizontally or vertically.
Both n and m are positive integers and 2 < = m.

https://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/

*/

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

// O(n)
int recTD(int m,int n,vector<int> &dp){
    
    if (n == 0){
        return 1;
    }
    if (n < 0){
        return 0;
    }
    
    // lookup
    if (dp[n] != -1){
        return dp[n];
    }
    
    int op1 = recTD(m,n-1,dp);
    int op2 = recTD(m,n-m,dp);
    
    return dp[n] = op1 + op2;
}

// O(n)
int dpBU(int m,int n){
    vector<int> dp(n+1,-1);
    dp[0] = 1;
    
    for (int i=1;i<=n;i++){
        dp[i] = dp[i-1];
        if (i-m >= 0){
            dp[i] = ((dp[i]%mod) + (dp[i-m]%mod))%mod;
        }
    }
    return dp[n];
}

int32_t main(){
    int t;
    cin>>t;
    while (t--){
        int m,n;
        cin>>n>>m;
        int ans = dpBU(m,n);
        cout << ans << "\n";
    }
}

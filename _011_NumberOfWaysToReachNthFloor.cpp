/*
Given N number of stairs. Also given the number of steps that one can cover at most in one leap (K). 
The task is to find the number of possible ways one (only consider combinations) can climb to the top of the building in K leaps or less from the ground floor.

https://www.geeksforgeeks.org/number-of-ways-to-reach-nth-floor-by-taking-at-most-k-leaps/

*/

#include <bits/stdc++.h>
using namespace std;

// O(NK)
int numberWaysBU(int n,int k){
    int m = k;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    
    for (int i=0;i<=m;i++){
        dp[i][0] = 1;
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j];
            if (i<=j){
                dp[i][j] += dp[i][j-i];
            }
        }
    }
    return dp[m][n];
}

int main(){
    int n=29;
    int k=5;
    
    int ans = numberWaysBU(n,k);
    cout << ans << "\n";
}

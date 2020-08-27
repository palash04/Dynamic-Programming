/*
Given 3 strings ,the task is to find the longest common sub-sequence in all three given sequences.

*/

#include <bits/stdc++.h>
using namespace std;

string X,Y,Z;

int dp[201][201][201];

int go(int l, int m, int n) {
    if (l == 0 or m == 0 or n == 0) {
        return 0;
    }
    
    if ( X[l-1] == Y[m-1] and Y[m-1] == Z[n-1] ) {
        return go(l-1,m-1,n-1) + 1;
    }
    
    if( dp[l][m][n] != -1 ) {
        return dp[l][m][n];
    }
    
    int ans = INT_MIN;
    ans = max(ans, go(l-1,m,n));
    ans = max(ans, go(l,m-1,n));
    ans = max(ans, go(l,m,n-1));
    
    return dp[l][m][n] = ans;
}

void solve() {
    cin>>X>>Y>>Z;
    int l = (int)X.size();
    int m = (int)Y.size();
    int n = (int)Z.size();
    memset(dp, -1, sizeof dp);
    int ans = go (l,m,n);
    cout << ans << "\n";
}

int main() {
    solve();
    return 0;
}

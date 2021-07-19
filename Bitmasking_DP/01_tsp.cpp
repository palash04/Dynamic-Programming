/*

https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/

*/

#include <bits/stdc++.h>
using namespace std;

/* macros */
#define inf 1e9
#define int long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vt vector
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define gtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": " << solve() << "\n";TC++;}
#define gvtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": "; vsolve(); TC++;}
#define notc solve();
#define mod 1000000007
#define ret return 0;

int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {40,30,0,10},
        {25,34,10,0}
};

const int n = 4;

int visited_all = (1<<n) - 1;

int dp[(1<<n) + 2][n + 2];

int go (int mask, int pos) {
    if (mask == visited_all) {
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for (int i=0;i<n;i++) {
        if ( (mask & (1<<i)) == 0 ) {
            ans = min(ans, go ( (1<<i) | mask  , i) + dist[pos][i]);
        }
    }

    return dp[mask][pos] = ans;
}

void solve() {
    int mask = 1;
    int pos = 0;

    memset(dp, -1, sizeof dp);

    int ans = go (mask, pos);
    cout << ans << "\n";
}

int32_t main(){
    solve();
}

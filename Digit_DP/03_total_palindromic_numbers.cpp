/*
https://www.codechef.com/problems/AOPN
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

string s,a,b;

int dp[20][11][11][2][2][2][2];

int go (int pos, int last, int slast, bool tight, bool odd, bool even, bool st) {
    if (pos == s.size()) {
        return odd and even;
    }

    if (dp[pos][last][slast][tight][odd][even][st] != -1) {
        return dp[pos][last][slast][tight][odd][even][st];
    }

    int ans = 0;

    if (st == 0) {
        ans = go (pos + 1, last, slast, tight&(s[pos] == '0'), odd, even, st);
        int en = tight ? s[pos] - '0' : 9;
        for (int i=1;i<=en;i++) {
            ans += go (pos + 1, i, slast, tight&(i == en), odd, even, 1);
        }
    } else {
        int en = tight ? s[pos]-'0' : 9;
        for (int i=0;i<=en;i++) {
            ans += go (pos + 1, i, last, tight&(i == en), odd | (i == slast), even | (i == last), 1);
        }
    }

    return dp[pos][last][slast][tight][odd][even][st] = ans;
}

void solve() {
    cin>>a>>b;
    s = b;
    memset(dp, -1, sizeof dp);
    int ans = go (0, 10, 10, 1, 0, 0, 0);
    s = a;
    memset(dp, -1, sizeof dp);
    ans -= go (0, 10, 10, 1, 0, 0, 0);
    cout << ans << "\n";
}

int32_t main(){
    fastio
    tc
    ret
}

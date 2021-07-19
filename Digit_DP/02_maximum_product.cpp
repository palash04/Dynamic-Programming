/*

https://codeforces.com/gym/100886/problem/G

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

string a,b;
pair<int, string> dp[20][2][2][2];


pair<int, string> go (int pos, int t1, int t2, int st) {

    if (pos == a.size()) {
        return {1, ""};
    }

    if (dp[pos][t1][t2][st].first != -1) {
        return dp[pos][t1][t2][st];
    }

    int mx = INT_MIN;
    string ans = "";

    int in = t1 ? a[pos] - '0' : 0;
    int en = t2 ? b[pos] - '0' : 9;

    for (int i = in; i <= en; i++ ) {
        int val;
        if (st == 0 and i == 0) {
            val = 1;
        }else {
            val = i;
        }

        pair<int, string> dpans = go (pos + 1, t1 & (i == in), t2 & (i == en), st | (i>0));

        if (val * dpans.first > mx) {
            mx = val * dpans.first;
            if (st == 0 and i == 0) {
                ans = dpans.second;
            }else {
                ans = "";
                ans = i + '0';
                ans += dpans.second;
                dpans.second = ans;
            }
        }
    }

    return dp[pos][t1][t2][st] = {mx, ans};
}

void solve() {
    cin>>a>>b;
    reverse(a.begin(), a.end());
    while (a.size() < b.size()) {
        a += "0";
    }
    reverse(a.begin(), a.end());

    for (int i=0;i<20;i++) {
        for (int j=0;j<2;j++) {
            for (int k=0;k<2;k++) {
                for (int l=0;l<2;l++) {
                    dp[i][j][k][l].first = -1;
                }
            }
        }
    }

    string ans = go (0, 1, 1, 0).second;
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}

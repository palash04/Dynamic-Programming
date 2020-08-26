/*
https://atcoder.jp/contests/dp/tasks/dp_h
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
#define pb push_back
#define fi first
#define se second
#define pi pair<int,int>
#define tc int t;cin>>t;while (t--){solve();}
#define gtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": " << solve() << "\n";TC++;}
#define gvtc int t;cin>>t;int TC=1;while (t--) {cout << "Case #" << TC << ": "; vsolve(); TC++;}
#define notc solve();
#define newline cout << "\n";
#define mod 1000000007
#define ret return 0;
#define sz(x) (int)x.size();
#define rep(i,a,b) for(int i=a;i<b;i++)
#define srt(x) sort(x.begin(), x.end())
#define rsrt(x) sort(x.rbegin(), x.rend())

int H,W;
vt<vc> board(1001, vc(1001));
int dp[1001][1001];


bool isSafe(int i,int j) {
    return i>=1 && i<=H && j>=1 && j<=W && board[i][j]=='.';
}

int go(int i,int j) {
    if (i == H and j == W) {
        return 1;
    }
    
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    
    int ans = 0;
    if (isSafe(i,j+1)) {
        ans = (ans%mod + go(i,j+1)%mod)%mod;
    }
    if (isSafe(i+1,j)) {
        ans = (ans%mod + go(i+1,j)%mod)%mod;
    }
    
    return dp[i][j] = ans;
}

void solve() {
    cin>>H>>W;
    rep (i,1,H+1) {
        rep (j,1,W+1) {
            cin>>board[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    int ans = go(1,1);
    cout << ans << "\n";
}

int32_t main(){
    fastio
    notc
    ret
}

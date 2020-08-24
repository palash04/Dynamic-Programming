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

string s;

int dp[20][11][11][2][2][2][2];

int go(int pos,int las, int slas, bool tight, bool odd, bool even, bool st) {
    if (pos == s.size()) {
        return (odd and even);
    }
    if (dp[pos][las][slas][tight][odd][even][st] != -1) {
        return dp[pos][las][slas][tight][odd][even][st];
    }
    
    int ans = 0;
    if ( st == 0 ) {
        ans = go( pos+1, las, slas, tight&(s[pos]=='0'), odd, even, st);
        int en = tight ? (s[pos]-'0'):9;
        for (int i=1;i<=en;i++) {
            ans += go(pos+1, i, slas, tight&(i==en), odd, even, 1);
        }
    }else {
        int en = tight ? (s[pos]-'0') : 9;
        for (int i=0;i<=en;i++) {
            ans += go(pos+1, i, las, tight&(i==en), odd|(i==slas), even|(i==las), 1);
        }
    }
    return dp[pos][las][slas][tight][odd][even][st] = ans;
}

void solve() {
    string a,b;
    cin>>a>>b;
    s = b;
    memset(dp, -1, sizeof dp);
    int ans = go(0,10,10,1,0,0,0);
    s = a;
    memset(dp, -1, sizeof dp);
    ans -= go(0,10,10,1,0,0,0);
    cout << ans << "\n";
}

int32_t main(){
    fastio
    tc
    ret
}
